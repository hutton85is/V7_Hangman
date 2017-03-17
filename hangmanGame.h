#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <iostream>
#include "charNode.h"
#include <set>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

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

    // add word to database set
    void addWordToDatabase(string addWord);

    // remove word from database set
    void removeWordFromDatabase(string rmWord);

    // function to set the private variable storing maximum available guesses
    void setMaxGuesses(int maxGuesses);

    // initialize variables for a new game, this function is only called when starting a new game
    void newGame();

    // get games played this session
    int getPlayed() const;

    // get games won this session
    int getWon() const;

    // get games lost this session
    int getLost() const;

    // get function for the score this game
    int getPoints() const;

    // get function for total score this session
    int getTotalPoints() const;

private:

    // node that points to the first element in a link of CharNode
    NodePtr root;

    // word being used in hangman
    string word;

    // games lost during session
    int lost;

    // games won during session
    int won;

    // games played during session
    int played;

    // points for this game
    int points;

    // points for this session
    int totalPoints;

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

    // variable to tell if we already have checked for a winner/looser at the end of a game
    // this is done since if we call isItWinner() function twice we add another win/loss
    bool alreadyCheckedWinnerLooser;

    // calculate points at the end of each game
    int calculatePoints();

};

#endif // TTTGAME_H
