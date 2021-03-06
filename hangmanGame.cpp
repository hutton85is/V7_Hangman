#include "hangmanGame.h"

hangmanGame::hangmanGame(){

    totalPoints = readFromHighScoreDatabase();

    lost = 0;

    won = 0;

    played = 0;

    word = "";

    initializeWordDatabase();
}

hangmanGame::~hangmanGame()
{
    loadToHighScoreDatabase();

    loadToWordDatabase();

    if (word != ""){

       removeNodes(root);
    }
}

void hangmanGame::removeNodes(NodePtr node){

    if (node){
        NodePtr temp = node;
        node = node->next;
        delete temp;
        removeNodes(node);
    }
}

void hangmanGame::newGame(){

    played++;

    // set initial points
    points = 100;

    lengthOfWord = word.length();

    guesses = 0;

    findRandomWord();

    wordToCharNode();

    alreadyCheckedWinnerLooser = false;
}

int hangmanGame::readFromHighScoreDatabase(){

    string highscore;

    ifstream myfile;
    myfile.open("HighscoreDatabase.txt");

    getline(myfile, highscore);

    return atoi(highscore.c_str());
}

void hangmanGame::loadToHighScoreDatabase(){

    ofstream myfile;
    myfile.open ("HighscoreDatabase.txt");

    myfile << totalPoints;

    myfile.close();
}

void hangmanGame::loadToWordDatabase(){

    ofstream myfile;
    myfile.open ("WordDatabase.txt");

    // iterate from a set into myfile to store words for hangman
    for (it = wordDatabaseSet.begin(); it != wordDatabaseSet.end(); it++){

        myfile << *it;
        myfile << '\n';
    }

    myfile.close();
}

void hangmanGame::initializeWordDatabase(){

    string line;
    ifstream myfile ("WordDatabase.txt");

    if (myfile.is_open()){

        // get all lines in myfile and insert to a set
        while (getline(myfile,line)){

          wordDatabaseSet.insert(line);
        }

        myfile.close();
    }
}

void hangmanGame::addWordToDatabase(string addWord){

    wordDatabaseSet.insert(addWord);
}

void hangmanGame::removeWordFromDatabase(string rmWord){

    wordDatabaseSet.erase(rmWord);
}


//Calculate only when a game is won
void hangmanGame::calculatePoints(){

    // when word is guessed without a faulty guess, give double points
    if (guesses == 0){

        points = points * 2;

        calculateTotalPoints();

        return;
    }

    // points are deducted as a multiple of ten of faulty guesses
    points = points - (10 * guesses);

    // set points as zero if they go negative
    if (points < 0){

        points = 0;
    }

    calculateTotalPoints();
}

void hangmanGame::calculateTotalPoints(){

    totalPoints = totalPoints + points;
}

// Find a random word from a set of words
void hangmanGame::findRandomWord(){

    // Figure a random number based on the time and the size of the set 'wordDataBaseSet'
    srand (time(NULL));
    int randomNumber = rand() % wordDatabaseSet.size() + 1;

    // iterate through the set to find the nth word based on 'randomNumber'
    it = wordDatabaseSet.begin();

    for (int i = 0; i < randomNumber; i++, it++){

        word = *it;
    }
}

int hangmanGame::getPoints() const{

    return points;
}

int hangmanGame::getTotalPoints() const{

    return totalPoints;
}

int hangmanGame::getPlayed() const{

    return played;
}

int hangmanGame::getWon() const{

    return won;
}

int hangmanGame::getLost() const{

    return lost;
}

string hangmanGame::getWord() const{

    return word;
}

int hangmanGame::getGuesses() const{

    return guesses;
}

NodePtr hangmanGame::getRoot() const{

    NodePtr temp = root;

    return temp;
}

int hangmanGame::getMaxGuesses() const{

    return maxGuesses;
}

void hangmanGame::setMaxGuesses(int maxGuesses) {

    this->maxGuesses = maxGuesses;
}

bool hangmanGame::checkGuess(string checkChar){

    bool someCharFound = false;

    // if guess is the same as the word to guess check all characters in linked list
    if (checkChar == word){

        for (NodePtr checkNode = root; checkNode != NULL; checkNode = checkNode->next){

            checkNode->hit = true;
        }

        someCharFound = true;

        // get some extra points if guesses made are in the range of {1,2,3}
        if (0 < guesses && guesses < 4){
            points = points + 50;
        }
    }

    // if the guess is a single character check if word contains it
    else if (checkChar.length() == 1){

        // run through the list of characters in the word and check if its there
        for (NodePtr checkNode = root; checkNode != NULL; checkNode = checkNode->next){

            if (checkChar[0] == checkNode->character){

                someCharFound = true;
                checkNode->hit = true;
            }
        }

    }

    // if character guessed is not a member of the word, increase guesses counter
    if (!someCharFound){

        guesses++;
    }

    return someCharFound;
}

bool hangmanGame::isItWon(){

    // Check if guesses made have reached the maximum limit
    // we do this to increase status of lost games and so we
    // dont have to iterate through the word if game is lost
    if (guesses == maxGuesses){

        if (!alreadyCheckedWinnerLooser){

            points = 0;
            lost++;
        }

        alreadyCheckedWinnerLooser = true;

        return false;
    }

    // run through a list of characters in word and check if any are not guessed
    for (NodePtr checkNode = root; checkNode != NULL; checkNode = checkNode->next){

        if (checkNode->hit != true){

            return false;
        }
    }

    if (!alreadyCheckedWinnerLooser){

            won++;
            calculatePoints();
        }

    alreadyCheckedWinnerLooser = true;

    // If all characters have been found, return true
    return true;
}

void hangmanGame::wordToCharNode(){

    int wordLength = word.length();
    root = new CharNode(word[0]);
    NodePtr run = root;

    // create a list of characters from the global variable 'word'
    for (int i = 1; i < wordLength; i++){

        NodePtr new_node = new CharNode(word[i]);
        run->next = new_node;
        run = new_node;
    }
}
