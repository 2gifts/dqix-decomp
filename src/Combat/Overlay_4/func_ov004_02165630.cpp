#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"

struct Obj021f9bb0;
struct Info02011930;

int GetWord0x0(int* obj);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(int* obj);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov004_02165a1c(void* obj);
extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_0202c540(void* p);
extern "C" unsigned char _Z32GetAndConsumeNameEntries02011930PvP12Info02011930S_S_(void* obj, struct Info02011930* info, void* name1, void* name2);
extern "C" int _Z31GetScaledStat_021634dc_021634dcPv(void* a);
unsigned char CopyToRegion0x6482IfDst(char* obj, void* dst);
extern "C" unsigned int _Z19GetShort28_021f9bb0P11Obj021f9bb0(struct Obj021f9bb0* obj);
extern "C" unsigned int _Z24GetFieldShort36_021f9ba0Pv(void* obj);
int IsGlobalU16InRange(GameState* state);

extern char* data_ov004_02171010;

struct Node02165630 {
    char pad[0x5c];
    short x;
    short y;
    char pad60;
    unsigned char active;
};

// USA: func_ov004_02165630
extern "C" ARM int func_ov004_02165630(void* a) {
#if defined(jpn)
 enum { countOffset = 0x9f4, recordStride = 0x1e4, flagOffset = 0x9fd };
#else
 enum { countOffset = 0x8f4, recordStride = 0x1c4, flagOffset = 0x8fd };
#endif
    if (*(unsigned char*)(data_ov004_02171010 + 0x1000 + countOffset) == 0) return 0;

    Node02165630* node = (Node02165630*)func_ov023_021f6880(func_ov011_021849c8(a), 0xa);
    if (!node || func_ov023_021f6f10(node) != 7) return 0;

    GameState* state = GameState::GetInstance();
    if (_Z28IsBrightnessTransitionActiveP13GameResources((int*)GetWord0x0((int*)state)) != 0) {
        node->active = 0;
        return 0;
    }
    node->active = 1;

    Node02165630* node2 = (Node02165630*)func_ov023_021f6880(func_ov011_021849c8(a), 0xa);
    if (!node2) return 0;
    if (func_ov023_021f6f10(node2) != 7) return 0;

    if (_Z32GetAndConsumeNameEntries02011930PvP12Info02011930S_S_(state, NULL, NULL, NULL) != 0) {
        int idx = _Z31GetScaledStat_021634dc_021634dcPv(a);
        if (((TreasureMapMetadata*)(data_ov004_02171010 + idx * 0x1c))->GetInitialByteUnknownBit()) {
            node->active = 0;
            return 0;
        }
        func_ov011_021848a0(a, 0x68);
    } else if (CopyToRegion0x6482IfDst((char*)state, NULL) != 0) {
        unsigned int k = _Z19GetShort28_021f9bb0P11Obj021f9bb0((struct Obj021f9bb0*)node2);
        if (*(unsigned char*)(data_ov004_02171010 + k * recordStride + 0xad4) != 3) {
            node->active = 0;
        } else {
            func_ov004_02165a1c(a);
        }
    } else {
        void* search = func_0202ae18();
        func_02012fe4();
        if (func_0202c540(search)) {
            func_ov011_021848a0(a, 0x6e);
        } else if (IsGlobalU16InRange(state)) {
            func_ov011_021848a0(a, 0x76);
        } else {
            short x = node2->x;
            unsigned int col = _Z19GetShort28_021f9bb0P11Obj021f9bb0((struct Obj021f9bb0*)node2);
            unsigned short idx = x * _Z24GetFieldShort36_021f9ba0Pv(node2) + col;
            if (((TreasureMapMetadata*)(data_ov004_02171010 + idx * 0x1c))->GetInitialByteUnknownBit()) {
                func_ov011_021848a0(a, 0x74);
            } else {
                *(unsigned char*)(data_ov004_02171010 + 0x1000 + flagOffset) = 1;
                func_ov011_021848a0(a, 0x66);
            }
        }
    }
    return 0;
}
