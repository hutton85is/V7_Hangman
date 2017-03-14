#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <iostream>
#include "charNode.h"
#include <set>

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

    int getGamesPlayed();

private:

    NodePtr root;

    string word;

    int lengthOfWord;

    int guesses;

    int maxGuesses;

    void wordToCharNode();

    void initializeWordDatabase();

    set<string> wordDatabaseSet;

};

#endif // TTTGAME_H
