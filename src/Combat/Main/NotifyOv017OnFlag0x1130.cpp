#include <globaldefs.h>
#if defined(jpn)
enum { kRegionalFieldOffset = 0x8c };
#else
enum { kRegionalFieldOffset = 0x6c };
#endif


void* GetElementStride0x74(unsigned char* obj, int index);
extern "C" void* func_02012fe4(void);
extern "C" void func_ov017_021d1874(unsigned char a, unsigned char b, unsigned char c, int d, int e, int f, int g);

// USA: func_020a8740
ARM void NotifyOv017OnFlag0x1130(void) {
    unsigned char* obj = (unsigned char*)func_02012fe4();
    int i = 0;
    for (;;) {
        unsigned char* entry = (unsigned char*)GetElementStride0x74(obj + kRegionalFieldOffset, i);
        i++;
        if (!entry) return;
        if (*(int*)(entry + 4) != 0xc) continue;
        unsigned char* sub = entry + 0x2c;
        unsigned short field = *(unsigned short*)(obj + 4);
        if (!sub) return;
        if (field == 0x1130 && sub[0] == 1) {
            func_ov017_021d1874(sub[0], sub[1], sub[2], 2, 0, 0, 0);
        }
    }
}
