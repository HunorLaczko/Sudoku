#include "SudokuNumberBox.hpp"
#include "SudokuTable.hpp"

using namespace W;

SudokuTable::SudokuTable(float _x, float _y, vector<int> _table, Window *_ablak)
{

    ablak = _ablak;
    int width=40;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9;j++)
        {

            table.push_back(SudokuNumberBox(_x+i*width, _y+j*width,width,width,{255,255,255},true,_ablak,_table[i*9+j],false));

        }

    }
}
