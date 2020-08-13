#ifndef GAME_STATES_H
#define GAME_STATES_H

#include <stack>

namespace Vine {
    class State
    {
    public:
        virtual void onEnter() = 0;
        virtual void onExit() = 0;
    };

    class GameState
    {
    private:
        std::stack<Vine::State*> _states;
    public:
        GameState() = default;
        void push(Vine::State* state);
    };

    class MenuState : public Vine::State
    {
    public:
        void onEnter();
        void onExit();
    };

    class PauseState : public Vine::State
    {
    public:
        void onEnter();
        void onExit();
    };

    class PlayState : public Vine::State
    {
    public:
        void onEnter();
        void onExit();
    };
};

#endif
