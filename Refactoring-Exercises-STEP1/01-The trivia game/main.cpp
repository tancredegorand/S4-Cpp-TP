#include <random>
#include "Game.hpp"

auto& random_generator()
{
    thread_local std::default_random_engine gen{std::random_device{}()};
    return gen;
}

/// Returns a random float between `min` and `max`.
float random_float(float min, float max)
{
    auto distribution = std::uniform_real_distribution<float>{min, max};
    return distribution(random_generator());
}

/// Returns a random int between `min` (included) and `max` (included).
int random_int(int min, int max)
{
    auto distribution = std::uniform_int_distribution<int>{min, max};
    return distribution(random_generator());
}

int main()
{
    Game aGame{};

    aGame.add("Chet");
    aGame.add("Pat");
    aGame.add("Sue");

    bool notAWinner{true};
    while (notAWinner)
    {
        aGame.roll(random_int(1, 5));

        if (random_int(0, 8) == 7)
        {
            notAWinner = aGame.wrongAnswer();
        }
        else
        {
            notAWinner = aGame.wasCorrectlyAnswered();
        }
    }
}