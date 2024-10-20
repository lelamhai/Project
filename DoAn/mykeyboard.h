#pragma once
enum KeyState
{
    // Common
    ENTER = 13,
    ESC = 27,

    //Number
    NUM_0 = 48,
    NUM_1 = 49,
    NUM_2 = 50,
    NUM_3 = 51,
    NUM_4 = 52,

    // Arrow
    UP = 72,
    DOWN = 80,
    LEFT = 75,
    RIGHT = 77,

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