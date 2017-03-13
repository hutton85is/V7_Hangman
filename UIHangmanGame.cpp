#include "UIHangmanGame.h"

UIHangmanGame::UIHangmanGame()
{
    game = new hangmanGame("Russell", 10);
}

UIHangmanGame::~UIHangmanGame()
{
    //dtor
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
