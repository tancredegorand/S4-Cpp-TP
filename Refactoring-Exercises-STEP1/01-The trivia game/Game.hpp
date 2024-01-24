#pragma once
#include <string>
#include <vector>

enum class Category {
    Pop,
    Science,
    Sports,
    Rock,

    COUNT, //must be last
    
}; 

class Game {
private:
    std::vector<std::string> players{};

    std::vector<int> places{};
    std::vector<int> purses{};

    std::vector<bool> inPenaltyBox{};

    std::vector<std::string> popQuestions{};
    std::vector<std::string> scienceQuestions{};
    std::vector<std::string> sportsQuestions{};
    std::vector<std::string> rockQuestions{};

    unsigned int currentPlayer{0};
    bool isGettingOutOfPenaltyBox{};

public:
    Game();
    std::string createRockQuestion(int index);
    bool isPlayable();
    bool add(const std::string& playerName);

    size_t howManyPlayers();
    void   roll(int roll);

    bool wasCorrectlyAnswered();
    bool wrongAnswer();

private:
    void askQuestion();
    std::string currentCategory();

    bool didPlayerWin();
};