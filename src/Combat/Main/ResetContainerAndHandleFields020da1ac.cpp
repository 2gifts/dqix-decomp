#include <globaldefs.h>

struct HandleStruct;
void ResetHandleFields_020da22c(struct HandleStruct* s);

extern "C" void* func_02057924(void*);
extern "C" void func_02057f00(void*, int);

// USA: func_020da1ac
ARM void ResetContainerAndHandleFields020da1ac(void* p0) {
    void* handle = func_02057924(p0);
    if (handle) {
        func_02057f00(handle, 0x14);
        func_02057f00(handle, 0x15);
        func_02057f00(handle, 0x16);
    }
    char* h = (char*)p0 + 0x14;
    unsigned char i = 0;
    while (i < 4) {
        ResetHandleFields_020da22c((struct HandleStruct*)h);
        i++;
        h += 0xc;
    }
    *(int*)((char*)p0 + 0x0) = 0;
    *(int*)((char*)p0 + 0x4) = 0;
    *(unsigned char*)((char*)p0 + 0xc) = 0;
    *(unsigned char*)((char*)p0 + 0xd) = 0;
    *(unsigned char*)((char*)p0 + 0xe) = 0;
    *(unsigned char*)((char*)p0 + 0xf) = 0;
    *(unsigned char*)((char*)p0 + 0x11) = 0;
}
