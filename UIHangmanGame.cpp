#include "UIHangmanGame.h"

UIHangmanGame::UIHangmanGame(){

    gamesPlayed = 0;

    game = new hangmanGame();

    play();
}

UIHangmanGame::~UIHangmanGame(){
    game->~hangmanGame();
}

void UIHangmanGame::displayCorrectGuesses(){

    string append = "";

    // Append to string all characters that are guessed correctly
    // all strings not guessed correctly are appended as '-'
    for (NodePtr node = game->getRoot(); node != NULL; node = node->next){

        if (node->hit){
            append += node->character;
        }
        else{
            append += "-";
        }
    }

    cout << "  " << append << endl << endl;
}

void UIHangmanGame::getMaxGuesses(){

    int maxGuesses;

    cout << "Enter how many tries you want to have to guess the word:" << endl;
    cin >> maxGuesses;
    cout << endl;

    // set maxguesses in game
    game->setMaxGuesses(maxGuesses);

    cout << endl;
    cout << endl << endl;
}

char UIHangmanGame::getGuessedCharInput(){

    char guess;

    cout << "Guess a character:" << endl << endl;
    cin >> guess;
    cout << endl;

    return guess;
}

void UIHangmanGame::displayIfCorrect(char guess){

    // if guess is correct/wrong display the appropriate message
    if (game->checkGuess(guess)){
        cout << "Correct you got that one right" << endl << endl << endl;
    }

    else{
        cout << "Sorry, not the correct character" << endl << endl << endl;
    }
}

void UIHangmanGame::displayWinnerOrLooser(){

    // if game is won/lost display the appropriate message
    if (game->isItWon()){

        cout << "Congratz you got it" << endl;
        cout << "The word is: ";
        cout << game->getWord() << endl << endl << endl;
    }

    else{

        cout << "Sorry, LOOSER" << endl;
        cout << "The word is: ";
        cout << game->getWord() << endl;
    }

    cout << endl << endl;
}

void UIHangmanGame::displayGamesPlayed(){
    cout << gamesPlayed << " games played" << endl;
}

void UIHangmanGame::displayGuessesLeft(){

    int guessesLeft = game->getMaxGuesses() - game->getGuesses();

    cout << "You have " << guessesLeft << " guesses left" << endl;
}

char UIHangmanGame::displayPlayMenu(){

    char choose;

    cout << "  ************************************************" << endl;
    cout << "   WELCOME TO THE BEST HANGMAN GAME EVER MADE  " << endl << endl;
    cout << "  'p': Play a game of hangman" << endl;
    cout << "  'a': Add word to hangman" << endl;
    cout << "  'r': Remove word from hangman" << endl;
    cout << "  'q': Quit" << endl << endl;
    cout << "  ************************************************" << endl;
    cin >> choose;
    cout << endl << endl;

    return choose;
}

void UIHangmanGame::play(){

    char choose;

    // Loop until variable 'choose' gets the value 'q' then break from the value
    while (true){

        game->newGame();

        choose = displayPlayMenu();

        if (choose == 'p'){

            getMaxGuesses();

            while (!game->isItWon() && game->getGuesses() != game->getMaxGuesses()){

                displayCorrectGuesses();

                displayGuessesLeft();

                displayIfCorrect(getGuessedCharInput());
            }

            gamesPlayed++;

            displayWinnerOrLooser();
        }

        else if (choose == 'a'){

            string addWord;
            cout << "Enter the word you would like to add: " << endl;
            cin >> addWord;
            game->addWordToDatabase(addWord);
            cout << endl << endl;
        }

        else if (choose == 'r'){

            string rmWord;
            cout << "Enter the word you would like to remove: " << endl;
            cin >> rmWord;
            game->removeWordFromDatabase(rmWord);
            cout << endl << endl;
        }

        else if (choose == 'q'){
            break;
        }
        else{
            choose = displayPlayMenu();
        }
    }

    displayGamesPlayed();
}
