#include "System/OverlayMD5.h"

// USA: func_ov031_02222830  (semantic: FillBytes_02222830)
extern "C" THUMB void func_ov031_02222830(void* destination, int value, unsigned int count) {
    char* dst = (char*)destination;
    unsigned int i = 0;
    if (i < count) {
        do {
            i++;
            *dst = (char)value;
            dst++;
        } while (i < count);
    }
}
