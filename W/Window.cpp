#include "Window.hpp"
#include <fstream>

namespace W
{

string to_string(float x)
{
    string temp;
    stringstream ss;
    ss<<x;
    ss>>temp;
    return temp;
}

int to_int(string s)
{
    int temp;
    stringstream ss;
    ss<<s;
    ss>>temp;
    return temp;
}

  unsigned int Window::size()
    {
        return widgets.size();
    }

Window::Window()
{
    focus = -1;
    valid = true;
}

void Window::handle(event ev)
{
    if(!valid)
    {
        Update();
    }


    bool talalt=false;
    bool re_focus = false;
    if(ev.type==ev_mouse && ev.button==btn_left)
    {
        if(focus!=-1 && widgets[focus]->is_selected(ev.pos_x,ev.pos_y))
        {
            widgets[focus]->handle(ev);
            re_focus = true;
        }
        else
        {
            for(size_t i=0; i<widgets.size(); ++i)
            {
                if(widgets[i]->is_selected(ev.pos_x,ev.pos_y) && widgets[i]->is_focusable())
                {
                    if(focus!=-1 && (signed)i!=focus)
                    {
                        widgets[focus]->setActive(false);
//                        widgets[focus]->handle(ev);
                    }
                    focus = i;
                    widgets[focus]->setActive(true);
                    talalt=true;
                }
            }
            if(!talalt && focus!=-1)
            {
                widgets[focus]->setActive(false);
                focus=-1;
            }

        }

//        cout<<focus<<endl;
    }

    if(focus!=-1 && !re_focus)
    {
        widgets[focus]->handle(ev);
    }

}

void Window::draw()
{
    gout<<move_to(0,0)<<color(220,220,220)<<box(size_x,size_y);
    for(Widget* &w:widgets)
    {
        w->draw();
    }
    if(focus!=-1)
        widgets[focus] -> draw();
}

void Window::setFocus(Widget* w)
{
    for(size_t i=0; i<widgets.size(); ++i)
    {
        if(widgets[i]==w)
        {
            focus=i;
            break;
        }
    }
}

void Window::addWidget(Widget *w)
{
    widgets.push_back(w);
}

void Window::invalidate()
{
    valid = false;
}

void Window::Update()
{

}

}

