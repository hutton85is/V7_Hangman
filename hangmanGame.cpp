#include "hangmanGame.h"

hangmanGame::hangmanGame(){

    initializeWordDatabase();
}

hangmanGame::~hangmanGame()
{

    loadToWordDatabase();

    if (root){
        while (root){
            NodePtr d = root;
            root = root->next;
            delete d;
        }
    }
}

void hangmanGame::newGame(){

    lengthOfWord = word.length();

    guesses = 0;

    findRandomWord();

    wordToCharNode();
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

bool hangmanGame::checkGuess(char checkChar){

    bool someCharFound = false;

    // run through the list of characters in the word and check if its there
    for (NodePtr checkNode = root; checkNode != NULL; checkNode = checkNode->next){
        if (checkChar == checkNode->character){
            someCharFound = true;
            checkNode->hit = true;
        }
    }

    // if character guessed is not a member of the word, increase guesses counter
    if (!someCharFound){
        guesses++;
    }

    return someCharFound;
}

bool hangmanGame::isItFound(char checkChar){

    bool someCharFound = false;

    // run through a list of characters to check if its been found
    for (NodePtr checkNode = root; checkNode != NULL; checkNode = checkNode->next){
        if (checkChar == checkNode->character){
            someCharFound = true;
        }
    }

    return someCharFound;
}

bool hangmanGame::isItWon(){

    // run through a list of characters in word and check if any are not guessed
    for (NodePtr checkNode = root; checkNode != NULL; checkNode = checkNode->next){
        if (checkNode->hit != true){
            return false;
        }
    }

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
