#include <globaldefs.h>

struct FieldBlock63d6_115b4 {
#if defined(jpn)
    char unk[0x6176];
#else
    char unk[0x63D6];
#endif
    unsigned char field;
};

// USA: func_020115b4
ARM void SetByteField0x63d6_020115b4(struct FieldBlock63d6_115b4* obj, unsigned char value) {
    obj->field = value;
}
