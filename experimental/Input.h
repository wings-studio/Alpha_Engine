#include <vector>
#include "ae_std.h"

enum class Key {
    Enter,
    Esc,

    Up,
    Down,
    Left,
    Right,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    Home,
    End,
    PageUp,
    PageDown,

    Space,
    Comma,
    Period,
    Minus,
    Plus,
    Slash,
    Percent,
    Equal,

    Zero,
    One,
    Two,
    Three,
	Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,

    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
	J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z
};

struct KeyEvent
{
	Key key;
};

class Input
{
public:		
};
