#include <globaldefs.h>

struct Elem2081 {
    char unk[0xc4];
    unsigned char key;
    char unk2[0x1b];
};

struct Obj2081 {
#if defined(jpn)
    char unk[0x24];
#else
    char unk[0x30];
#endif
    struct Elem2081* elems;
    char unk2[5];
    unsigned char count;
};

// USA: func_02081da8
ARM struct Elem2081* FindElementByByte0xc4(struct Obj2081* obj, int key) {
    unsigned char count = obj->count;
    struct Elem2081* p = obj->elems;
    unsigned char i;
    for (i = 0; i < count; i++) {
        if (key == p->key) {
            return p;
        }
        p++;
    }
    return NULL;
}
