#include <Game.h>
#include <gtest/gtest.h>

class GameTest : public ::testing::Test
{
protected:
    Vine::Game* game;
    void SetUp() override
    {
        game = new Vine::Game{};
    }

    void TearDown() override
    {}
};

TEST_F(GameTest, isRunningIsFalseInitially)
{
    ASSERT_FALSE(game->isRunning());
}
