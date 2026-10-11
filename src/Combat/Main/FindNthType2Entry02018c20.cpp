#include <globaldefs.h>
#if defined(jpn)
enum { kArrayOffset = 0x8c };
enum { kCountOffset = 0xb4 };
#else
enum { kArrayOffset = 0x6c };
enum { kCountOffset = 0x94 };
#endif


void* GetElementStride0x74(unsigned char* obj, int index);

// USA: func_02018c20
ARM void* FindNthType2Entry02018c20(unsigned char* obj, int n) {
    unsigned char* p = (unsigned char*)GetElementStride0x74(obj + kArrayOffset, 0);
    int count = *(int*)(obj + kCountOffset);
    int i;
    for (i = 0; i < count; i++) {
        if (*(int*)(p + 4) == 2) {
            if (n == 0) return p;
            n--;
        }
        p += 0x74;
    }
    return NULL;
}
