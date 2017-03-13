#include "hangmanGame.h"

using namespace std;

hangmanGame::hangmanGame(string word, int maxGuesses)
{
    lengthOfWord = word.length();
    guesses = 0;
    this->word = word;
    this->maxGuesses = maxGuesses;
    wordToCharNode();
}

hangmanGame::~hangmanGame()
{
    if (root){
        while (root){
            NodePtr d = root;
            root = root->next;
            delete d;
        }
    }
}

string hangmanGame::getWord() const{
    return word;
}

int hangmanGame::getMaxGuesses() const{
    return maxGuesses;
}

bool hangmanGame::checkGuess(char checkChar){

    bool someCharFound = false;

    for (NodePtr checkNode = root; checkNode != NULL; checkNode = checkNode->next){
        if (checkChar == checkNode->character){
            someCharFound = true;
            checkNode->hit = true;
        }
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
