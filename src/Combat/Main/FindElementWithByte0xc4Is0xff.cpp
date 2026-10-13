#include <globaldefs.h>

#if defined(jpn)
enum { kInitialPad = 0x24 };
#else
enum { kInitialPad = 0x30 };
#endif

struct Elem02081de0 {
    unsigned char pad_0[0xc4];
    unsigned char field_c4;
    unsigned char pad_c5[0x1b];
};

struct Obj02081de0 {
    unsigned char pad_0[kInitialPad];
    struct Elem02081de0 *field_30;
    unsigned char pad_34[5];
    unsigned char field_39;
};

// USA: func_02081de0
ARM struct Elem02081de0* FindElementWithByte0xc4Is0xff(struct Obj02081de0 *obj) {
    unsigned char count = obj->field_39;
    struct Elem02081de0 *p = obj->field_30;
    unsigned char i = 0;
    while (i < count) {
        if (p->field_c4 == 0xff) {
            return p;
        }
        p++;
        i++;
    }
    return NULL;
}
