#include <globaldefs.h>

void ClearListEntryIfMatch020be3f4(int, void*, unsigned int);

extern "C" void func_020d2c00(int);
void PostEvent0x1F(int, int);

// USA: func_020be474
ARM void PostRangeEvent0x1F(int start, int length, int c, int d) {
    ClearListEntryIfMatch020be3f4((int)(start), (void*)(c), (unsigned int)(d));
    PostEvent0x1F(start, start + length);
    func_020d2c00(start);
}
