#include "UIHangmanGame.h"

UIHangmanGame::UIHangmanGame(){

    won = 0;

    lost = 0;

    totalPoints = 0;

    points = 0;

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

void UIHangmanGame::decreasePoints(int dec){
    points = points - dec;
}

void UIHangmanGame::increasePoints(int inc){
    points = points + inc;
}

void UIHangmanGame::getMaxGuesses(){

    // Initialize points in the beginning of game
    points = 50;

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

            // when a correct guess for the hole word is made give extra 10 points,
            // but only if no more than two guesses have been made
            if (game->getGuesses() < 3){
                points = points + 10;
            }
        }
        else{
            points = points - 10;
        }

        return;
    }

    // if guess is correct/wrong display the appropriate message
    if (game->checkGuess(guess[0])){
        cout << "Correct you got that one right" << endl << endl;
    }

    else{
        points = points - 5;
        cout << "Sorry, not the correct character" << endl << endl;
    }
}

void UIHangmanGame::displayWinnerOrLooser(){

    totalPoints = totalPoints + points;

    // if game is won/lost display the appropriate message
    if (game->isItWon()){

        won++;
        cout << "Congratz you got it" << endl;
        cout << "The word is: ";
        cout << game->getWord() << endl;
        cout << "Points for this game: " << points << endl;
        cout << "Total points this session: " << totalPoints << endl << endl;
    }

    else{

        lost++;
        cout << "Sorry, LOOSER" << endl;
        cout << "The word is: ";
        cout << game->getWord() << endl;
        cout << "Points for this game: " << points << endl;
        cout << "Total points this session: " << totalPoints << endl << endl;
    }
}

void UIHangmanGame::displayGamesStatus(){

    cout << "games played: " << won + lost << endl;

    cout << "games won: " << won << endl;

    cout << "games lost: " << lost << endl << endl << endl;
}

void UIHangmanGame::displayGuessesLeft(){

    int guessesLeft = game->getMaxGuesses() - game->getGuesses();

    cout << "Guesses left: " << guessesLeft << endl;
}

char UIHangmanGame::displayPlayMenu(){

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

                displayLengthOfWord();

                displayGuessesLeft();

                displayIfCorrect(getGuessedCharInput());
            }

            displayWinnerOrLooser();

            displayGamesStatus();
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
            cout << "Thank you for playing hangman" << endl << endl;
            cout << "Total points you got during this session: " << totalPoints << endl;
            break;
        }
        else{
            choose = displayPlayMenu();
        }
    }
}
