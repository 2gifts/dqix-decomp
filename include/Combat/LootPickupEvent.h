#pragma once

#include "Memory/SafeAllocator.h"
#include "Graphics/Vector.h"

struct TailNode020469b4;
struct Foo02048004;

struct Obj021ae800 {
    signed char type;
    unsigned char complete, inList, unknown3;
    TailNode020469b4* next;
    unsigned char stage, mode;
    unsigned short timer;
    short itemId, unknownE;
    int task;
    Vector3fix position;
    int angle, fade;
    Foo02048004* sprite;
    SafeAllocator allocator;
};

void ResetHeaderAndAllocator_021ae800(Obj021ae800* event);

typedef char Obj021ae800SizeCheck[sizeof(Obj021ae800) == 0x40 ? 1 : -1];
