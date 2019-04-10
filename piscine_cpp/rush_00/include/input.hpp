#ifndef INPUT_HPP
#define INPUT_HPP

namespace Input
{
    enum
    {
        UP = 0,
        DOWN,
        RIGHT,
        LEFT,
        SPACE,
		ENTER
    };
}

#define KEYMASK(k) (1 << k)

#define DIRKEYMASK (KEYMASK(Input::UP) | KEYMASK(Input::DOWN) | KEYMASK(Input::RIGHT) | KEYMASK(Input::LEFT))

#endif
