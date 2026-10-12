#include <globaldefs.h>

#if defined(jpn)
enum { kSubPointerOffset = 0x144 };
#else
enum { kSubPointerOffset = 0x150 };
#endif


#if defined(jpn)
#define SetFieldFromLookup464_021e9818 func_ov023_021e977c
#endif
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void* variant);
extern "C" void func_ov017_021d6134(void* variant, int val);
extern "C" void* func_ov023_021e8f28(int idx);

// USA: func_ov023_021e9818
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldFromLookup464_021e9818(void* a) {
    GameState::GetInstance();
    int idx = func_ov017_021d60f4(a);
    void* e = func_ov023_021e8f28(idx);
    if (e == NULL) return 0;
    int idx2 = func_ov017_021d60f4((char*)a + 0x8);
    char* base = *(char**)((char*)e + kSubPointerOffset);
    unsigned char v = *(unsigned char*)(base + (idx2 & 0xff) + 0x464);
    func_ov017_021d6134((char*)a + 0x10, v);
    return 1;
}
