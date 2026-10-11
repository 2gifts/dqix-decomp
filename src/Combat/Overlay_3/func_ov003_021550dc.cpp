#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue36_2A = 0x2a };
enum { kRegionValue1E6_1E2 = 0x1e2 };
#else
enum { kRegionValue36_2A = 0x36 };
enum { kRegionValue1E6_1E2 = 0x1e6 };
#endif


struct Outer020e28dc;

struct Menu {
    char unk_0[kRegionValue36_2A];
    short cursor_;
};

extern unsigned short data_02114e30;
extern unsigned char data_02114e54;

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(struct Outer020e28dc* o);
int GetField0x15UnlessInactive(signed char* param);
void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);
extern "C" int _Z26RunAndCheckFlagBit02080dd4PviiiPhh(void* obj, int p1, int unused2, int unused3, unsigned char* outFlag, unsigned char extra);
extern "C" void func_020813ec(void* obj, int key);

struct Ctx021550dc {
    char unk_0[0x8];
    short* cursor_;
    char unk_c[0x18 - 0xc];
    Menu* menu_;
    Outer020e28dc* choice_;
    char unk_20[kRegionValue1E6_1E2 - 0x20];
    short group_;
    short previousCursor_;
};

// USA: func_ov003_021550dc
// JPN: func_ov003_021567c4
extern "C" ARM unsigned char func_ov003_021550dc(Ctx021550dc* self) {
    unsigned char confirmed = 0;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x401)) {
        confirmed = 1;
    }
    if (self->choice_ != NULL && _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(self->choice_)) {
        int choice = GetField0x15UnlessInactive((signed char*)self->choice_);
        if (choice >= 0) {
            confirmed = 1;
            *self->cursor_ = choice + 6;
        }
    } else if ((&data_02114e54)[0x55] != 0 && self->cursor_ != NULL) {
        Menu* menu = self->menu_;
        int x, y;
        SelectCoordsByFlag0x24(&data_02114e54, &x, &y);
        self->previousCursor_ = *self->cursor_;
        int item = _Z26RunAndCheckFlagBit02080dd4PviiiPhh(menu, self->group_, (short)x, (short)y, &confirmed, 1);
        if (item < 0) {
            return 0;
        }
        *self->cursor_ = item;
        short cursor = *self->cursor_;
        if (self->previousCursor_ != cursor) {
            menu->cursor_ = cursor;
            func_020813ec(menu, self->group_);
        }
    }
    return confirmed;
}
