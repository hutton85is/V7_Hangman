#ifndef UIHANGMANGAME_H
#define UIHANGMANGAME_H

#include "hangmanGame.h"

using namespace std;

class UIHangmanGame
{
public:

    UIHangmanGame();

    virtual ~UIHangmanGame();

private:

    // Create an instance of the game hangman
    hangmanGame *game;

    // Function that asks the user for the allowed max guesses
    void getMaxGuesses();

    // Function to display correct guesses
    // correct guess displays the correct character guessed
    // wrong guess displays '-' symbol
    void displayCorrectGuesses();

    // Function to play game
    void play();

    // Receive guess from user
    string getGuessedCharInput();

    // Display if guess is correct or wrong
    void displayIfCorrect(string guess);

    // Display if game is won or lost
    void displayWinnerOrLooser();

    // Display how many guesses are left
    void displayGuessesLeft();

    // Function to display game menu
    void displayPlayMenu();

    // Display games played
    void displayGamesStatus();

    // display length of word to guess
    void displayLengthOfWord();

    // Function to act on players choice of action
    void gotoAction(char choose);

    // Add word to database
    void addWord();

    // Remove word from database
    void removeWord();

    // display game points
    void displayGamePoints();
};

#endif // UIHANGMANGAME_H
