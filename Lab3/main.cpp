/*
    Name: Adrian Dy
    SID: 861118847
    Date: 4/21/2015

*/

#include <iostream>
#include <forward_list>

#include "lab3.h"

int main()
{   cout << "PART1:" << endl;
    TwoStackFixed<int> first(5, 2);    //size 5 partition at 2

    cout << "pushStack1(1): " << endl;
    first.pushStack1(1);
    cout << endl;

    cout << "pushStack1(2): " << endl;
    first.pushStack1(2);
    cout << endl;

    cout << "pushStack2(1): " << endl;
    first.pushStack2(1);
    cout << "pushStack2(2): " << endl;
    first.pushStack2(2);
    cout << endl;

    cout << "popStack1(): " << endl;    //popping retains the value, does not delete
    int num = first.popStack1();
    cout << "popped item: " << num << endl;
    cout << endl;

    cout << "popStack1(): " << endl;
    int num1 = first.popStack1();
    cout << "popped item: " << num1 << endl;
    cout << endl;

    cout << "popStack2(): " << endl;
    int num2 = first.popStack2();
    cout << "popped item: " << num2 << endl;
    cout << endl;

    cout << "popStack2(): " << endl;
    int num3 = first.popStack2();
    cout << "popped item: " << num3 << endl;
    cout << endl;

    cout << "Another 2 stack array: demonstrate underflow overflow" << endl;
    TwoStackFixed<char> second(7, 3);
    cout << "pushStack1('a'): " << endl;
    second.pushStack1('a');
    cout << endl;

    cout << "pushStack1('b'): " << endl;
    second.pushStack1('b');
    cout << endl;

    cout << "pushStack1('c'): " << endl;
    second.pushStack1('c');
    cout << endl;

    cout << "pushStack1('d'): " << endl;
    second.pushStack1('d');             //overflow, goes beyond partition

    cout << "pushStack2('d'): " << endl;
    second.pushStack2('g');
    cout << endl;

    cout << "pushStack2('e'): " << endl;
    second.pushStack2('f');
    cout << endl;

    cout << "pushStack2('e'): " << endl;
    second.pushStack2('e');
    cout << endl;

    cout << "pushStack2('d'): " << endl;
    second.pushStack2('d');              //overflow, goes beyond partition
    cout << endl;

    cout << "popStack1(): " << endl;
    char char1 = second.popStack1();
    cout << "popped item: " << char1 << endl;
    cout << endl;

    cout << "popStack2(): " << endl;
    char char2 = second.popStack2();
    cout << "popped item: " << char2 << endl;
    cout << endl;

    cout << "popStack2(): " << endl;
    char char3 = second.popStack2();
    cout << "popped item: " << char3 << endl;
    cout << endl;

    cout << "popStack2(): " << endl;
    char char4 = second.popStack2();
    cout << "popped item: " << char4 << endl;
    cout << endl;

    cout << "popStack2(): " << endl;
    second.popStack2();
    //cout << "popped item: " << char5 << endl;     //underflow check
    cout << endl;


    cout << "PART2:" << endl;               //note to self
                                                 //pops correspond to pushes
    TwoStackOptimal<double> third(4);           //i.e. whatever is pushed with pushFlexStack1 that stack is stack 1
                                                //so cannot popFlexStack1 what is in stack 2
    cout << "pushFlexStack1: " << endl;
    third.pushFlexStack1(1.11);
    cout << endl;

    cout << "pushFlexStack2: " << endl;
    third.pushFlexStack2(3.33);
    cout << endl;

    cout << "pushFlexStack2: " << endl;
    third.pushFlexStack2(4.44);
    cout << endl;

    cout << "pushFlexStack2:  " << endl;
    third.pushFlexStack2(5.55);
    cout << endl;

    cout << "pushFlexStack2:  check overflow" << endl;      //check for overflow condition
    third.pushFlexStack2(0);
    cout << endl;

    cout << "popFlexStack1(): " << endl;
    double double1 = third.popFlexStack1();
    cout << "popped item: " << double1 << endl;
    cout << endl;

    cout << "popFlexStack1(): " << endl;
    double double2 = third.popFlexStack1();         //check stack 1 underflow
    cout << "popped item: " << double2 << endl;
    cout << endl;

    cout << "popFlexStack2(): " << endl;
    double double3 = third.popFlexStack2();
    cout << "popped item: " << double3 << endl;
    cout << endl;

    cout << "popFlexStack2(): " << endl;
    double double4 = third.popFlexStack2();
    cout << "popped item: " << double4 << endl;
    cout << endl;

    cout << "popFlexStack2(): " << endl;
    double double5 = third.popFlexStack2();
    cout << "popped item: " << double5 << endl;
    cout << endl;

    cout << "popFlexStack2(): " << endl;
    double double6 = third.popFlexStack2();         //check stack 2 underflow
    cout << "popped item: " << double6 << endl;
    cout << endl;

/*
    cout << "PART3:" << endl;

    stack<double> doubleSource;
    doubleSource.push(4.0);
    doubleSource.push(3.0);
    doubleSource.push(2.0);
    doubleSource.push(1.0);
    stack<double> doubleAux;
    stack<double> doubleDest;
    showTowerStates(4, doubleSource, doubleAux, doubleDest);  */

    return 0;
}