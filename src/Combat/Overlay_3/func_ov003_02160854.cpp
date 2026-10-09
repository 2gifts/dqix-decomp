#include <globaldefs.h>
#include "GameState/GameState.h"

struct Outer020e28dc;

struct Menu02160854 {
    char unk_0[0x36];
    short cursor_;
};

struct Ctx02160854 {
    char pad0[0x324];
    Menu02160854* menu_;
    char pad1[0x390 - 0x328];
    Outer020e28dc* choice_;
    char pad2[0x470 - 0x394];
    short* cursor_;
    short previousCursor_;
    char pad3[0x488 - 0x476];
    short group_;
};

int GetWord0x0(int* obj);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int _Z27IsFieldNotPositive_021a4e70Ph(unsigned char* base);
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(Outer020e28dc* o);
int GetField0x15UnlessInactive(signed char* obj);
void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);
extern "C" int _Z26RunAndCheckFlagBit02080dd4PviiiPhh(void* obj, int p1, int p2, int p3, unsigned char* outFlag, unsigned char extra);

extern "C" {
extern unsigned short data_02114e30[];
extern unsigned char data_02114e54[];
extern short data_ov003_0217f484[];
extern short data_ov003_0217f426[];
void func_02080558(void* obj, int p1, int result, int flag, unsigned char extra);
void func_020813ec(Menu02160854* menu, int group);
void func_ov003_02160794(void* self);
}

// USA: func_ov003_02160854
extern "C" ARM unsigned char func_ov003_02160854(Ctx02160854* self) {
    unsigned char confirmed = 0;
    unsigned char* battleWord = (unsigned char*)GetWord0x0((int*)GameState::GetInstance());
    if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x401)) {
        if (_Z27IsFieldNotPositive_021a4e70Ph(battleWord)) {
            confirmed = 1;
        }
    }

    if (_Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(self->choice_)) {
        int choice = GetField0x15UnlessInactive((signed char*)self->choice_);
        if (choice >= 0) {
            confirmed = 1;
            *self->cursor_ = choice + 0x2c;
        }
    } else if (data_02114e54[0x55] && self->cursor_ != 0) {
        int x;
        int y;
        Menu02160854* menu = self->menu_;
        SelectCoordsByFlag0x24(data_02114e54, &x, &y);
        int item = _Z26RunAndCheckFlagBit02080dd4PviiiPhh(menu, self->group_, (short)x, (short)y, &confirmed, 0);
        if (item < 0)
            return 0;

        int i = 0;
        for (;;) {
            short lo = data_ov003_0217f484[i];
            if (lo < 0)
                break;
            i++;
            if (lo > item || item > data_ov003_0217f484[i++])
                continue;
            func_02080558(menu, self->group_, (short)(item + 4), 0, 0);
            func_02080558(menu, self->group_, (short)(item + 8), 0, 0);
            short base = data_ov003_0217f426[(i >> 1) - 1];
            if (base < 0)
                continue;
            func_02080558(menu, self->group_, (short)(base + (item - lo)), 0, 0);
        }

        *self->cursor_ = item;
        short cursor = *self->cursor_;
        if (self->previousCursor_ != cursor)
            menu->cursor_ = cursor;
        func_020813ec(menu, self->group_);
        func_ov003_02160794(self);
    }
    return confirmed;
}
