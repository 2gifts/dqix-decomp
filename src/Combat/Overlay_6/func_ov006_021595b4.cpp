#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#define func_ov006_021547c8 func_ov006_02155f30
#define func_ov006_021570fc func_ov006_02158704
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj2081;
struct Obj0205eaa0;

struct AlchemyPot {
    char unk_0[R(0x1054, 0x1258)];
    unsigned short windowFlags_;
};

struct AlchemyMenu {
    char unk_0[R(8, 0x10)];
    AlchemyPot* pot_;
    Obj2081* menu_;
    char unk_18[0x2c];
    short* cursor_;
    char unk_48[0xb8];
    char layout_[R(0x286, 0x27e)];
    short message_;
    char unk_380[0xc];
    unsigned char chosenCounts_[3];
    unsigned char state_;
    unsigned char step_;
    unsigned char unk_391;
    unsigned char messageStep_;
    unsigned char repeatDelay_;
    unsigned short flags_;
};

extern "C" short func_ov023_021e29d0(void* layout);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
extern "C" void func_ov006_0215f4dc(AlchemyMenu* self);
void SetElementFlag0x40(Obj2081* menu, int group, int flag);
extern "C" void func_ov006_021570fc(AlchemyPot* pot, int show);
extern "C" unsigned char _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* sound, int effect, int unk);

extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

// USA: func_ov006_021595b4
extern "C" ARM int func_ov006_021595b4(AlchemyMenu* self) {
    short element = func_ov023_021e29d0(self->layout_);
    int names = element == 0x78 ? 1 : 0;
    int window = element == 0x25 ? 1 : 0;
    if (self->chosenCounts_[0] > 1 || self->chosenCounts_[1] >= 1) {
        names = (names | TestFlag0SetAndFlag1Clear(data_02114e30, 0x400)) ? 1 : 0;
        if (names) {
            self->cursor_ = 0;
            self->state_ = 7;
            self->step_ = 6;
            func_ov006_0215f4dc(self);
            SetElementFlag0x40(self->menu_, 0x10, 1);
            self->flags_ &= ~0x10;
            self->flags_ |= 0x20;
            self->message_ = 0xa;
            self->messageStep_ = 0;
            return 1;
        }
    }
    if (names)
        return 1;
    if (self->flags_ & 0x10) {
        if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x300) || window) {
            AlchemyPot* pot = self->pot_;
            func_ov006_021570fc(pot, (pot->windowFlags_ & 0x800) ? 0 : 1);
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            return 1;
        }
    }
    return 0;
}
