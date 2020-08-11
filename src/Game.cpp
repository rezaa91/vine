#include "Game.h"
#include "Config.h"
#include "components/SpriteComponent.h"
#include "components/TransformComponent.h"
#include "components/VelocityComponent.h"
#include "input/GameInput.h"
#include "input/PlayerInput.h"
#include "Map.h"
#include "TextureManager.h"
#include <spdlog/spdlog.h>
#include <map>

SDL_Rect Vine::Game::_camera;

Vine::Game::Game()
    : _isRunning(false),
    _entityManager(new Vine::EntityManager{}),
    _gameState(new Vine::GameState{}),
    _lastFrame(0)
{
    _isPaused = false;
    _inputs.emplace_back(new Vine::GameInput{*this});
}

Vine::Game::~Game()
{
    spdlog::info("Cleaning up game...");
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
}

void Vine::Game::togglePause()
{
    _isPaused = !_isPaused;
    _isPaused ? _gameState->push(new PauseState{}) : _gameState->push(new PlayState{});
}

void Vine::Game::loadGameTextures()
{
    std::map<std::string, std::string> textures {
        {"../assets/sprites/player.png", "player"},
        {"../assets/tilemaps/block.png", "block"},
        {"../assets/tilemaps/center_grass.png", "center_grass"},
        {"../assets/tilemaps/left_grass.png", "left_grass"},
        {"../assets/tilemaps/right_grass.png", "right_grass"}
    };

    for (auto texture : textures)
    {
        Vine::TextureManager::addTexture(*_renderer, texture.first, texture.second);
    }
}

bool Vine::Game::initialise(const std::string title, const int width, const int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        spdlog::error("Unable to initialise SDL");
        return false;
    }

    _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, NULL);

    if (!_window)
    {
        spdlog::error("Unable to create window");
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, 0);

    if (!_renderer)
    {
        spdlog::error("Unable to create renderer");
        return false;
    }

    spdlog::debug("SDL window & render successfully created");

    SDL_SetRenderDrawColor(_renderer, 50, 50, 50, 255);
    _isRunning = true;
    loadGameTextures();

    _gameState->push(new Vine::PlayState{});

    Map map(
        *_renderer, 
        "../assets/tilemaps/map.csv",
        Vine::Config::Map::TILE_SIZE,
        Vine::Config::Map::WIDTH,
        Vine::Config::Map::HEIGHT
    );

    _tiles = map.createTiles();
    _camera = {0, 0, Vine::Config::Game::WIDTH, Vine::Config::Game::HEIGHT};

    Vine::Entity& player = _entityManager->addEntity("PLAYER");
    player.addComponent<Vine::SpriteComponent>(*_renderer, "player", 0, 0, 32, 32, 3, 120);
    player.addComponent<Vine::TransformComponent>(10, Vine::Config::Player::GROUND_LEVEL - 1);
    player.addComponent<Vine::VelocityComponent>(0, 0);
    _inputs.emplace_back(new Vine::PlayerInput{player});

    _player = &player;

    return true;
}

void Vine::Game::handleCameraMovement()
{
    Vine::TransformComponent* playerTransform = _player->getComponent<Vine::TransformComponent>();
    glm::vec2 playerPosition = playerTransform->getPosition();

    _camera.x = playerPosition.x - (Config::Game::WIDTH / 2);
    _camera.y = playerPosition.y - (Config::Game::HEIGHT / 2);

    _camera.x = _camera.x < 0 ? 0 : _camera.x;
    _camera.x = _camera.x > _camera.w ? _camera.w : _camera.x;
    _camera.y = _camera.y < 0 ? 0 : _camera.y;
    _camera.y = _camera.y > _camera.h ? _camera.h : _camera.y;
}

bool Vine::Game::isRunning() const
{
    return _isRunning;
}

void Vine::Game::checkCollisions()
{
    Vine::TransformComponent* playerTransform = _player->getComponent<Vine::TransformComponent>();
    glm::vec2 previousPosition = playerTransform->getPreviousPosition();
    const float buffer = 1;

    // todo remove hard code - assumes colliding from left
    previousPosition.x -= buffer;

    if(_collisionManager.playerAndTilesCollision(*_player, _tiles))
    {
        playerTransform->setPosition(previousPosition);
    }
}

void Vine::Game::handleEvents()
{
    while (SDL_PollEvent(&_event))
    {
        for (auto& input : _inputs)
        {
            input->handleInput(_event);
        }
    }
}

void Vine::Game::update()
{
    while(!SDL_TICKS_PASSED(SDL_GetTicks(), _lastFrame + Vine::Config::Game::FRAME_TARGET_TIME));
    float deltaTime = (SDL_GetTicks() - _lastFrame) / 1000.0f;
    _lastFrame = SDL_GetTicks();

    if (_isPaused)
    {
        return;
    }

    for (auto& tile : _tiles)
    {
        tile->update(deltaTime);
    }

    _entityManager->update(deltaTime);

    checkCollisions();

    handleCameraMovement();
}

void Vine::Game::render()
{
    SDL_RenderClear(_renderer);

    // render map
    for (auto& tile : _tiles)
    {
        tile->render();
    }

    _entityManager->render();

    SDL_RenderPresent(_renderer);
}

void Vine::Game::endGame()
{
    _isRunning = false;
}
