/*
Name: Adrian Dy
SID: 861118847
Date: 4/26/2015

*/

// -*- bst.h -*-

#ifndef BST_H
#define BST_H

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>

using namespace std;

#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST
{
    class Node
    {
    public:
        Node* left;
        Node* right;
        Value value;
        Node(const Value v = Value()) : value(v), left(nil), right(nil) {}

        Value& content() { return value;}
        bool isInternal() { return left != nil && right != nil; }
        bool isExternal() { return left != nil || right != nil; }
        bool isLeaf() { return left == nil && right == nil; }

        int height()    //returns the height of the subtree rooted at this node
        {
            int leftHeight, rightHeight;
            if(value == NULL)
                return 0;
            else
            {
                leftHeight = left->height();
                rightHeight = right->height();

                if(leftHeight > rightHeight)
                    return(leftHeight + 1);
                else
                    return(rightHeight + 1);
            }
        }
        int size()      //returns the size of the subtree rooted at this node
        {
            if(this == NULL)
                return 0;
            else
                return this->left->size() + this->right->size() + 1;
        }

    };      //end class Node

    //const Node* nil;      //later nil will point to a sentinel node
    Node* root;
    int count;

public:

    int size()      //size of the overall tree
    {
        if(root == NULL)
            return 0;
        else
            return root->left->size() + root->right->size() + 1;

    }

    bool empty() { return size() == 0; }

    void print_node( const Node* n )        //print the node's value
    {
        cout << n->value;
    }

    bool search( Value x )      //search for a Value in the BST and return true iff it was found
    {
        Node* temp = root;          //can't be used with value not in tree seg faults

        while(temp != NULL )
        {
            if(x == temp->value)
                break;

            if(x > temp->value)
                temp = temp->right;
            else if (x < temp->value)
                temp = temp->left;
        }
        if(x == temp->value)
            return true;
        else
            return false;
    }

    void preorder() const       //traverse and print the tree one Value per line in preorder
    {
        preorder(root);
    }


    void preorder(Node* current) const       //traverse and print the tree one Value per line in preorder
    {
        if(current == NULL)                    //DLR
            return;
        cout << current->value << " ";
        preorder(current->left);
        preorder(current->right);
    }

    void inorder() const       //traverse and print the tree one Value per line in inorder
    {
        inorder(root);
    }

    void inorder(Node* root) const       //traverse and print the tree one Value per line in inorder
    {
        if(root == NULL)                //LDR
            return;
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }

    void postorder() const       //traverse and print the tree one Value per line in postorder
    {
        postorder(root);
    }

    void postorder(Node* root) const       //traverse and print the tree one Value per line in postorder
    {
        if(root == NULL)        //LRD
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
/*
    Value& operator[] (int n)       //returns reference to the value field of the nth Node
    {

    }  */

    BST() : count(0), root(nil) {}

    void insert( Value X ) { root = insert( X, root ); }

    Node* insert( Value X, Node* T )    //the normal binary-tree insertion procedure
    {
        if( T == nil )
            T = new Node(X);        //the only place that T gets updated
        else if( X < T->value )
            T->left = insert( X, T->left );
        else if( X > T->value )
            T->right = insert( X, T->right );
        else
            T->value = X;

        //later, rebalancing code will be installed here

        return T;

    }

    void remove( Value X ) { root = remove( X, root ); }

    Node* remove( Value X, Node*& T)     //the normal binary-tree removal procedure
    {                                   //Weiss's code is faster but way more intricate
        if( T != nil )
        {
            if( X > T->value )
                T->right = remove( X, T->right );
            else if( X < T->value )
                T->left = remove( X, T->left );
            else
            {       //X == T->value
                if( T->right != nil )
                {
                    Node* x = T->right;
                    while( x->left != nil) x = x->left;
                    T->value = x->value;        //successor's value
                    T->right = remove( T->value, T->right );
                } else if(T ->left != nil )
                {
                    Node* x = T->left;
                    while( x->right != nil )
                        x = x->right;

                    T->value = x->value;    //predecessor's value
                    T->left = remove( T->value, T->left);
                } else
                {                   //*T is external
                    delete T;
                    T = nil;        //the only updating of T
                }
            }

        }
        //later, rebalancing code will be installed here

        return T;

    }
/*
    void okay() { okay(root); }
    void okay( Node* T )
    {
        //diagnostic code can be installed here
        return;
    }
*/


};      //end BST



#endif // BST_H