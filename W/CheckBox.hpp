#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

namespace W{
class CheckBox:public Widget
{
    bool is_checked;

public:
    void draw();
    void handle(event ev);
    bool is_focusable(){return true;}
    CheckBox(float xx, float yy, float aa, Color coll, bool akt, Window *win, bool check);
    bool getChecked(){return is_checked;}
};
}

#endif // CHECKBOX_HPP_INCLUDED
