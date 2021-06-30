#include <iostream>
#include "AVL.h"
using namespace std;
int main()
{
    // LR Rotation
    AVL tlr;
    tlr.RInsert(50);
    tlr.RInsert(10);
    tlr.RInsert(20);


    tlr.Inorder();
    cout << endl;

    // RL Rotation
    AVL trl;
    trl.RInsert(20);
    trl.RInsert(50);
    trl.RInsert(30);


    trl.Inorder();
}
