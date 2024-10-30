#pragma once
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_RETURN         0x0D

enum KeyState
{
    // Common
    DEL         = 83,
    SPACEBAR    = 32,
    ESC         = 27,
    ENTER       = 13,
    TAB         = 9,
    BACKSPACE   = 8,

    //Number
    NUM_0   = 48,
    NUM_1   = 49,
    NUM_2   = 50,
    NUM_3   = 51,
    NUM_4   = 52,

    // Arrow
    DOWN    = 80,
    RIGHT   = 77,
    LEFT    = 75,
    UP      = 72,
    
    // System
    F1 = 59,
    F2 = 60,
    F3 = 61,
    F4 = 62,
    F5 = 63,

    DEFAULT = -1
};
int keySpecial(int key);
void showCur(bool CursorVisibility);
bool checkKey(int key);