#include "SudokuWindow.hpp"

using namespace W;

SudokuWindow::SudokuWindow()
{
    vector<int> tmp = game.SendCurrentState();
    int width=40;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9;j++)
        {
            widgets.push_back(new SudokuNumberBox(i*width, j*width,width,width,{255,255,255},true,this,tmp[i*9+j],false));

        }

    }
}
