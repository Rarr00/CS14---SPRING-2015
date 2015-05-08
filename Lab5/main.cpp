/*
Name: Adrian Dy
SID: 861118847
Date: 5/07/2015

*/


#include <iostream>
#include <map>

#include "lab5.h"
using namespace std;

int main()
{                           //Does not compile with -Wall -Werror -peadantic
    BST<int> tree;

    tree.insert(50);
    tree.insert(20);
    tree.insert(60);
    tree.insert(10);
    tree.insert(40);
    tree.insert(70);
    tree.insert(35);
    tree.insert(45);

    cout << "Part 1: " << endl;
    tree.displayMinCover();

    cout << "Part 2: fubar " << endl;     //fubar
    tree.findSumPath(80);
    cout << endl;

    cout << "Part 3: " << endl;
    map<int,int> map0;
    tree.vertSum(0,map0);


    return 0;
}