#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

namespace W
{
class TextBox:public Widget
{
    std::string value;
    int start_pos;
    int end_pos;
    bool cursor_visible;
public:
    void draw();
    void handle(genv::event ev);
    bool is_focusable(){return true;}
    TextBox(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win, std::string v);
    string getText();
};
}

#endif // TEXTBOX_HPP_INCLUDED
