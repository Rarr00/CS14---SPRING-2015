/*
Name: Adrian Dy
SID: 861118847
Date: 4/26/2015
*/

#include <iostream>

#include "bst.h"

using namespace std;

int main()
{       //no operator[]
    BST<int> tree;

    tree.insert(5);
    tree.insert(10);
    tree.insert(1);
    tree.insert(3);
    tree.insert(4);
    tree.insert(8);

    cout << "Preorder: ";
    tree.preorder();        //prints recursively DLR
    cout << endl;
    cout << "Inorder: ";
    tree.inorder();        //prints recursively LDR
    cout << endl;
    cout << "Postorder: ";
    tree.postorder();        //prints recursively LRD
    cout << endl;

    tree.remove(3);
    tree.remove(5);

    cout << "Preorder: ";
    tree.preorder();        //prints recursively DLR
    cout << endl;
    cout << "Inorder: ";
    tree.inorder();        //prints recursively LDR
    cout << endl;
    cout << "Postorder: ";
    tree.postorder();        //prints recursively LRD
    cout << endl;

    int s1 = 0;
    s1 = tree.size();               //check size()
    cout << "size(): " << s1 << endl;

    //search() cannot be used with a value that is not in the tree, seg faults
    cout << "search(10): " << tree.search(10) << endl;      //returns 1 T
    cout<< endl;

    BST<string> tree1;

    tree1.insert("fubar");
    tree1.insert("another");
    tree1.insert("foobar");
    cout << "Another tree:" << endl;
    cout << "Preorder: ";
    tree1.preorder();        //prints recursively DLR
    cout << endl;
    cout << "Inorder: ";
    tree1.inorder();        //prints recursively LDR
    cout << endl;
    cout << "Postorder: ";
    tree1.postorder();        //prints recursively LRD
    cout << endl;

    int s2 = 0;
    s2 = tree1.size();               //check size()
    cout << "size(): " << s2 << endl;

    //search() cannot be used with a value that is not in the tree, seg faults
    cout << "search(\"fubar\"): " << tree1.search("fubar") << endl;      //returns 1 T
    cout<< endl;


    return 0;
}