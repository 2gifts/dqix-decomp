#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj2081 {
    char unk_0[0x36];
    short selected;
};

struct Cont0207fdf0;
struct Obj0205eaa0;
struct Obj0208203c;

void* GetPtrField0x2a04(GameState* gs);
void CallFunc0204c804OnNonMatchingKey(struct Cont0207fdf0* obj, int key);
extern "C" void func_ov003_021749c0(char* base);
short FindMappedMemberId02080468(void* obj, int id);
extern "C" void func_ov003_02177820(void* self);
extern "C" void func_ov003_02177938(void* self);
void SetElementFlag0x40(struct Obj2081* obj, int id, int value);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void ResetWithSub0208203c(struct Obj0208203c* obj);
extern "C" int func_ov003_021765b4(void* self);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern "C" int func_ov003_02179f34(void* self);
extern "C" int func_ov003_021766e8(void* self);
extern struct Obj0205eaa0 data_02108760;

struct Menu_0217a4ac {
    char unk_0[0x88c];
    char repeat[0x89c - 0x88c];
    struct Obj2081* menu;
    char unk_8a0[0xff8 - 0x8a0];
    short* cursor;
    short prevKey;
    short key;
    char unk_1000[4];
    short member1004;
    char unk_1006[6];
    short member100c;
    short member100e;
    short member1010;
    short field1012;
    short member1014;
    short member1016;
    char unk_1018[0x1030 - 0x1018];
    int switchValue;
    char unk_1034[2];
    short nextState;
    char unk_1038[4];
    unsigned char field103c;
    char unk_103d;
    unsigned char mode;
    unsigned char step;
    char unk_1040[3];
    signed char dir1043;
    char unk_1044[2];
    unsigned short flags;
};

// USA: func_ov003_0217a4ac
extern "C" ARM void func_ov003_0217a4ac(struct Menu_0217a4ac* self) {
    GetPtrField0x2a04(GameState::GetInstance());
    struct Obj2081* menu = self->menu;
    if (self->step == 0) {
        self->member1014 = 0;
        self->member1016 = 0;
        CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)menu, 0);
        self->step++;
        return;
    }
    if (self->step == 1) {
        func_ov003_021749c0((char*)self);
        switch (self->switchValue) {
        case 1:
            self->key = 0x11;
            break;
        case 2:
            self->key = 0x12;
            break;
        case 3:
            self->key = 0x13;
            break;
        case 4:
            self->key = 0x14;
            break;
        }
        if (self->member1010 < 0) {
            self->member1010 = FindMappedMemberId02080468(menu, self->key);
        }
        menu->selected = self->member1010;
        func_ov003_02177820(self);
        func_ov003_02177938(self);
        SetElementFlag0x40(menu, self->key, 0);
        SetEntryLowNibbleAndElement02080c68(menu, self->key, 0);
        ResetWithSub0208203c((struct Obj0208203c*)self->repeat);
        self->cursor = 0;
        self->step++;
        return;
    }
    if (self->step == 2) {
        self->cursor = &self->member1010;
        func_ov003_02177938(self);
        SetEntryLowNibbleAndElement02080c68(self->menu, 0x15, 1);
        if (func_ov003_021765b4(self)) {
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)self->repeat);
            self->cursor = 0;
            if (func_ov003_02179f34(self) == 0) {
                short next = 0x13;
                if (self->dir1043 < 0) {
                    next = 0x14;
                }
                self->nextState = next;
                CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)menu, 0);
                self->step = 0;
                self->flags |= 0x20;
                return;
            }
            int mode = 5;
            int inRange = 0;
            if (self->dir1043 >= 0 && self->dir1043 <= 3) {
                inRange = 1;
            }
            if (inRange == 0) {
                mode = 6;
                CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)menu, 0);
            }
            self->mode = mode;
            self->step = 0;
            SetEntryLowNibbleAndElement02080c68(menu, self->key, 1);
            self->prevKey = self->key;
            self->member100e = -1;
            self->field103c = 1;
            return;
        }
        if (!func_ov003_021766e8(self)) {
            return;
        }
        self->cursor = 0;
        CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)menu, 0);
        self->mode = 3;
        self->step = 0;
    }
}
