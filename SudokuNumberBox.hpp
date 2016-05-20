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
        bool is_focusable();
        void draw();
        void handle(event ev);
        void setValue(float x);
        void validation(bool x);
        void change_modifiable(bool _modifiable);
    };
}

#endif // SUDOKUNUMBERBOX_HPP_INCLUDED
