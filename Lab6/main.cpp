/*
Name: Adrian Dy
SID: 861118847
Date: 5/14/2015

*/

#include "selectionsort.h"

using namespace std;

int main()
{
    list<int> list0;

    list0.push_back(2);
    list0.push_back(4);
    list0.push_back(5);
    list0.push_back(1);
    list0.push_back(8);
    list0.push_back(9);

    cout << "pre: ";
    displaySingle(list0);

    selectionsort(list0);
    cout << "post: ";
    displaySingle(list0);

    //----next list with pair-------------

    typedef pair<int,int> Pair;

    list<Pair> list1;

    list1.push_back( make_pair(1,2) );
    list1.push_back( make_pair(3,-1) );
    list1.push_back( make_pair(-1,3) );
    list1.push_back( make_pair(0,0) );
    list1.push_back( make_pair(2,3) );
    list1.push_back( make_pair(1,2) );
    list1.push_back( make_pair(1,-2) );
    list1.push_back( make_pair(8,10) );

    cout << endl;
    cout << "pre: ";
    displayPair(list1);

    selectionsort(list1);
    cout << "post: ";
    displayPair(list1);

    //----next vector with pair-------------

    vector<Pair> vect0;

    vect0.push_back( make_pair(10,2) );
    vect0.push_back( make_pair(-3,-1) );
    vect0.push_back( make_pair(-8,0) );
    vect0.push_back( make_pair(1,1) );
    vect0.push_back( make_pair(1,1) );
    vect0.push_back( make_pair(0,0) );
    vect0.push_back( make_pair(10,2) );
    vect0.push_back( make_pair(5,5) );
    vect0.push_back( make_pair(5,-5) );
    vect0.push_back( make_pair(0,0) );
    vect0.push_back( make_pair(10,2) );

    cout << endl;
    cout << "pre: ";
    displayPair(vect0);

    selectionsort(vect0);
    cout << "post: ";
    displayPair(vect0);

    //----next list with pair-------------

    typedef pair<int,int> Pair;

    list<Pair> list2;

    list2.push_back( make_pair(-1,3) );
    list2.push_back( make_pair(0,0) );
    list2.push_back( make_pair(1,-2) );
    list2.push_back( make_pair(1,2) );
    list2.push_back( make_pair(1,2) );
    list2.push_back( make_pair(2,3) );
    list2.push_back( make_pair(3,-1) );
    list2.push_back( make_pair(8,10) );

    cout << endl;
    cout << "pre: ";
    displayPair(list2);

    selectionsort(list2);
    cout << "post: ";
    displayPair(list1);

    //-------------------
    cout << endl << endl;
    cout << "Question 2: " << endl;
    cout << "part a: selection sort is not stable due to the swap(), bigger value swaps with the min value";
    cout << " which displaces the values initial position " << endl;

    cout << "part b: In the 3rd example (5, 5) (5, -5) became (5, -5) (5, 5), confirming that ";
    cout << "the algorithm is unstable " << endl;

    return 0;
}