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

vector<int> SudokuGame::SendCurrentState()
{
    if(level<level_nr)
    {
        vector<int> tmp(&table[level*81],&table[level*81+81]);
//        for(int i=0;i<9;i++)
//        {
//            for(int j=0; j<9; j++)
//            {
//                cout<<tmp[i*9 + j]<<" ";
//            }
//            cout<<endl;
//        }
        return tmp;
    }
    else
    {
        vector<int> tmp;
        return tmp;
    }
}
