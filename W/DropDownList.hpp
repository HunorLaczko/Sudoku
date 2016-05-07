#ifndef DROPDOWNLIST_HPP_INCLUDED
#define DROPDOWNLIST_HPP_INCLUDED

namespace W{

class DropDownList:public Widget
{
    vector<string> items;
    int start_pos;
    int items_visible;
    int selected_item;
    int mouse_over_item;
    bool is_open;
public:
    void draw();
    void handle(event ev);
    bool is_focusable(){return true;}
    void setActive(bool value);
    bool is_selected(int xx, int yy);
    string getSelected();
    void AddItem(string x);
    DropDownList(float xx, float yy, float aa, Color coll, bool akt, Window *win, vector<string> it, int i_vis);

};
}
#endif // DROPDOWNLIST_HPP_INCLUDED
