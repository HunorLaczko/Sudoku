#include "Window.hpp"

using namespace W;

NumberBox::NumberBox(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win, float start, float endd, float st):Widget(xx,yy,aa,bb,coll,akt,win),value(start),interval_start(start),interval_end(endd),step(st){}

float NumberBox::getValue()
{
    return value;
}

void NumberBox::draw()
{
    gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a*0.8,b);
    gout<<move_to(x+a*0.8,y)<<color(180,180,180)<<box(a*0.2,b/2);
    gout<<move_to(x+a*0.8+gout.twidth("+"),y+b/4+gout.cascent()/2)<<color(0,0,0)<<text("+");
    gout<<move_to(x+a*0.8,y+b/2)<<color(180,180,180)<<box(a*0.2,b/2);
    gout<<move_to(x+a*0.8+gout.twidth("-"),y+3*b/4+gout.cascent()/2)<<color(0,0,0)<<text("-");
    gout<<move_to(x+a*0.8-5-gout.twidth(to_string(value)),y+b/2+gout.cascent()/2)<<color(0,0,0)<<text(to_string(value));
    if(selected)
    {
        gout<<move_to(x,y)<<color(51,153,255);
        gout<<line(a,0)<<line(0,b)<<line(-a,0)<<line(0,-b);
    }
}

void NumberBox::handle(event ev)
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
    if(ev.type==ev_mouse && ev.button==btn_left)
    {
        if(ev.pos_x>x+a*0.8 && ev.pos_x<x+a && ev.pos_y>y && ev.pos_y<y+b/2 && value<interval_end)
        {
            value+=step;
        }
        if(ev.pos_x>x+a*0.8 && ev.pos_x<x+a && ev.pos_y>y+b/2 && ev.pos_y<y+b && value>interval_start)
        {
            value-=step;
        }
    }
}
