#include "hangmanGame.h"

hangmanGame::hangmanGame(){

    lengthOfWord = word.length();

    guesses = 0;

    initializeWordDatabase();

    findRandomWord();

    wordToCharNode();
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

void hangmanGame::loadToWordDatabase(){

    for (it = wordDatabaseSet.begin(); it != wordDatabaseSet.end(); it++){
        cout << *it << endl;
    }
}

void hangmanGame::initializeWordDatabase(){

    string line;
    ifstream myfile ("WordDatabase.txt");

    if (myfile.is_open()){

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

void hangmanGame::findRandomWord(){

    srand (time(NULL));
    int randomNumber = rand() % wordDatabaseSet.size() + 1;

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

    for (NodePtr checkNode = root; checkNode != NULL; checkNode = checkNode->next){
        if (checkChar == checkNode->character){
            someCharFound = true;
            checkNode->hit = true;
        }
    }

    if (!someCharFound){
        guesses++;
    }

    return someCharFound;
}

bool hangmanGame::isItFound(char checkChar){

    bool someCharFound = false;

    for (NodePtr checkNode = root; checkNode != NULL; checkNode = checkNode->next){
        if (checkChar == checkNode->character){
            someCharFound = true;
        }
    }

    return someCharFound;
}

bool hangmanGame::isItWon(){

    bool gameWon = true;

    for (NodePtr checkNode = root; checkNode != NULL; checkNode = checkNode->next){
        if (checkNode->hit != true){
            gameWon = false;
        }
    }
    return gameWon;
}

void hangmanGame::wordToCharNode(){

    int wordLength = word.length();
    root = new CharNode(word[0]);
    NodePtr run = root;

    for (int i = 1; i < wordLength; i++){
        NodePtr new_node = new CharNode(word[i]);
        run->next = new_node;
        run = new_node;
    }
}
