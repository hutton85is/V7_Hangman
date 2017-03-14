#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <iostream>
#include "charNode.h"

using namespace std;

class hangmanGame
{

public:

    hangmanGame(string word, int maxGuesses);

    virtual ~hangmanGame();

    bool isItWon();

    string getWord() const;

    int getGuesses() const;

    int getMaxGuesses() const;

    NodePtr getRoot() const;

    bool checkGuess(char checkChar);

    bool isItFound(char checkChar);

private:

    NodePtr root;

    string word;

    int lengthOfWord;

    int guesses;

    int maxGuesses;

    void wordToCharNode();

};

#endif // TTTGAME_H
