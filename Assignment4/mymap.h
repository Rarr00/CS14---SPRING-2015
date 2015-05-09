/*
Name: Adrian Dy
SID: 861118847
Date: 5/03/2015

*/



#ifndef MYMAP_H_INCLUDED
#define MYMAP_H_INCLUDED

#include <iostream>
#include <set>

using namespace std;

template<typename Key, typename T>
class map_pair
{
public:
    const Key first;
    mutable T second;

    map_pair(Key s, T t) : first(s), second(t) {}
};

template<typename Key, typename T>
struct classcomp
{
    typedef map_pair<const Key, T> Pair;

    bool operator() (const Pair& lhs, const Pair& rhs) const
    {
        return lhs.first < rhs.first;
    }
};

template<typename Key, typename T>
class mymap
{
public:
    typedef map_pair<const Key, T> Pair;
    typedef set<Pair, classcomp<const Key, T> > PairSet;

    PairSet theSet;

    mymap()
    {
        theSet = PairSet();
    }

    mymap(const mymap<Key,T>& m)
    {
        theSet = m.theSet;
    }

    pair<typename PairSet::iterator, bool> insert( Pair p )
    {
        return theSet.insert(p);
    }

    T& operator[](const Key x)
    {
        pair<typename PairSet::iterator, bool> i = insert( Pair( x, T() ) );
        return i.first->second;
    }

    typename PairSet::iterator find(const Key& x) const
    {
        return theSet.find( Pair( x, T() ) );
    }

    typename PairSet::iterator end() const
    {
        return theSet.end();
    }


};


#endif // MYMAP_H_INCLUDED