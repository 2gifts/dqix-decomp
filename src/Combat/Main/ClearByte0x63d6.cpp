#include <globaldefs.h>

struct FieldBlock63d6_115c0 {
#if defined(jpn)
    char unk[0x6176];
#else
    char unk[0x63D6];
#endif
    unsigned char field;
};

// USA: func_020115c0
ARM void ClearByte0x63d6(struct FieldBlock63d6_115c0* obj) {
    obj->field = 0;
}
