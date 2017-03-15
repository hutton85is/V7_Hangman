#ifndef UIHANGMANGAME_H
#define UIHANGMANGAME_H

#include "hangmanGame.h"

using namespace std;

class UIHangmanGame
{
public:

    UIHangmanGame();

    virtual ~UIHangmanGame();

    // Function to play game
    void play();

private:

    // Create an instance of the game hangman
    hangmanGame *game;

    // Function that asks the user for the allowed max guesses
    void getMaxGuesses();

    // Function to display correct guesses
    // correct guess displays the correct character guessed
    // wrong guess displays '-' symbol
    void displayCorrectGuesses();

    // Receive guess from user
    char getGuessedCharInput();

    // Display if guess is correct or wrong
    void displayIfCorrect(char guess);

    // Display if game is won or lost
    void displayWinnerOrLooser();

    // Display how many guesses are left
    void displayGuessesLeft();

    // Variable that stores games played by player
    int gamesPlayed;

    // Function to display game menu
    char displayPlayMenu();

    // Display games played
    void displayGamesPlayed();
};

#endif // UIHANGMANGAME_H
