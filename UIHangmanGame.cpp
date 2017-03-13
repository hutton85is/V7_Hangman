#include "UIHangmanGame.h"

UIHangmanGame::UIHangmanGame()
{
    getStartingInfo();
}

UIHangmanGame::~UIHangmanGame()
{
}

void UIHangmanGame::getStartingInfo(){

    string word;
    int maxGuesses;

    cout << "Enter word to play in hangman: " << endl;
    cin >> word;

    cout << "Enter how many tries you want to have to guess the word" << endl;
    cin >> maxGuesses;

    game = new hangmanGame(word, maxGuesses);

    play();
}

void UIHangmanGame::play(){
    char a;
    while (!game->isItWon()){
        cout << "Enter a char" << endl;
        cin >> a;
        cout << "Was it found " << game->checkGuess(a) << endl;
    }
    cout << "Congratz you won" << endl;
}
