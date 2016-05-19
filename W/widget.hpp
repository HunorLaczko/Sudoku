#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include<iostream>
#include<cmath>
#include<time.h>
#include<vector>
#include<sstream>
#include<functional>
#include<cmath>
#include<iostream>
#include<cstring>
#include<string>


using namespace genv;
using namespace std;

const int size_x=1280;
const int size_y=720;

namespace W
{
class Window;

struct Color
{
    unsigned char r,g,b;
};

class Widget
{
protected:
    float x,y,a,b;
    Color col;
    bool selected;
    Window *ablak;
public:
    Widget(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win);
    virtual ~Widget(){}
    virtual void draw()=0;
    virtual void handle(genv::event ev);
    virtual void setActive(bool value);
    virtual bool is_focusable()=0;
    virtual bool is_selected(int xx, int yy);
};
}

#endif // WIDGET_HPP_INCLUDED
