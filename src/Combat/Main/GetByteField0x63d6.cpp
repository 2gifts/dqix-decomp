#include <globaldefs.h>

struct FieldBlock63d6_115a8 {
#if defined(jpn)
    char unk[0x6176];
#else
    char unk[0x63D6];
#endif
    unsigned char field;
};

// USA: func_020115a8
ARM int GetByteField0x63d6(struct FieldBlock63d6_115a8* obj) {
    return obj->field;
}
