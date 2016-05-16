#ifndef SUDOKUNUMBERBOX_HPP_INCLUDED
#define SUDOKUNUMBERBOX_HPP_INCLUDED

#include "W/widget.hpp"
#include "W/NumberBox.hpp"

namespace W
{
    class SudokuNumberBox:public NumberBox
    {
        bool valid;
        bool modifiable;
    public:
        SudokuNumberBox(float _x, float _y, float _a, float _b, Color _col, bool _aktiv, Window *_ablak, int _value, bool _modifiable);
        void draw();
        void handle(event ev);
    };
}

#endif // SUDOKUNUMBERBOX_HPP_INCLUDED
