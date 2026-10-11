#include <globaldefs.h>
#if defined(jpn)
enum { kRegionalFieldOffset = 0x8c };
#else
enum { kRegionalFieldOffset = 0x6c };
#endif


void* GetElementStride0x74(unsigned char* obj, int index);
extern "C" void* func_02012fe4(void);
extern "C" void* func_020a8a34(void*, int, int, int);

// USA: func_020a86b8
ARM void* FilterByTypeAndBytes020a86b8(int unused, int flag, unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4, unsigned char b5) {
    unsigned char* obj = (unsigned char*)func_02012fe4();
    int i = 0;
    for (;;) {
        unsigned char* entry = (unsigned char*)GetElementStride0x74(obj + kRegionalFieldOffset, i);
        i++;
        if (!entry) return entry;
        if (*(int*)(entry + 4) != 0xc) continue;
        unsigned char* sub = entry + 0x2c;
        if (!sub) return sub;
        if (flag != 0) {
            if (sub[0] == b0 && sub[1] == b1 && sub[2] == b2 && b0 == 1) {
                return func_020a8a34(sub, b3, b4, b5);
            }
        }
    }
}
