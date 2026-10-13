#include <globaldefs.h>

struct Entry0223bab4 {
    unsigned int w0;
    unsigned int w1;
};

// USA: func_ov031_0223bab4  (semantic: SetEntryFieldOrAll_0223bab4)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0223bab4(void* obj, int idx, int value, int flag) {
    Entry0223bab4* arr = *(Entry0223bab4**)((char*)obj + 0x8);
    unsigned int mask = 0xc1fffcff;
    if (idx >= 0) {
        unsigned int* p = &arr[idx].w0;
        if (value != 0x100 && value != 0x300) {
            unsigned int v = *p & mask;
            *p = v | value;
        } else {
            unsigned int v = *p & mask;
            *p = (v | value) | (flag << 0x19);
        }
        return;
    }
    idx = 0;
    int count = *((unsigned char*)obj + 0xc);
    if (count <= 0) return;
    do {
        unsigned int* p = &arr[idx].w0;
        if (value != 0x100 && value != 0x300) {
            unsigned int v = *p & mask;
            *p = v | value;
        } else {
            unsigned int v = *p & mask;
            *p = (v | value) | (flag << 0x19);
        }
        idx++;
    } while (idx < *((unsigned char*)obj + 0xc));
}
