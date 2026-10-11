#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kRegionValue480_2A8 = 0x2a8 };
#else
enum { kRegionValue480_2A8 = 0x480 };
#endif


extern "C" void* func_ov003_02160bf8(void* obj, int key);

struct KeyedList0207c378;
extern "C" int func_0207c378(struct KeyedList0207c378* obj, int value, int amount, int key);

struct FindEntryContainer02086a04;
int RemoveOrShiftMarkedEntry02086a04(struct FindEntryContainer02086a04* c, int id);

extern unsigned short data_ov003_0217f494[9];
extern unsigned short data_ov003_0217f4a6[9];

// USA: func_ov003_021668fc
// JPN: func_ov003_021667f8
extern "C" ARM void func_ov003_021668fc(char* self) {
    if (*(short*)(self + kRegionValue480_2A8) < 0) return;

    GameState* bs = GameState::GetInstance();
    void* p2a04 = GetPtrField0x2a04(bs);
    void* found = func_ov003_02160bf8(self, *(short*)(self + kRegionValue480_2A8));
    if (found == 0) return;

    char* base = (char*)found + 0x160;

    short arrB[9];
    short arrA[9];

    unsigned int cntB = 9;
    char* dstB = (char*)arrB;
    char* srcB = (char*)data_ov003_0217f494;
    do {
        *(unsigned short*)dstB = *(unsigned short*)srcB;
        dstB += 2;
        srcB += 2;
    } while (--cntB);

    unsigned int cntA = 9;
    char* dstA = (char*)arrA;
    char* srcA = (char*)data_ov003_0217f4a6;
    do {
        *(unsigned short*)dstA = *(unsigned short*)srcA;
        dstA += 2;
        srcA += 2;
    } while (--cntA);

    unsigned char idx = 0;
    short key;
    while ((key = arrB[idx]) >= 0) {
        short v = *(short*)(base + key * 2);
        if (v >= 0) {
            func_0207c378((struct KeyedList0207c378*)((char*)p2a04 + 0x1d4), v, 1, arrA[idx]);
        }
        idx = (unsigned char)(idx + 1);
    }

    RemoveOrShiftMarkedEntry02086a04((struct FindEntryContainer02086a04*)p2a04, (signed char)*(short*)(self + kRegionValue480_2A8));
}
