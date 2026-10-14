#include <globaldefs.h>
void ClearListEntryIfMatch020be3f4(int, void*, unsigned int);

extern "C" void func_020d2c98(int);
void PostEvent0x20_020d20c4(int, int);

// USA: func_020be4a4
ARM void PostRangeEvent0x20_020be4a4(int start, int length, int c, int d) {
    ClearListEntryIfMatch020be3f4((int)(start), (void*)(c), (unsigned int)(d));
    PostEvent0x20_020d20c4(start, start + length);
    func_020d2c98(start);
}
