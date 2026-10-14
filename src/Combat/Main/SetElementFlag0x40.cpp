#include <globaldefs.h>

struct Obj2081;

struct Elem2081 {
    char unk[0xc5];
    unsigned char flags;
    char unk2[0x1a];
};

struct Elem2081* FindElementByByte0xc4_02081da8(struct Obj2081* obj, int key);
extern "C" void func_020813ec(struct Obj2081* obj, int key);

// USA: func_02081ea4
ARM void SetElementFlag0x40_02081ea4(struct Obj2081* obj, int key, int enable) {
    struct Elem2081* elem = FindElementByByte0xc4_02081da8(obj, key);
    if (elem != NULL) {
        if (enable != 0) {
            elem->flags |= 0x40;
        } else {
            elem->flags &= ~0x40;
        }
        func_020813ec(obj, key);
    }
}
