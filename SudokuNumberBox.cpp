#include "W/Window.hpp"


using namespace W;

SudokuNumberBox::SudokuNumberBox(float _x, float _y, float _a, float _b, Color _col, bool _aktiv, Window *_ablak, int _value, bool _modifiable):NumberBox(_x,_y,_a,_b,_col,_aktiv,_ablak,0,9,1),valid(true),modifiable(_modifiable)
{
    value=_value;
    selected = false;
}

bool SudokuNumberBox::is_focusable()
{
    return modifiable;
}

void SudokuNumberBox::draw()
{
    if(modifiable)
    {
        gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a,b);
    }
    else
    {
        gout<<move_to(x,y)<<color(245,245,245)<<box(a,b);
    }
    if(value!=0)
    {

        if(valid)
        {

            gout<<move_to(x+(a-gout.twidth(to_string(value)))/2,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text(to_string(value));
        }
        else
        {
            gout<<move_to(x,y)<<color(255,0,0)<<box(a,b);
            gout<<move_to(x+(a-gout.twidth(to_string(value)))/2,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text(to_string(value));
        }
    }
        if(selected)
    {
        gout<<move_to(x,y)<<color(51,153,255);
        gout<<line(a,0)<<line(0,b)<<line(-a,0)<<line(0,-b);
    }

}

void SudokuNumberBox::handle(event ev)
{
    if(modifiable)
    {
        if(selected)
        {
            if(ev.type==ev_key && (ev.keycode==key_up || ev.keycode==key_pgup) && value<interval_end)
            {
                value+=step;
                ablak->invalidate();
            }
            if(ev.type==ev_key && (ev.keycode==key_down || ev.keycode==key_pgdn) && value>interval_start)
            {
                value-=step;
                ablak->invalidate();
            }
        }
        if(ev.type==ev_key && ev.keycode >= '1' && ev.keycode <= '9')
        {
            value = ev.keycode - '0';
            ablak->invalidate();
        }
        if(ev.type==ev_mouse && ev.button==btn_wheeldown && value<interval_end)
        {
            value+=step;
            ablak->invalidate();
        }
        if(ev.type==ev_mouse && ev.button==btn_wheelup && value>interval_start)
        {
            value-=step;
            ablak->invalidate();
        }
    }
}

void SudokuNumberBox::setValue(float x)
{
    value = x;
    ablak->invalidate();
}
void SudokuNumberBox::validation(bool x)
{
    valid = x;
    ablak->invalidate();
}
void SudokuNumberBox::change_modifiable(bool _modifiable)
{
    modifiable = _modifiable;
}


