#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

void InitStruct0205a444(char* obj);
struct Struct020dfc40;
void ResetStruct020dfc40(Struct020dfc40* p);
void InitBigStruct0205c790(char* obj);

// JPN: func_ov003_0216f8dc
// USA: func_ov003_0216ffbc  (semantic: InitBattleStateStruct_0216ffbc)
extern "C" ARM void func_ov003_0216ffbc(char* obj) {
    obj[0] = 1;
    obj[1] = 0;
    obj[2] = 0;
    obj[3] = 0;
    obj[4] = 0;
    obj[5] = 0;
    obj[6] = 0;
    obj[7] = -1;
    obj[8] = 0;
    obj[9] = -1;
    obj[0xa] = 0;
    *(short*)(obj + 0xc) = 0;
    *(short*)(obj + 0xe) = 0;
    *(int*)(obj + 0x10) = -1;
    *(int*)(obj + 0x14) = 0;
    *(int*)(obj + 0x18) = 0;
    *(int*)(obj + 0x1c) = -1;
    *(short*)(obj + 0x20) = 0;
    *(int*)(obj + 0x24) = 0;
    *(short*)(obj + 0x28) = 0;

    int i;
    for (i = 0; i < 3; i++)
        *(short*)(obj + i * 2 + 0x2a) = -1;

    memset(obj + 0x30, 0, 0xb);

    obj[0x3b] = 0;
    *(int*)(obj + 0x3c) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    obj[0x58] = 0;
    obj[0x59] = 0;
    *(int*)(obj + 0x5c) = 0;
    *(int*)(obj + 0x60) = 0;
    *(int*)(obj + 0x64) = 0;
    InitStruct0205a444(obj + 0x68);

    ((SafeAllocator*)(obj + 0xbc))->ResetAllocatorPointer();

    *(int*)(obj + 0xd0) = 0;
    *(int*)(obj + 0xd4) = 0;
    *(int*)(obj + 0xd8) = 0;
    *(int*)(obj + 0x16c) = 0;
    *(int*)(obj + 0x174) = 0;
    ResetStruct020dfc40((Struct020dfc40*)(obj + 0xdc));

    InitBigStruct0205c790(obj + 0x178);

#if !defined(jpn)
    memset(obj + 0x3b0, -1, 0x20);
#endif
}
