#include <globaldefs.h>
#if defined(jpn)
enum { kCountOffset = 0x496 };
#else
enum { kCountOffset = 0x476 };
#endif


struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

struct S02013cb0 {
    unsigned short field0;
    unsigned char pad2[kCountOffset - 2];
    unsigned char count;
    unsigned char pad3;
    unsigned char* arrayPtr;
};

// USA: func_02013cb0
ARM void SetElementFlagsFromMask02013cb0(struct S02013cb0* obj, unsigned int mask) {
    int i;
    for (i = 0; i < obj->count; i++) {
        if (mask & (1 << i)) {
            unsigned char* elem = obj->arrayPtr + i * 0x368;
            *(short*)(elem + 2) = -1;
        }
    }
    struct Entry_02028bd0* base = GetEntryTableBase();
    struct Entry_02028bd0* result = FindInlineEntryById(base, obj->field0);
    if (result == NULL) {
        return;
    }
    unsigned short* fieldPtr = (unsigned short*)((unsigned char*)result + 2);
    unsigned int cur = *fieldPtr;
    *fieldPtr = (cur & 0xffff000f) | ((mask << 20) >> 16);
}
