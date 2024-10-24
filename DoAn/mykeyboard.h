#pragma once
enum KeyState
{
    // Common
    ENTER       = 13,
    ESC         = 27,
    BACKSPACE   = 8,
    SPACE       = 32,
    TAB         = 9,

    //Number
    NUM_0   = 48,
    NUM_1   = 49,
    NUM_2   = 50,
    NUM_3   = 51,
    NUM_4   = 52,

    // Arrow
    A_UP    = 72,
    A_DOWN  = 80,
    A_LEFT  = 75,
    A_RIGHT = 77,

    // System
    F1 = 59,
    F2 = 60,
    F3 = 61,
    F4 = 62,
    F5 = 63,

    DEFAULT = -1
};
int keyArrow(int key);
void showCur(bool CursorVisibility);
bool checkKey(int key);