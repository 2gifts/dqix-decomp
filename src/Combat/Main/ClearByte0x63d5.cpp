#include <globaldefs.h>

struct FieldBlock63d5_12050 {
#if defined(jpn)
    char unk[0x6175];
#else
    char unk[0x63D5];
#endif
    unsigned char field;
};

// USA: func_02012050
ARM void ClearByte0x63d5_02012050(struct FieldBlock63d5_12050* obj) {
    obj->field = 0;
}
