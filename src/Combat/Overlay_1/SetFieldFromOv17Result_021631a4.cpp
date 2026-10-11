#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_021631a4
ARM int SetFieldFromOv17Result_021631a4(void* obj) {
#if defined(jpn)
    enum { queueOffset = 0x524, fieldOffset = 0x80 };
#else
    enum { queueOffset = 0x734, fieldOffset = 0x84 };
#endif
    char* base = (char*)func_ov017_0218b5b0();
    char* q = *(char**)(base + 0x3000 + queueOffset);
    int v = func_ov017_021d60f4(obj);
    *(short*)(q + 0x100 + fieldOffset) = (short)v;
    return 1;
}
