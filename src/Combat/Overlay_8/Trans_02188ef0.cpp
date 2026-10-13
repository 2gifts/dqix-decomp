#include <globaldefs.h>

extern "C" void _Z18InitFlags_021eb414Pc(char*, unsigned int);

// USA: func_ov008_02188ef0  (semantic: Trans_02188ef0)
extern "C" ARM void func_ov008_02188ef0(char* self) {
    unsigned int state = *(unsigned int*)(self + 0xb18);
    if ((state & 0x100000) == 0 || (state & 0x200000) != 0) { return; }
    if (*(unsigned char*)(self + 0xb2a) != 0) { return; }
    char* obj = *(char**)(self + 0xb08);
    if (obj != 0) {
        unsigned int flags = *(unsigned short*)(obj + 0x438);
        if ((flags & 0x4) == 0) {
            _Z18InitFlags_021eb414Pc(obj, flags);
        }
    }
    *(unsigned char*)(self + 0xb13) = 0;
    *(unsigned char*)(self + 0xb10) = 0xd;
    *(unsigned char*)(self + 0xb11) = 0;
    *(unsigned char*)(self + 0xb2a) = *(unsigned char*)(self + 0xb2a) + 1;
}
