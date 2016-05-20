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
        MessageBox *message;
        DropDownList *levels;
        Label *instructions;
    public:
        SudokuWindow();
        ~SudokuWindow(){}
        void draw();
        void Update();
        void Reset();
    };
}

#endif // SUDOKUWINDOW_HPP_INCLUDED
