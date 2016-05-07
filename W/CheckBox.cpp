#include "Window.hpp"

using namespace W;

CheckBox::CheckBox(float xx, float yy, float aa, Color coll, bool akt, Window *win, bool check):Widget(xx,yy,aa,aa,coll,akt,win),is_checked(check){}

void CheckBox::handle(event ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left)
    {
        is_checked=!is_checked;
    }
}


void CheckBox::draw()
{
    gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a,b);
    if(is_checked)
    {
        gout<<move_to(x,y)<<color(0,0,0)<<line(a,b);
        gout<<move_to(x+a,y)<<color(0,0,0)<<line(-a,b);
    }
}
