#pragma once

#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Obj02079808;
struct Elem02079bac;

struct Struct02079a58 {
    unsigned int count : 12;
    unsigned int size : 19;
    unsigned int flag : 1;
    void* p1;
    void* p2;
};

struct Header02079bac {
    unsigned int count : 12;
    unsigned int hi : 19;
    unsigned int flag : 1;
    Elem02079bac* arr;
    unsigned char* extra;
};

typedef int (*ActionRecordRelocator)(void*, Obj02079808*);
typedef void (*ElemFn02079bac)(Header02079bac*, void*);
typedef void (*ObjFn02079bac)(Header02079bac*);

extern "C" int func_02079a58(Struct02079a58* table, SafeAllocator* allocator, void* data,
                            ActionRecordRelocator relocate,
                            void (*finish)(Struct02079a58*)
#if !defined(jpn)
                            , SafeAllocator* dataAllocator
#endif
);

extern "C" int func_02079bac(Header02079bac* table, SafeAllocator* allocator, void* data,
                            ElemFn02079bac relocate, ObjFn02079bac finish
#if !defined(jpn)
                            , SafeAllocator* dataAllocator
#endif
);

int RelocateOffsets02079808(void* table, Obj02079808* record);

struct ActionDataTables {
    Struct02079a58 actions;
    Struct02079a58 alternateActions;
    Header02079bac damage;
    Header02079bac alternateDamage;
};

ActionDataTables* GetData02108e10_020797dc();

extern "C" void func_02079900(ActionDataTables* tables, SafeAllocator* allocator);
extern "C" void func_02079cf8(ActionDataTables* tables, SafeAllocator* allocator, SafeAllocator* dataAllocator);

typedef char VerifyActionTableSize[sizeof(Struct02079a58) == 12 ? 1 : -1];
typedef char VerifyDamageTableSize[sizeof(Header02079bac) == 12 ? 1 : -1];
typedef char VerifyDamageTableOffset[offsetof(ActionDataTables, damage) == 0x18 ? 1 : -1];
typedef char VerifyAlternateActionTableOffset[offsetof(ActionDataTables, alternateActions) == 0xc ? 1 : -1];
typedef char VerifyAlternateDamageTableOffset[offsetof(ActionDataTables, alternateDamage) == 0x24 ? 1 : -1];
typedef char VerifyActionDataTablesSize[sizeof(ActionDataTables) == 0x30 ? 1 : -1];
