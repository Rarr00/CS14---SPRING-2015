#ifndef WORDLADDER_H_INCLUDED
#define WORDLADDER_H_INCLUDED

#include<string>
#include<list>
#include<stack>
#include<queue>
#include<fstream>

using namespace std;

class WordLadder
{
private:
    list<string> dictionary;
public:

    WordLadder(const string& listFile)
    {
        string line;
        ifstream file;

        /*ifstream file(listFile.c_str());
        string word;
        while(file >> word)
            dictionary.push_back(word); */

        file.open(listFile.c_str());

        if(!file.good())
        {
            cout << "File is not open" << endl;
        }
        else
        {
            while(file >> line)
            {
                dictionary.push_back(line);
            }
        }
        file.close();
    }

    bool neighbor(string x, string y)
    {
        int numDiff = 0;        //number of different letters

        for(unsigned i = 0; i < x.size(); i++)              //i < x.size() --- x.size() is unsigned must be compared with unsigned so unsigned i
        {
            if(x.at(i) != y.at(i))
                numDiff++;
        }
        if(numDiff == 1)
            return true;
        else
            return false;

    }

    void outputLadder(const string& start, const string& end)
    {
        queue< stack<string> > workList;        //create queue of stacks
        stack<string> stk;              //create stack of strings
        stk.push(start);            //push start word on this stack
        workList.push(stk);             //enqueue the stack
        cout << "Finding a ladder from " << start << " to " << end << endl;

        while(!workList.empty())                                                                        //while queue is not empty                                                
        {
            for(auto iElement = dictionary.begin(); iElement != dictionary.end(); iElement++)       //for each word in the dictionary
            {
                if( neighbor(workList.front().top(), *iElement) )                           //if a word is exactly one letter different from top string of front stack            
                {
                    if(*iElement == end)                                        //if this word is the end word, print front stack plus THIS word is printed as word ladder
                    {
                           list<string> temp;                       //create a list for output

                           while(!workList.front().empty())                   
                           {
                               temp.push_back(workList.front().top());      //push back to temp the top string of front stack
                               workList.front().pop();              
                           }
                           while(!temp.empty())                     //while list not empty
                           {
                               cout << temp.back() << " ";          //output the back
                               temp.pop_back();                     //pop the back
                           }
                            cout << *iElement << endl;          //output last word
                            return;
                    }
                    stack<string> cpy = workList.front();       //make a copy of front stack
                    cpy.push(*iElement);                    //push found word into copy
                    workList.push(cpy);                     //enqueue the copy
                    dictionary.erase(iElement);     //erase this word in dictionary list, but iElement will point to the  next word
                    iElement--;                     //so decrement position
                }
            }
            workList.pop();         //remove from queue

        }

    }



};



#endif // WORDLADDER_H_INCLUDED