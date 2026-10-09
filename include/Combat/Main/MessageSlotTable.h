#pragma once

#include <globaldefs.h>

struct MessageSlotTable_020dd7ac {
    int flag;
    int unused04;
    void *ptrs[12];
    unsigned char pad38;
    unsigned char pad39[3];
    unsigned short f3c;
    unsigned short f3e;
    unsigned short f40;
    unsigned short f42;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    unsigned short f64;
    unsigned short f66;
    unsigned short f68;
    unsigned short f6a;
    unsigned short f6c;
    unsigned short f6e;
    unsigned short f70;
    unsigned short f72;
    unsigned short f74;
    unsigned short f76;
    unsigned short f78;
    unsigned short f7a;
};

extern "C" void func_020dd9b4(MessageSlotTable_020dd7ac *table, unsigned int kind, void *firstValue, void *secondValue);
