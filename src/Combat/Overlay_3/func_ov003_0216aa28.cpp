#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Grid0216aa28 {
    char pad0[0x30];
    int cursor;
    char pad34[0x50 - 0x34];
};

struct GridList0216aa28 {
    int header;
    struct Grid0216aa28 grids[2];
};

struct TouchState_02114e54 {
    char unk_0[0x24];
    unsigned short field_0x24;
    char unk_26[0x5f - 0x26];
    unsigned char field_0x5f;
};

struct Container020e0310;
struct StructA0205d5d0;

struct Menu0216aa28 {
    char pad0[0x64];
    char names[0x7c - 0x64];
    char* textBuf;
    char pad80[0xe4 - 0x80];
    struct GridList0216aa28 list;
    char pad188[0x194 - 0x188];
    unsigned char layout;
    char pad195[0x4ea - 0x195];
    unsigned char pendingMode;
    unsigned char pendingReset;
    char pad4ec[0x56c - 0x4ec];
    int selection;
};

struct Ptr2a04_0216aa28 {
    char pad0[0xf6c];
    int value;
};

struct StoreStruct;

extern struct TouchState_02114e54 data_02114e54;

extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
extern "C" void func_ov003_02169a84(struct Menu0216aa28* menu, char* dst, int flag);
extern "C" void func_ov003_02169d10(struct Menu0216aa28* menu, char* dst, int flag);
extern "C" struct StoreStruct* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(struct StoreStruct* g);
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex(unsigned char* base, int index, unsigned char value);

static inline struct Grid0216aa28* GetGrid(void* list) {
    struct Grid0216aa28* grid = ((struct GridList0216aa28*)list)->grids;
    return grid;
}

// USA: func_ov003_0216aa28
extern "C" ARM void func_ov003_0216aa28(struct Menu0216aa28* menu) {
    unsigned char mode = menu->pendingMode;
    if (mode != 0) {
        int flag = 0;
        if (mode == 2) {
            if (data_02114e54.field_0x5f != 0 && data_02114e54.field_0x24 != 0) {
                if (GetGrid(&menu->list)->cursor >= 0) {
                    flag = 1;
                } else if (menu->selection >= 0) {
                    flag = 1;
                } else {
                    return;
                }
            }
        } else if (mode == 4) {
            flag = 1;
        }
        memset(menu->textBuf, 0, 0x960);
        unsigned char layout = menu->layout;
        switch (layout) {
        case 1:
            func_ov003_02169a84(menu, menu->textBuf, flag);
            break;
        case 2:
            func_ov003_02169d10(menu, menu->textBuf, flag);
            break;
        }
        if (layout == 2) {
            _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)&menu->list, layout, (int)menu->textBuf, 0, 1);
        } else {
            _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)&menu->list, layout, (int)menu->textBuf, 1, 0);
        }
    }
    if (menu->pendingReset == 0) {
        return;
    }
    GameState* gs = GameState::GetInstance();
    struct StoreStruct* g = _Z26GetGlobalField0x1c020421a0v();
    struct Ptr2a04_0216aa28* p = (struct Ptr2a04_0216aa28*)GetPtrField0x2a04(gs);
    memset(menu->textBuf, 0, 0x960);
    _Z20AppendString02042058PcPKc(menu->textBuf, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)menu->names, 0x65));
    func_02046380(g);
    StoreInArray0x8b0(g, 0, p->value);
    SetByteInRange((unsigned char*)g, 0, 7);
    SetByteAtIndex((unsigned char*)g, 0, 1);
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)&menu->list, 0, (int)menu->textBuf, 1, 0);
    menu->pendingReset = 0;
}
