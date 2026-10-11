#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" char* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d612c(void* obj);
extern char data_ov001_02165745;

// USA: func_ov001_021613d0
ARM int FormatFieldD8_021613d0(void* obj) {
#if defined(jpn)
    enum { queueOffset = 0x524, fieldOffset = 0xd4 };
#else
    enum { queueOffset = 0x734, fieldOffset = 0xd8 };
#endif
    char* base = func_ov017_0218b5b0();
    char* p = *(char**)(base + 0x3000 + queueOffset);
    int v = func_ov017_021d612c(obj);
    sprintf(p + fieldOffset, &data_ov001_02165745, v);
    return 1;
}
