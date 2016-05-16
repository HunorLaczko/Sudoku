#include "Window.hpp"

namespace W
{

TextBox::TextBox(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win, std::string v):Widget(xx,yy,aa,bb,coll,akt,win),value(v),start_pos(0),end_pos(v.size()-1),cursor_visible(false) {}

string TextBox::getText()
{
    if(value!="")
    {
        return value;
    }
    else
    {
        return "TextBox empty!";
    }
}

void TextBox::draw()
{
    gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a,b);
    if(selected==false)
    {
        cursor_visible=false;
        int i=0;
        while(gout.twidth(value.substr(0,i)+"... ")<a && (unsigned)i<value.size())
        {
            i++;
        }
        gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a,b);
        if(i!=0 && gout.twidth(value)>a)
        {
            gout<<move_to(x,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text(value.substr(0,i)+"...");
        }
        else
        {
            gout<<move_to(x,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text(value.substr(0,i));
        }
    }
    else
    {


        if(gout.twidth(value.substr(start_pos)+"|")>a) start_pos++;
        gout<<move_to(x,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text(value.substr(start_pos));
        if(cursor_visible) gout<<move_to(x+gout.twidth(value.substr(start_pos)),y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text("|");
        gout<<move_to(x,y)<<color(51,153,255);
        gout<<line(a,0)<<line(0,b)<<line(-a,0)<<line(0,-b);
    }

}

void TextBox::handle(event ev)
{
    if(selected)
    {
        if(ev.type==ev_key &&   isprint(ev.keycode))
        {
            value+=ev.keycode;
        }
        else if(ev.keycode==key_backspace && value != "")
        {
            value.erase(value.end()-1);
            if(start_pos>0)
                start_pos--;
        }
        if(ev.type==ev_timer)
        {
            static int counter=0;
            if((++counter)%50==0)
            {
                cursor_visible=!cursor_visible;
                counter=0;
            }
            if(cursor_visible) gout<<move_to(x+gout.twidth(value.substr(start_pos)),y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text("|");
        }
    }
}




}
