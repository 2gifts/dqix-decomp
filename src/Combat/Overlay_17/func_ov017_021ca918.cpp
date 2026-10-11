#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(GameState* battleStruct);

struct SrcEntry021ca918 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned char bytes8[4];
    short fieldc;
    short fielde;
    short field10;
    short field12;
};

// JPN: func_ov017_021cadc8
// USA: func_ov017_021ca918
extern "C" ARM void func_ov017_021ca918(int unused0, struct SrcEntry021ca918* src, GameState* battleStruct, unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    void* table = *(void**)(base + 0x3000 + regionalOffset0);
    void* state = GetField6b0_021b8470(table);
    if (state == NULL) return;
    unsigned char* obj = *(unsigned char**)((char*)state + 0x8000 + 0xe18);
    if (obj == NULL) return;

    if (*(signed char*)(obj + 0x2a) == GetField0x3acValue(battleStruct)) return;
    if (*(unsigned short*)(obj + 8) != src->field4) return;

    int idx = src->field6 - 0xc0;
    if (idx < 0) return;
    if (idx >= 8) return;

    unsigned char* entry = obj + 0x158 + idx * 0xa4;
    memcpy(entry + 0x58, src->bytes8, 4);
    *(short*)(entry + 0x28) = src->fieldc;
    *(short*)(entry + 0x2a) = src->fielde;
    *(short*)(entry + 0x2c) = src->field10;
    *(short*)(entry + 0x2e) = src->field12;
}
