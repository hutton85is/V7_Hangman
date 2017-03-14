#include "UIHangmanGame.h"

UIHangmanGame::UIHangmanGame(){

    gamesPlayed = 0;

    play();
}

UIHangmanGame::~UIHangmanGame(){
    delete game;
}

void UIHangmanGame::displayCorrectGuesses(){

    string append = "";

    for (NodePtr node = game->getRoot(); node != NULL; node = node->next){

        if (node->hit){
            append += node->character;
        }
        else{
            append += "-";
        }
    }

    cout << append << endl << endl;
}

void UIHangmanGame::getStartingInfo(){

    int maxGuesses;

    cout << "Enter how many tries you want to have to guess the word" << endl;
    cin >> maxGuesses;
    cout << endl;

    game = new hangmanGame(maxGuesses);
}

char UIHangmanGame::getGuessedCharInput(){
    char guess;
    cout << "Guess a character" << endl;
    cin >> guess;
    cout << endl;
    return guess;
}

void UIHangmanGame::displayIfCorrect(char guess){

    if (game->checkGuess(guess)){
        cout << "Correct you got that one right" << endl;
    }

    else{
        cout << "Sorry, not the correct character" << endl;
    }
}

void UIHangmanGame::displayWinnerOrLooser(){

    if (game->isItWon()){
        cout << "Congratz you got it" << endl;
        cout << "The word is: ";
        cout << game->getWord() << endl;
    }

    else{
        cout << "Sorry, LOOSER" << endl;
        cout << "The word is: ";
        cout << game->getWord() << endl;
    }

    cout << endl << endl;
}

void UIHangmanGame::displayGuessesLeft(){

    int guessesLeft = game->getMaxGuesses() - game->getGuesses();

    cout << "You have " << guessesLeft << " guesses left" << endl;
}

bool UIHangmanGame::playAgain(){

    string play;

    if (gamesPlayed == 0){
        return true;
    }

    cout << "Do you want to play again? hit 'no' or 'n' to quit and any key to play again" << endl;
    cin >> play;

    if (play == "n" || play == "N" || play == "No" || play == "no"){
        return false;
    }

    return true;
}

void UIHangmanGame::play(){

    char guess;

    while (playAgain()){

        getStartingInfo();

        while (!game->isItWon() && game->getGuesses() != game->getMaxGuesses()){

            displayCorrectGuesses();

            displayGuessesLeft();

            guess = getGuessedCharInput();

            displayIfCorrect(guess);
        }

        gamesPlayed++;

        displayWinnerOrLooser();
    }
}
