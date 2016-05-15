#include "Window.hpp"

using namespace W;

const int arrow_size = 20;
const int slider_width = 20;

DropDownList::DropDownList(float xx, float yy, float aa, Color coll, bool akt, Window *win, vector<string> it, int i_vis):Widget(xx,yy,aa,25,coll,akt,win),items(it),start_pos(0),items_visible(i_vis),selected_item(-1),mouse_over_item(-1),is_open(false){}

void DropDownList::setActive(bool value)
{
    selected=value;
    if(value==false)
    {
        is_open=false;
    }
}

bool DropDownList::is_selected(int xx, int yy)
{
    if(!is_open)
    {
        return xx>=x&& xx<=a+x && yy>y && yy<b+y;
    }
    else
    {
        return xx>=x && xx<=a+x && yy>y && yy<b*(1+items_visible)+y;
    }

}

string DropDownList::getSelected()
{
    if(selected_item != -1)
    {
        return items[selected_item];
    }
    else
    {
        return "No item selected!";
    }
}

int DropDownList::getSelectedIndex()
{
    return selected_item;
}

void DropDownList::RemoveItem(int s)
{
    items.erase(items.begin()+s);
    if(selected_item == (signed)items.size() )
    {
        selected_item--;

    }
    if(selected_item < (signed)items.size() - 1)
    {
//        selected_item ++;
    }
    cout<<selected_item <<": "<<items[selected_item]<<endl;
    for(size_t i=0;i<items.size();++i)
        cout<<items[i]<<endl;
}

void DropDownList::AddItem(string x)
{
    items.push_back(x);
}

void DropDownList::handle(event ev)
{
    if(ev.type == ev_mouse)
    {
        if(ev.pos_x>x && ev.pos_x<x+a - slider_width && ev.pos_y>y+b && ev.pos_y<b*(1+items_visible)+y )
        {
            mouse_over_item = (-y-b+ev.pos_y)/b + start_pos;
//            cout<<mouse_over_item <<endl;
        }
        if(!is_selected(ev.pos_x, ev.pos_y))
        {
            mouse_over_item = -1;
        }

    }
    if( ( (ev.type == ev_key && ev.keycode == key_up) || (ev.type == ev_mouse && ev.button == btn_wheelup)) && start_pos>0)
    {
        start_pos--;
    }
    if(( (ev.type == ev_key && ev.keycode == key_down) || (ev.type == ev_mouse && ev.button == btn_wheeldown) ) && start_pos+items_visible<(signed)items.size())
    {
        start_pos++;
    }


    if(ev.type==ev_mouse && ev.button==btn_left)
    {
        if(ev.pos_x>x+a-arrow_size && ev.pos_x<x+a && ev.pos_y>y && ev.pos_y<y+b )
        {
//            cout<<is_open<<endl;
            is_open=!is_open;
        }
        if(ev.pos_x>x && ev.pos_x<x+a- slider_width && ev.pos_y>y+b && ev.pos_y<b*(1+items_visible)+y )
        {
            selected_item = (-y-b+ev.pos_y)/b + start_pos;
            setActive(false);
        }
//        if(ev.pos_x>x && ev.pos_x<x+a - arrow_size && ev.pos_y>y+b && ev.pos_y<b*(1+items_visible)+y )
//        {
//            selected_item = (-y-b+ev.pos_y)/b + start_pos;
//            setActive(false);
//        }
        if(ev.pos_x>x+a - slider_width && ev.pos_x<x+a  && ev.pos_y>y+b && ev.pos_y<2*b+y && start_pos>0)
        {
            start_pos --;
        }

        if(ev.pos_x>x+a - slider_width && ev.pos_x<x+a  && ev.pos_y>y+b*items_visible && ev.pos_y<(items_visible+1)*b+y && start_pos+items_visible<(signed)items.size())
        {
            start_pos++;
        }

    }

}

void DropDownList::draw()
{
    gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a - arrow_size,b);
    gout<<move_to(x+a - arrow_size,y)<<color(180,180,180)<<box(arrow_size,b);
    gout<<move_to(x+a - arrow_size*0.9,y+b*0.1)<<color(0,0,0)<<line(arrow_size*0.45,b*0.8)<<line(arrow_size*0.45,-b*0.8);
    if(selected)
    {
        gout<<move_to(x,y)<<color(51,153,255);
        gout<<line(a,0)<<line(0,b)<<line(-a,0)<<line(0,-b);
    }
    if(selected_item!=-1)
    {
        gout<<move_to(x,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text(items[selected_item]);
    }
    else
    {
        gout<<move_to(x,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text("Choose");
    }

    if(is_open)
    {

        for(size_t i = 0; i<items.size() && i< (unsigned)items_visible; ++i)
        {
            if(items.size()>(unsigned)items_visible)
            {
                if((signed)(start_pos+i) == mouse_over_item)
                {
                    gout<<move_to(x,y+(i+1)*b)<<color(180,180,180)<<box(a-slider_width,b);
                }
                else
                {
                    gout<<move_to(x,y+(i+1)*b)<<color(255,255,255)<<box(a-slider_width,b);
                }
                gout<<move_to(x+(a-gout.twidth(items[start_pos+i]) - slider_width )/2,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent()+(i+1)*b)<<color(0,0,0)<<text(items[start_pos+i]);
            }
            else
            {
                if((signed)(start_pos+i) == mouse_over_item)
                {
                    gout<<move_to(x,y+(i+1)*b)<<color(180,180,180)<<box(a,b);
                }
                else
                {
                    gout<<move_to(x,y+(i+1)*b)<<color(255,255,255)<<box(a,b);
                }
                gout<<move_to(x+(a-gout.twidth(items[start_pos+i]))/2,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent()+(i+1)*b)<<color(0,0,0)<<text(items[start_pos+i]);
            }
        }
        if(items.size()>(unsigned)items_visible)
        {
            float slider_height = (b*items_visible - 2*b)/(items.size()-items_visible+1);
            gout<<move_to(x+a - slider_width,y+items_visible*b)<<color(180,180,180)<<box(slider_width,b);
            gout<<move_to(x+a - slider_width*0.9,y+b*0.1+items_visible*b)<<color(0,0,0)<<line(slider_width*0.45,b*0.8)<<line(slider_width*0.45,-b*0.8);
            gout<<move_to(x+a - slider_width,y+b)<<color(180,180,180)<<box(slider_width,b);
            gout<<move_to(x+a - slider_width*0.9,y-b*0.1+b*2)<<color(0,0,0)<<line(slider_width*0.45,-b*0.8)<<line(slider_width*0.45,b*0.8);
            gout<<move_to(x+a - slider_width,y+2*b)<<color(200,200,200)<<box(slider_width,b*(items_visible-2));
            gout<<move_to(x+a - slider_width,y+b+b+start_pos*slider_height)<<color(120,120,120)<<box(slider_width,slider_height);
        }
//        gout<<move_to(x+a-slider_width, (items_visible)*b+y) << color(255,0,255)<<box(slider_width,b);
    }

}
