#ifndef SUDOKUWINDOW_HPP_INCLUDED
#define SUDOKUWINDOW_HPP_INCLUDED

#include "SudokuTable.hpp"
#include "W/Window.hpp"

namespace W
{
    class SudokuWindow:public Window
    {
        SudokuGame game;
        vector<SudokuNumberBox*> numbers;
        Button *test;
    public:
        SudokuWindow();
        ~SudokuWindow(){}
        void Update();
    };
}

#endif // SUDOKUWINDOW_HPP_INCLUDED
