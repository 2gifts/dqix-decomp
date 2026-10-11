#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);

// USA: func_ov004_02165b14  (semantic: SetGlobalFieldsFlagAndTwo_02165b14)
extern "C" ARM int func_ov004_02165b14(void) {
#if defined(jpn)
    enum { byteOffset = 0x7e2, wordOffset = 0x86c };
#else
    enum { byteOffset = 0x9b2, wordOffset = 0x99c };
#endif
    int g = GetGlobalField0x1c020421a0();
    *(unsigned char*)(g + 0x1000 + byteOffset) = 1;
    *(int*)(g + wordOffset) = 2;
    return 0;
}
