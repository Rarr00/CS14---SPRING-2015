/*
    Name: Adrian Dy
    SID: 861118847
    Date: 5/01/2015

*/


#ifndef LAB4_H_INCLUDED
#define LAB4_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue> 

using namespace std;


typedef pair<int, int> Entry;
/*
class priority_queue
{
public:
    vector<Entry> entries;
    
    Entry& front() { return entries.back(); }
    
    void pop() { entries.pop_back(); }
    
    void push(Entry e)
    {
        entries.push_back(e);
        for(int i = entries.size() - 1; i != 0; --i)
        {
            if(entries[i].first + entries.second < entries[i-1].first + entries[i-1].second)     //replace this line with code for comparing int pairs
                break;
            swap(entries[i],  entries[i-1] );
        }
    }
    
};   */

void preOrderPrimes(int m, int n, int k)    //DLR
{
    if(m + n < k)
    {
        cout << m << " " << n << endl;
        preOrderPrimes( (2*m-n), m, k );            //Left subtree
        preOrderPrimes( (2*m+n), m, k );
        preOrderPrimes( (m+2*n), n, k );
        m += 1;
        preOrderPrimes( (2*m-n), m, k );            //Right subtree
        preOrderPrimes( (2*m+n), m, k );
        preOrderPrimes( (m+2*n), n, k );

    }else
        return;
}

void postOrderPrimes(int m, int n, int k)    //LRD
{
    if(m + n < k)
    {
        postOrderPrimes( (2*m-n), m, k );            //Left subtree
        postOrderPrimes( (2*m+n), m, k );
        postOrderPrimes( (m+2*n), n, k );
        cout << m << " " << n << endl;
        m += 1;
        postOrderPrimes( (2*m-n), m, k );            //Right subtree
        postOrderPrimes( (2*m+n), m, k );
        postOrderPrimes( (m+2*n), n, k );

    }else
        return;
}




void sortedPrimes(int m, int n, int k, priority_queue<Entry>& primes)   
{
    
    if(m + n < k)
    {
        pair<int,int> two(m,n);
        primes.push(two);
      
        sortedPrimes( (2*m-n), m, k, primes );            
        sortedPrimes( (2*m+n), m, k, primes );
        sortedPrimes( (m+2*n), n, k, primes );
        
        m += 1;
        pair<int,int> three(m,n);
        primes.push(three);
      
        sortedPrimes( (2*m-n), m, k, primes );            
        sortedPrimes( (2*m+n), m, k, primes );
        sortedPrimes( (m+2*n), n, k, primes );   

    }else
        return; 
        
} 

void displaySorted(priority_queue<Entry>& pq)  
{
    //cant iterate queue so copy over to another container this case deque
    
   // pair<int,int> two;
   /*
    deque<Entry> deq;
    while(pq.size() != 0)
    {
        deq.push_back(pq.front());
        pq.pop();
    }
    
    for(auto it = deq.cbegin(); it != deq.cend(); ++it)
        cout << deq.at(it).first << " " << deq.at(it).second << endl;    */
        
    while(!pq.empty())
    {
        pair<int,int> p2( pq.top() );
        pq.pop();
        cout << p2.first << " " << p2.second << endl;
    }
        
}



#endif // LAB4_H_INCLUDED