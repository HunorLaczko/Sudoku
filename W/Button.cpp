#include "Window.hpp"

using namespace W;

void Button::draw()
{
    gout<<move_to(x,y)<<color(col.r,col.g,col.b)<<box(a,b);
    gout<<move_to(x+(a-gout.twidth(szoveg))/2,y+(b-gout.cascent()-gout.cdescent())/2+gout.cascent())<<color(0,0,0)<<text(szoveg);

}
