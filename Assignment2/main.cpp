#include <iostream>
#include <cstdlib>

#include "WordLadder.h"

using namespace std;



int main(int argc, char* argv[])
{

    if(argc != 4)
    {
        cout << "Usage: wordladder <dictionary_file> <start_word> <end_word> " << endl;
        exit(-1);
    }
    string dictionaryFile = argv[1];
    string startWord = argv[2];
    string endWord = argv[3];

    WordLadder ladder (dictionaryFile);
    ladder.outputLadder(startWord,endWord);


    return 0;
}