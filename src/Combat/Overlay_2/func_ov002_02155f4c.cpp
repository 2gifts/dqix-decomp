#include "System/ColorEffects.h"
#include <globaldefs.h>

struct Container021e76a8;
struct Obj0205d2bc;
struct SelfState020e2834;
struct Outer020e28dc;
struct Entry020e2cc4;

extern "C" void _Z29CallInitEntriesIfSet_021e76a8P17Container021e76a8(Container021e76a8 *c);
extern "C" void _Z30CallDispatchIfFlagSet_021eb4f4Pc(char *p);
extern "C" void func_ov013_02184aec(void *p);
extern "C" void _Z19InitEntries0205d2bcP11Obj0205d2bc(Obj0205d2bc *o);
void SetFieldsAt0x4And0x8(int *p, int a, int b);
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(Outer020e28dc *o);
extern "C" void _Z23SetEntryEnabled020e2cc4P13Entry020e2cc4i(Entry020e2cc4 *e, int enabled);
extern "C" void _Z29SetYesNoButtonPalette020e2834P17SelfState020e2834(SelfState020e2834 *s);

struct Button02155f4c {
    char unk_0[0x10];
    char *panel;
};

struct State02155f4c {
    Button02155f4c *buttons[2];
};

// USA: func_ov002_02155f4c
extern "C" ARM void func_ov002_02155f4c(State02155f4c *self) {
    char *base = (char *) self;
    if (*(unsigned char *) (base + 0x1cc3) != 0) {
        _Z29CallInitEntriesIfSet_021e76a8P17Container021e76a8((Container021e76a8 *) (base + 0x8b4));
    }
    if (*(char **) (base + 0x2468) != 0) {
        _Z30CallDispatchIfFlagSet_021eb4f4Pc(*(char **) (base + 0x2468));
    }
    int mode = *(int *) (base + 0x1bb8);
    if (mode != 0 && mode == 0x1e && *(int *) (base + 0x1bc0) > 4) {
        func_ov013_02184aec(base + 0x1d70);
    }
    if (*(int *) (base + 0x1bb8) != 0x1e) {
        _Z19InitEntries0205d2bcP11Obj0205d2bc((Obj0205d2bc *) (base + 0xec8));
    }
    if (self->buttons[0] != 0) {
        if (*(char **) (base + 0x2468) == 0) {
            ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
        }
        int *panel = (int *) (self->buttons[0]->panel + 0x28);
        SetFieldsAt0x4And0x8(panel, 0x11, 1);
        _Z23SetEntryEnabled020e2cc4P13Entry020e2cc4i(
            (Entry020e2cc4 *) panel, _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc((Outer020e28dc *) self->buttons[0]));
        _Z29SetYesNoButtonPalette020e2834P17SelfState020e2834((SelfState020e2834 *) self->buttons[0]);
    }
    if (self->buttons[1] != 0) {
        int *panel = (int *) (self->buttons[1]->panel + 0x28);
        SetFieldsAt0x4And0x8(panel, 0x11, 1);
        _Z23SetEntryEnabled020e2cc4P13Entry020e2cc4i(
            (Entry020e2cc4 *) panel, _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc((Outer020e28dc *) self->buttons[1]));
        _Z29SetYesNoButtonPalette020e2834P17SelfState020e2834((SelfState020e2834 *) self->buttons[1]);
    }
}
