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
};

#endif // UIHANGMANGAME_H
