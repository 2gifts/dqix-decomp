#include <globaldefs.h>
#include "GameState/GameState.h"

class GameState;
struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Obj0205eaa0;

void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *o, int a, int b);
int TestFlag0SetAndFlag1Clear(unsigned short *flags, int mask);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
void SetElementFieldC2(struct Struct_0205d81c *s, int key, int value);
void *GetPtrField0x2a04(GameState *gs);
unsigned char *GetFieldAt0x150(unsigned char *c);
extern "C" void func_ov002_02161cf0(void *self);
extern "C" void func_ov002_0215fb54(void *self);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
extern "C" void func_ov002_02156e90(void *self);
extern unsigned short data_02114e30;
extern char data_02108760[];

// USA: func_ov002_02167eb0
extern "C" ARM void func_ov002_02167eb0(char *base) {
    int phase = *(int *) (base + 0x1bc0);
    if (phase == 0) {
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0xec8), 0, 3);
        func_ov002_02161cf0(base);
        func_ov002_0215fb54(base);
        (*(int *) (base + 0x1bc0))++;
        return;
    }
    if (phase != 1) return;
    *(int *) (base + 0x247c) |= 4;
    short old                  = *(short *) (base + 0x1c04);
    *(short *) (base + 0x1c04) = GetActiveScaledSum0205d794((struct Struct_0205c570 *) (base + 0xec8));
    if (old != *(short *) (base + 0x1c04)) return;
    int pressed = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int confirm = (pressed | IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(base + 0xec8), 0x14)) ? 1 : 0;
    if (confirm) {
        func_ov002_0215b9a4(base, *(int *) (base + 0x1bb8) & 0xff, 1);
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 1, 0);
        GameState *gs = GameState::GetInstance();
        GetPtrField0x2a04(gs);
        unsigned char *m = (unsigned char *)gs->GetPartyMemberByIndex(*(signed char *) (base + 0x1c20));
        if (m == 0) return;
        *(int *) (GetFieldAt0x150(m) + 0x94c) = *(short *) (base + 0x1c04);
        *(short *) (base + 0x1c04)            = -1;
        func_ov002_02156e90(base);
        SetElementFieldC2((struct Struct_0205d81c *) (base + 0xec8), 0x1a, 0);
        SetElementFieldC2((struct Struct_0205d81c *) (base + 0xec8), 0x1b, 0);
        return;
    }
    if (CheckFlagOrThreshold_02161b48(base, 1)) {
        *(short *) (base + 0x1c04) = -1;
        func_ov002_02156e90(base);
        SetElementFieldC2((struct Struct_0205d81c *) (base + 0xec8), 0x1a, 0);
        SetElementFieldC2((struct Struct_0205d81c *) (base + 0xec8), 0x1b, 0);
    }
}
