#include "UIHangmanGame.h"

UIHangmanGame::UIHangmanGame()
{
    getStartingInfo();
}

UIHangmanGame::~UIHangmanGame()
{
}

void UIHangmanGame::displayCorrectGuesses(){

    string append = "";

    for (NodePtr node = game->getRoot(); node != NULL; node = node->next){

        if (node->hit){
            append += node->character;
            append += ' ';
        }
        else{
            append += "_ ";
        }
    }

    cout << append << endl << endl;
}

void UIHangmanGame::getStartingInfo(){

    string word;
    int maxGuesses;

    cout << "Enter word to play in hangman: " << endl;
    cin >> word;
    cout << endl;

    cout << "Enter how many tries you want to have to guess the word" << endl;
    cin >> maxGuesses;
    cout << endl;

    game = new hangmanGame(word, maxGuesses);

    play();
}

void UIHangmanGame::play(){

    char guess;

    while (!game->isItWon() && game->getGuesses() != game->getMaxGuesses()){

        displayCorrectGuesses();
        cout << "Guess a character" << endl;
        cin >> guess;
        cout << endl;

        if (game->checkGuess(guess)){
            cout << "Correct you got that one right" << endl;
        }
        else{
            cout << "Sorry, not the correct character" << endl;
        }

    }

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

}
