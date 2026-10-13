#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
int GetGlobalField0x1c020421a0(void);

// KEEP-NAME
// USA: func_ov001_0215e97c
// JPN: func_ov001_0215fff4
ARM int SetByteFlagFromCheck_0215e97c(void* obj) {
    char* messages = (char*)GetGlobalField0x1c020421a0();
    unsigned char flag = func_ov017_021d60f4(obj) != 0;
#if defined(jpn)
    messages[0x17fc] = flag;
#else
    messages[0x19cb] = flag;
#endif
    return 1;
}
