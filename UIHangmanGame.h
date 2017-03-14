#ifndef UIHANGMANGAME_H
#define UIHANGMANGAME_H

#include "hangmanGame.h"

class UIHangmanGame
{
    public:

        UIHangmanGame();

        virtual ~UIHangmanGame();

        void play();

    private:

        hangmanGame *game;

        void getStartingInfo();

        void displayCorrectGuesses();

        char getGuessedCharInput();

        void displayIfCorrect(char guess);

        void displayWinnerOrLooser();

        void displayGuessesLeft();

        bool playAgain();

        int gamesPlayed;
};

#endif // UIHANGMANGAME_H
