#ifndef UIHANGMANGAME_H
#define UIHANGMANGAME_H

#include "hangmanGame.h"

using namespace std;

class UIHangmanGame
{
    public:

        UIHangmanGame();

        virtual ~UIHangmanGame();

        void play();

    private:

        hangmanGame *game;

        void getMaxGuesses();

        void displayCorrectGuesses();

        char getGuessedCharInput();

        void displayIfCorrect(char guess);

        void displayWinnerOrLooser();

        void displayGuessesLeft();

        bool playAgain();

        int gamesPlayed;

        char displayPlayMenu();
};

#endif // UIHANGMANGAME_H
