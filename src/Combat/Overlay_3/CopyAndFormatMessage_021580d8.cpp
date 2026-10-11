#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { kRegionValue200_118 = 0x118 };
#else
enum { kRegionValue200_118 = 0x200 };
#endif


int StringLength(const char* s);
extern char data_ov003_0217fce0;

struct Obj021580d8 {
    int field0;
    char* field4;
    int field8;
    char blockA[0x38];
    char blockB[0x200];
};

struct Src021580d8 {
    int f0;
    char* f4;
    int f8;
};

// USA: func_ov003_021580d8  (semantic: CopyAndFormatMessage_021580d8)
// JPN: func_ov003_021595c4
extern "C" ARM void func_ov003_021580d8(struct Obj021580d8* dst, struct Src021580d8* src) {
    char* text;
    if (src == 0) {
        return;
    }
    dst->field0 = src->f0;
    dst->field4 = src->f4;
    dst->field8 = src->f8;
    dst->field4 = dst->blockB;
    text = src->f4;
    if (text == 0) {
        return;
    }
    memset(dst->blockB, 0, kRegionValue200_118);
    sprintf(dst->blockB + StringLength(dst->blockB), &data_ov003_0217fce0, text);
}
