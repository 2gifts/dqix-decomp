#include <globaldefs.h>
#if defined(jpn)
#define LIST_OFFSET 0x34
#else
#define LIST_OFFSET 0x38
#endif

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);
extern "C" void func_ov013_02186bd4(void*);

// USA: func_ov013_02186c64  (semantic: SetElemFlagAndApply02186c64)
extern "C" ARM void func_ov013_02186c64(void* obj, int key, int flag) {
    Elem_0205d81c* elem = FindElementByC40205d81c((Struct_0205d81c*)((char*)obj + LIST_OFFSET), key);
    if (elem == 0) return;

    unsigned char* fieldC5 = (unsigned char*)elem + 0xc5;
    unsigned char v = *fieldC5;
    *fieldC5 = flag ? (v | 0x40) : (v & ~0x40);

    if (key != 0) return;
    func_ov013_02186bd4(obj);
}
