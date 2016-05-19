#ifndef NUMBERBOX_HPP_INCLUDED
#define NUMBERBOX_HPP_INCLUDED

#include "widget.hpp"

namespace W{
class NumberBox:public Widget
{
protected:
    float value;
    float interval_start,interval_end;
    float step;
public:
    virtual void draw();
    virtual void handle(event ev);
    virtual bool is_focusable(){return true;}
    float getValue();
    NumberBox(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win, float start, float endd, float st);
};
}

#endif // NUMBERBOX_HPP_INCLUDED
