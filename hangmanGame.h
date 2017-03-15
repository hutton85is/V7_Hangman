#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <iostream>
#include "charNode.h"
#include <set>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

class hangmanGame
{

public:

    hangmanGame();

    virtual ~hangmanGame();

    // Function to check if a game is won
    bool isItWon();

    // get function for the word being guessed
    string getWord() const;

    // get function for total guesses made
    int getGuesses() const;

    // get function for maximum guesses allowed
    int getMaxGuesses() const;

    // get function to get the root-node of the link containing characters in word and their info
    NodePtr getRoot() const;

    // function to verify if guess is correct
    bool checkGuess(char checkChar);

    // check if a character is already found(guessed)
    bool isItFound(char checkChar);

    // get number of games played in a set
    int getGamesPlayed();

    // add word to database set
    void addWordToDatabase(string addWord);

    // remove word from database set
    void removeWordFromDatabase(string rmWord);

    // function to set the private variable storing maximum available guesses
    void setMaxGuesses(int maxGuesses);

    // initialize variables for a new game
    void newGame();

private:

    // node that points to the first element in a link of CharNode
    NodePtr root;

    // word being used in hangman
    string word;

    // games lost

    // length of word being used in hangman
    int lengthOfWord;

    // guesses made
    int guesses;

    // guesses allowed
    int maxGuesses;

    // create a list containing all characters in a word and info
    void wordToCharNode();

    // function to read the word database and insert it to a set
    void initializeWordDatabase();

    // contains a set of all words in the database for hangman
    set<string> wordDatabaseSet;

    // an iterator to run through the set
    set<string>::iterator it;

    // function to search for a random word in the wordDatabaseSet
    void findRandomWord();

    // function that pushes the wordDatabaseSet back to a text file
    void loadToWordDatabase();

};

#endif // TTTGAME_H
