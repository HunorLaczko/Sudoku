 #include "Window.hpp"

 using namespace W;

 Label::Label(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win, std::string v):Widget(xx,yy,aa,bb,coll,akt,win),value(v){}

void Label::draw()
{
    gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a,b);
    int lines=1;
    for(size_t i=0;i<value.size()-1;i++)
    {
        if(value[i] == '\n' )
        {
            lines++;
        }
    }
    gout<<move_to(x+(a-gout.twidth(value))/2,y+(b-gout.cascent()*lines-gout.cdescent()*lines)/2+gout.cascent())<<color(0,0,0)<<text(value);
}

