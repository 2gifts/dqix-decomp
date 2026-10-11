#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue1F7_1F3 = 0x1f3 };
enum { kRegionValue150_144 = 0x144 };
enum { kRegionValue950_8B8 = 0x8b8 };
#else
enum { kRegionValue1F7_1F3 = 0x1f7 };
enum { kRegionValue150_144 = 0x150 };
enum { kRegionValue950_8B8 = 0x950 };
#endif


int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_02083cbc(void* a, void* obj, void* tail);
extern "C" void func_02083e28(void* a, int arg2);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);

extern "C" void func_ov017_021cc730(int id, unsigned char arg1, unsigned char arg2, unsigned char arg3);
extern "C" void func_ov017_021cf078(int combatantId, unsigned short slot, unsigned char flag);
extern "C" void func_ov017_021ccc34(int combatantId);
extern "C" void func_ov017_021c9e00(int id, int flagA, int flagB, int flagC);

// USA: func_ov003_02155e38
// JPN: func_ov003_02157494
extern "C" ARM void func_ov003_02155e38(void* p) {
    char* obj = (char*)p;
    GameState* bs = GameState::GetInstance();
    signed char idx = *(signed char*)(obj + kRegionValue1F7_1F3);
    GameObject* c = bs->GetPartyMemberByIndex(idx);
    if (c == 0) {
        return;
    }
    int t = *(int*)((char*)c + kRegionValue150_144);
    int slot = *(int*)((char*)t + kRegionValue950_8B8);
    int field150 = GetFieldAt0x150((unsigned char*)c);
    char* arr = (char*)field150;
    *(short*)(arr + slot * 2 + 0x16c) = 1;
    unsigned char* cntArr = (unsigned char*)(arr + 0x186);
    *(int*)(arr + slot * 4 + 0x138) = 0;
    unsigned char v = ++cntArr[slot];
    if (v > 10) {
        cntArr[slot] = v = 10;
    }
    func_02083cbc(arr, obj + 0x90, obj + 0xcc);
    func_02083e28(arr, 0);
    *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x30);
    *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x32);
    if (CheckField0NonZero((int*)func_0202ae18()) == 0) {
        return;
    }
    signed char id2 = *(signed char*)(obj + kRegionValue1F7_1F3);
    func_ov017_021cc730(id2, 1, 0, 0);
    func_ov017_021cf078(id2, (unsigned char)slot, 0);
    func_ov017_021ccc34(id2);
    func_ov017_021c9e00(id2, 1, 0, 1);
}
