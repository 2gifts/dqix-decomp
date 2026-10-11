#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_02163200
ARM int SetLinkedByteFromOv17_02163200(void* obj) {
#if defined(jpn)
    enum { queueOffset = 0x3524, fieldOffset = 0x103 };
#else
    enum { queueOffset = 0x3734, fieldOffset = 0x107 };
#endif
    char* p = (char*)func_ov017_0218b5b0();
    unsigned char v = *(unsigned char*)(*(char**)(p + queueOffset) + fieldOffset);
    func_ov017_021d6134(obj, v);
    return 1;
}
