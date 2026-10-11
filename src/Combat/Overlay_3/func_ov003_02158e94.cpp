#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov003_021594c4 func_ov003_0215a990
#define func_ov003_0215a740 func_ov003_0215bbc0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj0215c300;
extern "C" int _Z32DecrementFieldClampZero_0215c300P11Obj0215c300i(struct Obj0215c300* obj, int amount);
extern "C" void func_ov003_02159464(void* obj);
extern "C" void func_ov003_0215c510(void* obj);

struct Outer020e28dc;
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(struct Outer020e28dc* o);

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xc5];
    unsigned char flagsC5;
};
struct Elem_0205d81c* FindElementForFieldB0(struct Struct_0205d81c* s);
int IsField0x9cEqual3(unsigned char* obj);
void SetFieldAt0x30(void* obj, int value);
extern "C" int func_0205d0e0(void* p, int val);

extern "C" void func_ov003_021594c4(void* obj);
extern "C" void _Z29UpdateHandshakeState_02159b20Pv(void* obj);
extern "C" void func_ov003_02159c04(void* obj);
extern "C" void func_ov003_02159d0c(void* obj, int amount);
extern "C" void func_ov003_0215a5b4(void* obj);
extern "C" void func_ov003_0215a740(void* obj, int amount, int msgId);
extern "C" void _Z28UpdateResponseState_0215af00Pv(void* obj);
extern "C" void func_ov003_0215b1dc(void* obj, int amount);
extern "C" void func_ov003_0215af9c(void* obj);
extern "C" void _Z32UpdateChatResponseState_0215b0e8Pv(void* obj);
extern "C" void func_ov003_0215c0ec(void* obj);

struct Obj02158e94 {
    unsigned char pad0[0xf4];
    unsigned char elements[0x4];
    unsigned char field_0xf8[0x478];
    struct Outer020e28dc* choice;
    int lastAmount;
    unsigned char pad578[0xa];
    unsigned char field_0x582;
    unsigned char pad583[0x4];
    unsigned char field_0x587;
    signed char state;
    unsigned char pad589[0x16];
    unsigned char flags;
};

// USA: func_ov003_02158e94
extern "C" ARM int func_ov003_02158e94(struct Obj02158e94* self, int amount) {
    if (self->state == 11) {
        return 1;
    }

    self->lastAmount = amount;

    if (_Z32DecrementFieldClampZero_0215c300P11Obj0215c300i((struct Obj0215c300*)self, amount) != 0) {
        return 0;
    }

    func_ov003_02159464(self);

    if ((self->flags & 8) && !(self->flags & 0x10)) {
        func_ov003_0215c510(self);
        return 0;
    }

    if (self->choice != 0 && !_Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(self->choice) && self->state != 0 && self->field_0x587 == 0) {
        struct Elem_0205d81c* elem = FindElementForFieldB0((struct Struct_0205d81c*)self->elements);
        if (elem != 0 && IsField0x9cEqual3((unsigned char*)elem) != 0 && (elem->flagsC5 & 2) == 0) {
            SetFieldAt0x30(self->field_0xf8, -1);
        }
        self->field_0x582 = func_0205d0e0(self->elements, amount);
    }

    switch (self->state) {
    case 0:
        func_ov003_021594c4(self);
        break;
    case 1:
        _Z29UpdateHandshakeState_02159b20Pv(self);
        break;
    case 2:
        func_ov003_02159c04(self);
        break;
    case 3:
        func_ov003_02159d0c(self, amount);
        break;
    case 4:
        func_ov003_0215a5b4(self);
        break;
    case 5:
        func_ov003_0215a740(self, amount, 0x406);
        break;
    case 6:
        func_ov003_0215a740(self, amount, 0x410);
        break;
    case 7:
        func_ov003_0215a740(self, amount, 0x41a);
        break;
    case 8:
        _Z28UpdateResponseState_0215af00Pv(self);
        break;
    case 9:
        func_ov003_0215b1dc(self, amount);
        break;
    case 10:
        func_ov003_0215af9c(self);
        break;
    case 12:
        _Z32UpdateChatResponseState_0215b0e8Pv(self);
        break;
    }

    func_ov003_0215c0ec(self);
    return 0;
}
