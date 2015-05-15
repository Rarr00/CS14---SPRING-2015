/*
Name: Adrian Dy
SID: 861118847
Date: 5/14/2015

*/

/*
Question 2:
    part a: selection sort is not stable due to the swap(), bigger value swaps with the min value
    which displaces the values initial position

    part b: In the 3rd example (5, 5) (5, -5) became (5, -5) (5, 5), confirming that
    the algorithm is unstable
*/

#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <array>
#include <map>
#include <queue>
#include <deque>

using namespace std;

template<typename T>
void displaySingle(const T& someList)
{
    for(auto it = someList.cbegin(); it != someList.cend(); it++ )
        cout << *it << " ";

    cout << endl;
}

template<typename T>
void displayPair(const T& someList)
{
    for(auto it = someList.cbegin(); it != someList.cend(); it++ )
        cout << "(" << it->first << ", " << it->second << ") ";

    cout << endl;
}

template<typename L>
void selectionsort(L &l)
{
    int copy = 0;
    int moves = 0;

    for(auto iElement = l.begin(); iElement != l.end(); iElement++ )
    {
        auto min = iElement;

        for(auto j = iElement; j != l.end(); j++)
        {
            if(*j < *min)
                min = j;
        }
        if(iElement != min)        //reduces number of moves, only swaps if
        {
            swap(*iElement, *min);
            moves += 3;         //swap takes 3 moves
        }

    }

    cout << copy << " copies and " << moves << " moves" << endl;
}

#endif // SELECTIONSORT_H_INCLUDED
