#include <globaldefs.h>

struct FieldBlock63d6_11590 {
#if defined(jpn)
    char unk[0x6176];
#else
    char unk[0x63D6];
#endif
    unsigned char field;
};

// USA: func_02011590
ARM int IsByte0x63d6Set(struct FieldBlock63d6_11590* obj) {
    return obj->field != 0;
}
