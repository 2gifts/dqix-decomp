#include <globaldefs.h>

extern "C" int func_ov016_0218f16c(void* object, void* destination, int stride, int mode);

// USA: func_ov016_0218e708
ARM int CallIfNonNullBool_0218e708(void* object, void* destination, int stride, int mode) {
    if (object == NULL) return 0;
    return func_ov016_0218f16c(object, destination, stride, mode) == 1;
}
