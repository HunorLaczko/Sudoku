#include "SudokuWindow.hpp"

using namespace W;

SudokuWindow::SudokuWindow()
{
    vector<int_bool> tmp = game.SendCurrentState();
    int width=40;
    int tmp_x=0, tmp_y=0;
    for(int i=0; i<9; i++)
    {
        tmp_x += width;
        tmp_y=0;
        if(i%3==0) tmp_x += 10;
        tmp_x++;
        for(int j=0; j<9;j++)
        {
            tmp_y += width;
            SudokuNumberBox *nr;
            if(j%3==0) tmp_y += 10;
            if(tmp[i*9+j].value != 0)
            {
                nr = new SudokuNumberBox(tmp_y, tmp_x,width,width,{255,255,255},true,this,tmp[i*9+j].value,false);

            }
            else
            {

                nr = new SudokuNumberBox(tmp_y, tmp_x,width,width,{255,255,255},true,this,tmp[i*9+j].value,true);

            }
            widgets.push_back(nr);
            numbers.push_back(nr);

            tmp_y++;


        }
    }
    test = new Button(500,100,100,30,{255,255,255},true,this,"Test",[this](){ Update();});
    widgets.push_back(test);
}


void SudokuWindow::Update()
{
    cout<<"Update";
    vector<int> tmp;
    for(int i=0;i<81;i++)
    {
        tmp.push_back(numbers[i]->getValue());
    }
    game.getNewState(tmp);

    vector<int_bool> friss;
    friss = game.SendCurrentState();

    for(size_t i =0; i< friss.size(); i++)
    {
        numbers[i]->setValue(friss[i].value);
        numbers[i]->validation(!friss[i].wrong);
    }


}
