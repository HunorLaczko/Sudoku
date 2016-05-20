#ifndef MESSAGEBOX_HPP_INCLUDED
#define MESSAGEBOX_HPP_INCLUDED

namespace W
{
    class MessageBox:public Widget
    {
        string value;
        bool visible;
    public:
        void draw();
        MessageBox(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win, string _value, bool _visible);
        bool is_focusable(){return true;}
        void setValue(string _value);
        void Show();
        void Hide();
        void handle(event ev);
    };
}

#endif // MESSAGEBOX_HPP_INCLUDED
