#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED


#include "widget.hpp"
#include "Label.hpp"
#include "TextBox.hpp"
#include "NumberBox.hpp"
#include "DropDownList.hpp"
#include "CheckBox.hpp"
#include "Button.hpp"
#include "../SudokuTable.hpp"
#include "../SudokuNumberBox.hpp"
#include "../GameCore.hpp"
#include "../MessageBox.hpp"

namespace W
{

class Widget;
string to_string(float x);
int to_int(string s);

class Window
{
protected:
    std::vector<Widget*> widgets;
    Widget* kivalasztva;
    int focus;
    bool valid;


public:
    Window();
    virtual ~Window(){}
    unsigned int size();
    void handle(event ev);
    virtual void draw();
    void setFocus(Widget *w);
    void setFocus(int _focus);
    void addWidget(Widget *w);
    virtual void Update();
    void invalidate();

};

}

#endif // WINDOW_HPP_INCLUDED
