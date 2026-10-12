#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define data_020ef6d0 data_020ef5c0
#define data_020ef6ca data_020ef5b5
#define data_020ef6d3 data_020ef5c3
#define SetIndexedRecord020265a8 func_02025f0c
extern "C" ARM void func_02025f0c(char* obj, int index, const char* name, int extra);
enum { kNameStride = 0x24, kExtraBase = 0x668 };
#else
enum { kNameStride = 0x48, kExtraBase = 0x6d4 };
#endif

extern char data_020ef6d0;
extern char data_020ef6ca;
extern char data_020ef6d3;

// USA: func_020265a8
ARM void SetIndexedRecord020265a8(char* obj, int index, const char* name, int extra) {
    if ((unsigned int)index >= 3) return;
    if (name != NULL && *name != 0) {
        strcpy(obj + 0x5fc + index * kNameStride, name);
        sprintf(obj + kExtraBase + index * 8, &data_020ef6d0, extra);
    } else {
        strcpy(obj + 0x5fc + index * kNameStride, &data_020ef6ca);
        strcpy(obj + kExtraBase + index * 8, &data_020ef6d3);
    }
}
