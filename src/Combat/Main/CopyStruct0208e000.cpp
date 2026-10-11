#include <globaldefs.h>

struct Copy0208e000 {
    short field0;
    unsigned short field2;
    int field4;
    int field8;
#if defined(jpn)
    int fieldC;
#endif
};

// USA: func_0208e000
ARM void CopyStruct0208e000(struct Copy0208e000* dst, struct Copy0208e000* src) {
    dst->field0 = src->field0;
    dst->field2 = src->field2;
    dst->field4 = src->field4;
    dst->field8 = src->field8;
#if defined(jpn)
    dst->fieldC = src->fieldC;
#endif
}
