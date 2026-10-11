#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(GameState* battleStruct);

// JPN: func_ov017_021c7590
// USA: func_ov017_021c70e0  (semantic: CopyFieldsToCombatant_021c70e0)
extern "C" ARM void func_ov017_021c70e0(int unused0, unsigned char* src, GameState* battleStruct, unsigned char* ovBase) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    unsigned char* h = *(unsigned char**)(ovBase + 0x3000 + regionalOffset0);
    unsigned char* r = (unsigned char*)func_ov017_021b8478(h);
    if (!r) return;
    if (!func_ov017_021b8468(h)) return;
    if (!GetField6b0_021b8470(h)) return;

    int fieldVal = GetField0x3acValue(battleStruct);
    if (*(signed char*)(r + 0x2a) == fieldVal) return;

    if (*(unsigned short*)(r + 0x8) != *(unsigned short*)(src + 0x4)) return;

    GameObject* c = battleStruct->GetCombatantByIndex(*(unsigned short*)(src + 0x6));
    if (!c) return;

    memcpy((char*)*(int*)((char*)c + 0x138) + 0x58, src + 0x8, 4);
    *(short*)((char*)*(int*)((char*)c + 0x138) + 0x28) = *(short*)(src + 0xc);
    *(short*)((char*)*(int*)((char*)c + 0x138) + 0x2a) = *(short*)(src + 0xe);
    *(short*)((char*)*(int*)((char*)c + 0x138) + 0x2c) = *(short*)(src + 0x10);
    *(short*)((char*)*(int*)((char*)c + 0x138) + 0x2e) = *(short*)(src + 0x12);
}
