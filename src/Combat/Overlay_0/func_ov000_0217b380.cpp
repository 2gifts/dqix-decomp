#include <globaldefs.h>
#include "Util/Random.h"

struct BattleMenu0217b380 {
#if defined(jpn)
    char pad0[0x1faa];
#else
    char pad0[0x1d72];
#endif
    unsigned short flags;
};

struct Data0217b380 {
#if defined(jpn)
    struct BattleMenu0217b380* menu;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    struct BattleMenu0217b380* menu;
#endif
};
extern struct Data0217b380 data_ov000_02184294;

struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
int GetClampedArrayField0xd1c(char* base, int index);
int CountMatchingValues02175348(void* obj, int value);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
int CheckFlagsOrField_0217ab48_0217ab48(void* obj);
extern "C" void func_ov000_02170db0(void* obj);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* menu, void* obj, int state, int arg1, int arg2, int flag);

extern unsigned short data_02114e30;
extern struct Obj0205eaa0 data_02108760;

struct MenuState0217b380 {
    char pad0[0x10];
    signed char stack[8];
    signed char stackTop;
    char pad19[4];
    signed char selection;
    char pad1e[0x1a];
    struct Struct_0205c570* window;
};

// USA: func_ov000_0217b380
extern "C" ARM int func_ov000_0217b380(struct MenuState0217b380* self, int arg1, int arg2) {
    data_ov000_02184294.menu->flags |= 0x100;
    int base = GetActiveScaledSum0205d794(self->window);
    self->selection = base;
    int pressed = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int confirm = (pressed | IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)self->window, 0x14)) != 0;
    if (confirm) {
        if (IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)self->window, 0x14)) {
            int value = GetClampedArrayField0xd1c((char*)data_ov000_02184294.menu, base);
            int matches = CountMatchingValues02175348(data_ov000_02184294.menu, value);
            self->selection = NextRandomMax(GetBTRandom(), matches * 100) / 100 + (signed char)base;
        }
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        self->stackTop++;
        self->stack[self->stackTop] = 100;
        func_ov000_02170db0(self);
    } else if (CheckFlagsOrField_0217ab48_0217ab48(self)) {
        func_ov000_0217629c(self);
        self->stack[self->stackTop] = 0;
        self->stackTop--;
        self->selection = -1;
        func_ov000_0217ab8c(self, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.menu, self, self->stack[self->stackTop],
                            data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
