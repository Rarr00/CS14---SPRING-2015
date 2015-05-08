#ifndef LAB5_H_INCLUDED
#define LAB5_H_INCLUDED

/*
Name: Adrian Dy
SID: 861118847
Date: 5/07/2015

*/

// -*- bst.h -*-


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


/*-------------------------------LAB 5------------------------------*/

int min(int x, int y){return (x<y)? x : y;}
int minCover(Node* current)
{
    /*
    if(current = nil)
        return;
    minCover(current->left);

    if(current == root->left || current == root->right || !(current->isLeaf() ) )
    {
        if(current != root)
        {
            cout << current->value << " ";
            vtxCoverSize += 1;
        }
    }
    minCover(current->right);       */

    if(current==NULL)
        return 0;

    if(current->left == NULL && current->right == NULL)
        return 0;

    if(current != root)
        cout << current->value << " " ;

    int vtxCoverSize = 1 + minCover(current->left) + minCover(current->right);

    int vtxCovernotRoot =0;
    if(current->left)
    {
        //cout << current->value << " " ;
        vtxCovernotRoot += 1 + minCover(current->left->left) + minCover(current->left->right);
    }
    if(current->right)
    {
        //cout << current->value << " ";
        vtxCovernotRoot += 1 + minCover(current->right->left) + minCover(current->right->right);
    }

    return min(vtxCoverSize,vtxCovernotRoot);

}

void displayMinCover()
{
    int minNum = minCover(root);
    cout << endl;
    cout << minNum << endl;
}

void findSumPath(int sum)
{
    findSumPath(root, sum);
}
void findSumPath(Node* current, int sum)
{
    if(current == NULL)
        cout << "0" << endl;
    else
    {
        int sumOfsub = sum - current->value;    //check subtree

        if(sumOfsub == 0 && current->left == NULL && current->right == NULL) //if sum still 0 and leaf nodes null
            cout << "0" << endl;

        if(current->left)
         {
             cout << current->value << " ";
             findSumPath(current->left, sumOfsub);
         }
         if(current->right)
         {
             cout << current->value << " ";
             findSumPath(current->right, sumOfsub);
         }
    }
}

void vertSum(int hd, map<int,int> &m)   //hd is horizontal distance, if 2 nodes same hd they are on same vert. line
{
    vertSum(root, 0, m);

    for(auto it = m.begin(); it != m.end(); ++it)
        cout << it->second <<  " ";
}

void vertSum(Node* current, int hd, map<int,int> &m)
{
    if(current == NULL)
        return;
    m[hd] += current->value;
    vertSum(current->left,hd-1,m);
    vertSum(current->right,hd+1,m);
}




};      //end BST



#endif // LAB5_H_INCLUDED