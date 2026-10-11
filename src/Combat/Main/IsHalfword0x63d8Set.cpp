#include <globaldefs.h>

struct FieldBlock63d8_115d0 {
#if defined(jpn)
    char unk[0x6178];
#else
    char unk[0x63D8];
#endif
    unsigned short field;
};

// USA: func_020115d0
ARM int IsHalfword0x63d8Set(struct FieldBlock63d8_115d0* obj) {
    return obj->field != 0;
}
