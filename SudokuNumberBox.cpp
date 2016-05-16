#include "W/Window.hpp"


using namespace W;

SudokuNumberBox::SudokuNumberBox(float _x, float _y, float _a, float _b, Color _col, bool _aktiv, Window *_ablak, int _value, bool _modifiable):NumberBox(_x,_y,_a,_b,_col,_aktiv,_ablak,0,9,1),valid(true),modifiable(_modifiable){value=_value; selected = false; }

void SudokuNumberBox::draw()
{
    gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a,b);
    if(selected)
    {
        gout<<move_to(x,y)<<color(51,153,255);
        gout<<line(a,0)<<line(0,b)<<line(-a,0)<<line(0,-b);
    }
    if(valid)
    {
        gout<<move_to(x+(a-gout.twidth(to_string(value)))/2,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text(to_string(value));
        //gout<<move_to(x+a*0.8-5-gout.twidth(to_string(value)),y+b/2+gout.cascent()/2)<<color(0,0,0)<<text(to_string(value));
    }
    else
    {
        gout<<move_to(x-gout.twidth(to_string(value)),y+b/2+gout.cascent()/2)<<color(255,0,0)<<text(to_string(value));
    }


}


void SudokuNumberBox::handle(event ev)
{
if(selected)
    {
        if(ev.type==ev_key && (ev.keycode==key_up || ev.keycode==key_pgup) && value<interval_end)
        {
            value+=step;
        }
        if(ev.type==ev_key && (ev.keycode==key_down || ev.keycode==key_pgdn) && value>interval_start)
        {
            value-=step;
        }
    }
    if(ev.type==ev_key && ev.keycode >= '1' && ev.keycode <= '9')
    {
        value = ev.keycode - '0';
    }
    if(ev.type==ev_mouse && ev.button==btn_wheeldown && value<interval_end)
    {
        value+=step;
    }
    if(ev.type==ev_mouse && ev.button==btn_wheelup && value>interval_start)
    {
        value-=step;
    }
}
