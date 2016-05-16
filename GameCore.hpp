#ifndef GAMECORE_HPP_INCLUDED
#define GAMECORE_HPP_INCLUDED

#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class SudokuGame
{
    vector<int> table;
    int level;
    int level_nr;
public:
    SudokuGame();
    void debug();
    vector<int> SendCurrentState();
};


#endif // GAMECORE_HPP_INCLUDED
