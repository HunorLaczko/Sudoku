#include "graphics.hpp"
#include "widget.hpp"


namespace W
{

void Widget::draw()
{
    gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a,b);

}

void Widget::setActive(bool value)
{
    selected=value;
}

void Widget::handle(event ev)
{

}

bool Widget::is_selected(int xx, int yy)
{
    return xx>=x&& xx<=a+x && yy>y && yy<b+y;
}

Widget:: Widget(float xx, float yy, float aa, float bb, Color coll, bool akt, Window *win):x(xx),y(yy),a(aa),b(bb),col(coll),selected(akt),ablak(win) {}

}
