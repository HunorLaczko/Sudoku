#include "Application.hpp"

using namespace W;

void Application::run()
{
    event ev;
    gin.timer(10);
    while(gin >> ev&& ev.keycode!=key_escape)
    {
        Ablak.handle(ev);
        Ablak.draw();
        gout<<refresh;
    }
}
