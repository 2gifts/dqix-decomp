#include <globaldefs.h>

extern "C" void func_02048150(void*);

struct T02053fe4 {
#if defined(jpn)
    char pad[0x180];
#else
    char pad[0x18c];
#endif
    unsigned int field18c;
};

// USA: func_02053fe4
ARM void ClearFieldBit02053fe4(struct T02053fe4* obj) {
    func_02048150(obj);
    obj->field18c &= ~1;
}
