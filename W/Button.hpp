#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

//template<typename Fun>
namespace W{
class Button:public Widget
{
    string szoveg;
    std::function<void()> _f;

public:
    Button(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win, string v, std::function<void()> f):Widget(xx,yy,aa,bb,coll,akt,win),szoveg(v),_f(f){}
    void draw();
//    void handle(event ev);

    bool is_focusable(){return true;}
     void handle(event ev)
    {
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            _f();
        }

    }
};
}

#endif // BUTTON_HPP_INCLUDED
