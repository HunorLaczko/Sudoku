#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "Window.hpp"
#include "../SudokuWindow.hpp"

namespace W{

class Application
{
    const int X,Y;

    SudokuWindow Ablak;

public:
    Application(int _X, int _Y):X(_X),Y(_Y){gout.open(X,Y);}
    void run();
};

}
#endif // APPLICATION_HPP_INCLUDED
