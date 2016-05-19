#ifndef SUDOKUTABLE_HPP_INCLUDED
#define SUDOKUTABLE_HPP_INCLUDED

#include "SudokuNumberBox.hpp"

namespace W{

class SudokuTable
{
    float x,y;
    vector<SudokuNumberBox> table;
    Window *ablak;
public:
    SudokuTable(float _x, float _y, vector<int> _table, Window *_ablak);

};

}
#endif // SUDOKUTABLE_HPP_INCLUDED
