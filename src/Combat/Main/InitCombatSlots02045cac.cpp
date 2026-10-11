#include <globaldefs.h>

struct State0204166c;
#if defined(jpn)
extern "C" void func_02041bbc(struct State0204166c* s);
#define Forward020416c0 func_02041bbc
#else
void Forward020416c0(struct State0204166c* s);
#endif

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);

struct CombatSlots02045cac {
#if defined(jpn)
    char pad0[0x884];
#else
    char pad0[0x9b4];
#endif
    int field9b4;
    unsigned char stateArr[0xe00];
    unsigned char byteArr[0x80];
#if defined(jpn)
    char pad1838[0x17e0 - 0x1708];
#else
    char pad1838[0x19b0 - 0x1838];
#endif
    unsigned char flagByte;
#if defined(jpn)
    char pad19b1[0x1c4c - 0x17e1];
#else
    char pad19b1[0x1e28 - 0x19b1];
#endif
    void* ptrField;
};

// USA: func_02045cac
ARM void InitCombatSlots02045cac(struct CombatSlots02045cac* obj) {
    obj->flagByte = 1;
#if defined(jpn)
    obj->field9b4 = 14;
#else
    obj->field9b4 = 0;
#endif
#if defined(jpn)
    for (int i = 14; i < 0x80; i++) {
#else
    for (int i = 0; i < 0x80; i++) {
#endif
        Forward020416c0((struct State0204166c*)(obj->stateArr + i * 0x1c));
        obj->byteArr[i] = 0;
    }
    if (obj->ptrField != NULL) {
        CopyInternalFields0207df50((struct Foo0207df50*)obj->ptrField);
    }
}
