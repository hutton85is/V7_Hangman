
#ifndef CHARNODE_H
#define CHARNODE_H

#include <string>

using namespace std;

class CharNode
{
public:

    CharNode();
    CharNode(char character);
    ~CharNode();
    char character;
    CharNode *next;
    bool hit;

};

typedef CharNode* NodePtr;

#endif // INTNODE_H
