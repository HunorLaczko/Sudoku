#ifndef LABEL_HPP_INCLUDED
#define LABEL_HPP_INCLUDED


#include "widget.hpp"

namespace W{

class Label:public Widget
{
    std::string value;
public:
    void draw();
    Label(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win, std::string v);
    bool is_focusable(){return false;}
};
}

#endif // LABEL_HPP_INCLUDED
