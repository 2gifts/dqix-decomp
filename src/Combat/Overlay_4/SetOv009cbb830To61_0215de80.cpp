#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_0215de80 func_ov004_0215edb0
#endif


struct Struct0209c830;
extern "C" void _Z27SetValueAndActivate0209c830P14Struct0209c830t(struct Struct0209c830*, unsigned short);

extern struct Struct0209c830 data_02109bf4;

// USA: func_ov004_0215de80  (semantic: SetOv009cbb830To61_0215de80)
extern "C" ARM int func_ov004_0215de80(void) {
    _Z27SetValueAndActivate0209c830P14Struct0209c830t(&data_02109bf4, 0x3d);
    return 0;
}
