/*
    Name: Adrian Dy
    SID: 861118847
    Date: 4/21/2015

*/

#ifndef LAB3_H_INCLUDED
#define LAB3_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<stack>

using namespace std;

template<typename T>
class TwoStackFixed
{
private:
    T* arr;
    int capacity;
    int top1, top2, partition; //top1 initially points to arr[-1]

public:

    TwoStackFixed(int size, int maxtop)     //maxtop is partition
    {
        capacity = size;
        arr = new T [size];
        top1 = -1;
        top2 = capacity;
        partition = maxtop;
    }

    void display()
    {
        for(int i = 0; i < capacity; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    void pushStack1(T value)    //push doesn't push next value over, push only traverses array and fills cell
    {
        if(top1 < partition && (top1+1) != partition)
        {
            top1++;
            arr[top1] = value;
            display();
        }
        else
        {
            cout << "overflow" << endl;
            return;
            //exit(1);
        }
    }

    void pushStack2(T value)
    {
        if(top2 > partition && (top2-1) != partition)
        {
            top2--;
            arr[top2] = value;
            display();
        }
        else
        {
            cout << "overflow" << endl;
            return;
            //exit(1);
        }
    }

    T popStack1()
    {
        if(top1 >= 0 )
        {
            T returnVal = arr[top1];
            top1--;
            display();
            return returnVal;
        }
        else
        {
            cout << "underflow" << endl;
            T returnVal = arr[top1];
            return returnVal;
            //exit(1);
        }
    }

    T popStack2()
    {
        if(top2 < capacity)
        {
            T returnVal = arr[top2];
            top2++;
            display();
            return returnVal;
        }
        else
        {
            cout << "underflow" << endl;
            T returnVal = arr[top1];
            return returnVal;
            // exit(1);
        }
    }

    bool isFullStack1()
    {
        return (top1 == partition - 1);
    }

    bool isFullStack2()
    {
        return (top2 == partition + 1);
    }

    bool isEmptyStack1()
    {
        if(arr[0] == NULL && arr[partition-1] == NULL)
            return true;
        else
            return false;
    }

    bool isEmptyStack2()
    {
        if(arr[partition+1] == NULL && arr[capacity] == NULL)
            return true;
        else
            return false;
    }

};

template<typename T>
class TwoStackOptimal
{
private:
    T* arr;
    int capacity;
    int top1, top2;     //top1 initially points to arr[-1]

public:

    TwoStackOptimal(int size)     //maxtop is partition
    {
        capacity = size;
        arr = new T [size];
        top1 = -1;
        top2 = capacity;
    }

    void display()
    {
        for(int i = 0; i < capacity; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    void pushFlexStack1(T value)
    {
        if(top1 < top2 - 1)     //check if there is space
        {
            top1++;
            arr[top1] = value;
            display();
        }
        else
        {
            cout << "overflow" << endl;
            return;
            //exit(1);
        }
    }

    void pushFlexStack2(T value)
    {
        if(top1 < top2 - 1)
        {
            top2--;
            arr[top2] = value;
            display();
        }
        else
        {
            cout << "overflow" << endl;
            return;
            //exit(1);
        }
    }

    T popFlexStack1()               //pops correspond to pushes
    {                               //i.e. whatever is pushed with pushFlexStack1 that stack is stack 1
        if(top1 >= 0 )              //so cannot popFlexStack1 what is in stack 2
        {
            T returnVal = arr[top1];
            top1--;
            display();
            return returnVal;
        }
        else
        {
            cout << "underflow" << endl;
            T returnVal = arr[top1];
            return returnVal;
            //exit(1);
        }
    }

    T popFlexStack2()
    {
        if(top2 < capacity)
        {
            T returnVal = arr[top2];
            top2++;
            display();
            return returnVal;
        }
        else
        {
            cout << "underflow" << endl;
            T returnVal = arr[top1];
            return returnVal;
            // exit(1);
        }
    }

    bool isFullStack()          //checks the whole array
    {
        return (top1 >= top2 - 1);
    }

    bool isEmptyStack()         //checks whole array
    {
        if(arr[0] == NULL && arr[capacity] == NULL)
            return true;
        else
            return false;
    }

};
/*
template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{

    if(n > 0)
    {
        showTowerStates(n-1, A, C, B);
//        cout << "Move " << A.top() << " from peg " << *A << " to peg " << *C << endl;
        T value = C.push(A.pop());
        showTowerStates(n-1, B, A, C);
    }
}
*/


#endif // LAB3_H_INCLUDED