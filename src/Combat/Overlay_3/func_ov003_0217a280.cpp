#include <globaldefs.h>

struct Obj2081 {
    char unk_0[0x36];
    short selected;
};
int HasElementByByte0xc4(struct Obj2081* obj, int key);
short FindMappedMemberId02080468(void* obj, int id);
extern "C" void func_020813ec(void* obj, int key);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void CallFunc0204c804OnMatchingKey(struct Obj2081* obj, int key);

struct Obj0208203c;
void ResetWithSub0208203c(struct Obj0208203c* obj);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);

struct Menu_0217a280 {
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
    char unk_100e[4];
    short field1012;
    char unk_1014[0x1036 - 0x1014];
    short nextState;
    char unk_1038[6];
    unsigned char mode;
    unsigned char step;
    char unk_1040[6];
    unsigned short flags;
};

// USA: func_ov003_0217a280
extern "C" ARM void func_ov003_0217a280(struct Menu_0217a280* self) {
    struct Obj2081* menu = self->menu;
    if (self->step == 0) {
        self->key = 2;
        if (HasElementByByte0xc4(menu, self->key) == 0) {
            if (self->member1004 < 0) {
                self->member1004 = FindMappedMemberId02080468(menu, self->key);
            }
            menu->selected = self->member1004;
            func_020813ec(menu, self->key);
            SetEntryLowNibbleAndElement02080c68(menu, self->key, 1);
            self->prevKey = self->key;
        }
        self->key = 0x10;
        if (self->member100c < 0) {
            self->member100c = FindMappedMemberId02080468(menu, self->key);
        }
        menu->selected = self->member100c;
        func_020813ec(menu, self->key);
        ResetWithSub0208203c((struct Obj0208203c*)self->repeat);
        self->cursor = 0;
        self->step++;
    } else if (self->step == 1) {
        self->cursor = &self->member100c;
        if (func_ov003_021765b4(self)) {
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)self->repeat);
            self->cursor = 0;
            switch (self->member100c) {
            case 0x76:
                self->prevKey = self->key;
                self->nextState = 0xb;
                self->mode = 4;
                self->step = 0;
                self->flags |= 0x20;
                break;
            case 0x77:
                self->prevKey = self->key;
                self->nextState = 0xc;
                self->mode = 7;
                self->step = 0;
                self->field1012 = -1;
                self->flags |= 0x20;
                break;
            }
        } else if (func_ov003_021766e8(self)) {
            ResetWithSub0208203c((struct Obj0208203c*)self->repeat);
            self->cursor = 0;
            self->nextState = 0xa;
            self->mode = 1;
            self->step = 0;
            CallFunc0204c804OnMatchingKey(menu, self->key);
        }
    }
}
