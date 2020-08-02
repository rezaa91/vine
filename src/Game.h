#ifndef GAME_H
#define GAME_H

#include "EntityManager.h"
#include "fsm/GameStates.h"
#include "input/Input.h"
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

    public:
        Game();
        ~Game();

        bool initialise(const std::string title, const int width, const int height);
        bool isRunning() const;

        void handleEvents();
        void update();
        void render();

        void togglePause();
        void endGame();
    };
};

#endif
