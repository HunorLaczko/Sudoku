#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

namespace W{
class Button:public Widget
{
    string szoveg;
    std::function<void()> _f;

public:
    Button(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win, string v, std::function<void()> f):Widget(xx,yy,aa,bb,coll,akt,win),szoveg(v),_f(f){}
    void draw();
    bool is_focusable(){return true;}
    void handle(event ev);
};
}

#endif // BUTTON_HPP_INCLUDED
