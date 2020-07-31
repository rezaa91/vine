#include "Game.h"
#include "Config.h"
#include "components/SpriteComponent.h"
#include "components/TransformComponent.h"
#include "components/VelocityComponent.h"
#include <spdlog/spdlog.h>

Vine::Game::Game()
    : _isRunning(false),
    _entityManager(new Vine::EntityManager{}),
    _gameState(new Vine::GameState{}),
    _inputManager(new Vine::InputManager{}),
    _lastFrame(0)
{}

Vine::Game::~Game()
{
    spdlog::info("Cleaning up game...");
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
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

    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    _isRunning = true;
    _gameState->push(new Vine::PlayState{});

    Vine::Entity& entity1 = _entityManager->addEntity("TESTING");
    entity1.addComponent<Vine::SpriteComponent>(*_renderer, "../assets/sprites/player.png", 0, 0, 32, 32);
    entity1.addComponent<Vine::TransformComponent>(10, 10);
    entity1.addComponent<Vine::VelocityComponent>(50, 0);

    return true;
}

bool Vine::Game::isRunning() const
{
    return _isRunning;
}

void Vine::Game::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                _isRunning = false;
                break;
            default:
                _inputManager->pollEvent(event);
                break;
        }
    }
}

void Vine::Game::update()
{
    while(!SDL_TICKS_PASSED(SDL_GetTicks(), _lastFrame + Vine::Config::Game::FRAME_TARGET_TIME));
    float deltaTime = (SDL_GetTicks() - _lastFrame) / 1000.0f;
    _lastFrame = SDL_GetTicks();

    _entityManager->update(deltaTime);
}

void Vine::Game::render()
{
    SDL_RenderClear(_renderer);

    _entityManager->render();

    SDL_RenderPresent(_renderer);
}


