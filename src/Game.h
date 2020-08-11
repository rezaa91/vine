#ifndef GAME_H
#define GAME_H

#include "EntityManager.h"
#include "CollisionManager.h"
#include "fsm/GameStates.h"
#include "input/Input.h"
#include "components/TileComponent.h"
#include <string>
#include <vector>
#include <SDL2/SDL.h>

namespace Vine {
    class Game
    {
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        Vine::EntityManager* _entityManager;
        Vine::GameState* _gameState;
        SDL_Event _event;
        bool _isRunning;
        bool _isPaused;
        int _lastFrame;
        std::vector<Vine::Input*> _inputs;
        std::vector<Vine::TileComponent*> _tiles;
        Vine::Entity* _player;
        CollisionManager _collisionManager;

        void loadGameTextures();
        void handleCameraMovement();
    public:
        static SDL_Rect _camera;

        Game();
        ~Game();

        bool initialise(const std::string title, const int width, const int height);
        bool isRunning() const;
        void checkCollisions();

        void handleEvents();
        void update();
        void render();

        void togglePause();
        void endGame();
    };
};

#endif
