#include <iostream>
#include <string>
#include "lab4.h"

using namespace std;

int main(int argc, char* argv[])
{                                   //note to self
    int in = stoi(argv[1]);         //stoi c++11 takes std::string as argument, so no need for atoi(str.c_str())

    cout << "Preorder: " << endl;
    preOrderPrimes(2, 1, in);        //(2,1) is for the left tree, right tree is handled in function
    cout << endl;

    cout << "Postorder: " << endl;
    postOrderPrimes(2, 1, in);
    cout << endl;

    cout << "Sorted: descending" << endl;  //not correct prints some not coprime FUBAR
    priority_queue< pair<int,int> > pq;
    sortedPrimes(2, 1, in, pq);
    displaySorted(pq);
    
    return 0;
}
