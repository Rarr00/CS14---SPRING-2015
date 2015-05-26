/*
Name: Adrian Dy
SID: 861118847
Date: 5/14/2015

- stores words from words.txt to a vector, words.txt contains 50,000 words
- create set representing tree and unordered_set representing hash table
- find insertion time for set and unordered_set every 5000 words from vector
- average the times across the 10 runs
*/

#include <iostream>
#include <fstream>
#include <string>            
#include <vector>               //at() returns reference, returns element, at(i)
#include <set>
#include <unordered_set>
#include <algorithm>            //for shuffle()
#include <random>               //for std::default_random_engine
#include <chrono>               //for clock

using namespace std;
using namespace std::chrono;

int main()
{
    vector<string> data;                        //read from file and store to vector
    string fromWords;
    ifstream file;

    file.open("words.txt");

    if(!file.good())
        cout << "File is not open" << endl;
    
    else
    {
         while(file >> fromWords)
                data.push_back(fromWords);
    }
    file.close();
    //------------------------------------
    vector<float> AVGs_treeInsert;              //vectors to store averages
    vector<float> AVGs_hashInsert;              //stores avg times per 10 runs
    vector<float> AVGs_treeFind;
    vector<float> AVGs_hashFind;
    
    int count = 5000;
    while(count <= 50000)                       //should run 10 times not 1 to 10 because count value
    {                                           //used in inner loop
        float ave_treeInsert = 0;
        float ave_hashInsert = 0;
        float ave_treeFind = 0;
        float ave_hashFind = 0;
                                                //for every 10 iterations, shuffle words then count time
        for(int i = 0; i < 10; i++)              //for insert and find for set and unorederd_set
        {                                       
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();           //for shuffle()   
            shuffle( data.begin(), data.end(), default_random_engine(seed) );               //shuffles data vector
            
            set<string> tree;                       // vector data form words file to tree and hash
            unordered_set<string> hashTable;
            
            //-----Tree insert, and finds the time duration of insert-----
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            
            for(int j = 0; j < count; j++)          //inserts 5000 words to tree
                tree.insert( data.at(j) );
            
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            
            duration<float> timeSpan_treeInsert = duration_cast<duration<float>>(t2 - t1);  //in seconds (?)
            
            ave_treeInsert += timeSpan_treeInsert.count();           //duration::count, count() returns duration
            //------------------------------------------------------------
            //-----Hash insert, and finds the time duration of insert-----
            high_resolution_clock::time_point t3 = high_resolution_clock::now();
            
            for(int j = 0; j < count; j++)          //inserts 5000 words to hashTable
                hashTable.insert( data.at(j) );
            
            high_resolution_clock::time_point t4 = high_resolution_clock::now();
            
            duration<float> timeSpan_hashInsert = duration_cast<duration<float>>(t4 - t3);
            
            ave_hashInsert += timeSpan_hashInsert.count();           //duration::count, count() returns duration
            //------------------------------------------------------------
            //-----Tree find, and finds the time duration of find-----
            high_resolution_clock::time_point t5 = high_resolution_clock::now();
            
            tree.find("zZt");                            //find something, find duration
            
            high_resolution_clock::time_point t6 = high_resolution_clock::now();
            
            duration<float> timeSpan_treeFind = duration_cast<duration<float>>(t6 - t5);
            
            ave_treeFind += timeSpan_treeFind.count();          //duration::count, count() returns duration
            //------------------------------------------------------------
             //-----Hash find, and finds the time duration of find-----
            high_resolution_clock::time_point t7 = high_resolution_clock::now();
            
            hashTable.find("zZt");                            //find something, find duration
            
            high_resolution_clock::time_point t8 = high_resolution_clock::now();
            
            duration<float> timeSpan_hashFind = duration_cast<duration<float>>(t8 - t7);
            
            ave_hashFind += timeSpan_hashFind.count();           //duration::count, count() returns duration
            //------------------------------------------------------------
        }
        ave_treeInsert /= 10.0;             //averages across 10 runs
        ave_hashInsert /= 10.0;
        ave_treeFind /= 10.0;
        ave_hashFind /= 10.0; 
        
        AVGs_treeInsert.push_back(ave_treeInsert);          //store values to corresponding vectors
        AVGs_hashInsert.push_back(ave_hashInsert);
        AVGs_treeFind.push_back(ave_treeFind);
        AVGs_hashFind.push_back(ave_hashFind);
        
        
        count += 5000;
    }
    
    ofstream ofs("data.txt");          //output the averages to data.txt
    
    int n = 5000;                           //value n in lab specs, there are 50,000 words, 10 avgs, so make n 5000
    for(int i = 0; i < 10; i++)                     //ten iterations
    {
        ofs << n << " ";
        ofs << AVGs_treeInsert.at(i) << " ";        //output averages for tree insertion time
        ofs << AVGs_hashInsert.at(i) << " ";        //output averages for hash insertion time
        ofs << AVGs_treeFind.at(i) << " ";        //output averages for tree find time
        ofs << AVGs_hashFind.at(i) << endl;        //output averages for hash find time
        n += 5000;
    }
                                            
    ofs.close();

    
    return 0;
}