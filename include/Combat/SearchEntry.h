#pragma once

struct SearchStruct;

struct SearchEntry0202c178 {
    union {
        unsigned short raw;
        struct {
            unsigned short selected : 3;
            unsigned short reserved : 5;
            unsigned short kind : 8;
        };
    } flags;
    unsigned short active : 1;
    unsigned short members : 4;
    unsigned short selector1 : 2;
    unsigned short selector2 : 2;
    unsigned short selector3 : 2;
    unsigned short bit11 : 1;
    unsigned short bit12 : 1;
    unsigned short bit13 : 1;
    unsigned short bit14 : 1;
    unsigned short bit15 : 1;
    unsigned short mask;
    unsigned short field6;
    short x;
    short y;
    short z;
    short angle;
};

SearchEntry0202c178* GetEntryBySignedByteIndex_0202c178(SearchStruct* object, int value);
void ShiftRecords0202c478(SearchStruct* object);
