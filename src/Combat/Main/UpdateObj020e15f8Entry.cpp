#include <globaldefs.h>
#include "std_library_functions.h"

struct FourShorts020e12a8;
void StoreFourShorts(struct FourShorts020e12a8* dst, short a, short b, short c, short d);

extern "C" int func_020420e8(int, unsigned char);
#if defined(jpn)
extern "C" void func_0205b234(void*, short, short, int, unsigned char, unsigned char);
#else
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);
#endif

// USA: func_020e2310
ARM void UpdateObj020e15f8Entry(char* obj, int idx, int a2, int a3, int a4, unsigned char a5, unsigned char a6)
{
    if (idx >= 0 && idx < 3) {
        #if defined(jpn)
        int ret = strlen((char*)a4);
        int advance = a5;
        int height = a5;
#else
        int ret = func_020420e8(a4, a6);
        int advance = 1;
        int height = 0xc;
#endif
        StoreFourShorts((struct FourShorts020e12a8*)(obj + 0xa + idx * 8), a2, a3, a2 + ret * advance, a3 + height);
    }
    if ((signed char)obj[8] <= idx) {
        obj[8] = idx + 1;
    }
    void **p = *(void***)(obj + 4);
    func_0205b234(p[1], a2, a3, a4, a5, a6);
}
