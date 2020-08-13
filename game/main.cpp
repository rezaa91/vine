#include <Config.h>
#include <Game.h>
#include <spdlog/spdlog.h>

int main(int argc, char** argv)
{
    spdlog::info("Application starting...");
    Vine::Game* game = new Vine::Game;

     if (!game->initialise(Vine::Config::Game::WINDOW_TITLE, Vine::Config::Game::WIDTH, Vine::Config::Game::HEIGHT))
     {
         spdlog::error("Unable to initialise game");

         return 500;
     }

     while (game->isRunning())
     {
         game->handleEvents();
         game->update();
         game->render();
     }

    return 0;
}
