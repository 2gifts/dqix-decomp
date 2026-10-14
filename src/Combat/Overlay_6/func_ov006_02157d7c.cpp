#include <globaldefs.h>

#if defined(jpn)
enum { kPot = 8, kFlags = 0x962, kButtons = 0xa0, kMenuCursor = 0x2a };
#else
enum { kPot = 0x10, kFlags = 0xae2, kButtons = 0xa8, kMenuCursor = 0x36 };
#endif

struct Obj0207fc6c;
struct Obj2081;
struct Outer020e28dc;
struct Ctx020e263c;

extern "C" int func_ov017_021959b4(void);
void SetFlags_021585ac_021585ac(void* p);
int IsAnimationActive0209ca2c(void* obj);
extern char data_02109bf4[];
extern "C" void func_ov006_021549ac(void* pot, int ticks);
void CallFunc0204c87cOverEntries0207fc6c(struct Obj0207fc6c* obj, int arg);
extern "C" void func_ov006_0215a00c(void* self, int n);
int CheckFlagOrByte55_02158c70();
void CallFunc0204c804OnMatchingKey_0207fdcc(struct Obj2081* obj, int key);
extern "C" unsigned short func_02081f20(void* obj, int ticks);
extern "C" int func_020800fc(void* obj, short* key, short a, unsigned short b, unsigned char c, int d);
int ClearSublistEntriesFlag4_020804fc(void* obj, int id);
extern "C" int func_020813ec(void* obj, int id);
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
void UpdateEntryStateAndPosition(struct Ctx020e263c* c, int key);

typedef int (*CheckFlag55Fn)(void* self);

struct Obj02157d7c {
    char pad0[kPot];
    void* pot_;
    void* menu_;
    void* outer_;
    char pad1c[0x44 - 0x1c];
    short* f44;
    char pad48[0x9c - 0x48];
    char sub9c[0xa8 - 0x9c];
    unsigned short fa8;
    unsigned char faa;
    char padab[0x300 - kButtons - 3];
    char pad300[0x34c - 0x300];
    int f34c;
    int f350;
    char pad354[0x38f - 0x354];
    unsigned char f38f;
    unsigned char f390;
    char pad391[0x42c - 0x391];
    signed char f42c;
    char pad42d[0x42f - 0x42d];
    unsigned char f42f;
    char pad430[0x433 - 0x430];
    unsigned char f433;
};

typedef void (Obj02157d7c::*PMF02157d7c)();
struct HandlerTable02157d7c { PMF02157d7c e[14]; };
extern struct HandlerTable02157d7c data_ov006_021601fc;
extern PMF02157d7c data_020e6d5c;
extern int data_ov006_02160398;

// USA: func_ov006_02157d7c
extern "C" ARM int func_ov006_02157d7c(struct Obj02157d7c* self, int arg)
{
    self->f34c = arg;
    if (func_ov017_021959b4() != 0)
        SetFlags_021585ac_021585ac(self);

    if ((*(unsigned short*)((char*)self + 0x300 + 0x94) & 0x200) == 0)
    {
        if (self->f433 != 0)
        {
            if (self->f44 != 0)
                *self->f44 = -1;
            self->f44 = 0;
            self->f38f = 0xc;
            self->f390 = 0;
            self->f433 = 0;
        }
    }

    unsigned int s = self->f38f;
    if (((s <= 4) ? 1 : 0) > s)
    {
    }
    else
    {
        self->f42c = (signed char)(((signed char*)((char*)self + 0x400))[0x2c] + arg);
        self->f42c = (signed char)(((signed char*)((char*)self + 0x400))[0x2c] & 0x3f);
    }

    if (IsAnimationActive0209ca2c(data_02109bf4) == 0)
        self->f42f = 0;

    func_ov006_021549ac(self->pot_, arg);

    Obj0207fc6c* menu = (Obj0207fc6c*)self->menu_;
    if (menu != 0)
        CallFunc0204c87cOverEntries0207fc6c(menu, arg);

    if (*(short*)((char*)self + 0x300 + 0x7e) >= 0)
    {
        self->f42c = 0;
        func_ov006_0215a00c(self, 0);
        return 0;
    }

    if (*(unsigned short*)((char*)self + 0x300 + 0x94) & 0x100)
    {
        if (((CheckFlag55Fn)CheckFlagOrByte55_02158c70)(self) != 0)
        {
            CallFunc0204c804OnMatchingKey_0207fdcc((Obj2081*)menu, 0);
            CallFunc0204c804OnMatchingKey_0207fdcc((Obj2081*)menu, 1);
            *(unsigned short*)((char*)self + 0x300 + 0x94) &= ~0x100;
        }
        return 0;
    }

    if (*(unsigned short*)((char*)self->pot_ + kFlags) & 0x380)
    {
        self->f42c = 0;
        return 0;
    }

    if (self->f44 != 0)
    {
        func_02081f20(self->sub9c, arg);
        *(short*)((char*)self + 0x300 + 0x5e) = *self->f44;
        self->f350 = func_020800fc(menu, self->f44, *(short*)((char*)self + 0x300 + 0x5e),
                                   *(unsigned short*)((char*)self + kButtons),
                                   *(unsigned char*)((char*)self + kButtons + 2),
                                   (*(unsigned short*)((char*)self + 0x300 + 0x94) & 4) != 0);
        *(short*)((char*)menu + kMenuCursor) = *self->f44;
        if (self->f350 != 0)
            ClearSublistEntriesFlag4_020804fc(menu, *(short*)((char*)self + 0x300 + 0x6e));
        if (*(short*)((char*)self + 0x300 + 0x5e) != *self->f44)
            func_020813ec(menu, *(short*)((char*)self + 0x300 + 0x6e));
    }

    if (self->outer_ != 0)
    {
        if (GetInnerFlagBit0020e28dc((struct Outer020e28dc*)self->outer_) != 0)
            UpdateEntryStateAndPosition((struct Ctx020e263c*)self->outer_, self->f34c);
    }

    if ((data_ov006_02160398 & 1) == 0)
    {
        data_ov006_021601fc.e[13] = data_020e6d5c;
        data_ov006_02160398 |= 1;
    }

    if (data_ov006_021601fc.e[self->f38f] == 0)
        return 1;

    (self->*data_ov006_021601fc.e[self->f38f])();
    return 0;
}
