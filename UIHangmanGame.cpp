#include "UIHangmanGame.h"

UIHangmanGame::UIHangmanGame(){

    game = new hangmanGame();

    displayPlayMenu();
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

string UIHangmanGame::getGuessedCharInput(){

    string guess;

    cout << "Guess a character: ";
    cin >> guess;
    cout << endl << endl;

    return guess;
}

void UIHangmanGame::displayLengthOfWord(){
    cout << "Length of word: " << game->getWord().length() << endl;
}

void UIHangmanGame::displayIfCorrect(string guess){

    // if variable guess is longer than 1 we have a guess for the hole word
    if (1 < guess.length()){

        // when a correct guess is made iterate through the word to make it guessed
        if (guess == game->getWord()){

            for (size_t i = 0; i < guess.length(); i++){
                game->checkGuess(guess[i]);
            }

            cout << "Congratz you guessed the hole word in one word" << endl;
        }

        return;
    }

    // if guess is correct/wrong display the appropriate message
    if (game->checkGuess(guess[0])){
        cout << "Correct you got that one right" << endl << endl;
    }

    else{
        cout << "Sorry, not the correct character" << endl << endl;
    }
}

void UIHangmanGame::displayWinnerOrLooser(){

    // if game is won/lost display the appropriate message
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

void UIHangmanGame::displayGamesStatus(){

    cout << "games played: " << game->getPlayed() << endl;

    cout << "games won: " << game->getWon() << endl;

    cout << "games lost: " << game->getLost() << endl << endl << endl;
}

void UIHangmanGame::displayGuessesLeft(){

    int guessesLeft = game->getMaxGuesses() - game->getGuesses();

    cout << "Guesses left: " << guessesLeft << endl;
}

void UIHangmanGame::displayPlayMenu(){

    char choose;

    cout << "  ************************************************" << endl;
    cout << "   WELCOME TO THE BEST HANGMAN GAME EVER MADE  " << endl << endl;
    cout << "  'p': Play a game of hangman" << endl;
    cout << "  'a': Add word to hangman" << endl;
    cout << "  'r': Remove word from hangman" << endl;
    cout << "  'q': Quit" << endl << endl;
    cout << "  ************************************************" << endl << endl;

    cout << "What do you want to do: ";
    cin >> choose;
    cout << endl << endl;

    gotoAction(choose);
}

void UIHangmanGame::gotoAction(char choose){

    if (choose == 'p'){
        play();
    }

    else if (choose == 'a'){

        addWord();
    }

    else if (choose == 'r'){

        removeWord();
    }

    else if (choose == 'q'){
        return;
    }

    displayPlayMenu();
}

void UIHangmanGame::addWord(){

    string addWord;
    cout << "Enter the word you would like to add: " << endl;
    cin >> addWord;
    game->addWordToDatabase(addWord);
    cout << endl << endl;
}

void UIHangmanGame::removeWord(){
    string rmWord;
    cout << "Enter the word you would like to remove: " << endl;
    cin >> rmWord;
    game->removeWordFromDatabase(rmWord);
    cout << endl << endl;
}

void UIHangmanGame::play(){

    game->newGame();

    getMaxGuesses();

    while (!game->isItWon() && game->getGuesses() != game->getMaxGuesses()){

        displayCorrectGuesses();

        displayLengthOfWord();

        displayGuessesLeft();

        displayIfCorrect(getGuessedCharInput());
    }

    displayWinnerOrLooser();

    displayGamesStatus();

    cout << "points for this game: " << game->getPoints() << endl;
}
