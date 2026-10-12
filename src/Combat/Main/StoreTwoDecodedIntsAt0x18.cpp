#include <globaldefs.h>

#if defined(jpn)
#define StoreTwoDecodedIntsAt0x18 func_0201f258
enum { ObjectSlotOffset = 0xc };
#else
enum { ObjectSlotOffset = 0x10 };
#endif

struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c* p);
extern int data_020fdc4c;

#if defined(jpn)
extern "C" ARM int func_0201f258(Variant02030b0c* args);
#endif

// USA: func_0201f4cc
ARM int StoreTwoDecodedIntsAt0x18(Variant02030b0c* args) {
    int v1 = _ZNK6Script9Parameter5ToIntEv(args);
    int v2 = _ZNK6Script9Parameter5ToIntEv(args + 1);
    char* obj = *(char**)((char*)&data_020fdc4c + ObjectSlotOffset);
    *(int*)(obj + 0x18) = v1;
    *(int*)(obj + 0x1c) = v2;
    return 1;
}
