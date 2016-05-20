#ifndef GAMECORE_HPP_INCLUDED
#define GAMECORE_HPP_INCLUDED

#include<iostream>
#include<vector>
#include<map>
#include<fstream>

using namespace std;

class int_bool
{

public:
    int value;
    bool wrong;
    int_bool(int _value, bool _wrong):value(_value),wrong(_wrong){}
};

class SudokuGame
{
    vector<int> table;
    int level;
    int level_nr;
public:
    SudokuGame();
    void debug();
    vector<int_bool> SendCurrentState();
    void getNewState(vector<int> tmp);
    bool win();
    void ChooseLevel(int _level);
    int getLevel();
    void reset();
};


#endif // GAMECORE_HPP_INCLUDED
