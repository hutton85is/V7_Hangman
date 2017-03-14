
#ifndef CHARNODE_H
#define CHARNODE_H

#include <string>

using namespace std;

class CharNode
{

public:

    char character;
    bool hit;
    CharNode *next;

    CharNode(char value, bool nohit = false, CharNode *nolink = NULL)
        : character(value), hit(nohit), next(nolink){}

};

typedef CharNode* NodePtr;

#endif // INTNODE_H
