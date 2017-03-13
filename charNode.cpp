#include "charNode.h"

using namespace std;

CharNode::CharNode(char character){
    this->character = character;
    hit = false;
    next = NULL;
}

CharNode::~CharNode(){}
