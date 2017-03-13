#include <iostream>
#include "hangmanGame.h"

using namespace std;

int main()
{
    hangmanGame t("Russell", 10);
    char a;
    while (!t.isItWon()){
        cout << "Enter a char" << endl;
        cin >> a;
        cout << "Was it found " << t.checkGuess(a) << endl;
    }
    cout << "Congratz you won" << endl;
    return 0;
}
