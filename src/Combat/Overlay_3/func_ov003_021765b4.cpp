#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue36_2A = 0x2a };
enum { kRegionValue89C_818 = 0x818 };
enum { kRegionValueFF8_F74 = 0xf74 };
enum { kRegionValue8A0_81C = 0x81c };
enum { kRegionValueFFE_F7A = 0xf7a };
enum { kRegionValueFFC_F78 = 0xf78 };
#else
enum { kRegionValue36_2A = 0x36 };
enum { kRegionValue89C_818 = 0x89c };
enum { kRegionValueFF8_F74 = 0xff8 };
enum { kRegionValue8A0_81C = 0x8a0 };
enum { kRegionValueFFE_F7A = 0xffe };
enum { kRegionValueFFC_F78 = 0xffc };
#endif


struct Outer020e28dc;

struct Menu {
    char unk_0[kRegionValue36_2A];
    short cursor_;
};

extern "C" {
extern unsigned short data_02114e30[];
extern unsigned char data_02114e54[];
void func_020813ec(Menu*, int);
}

int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(Outer020e28dc*);
int GetField0x15UnlessInactive(signed char*);
void SelectCoordsByFlag0x24(unsigned char*, int*, int*);
extern "C" int _Z26RunAndCheckFlagBit02080dd4PviiiPhh(void*, int, int, int, unsigned char*, unsigned char);

struct Ctx021765b4 {
    Outer020e28dc* choice_;
    char pad0[kRegionValue89C_818 - 0x4];
    Menu* menu_;
    char pad1[kRegionValueFF8_F74 - kRegionValue8A0_81C];
    short* cursor_;
    char pad2[kRegionValueFFE_F7A - kRegionValueFFC_F78];
    short group_;
    short previousCursor_;
};

// USA: func_ov003_021765b4
// JPN: func_ov003_02175604
extern "C" ARM unsigned char func_ov003_021765b4(Ctx021765b4* self)
{
    unsigned char confirmed = 0;
    if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x401))
        confirmed = 1;
    if (self->choice_ != 0 && _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(self->choice_))
    {
        int choice = GetField0x15UnlessInactive((signed char*)self->choice_);
        if (choice >= 0)
        {
            confirmed = 1;
            *self->cursor_ = choice + 2;
        }
    }
    else if (data_02114e54[0x55] && self->cursor_ != 0)
    {
        int x;
        int y;
        Menu* menu = self->menu_;
        SelectCoordsByFlag0x24(data_02114e54, &x, &y);
        self->previousCursor_ = *self->cursor_;
        int item = _Z26RunAndCheckFlagBit02080dd4PviiiPhh(menu, self->group_, (short)x, (short)y, &confirmed, 1);
        if (item < 0)
            return 0;
        *self->cursor_ = item;
        short cursor = *self->cursor_;
        if (self->previousCursor_ != cursor)
        {
            menu->cursor_ = cursor;
            func_020813ec(menu, self->group_);
        }
    }
    return confirmed;
}
