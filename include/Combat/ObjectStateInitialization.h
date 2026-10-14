#pragma once

#include "World/Object3D.h"

struct Struct02032fb8 {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned short w;
};

struct ObjectStatePrefix {
    Object3D object;
    unsigned short fieldAc;
    unsigned short fieldAe;
    unsigned short fieldB0;
    unsigned short fieldB2;
    unsigned short fieldB4;
    unsigned short fieldB6;
    unsigned short fieldB8;
    unsigned short fieldBa;
    unsigned short fieldBc;
    unsigned char fieldBe;
    unsigned char fieldBf;
    unsigned char fieldC0;
    unsigned char fieldC1Low : 2;
    unsigned char fieldC1Bit2 : 1;
    unsigned char fieldC1Bit3 : 1;
    unsigned char fieldC1High : 4;
    unsigned char fieldC2Low : 4;
    unsigned char fieldC2Bit4 : 1;
    unsigned char fieldC2Bit5 : 1;
    unsigned char fieldC2Bit6 : 1;
    unsigned char fieldC2Bit7 : 1;
    unsigned char fieldC3;
    unsigned short fieldC4Low : 15;
    unsigned short fieldC4High : 1;
    unsigned short fieldC6;
    unsigned char unknownC8[0x18];
    unsigned char fieldE0Bit0 : 1;
    unsigned char fieldE0Bit1 : 1;
    unsigned char fieldE0Bit2 : 1;
    unsigned char fieldE0Bit3 : 1;
    unsigned char fieldE0Bit4 : 1;
    unsigned char fieldE0Bit5 : 1;
    unsigned char fieldE0Bit6 : 1;
    unsigned char fieldE0Bit7 : 1;
    unsigned char unknownE1[0x33];
    Struct02032fb8 firstHalfwords;
    Struct02032fb8 secondHalfwords;
    unsigned int field124;
    unsigned int field128;
    unsigned short field12c;
};

typedef char ObjectStatePrefixExtentCheck[sizeof(ObjectStatePrefix) == 0x130 ? 1 : -1];
typedef char ObjectStatePrefixB4Check[offsetof(ObjectStatePrefix, fieldB4) == 0xb4 ? 1 : -1];

void ClearFourHalfwords(Struct02032fb8 *value);
extern "C" void func_02032e58(void *receiver);
