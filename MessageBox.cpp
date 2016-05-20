#include "W/Window.hpp"
#include "MessageBox.hpp"

using namespace W;

MessageBox::MessageBox(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win, string _value, bool _visible):Widget(xx,yy,aa,bb,coll,akt,win),value(_value),visible(_visible) {}

void MessageBox::draw()
{
    if(visible)
    {
        gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a,b);
        gout<<move_to(x+(a-gout.twidth(value))/2,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text(value);
    }
}

void MessageBox::setValue(string _value)
{
    value=_value;
    ablak->invalidate();
}

void MessageBox::Show()
{
    visible=true;
    ablak->invalidate();
}

void MessageBox::Hide()
{
    visible=false;
    ablak->invalidate();
}

void MessageBox::handle(event ev)
{
    if(ev.type == ev_mouse && ev.button == btn_left)
    {
        cout<<"y";
        visible = false;
        ablak->invalidate();
    }
}
