#include <globaldefs.h>

struct Obj02041654 {
    char unk0[0x54];
    int field54;
#if defined(jpn)
    char unk58[0x26c];
#else
    char unk58[0x278];
#endif
    unsigned short flags;
    char unk2d2[0x2];
    int field2d4;
};

// USA: func_02041654
ARM int GetFieldByFlagBit02041654(struct Obj02041654* obj) {
    if (obj->flags & 0x2) {
        return obj->field2d4;
    }
    return obj->field54;
}
