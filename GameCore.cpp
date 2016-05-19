#include "GameCore.hpp"

SudokuGame::SudokuGame()
{
    ifstream f("input.txt");
    f>>level_nr;
    int x;
    for(int i=0; i< level_nr*81; i++)
    {
        f>>x;
        table.push_back(x);
    }

    f.close();
    level=0;
//    cout<<"Read:\n";
//    for(int i=0;i<9;i++)
//    {
//        for(int j=0; j<9; j++)
//        {
//            cout<<table[level*81 + i*9 + j]<<" ";
//        }
//        cout<<endl;
//    }
}


void SudokuGame::debug()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<table[level*81 + i*9 + j]<<" ";
        }
        cout<<endl;
    }
}

vector<int_bool> SudokuGame::SendCurrentState()
{
    if(level==level_nr)
    {
        level = 0;
    }
//    vector<bool> tmp_validatity;


        vector<int_bool> tmp;
        for(int i=0;i<81;i++)
        {
            tmp.push_back(int_bool(table[level*81+i],true));
        }
        return tmp;


}

void SudokuGame::getNewState(vector<int> tmp)
{
    table = tmp;
}
