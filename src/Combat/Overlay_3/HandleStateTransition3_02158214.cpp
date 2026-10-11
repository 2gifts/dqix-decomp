#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue1F9_1F5 = 0x1f5 };
enum { kRegionValue32C_328 = 0x328 };
enum { kRegionValue1EE_1EA = 0x1ea };
enum { kRegionValue1EC_1E8 = 0x1e8 };
enum { kRegionValue204_200 = 0x200 };
enum { kRegionValue200_1FC = 0x1fc };
enum { kRegionValue1F8_1F4 = 0x1f4 };
#else
enum { kRegionValue1F9_1F5 = 0x1f9 };
enum { kRegionValue32C_328 = 0x32c };
enum { kRegionValue1EE_1EA = 0x1ee };
enum { kRegionValue1EC_1E8 = 0x1ec };
enum { kRegionValue204_200 = 0x204 };
enum { kRegionValue200_1FC = 0x200 };
enum { kRegionValue1F8_1F4 = 0x1f8 };
#endif


int GetWord0x0(int* obj);
int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);

struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);

extern "C" void _Z16SetSubBrightnessP13GameResourcesii(int obj, int value, int frames);
extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(int* obj);
void InitFlags_021eb414(char* obj);
extern "C" void func_ov023_021eb43c(void* obj);
extern "C" void func_ov023_021eb26c(void* obj);

// USA: func_ov003_02158214
// JPN: func_ov003_02159700
extern "C" ARM void func_ov003_02158214(void* p) {
    char* self = (char*)p;
    GameState* bs = GameState::GetInstance();
    int word0 = GetWord0x0((int*)bs);
    unsigned char state = *(unsigned char*)(self + kRegionValue1F9_1F5);

    if (state == 0) {
        *(int*)(self + kRegionValue32C_328) = 0;
        ReinitController02043204((char*)GetGlobalField0x1c020421a0());

        *(short*)(self + kRegionValue1EE_1EA) = -1;
        *(short*)(self + kRegionValue1EC_1E8) = *(short*)(self + kRegionValue1EE_1EA);

        if (*(void**)(self + 0x1c) != 0 &&
            GetInnerFlagBit0020e28dc((struct Outer020e28dc*)*(void**)(self + 0x1c)) != 0) {
            ResetSelectionState020e25e8((struct Obj020e25e8*)*(void**)(self + 0x1c));
        }

        unsigned char newState = 3;
        *(unsigned char*)(self + kRegionValue1F9_1F5) = newState;
        if (*(void**)(self + kRegionValue204_200) == 0) return;
        _Z16SetSubBrightnessP13GameResourcesii(word0, newState - 0x13, 0);
        *(unsigned char*)(self + kRegionValue1F9_1F5) = 1;
        return;
    }

    if (state == 1) {
        if (_Z31IsSubBrightnessTransitionActiveP13GameResources((int*)word0) != 0) return;
        InitFlags_021eb414(*(char**)(self + kRegionValue204_200));
        *(unsigned char*)(self + kRegionValue1F9_1F5) = 2;
        return;
    }

    if (state == 2) {
        func_ov023_021eb43c(*(void**)(self + kRegionValue204_200));
        if (*(unsigned short*)(*(char**)(self + kRegionValue204_200) + 0x438) & 4) {
            func_ov023_021eb26c(*(void**)(self + kRegionValue204_200));
            ((SafeAllocator*)(*(char**)(self + 0) + 0x64))->Reset();
            *(int*)(self + kRegionValue204_200) = 0;
            *(int*)(self + kRegionValue200_1FC) = 0;
            *(unsigned char*)(self + kRegionValue1F9_1F5) = 3;
        }
        return;
    }

    if (state == 3) {
        *(unsigned char*)(self + kRegionValue1F8_1F4) = 5;
        *(unsigned char*)(self + kRegionValue1F9_1F5) = 0;
    }
}
