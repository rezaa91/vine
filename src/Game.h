#ifndef GAME_H
#define GAME_H

#include "EntityManager.h"
#include "fsm/GameStates.h"
#include "InputManager.h"
#include <string>
#include <SDL2/SDL.h>

namespace Vine {
    class Game
    {
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        Vine::EntityManager* _entityManager;
        Vine::GameState* _gameState;
        Vine::InputManager* _inputManager;
        bool _isRunning;
        int _lastFrame;
    public:
        Game();
        ~Game();

        bool initialise(const std::string title, const int width, const int height);
        bool isRunning() const;

        void handleEvents();
        void update();
        void render();
    };
};

#endif
