#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue1F7_1F3 = 0x1f3 };
enum { kRegionValue1FC_1F8 = 0x1f8 };
enum { kRegionValue330_32C = 0x32c };
enum { kRegionValue334_330 = 0x330 };
#else
enum { kRegionValue1F7_1F3 = 0x1f7 };
enum { kRegionValue1FC_1F8 = 0x1fc };
enum { kRegionValue330_32C = 0x330 };
enum { kRegionValue334_330 = 0x334 };
#endif


extern "C" float _fflt(int v);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float v);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" void func_ov017_021c9e00(int id, int flagA, int flagB, int flagC);

// USA: func_ov003_02155740  (semantic: RescaleCombatantSizeTarget_02155740)
// JPN: func_ov003_02156dc4
extern "C" ARM void func_ov003_02155740(char* obj) {
    GameState* battle = GameState::GetInstance();
    signed char idx = *(signed char*)(obj + kRegionValue1F7_1F3);
    GameObject* c = battle->GetPartyMemberByIndex(idx);
    if (c == 0) {
        return;
    }

    if (*(int*)(obj + kRegionValue1FC_1F8) & 1) {
        unsigned short* src = *(unsigned short**)((char*)c + 0x134);
        unsigned short w = src[0x30 / 2];
        int v1 = _ffix(_fmul(*(float*)(obj + kRegionValue330_32C), _fflt(w)));
        unsigned short h = src[0x32 / 2];
        int v2 = _ffix(_fmul(*(float*)(obj + kRegionValue334_330), _fflt(h)));

        if (v1 <= 0) v1 = 1;
        if (v2 <= 0) v2 = 0;
        if (w < v1) v1 = w;
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = (unsigned short)v1;
        if (h < v2) v2 = h;
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = (unsigned short)v2;
    } else {
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x30);
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x32);
    }

    void* ptr = func_0202ae18();
    if (CheckField0NonZero((int*)ptr) == 0) {
        return;
    }
    signed char id2 = *(signed char*)(obj + kRegionValue1F7_1F3);
    func_ov017_021c9e00(id2, 1, 0, 1);
}
