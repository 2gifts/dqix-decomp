#include <globaldefs.h>
#if defined(jpn)
extern "C" int _Z12StringLengthPKc(const char*);
#endif

struct Container02080f8c;
struct Container02080fa8;
struct Container02080cc0;

int CallFunc020e0434With02153694(int value);
void SetEntryFirstField02080f8c(struct Container02080f8c* obj, int id, int value);
void SetSublistEntryField14LowBits_02080798(void* obj, int id, int value);
void SetEntryHalfword0xe(void* obj, int id, int value);
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);
char* LookupValueByEntryKey02081010(void* obj, int id);
extern "C" int func_020420e8(const char* text, int large);
void GetEntryFieldsAt0x602080828(void* obj, int id, short* x, short* y);
void SetEntryFieldsAt0x602080854(void* obj, int id, int x, int y);
int SetEntryFlagById02080b2c(void* obj, int id);
int SetEntryFlagById02080b40(void* obj, int id);
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);

struct Window02167e28 {
    char pad[0x10];
    void* layout;
};

// JPN: func_ov003_02167ce4
// USA: func_ov003_02167e28
extern "C" ARM void func_ov003_02167e28(struct Window02167e28* self, char* name, int flag, unsigned char index,
                                        unsigned char badge, int valueA, int valueB) {
    void* obj = self->layout;
#if !defined(jpn)
    SetEntryFirstField02080f8c((struct Container02080f8c*)obj, 3, CallFunc020e0434With02153694(0x3f3));
    SetSublistEntryField14LowBits_02080798(obj, 3, 1);
#endif
    SetEntryFirstField02080f8c((struct Container02080f8c*)obj, 0, (int)name);
#if !defined(jpn)
    SetSublistEntryField14LowBits_02080798(obj, 0, 1);
#endif
    SetEntryHalfword0xe(obj, 1, (short)flag);
    SetEntryFirstField02080fa8((struct Container02080fa8*)obj, 5, valueA);
    SetEntryFirstField02080fa8((struct Container02080fa8*)obj, 6, valueB);
    SetEntryHalfword0xe(obj, 2, (short)(index + 2));
#if defined(jpn)
    int width = (_Z12StringLengthPKc(LookupValueByEntryKey02081010(obj, 2)) >> 1) * 10;
#else
    int width = func_020420e8(LookupValueByEntryKey02081010(obj, 2), 0);
#endif
    short x;
    short y;
    GetEntryFieldsAt0x602080828(obj, 2, &x, &y);
    x = 0x40;
    x -= width >> 1;
    SetEntryFieldsAt0x602080854(obj, 2, x, y);
    SetEntryFlagById02080b2c(obj, 0x2c);
    if (badge == 0) {
        return;
    }
    SetEntryFlagById02080b40(obj, 0x2c);
#if defined(jpn)
    SetEntryFieldsAt0x602080854(obj, 0x2c, (short)(x + width + 1), (short)(y + 2));
#else
    SetEntryFieldsAt0x602080854(obj, 0x2c, (short)(x + width + 1), y);
#endif
    SetEntryHalfword0xe(obj, 0x2c, (short)(badge + 0x1c));
    int nibble = 5;
    if (badge == 10) {
        nibble = 0xd;
    }
    SetEntryHighNibble0x13((struct Container02080cc0*)obj, 0x2c, nibble);
}
