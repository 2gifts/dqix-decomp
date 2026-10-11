#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x1faa
#define REGION_OFFSET_1 0x1fa0
#define REGION_OFFSET_2 0x1f98
#else
#define REGION_OFFSET_0 0x1d72
#define REGION_OFFSET_1 0x1d68
#define REGION_OFFSET_2 0x1d60
#endif


extern "C" int func_02092bcc(void* p, int val);
extern "C" int func_02092b34(void* p);
extern "C" void func_ov000_02176e3c(void* obj, int zero, int val, int arg1, int arg2, int one);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);

// USA: func_ov000_0217de64
extern "C" ARM void func_ov000_0217de64(char* obj, int arg1, int arg2) {
    unsigned short flags = *(unsigned short*)(obj + REGION_OFFSET_0);
    *(unsigned short*)(obj + REGION_OFFSET_0) = flags & ~0x100;
    int r = func_02092bcc(obj + 0x7c, *(int*)(obj + 0x94c));
    if (r == 0) {
        return;
    }
    func_02092b34(obj + 0x7c);
    signed char idx1 = *(volatile signed char*)(obj + REGION_OFFSET_1);
    *(unsigned char*)(obj + idx1 + REGION_OFFSET_2) = 0;
    *(signed char*)(obj + REGION_OFFSET_1) = *(volatile signed char*)(obj + REGION_OFFSET_1) - 1;
    func_ov000_02176e3c(obj, 0, *(signed char*)(obj + *(volatile signed char*)(obj + REGION_OFFSET_1) + REGION_OFFSET_2), arg1, arg2, 0);
    func_ov000_0217c638(obj, arg1, arg2);
}
