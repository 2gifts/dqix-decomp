#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0xc };
#else
enum { FIELD_OFFSET = 0x10 };
#endif

struct Variant02030b0c;

extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c* p);

extern int data_020fdc4c;

#if defined(jpn)
#define StoreDecodedIntAt0x14 func_0201f5d0
extern "C" ARM int func_0201f5d0(Variant02030b0c* arg);
#endif

// USA: func_0201f844
ARM int StoreDecodedIntAt0x14(Variant02030b0c* arg) {
    int v = _ZNK6Script9Parameter5ToIntEv(arg);
    *(int*)(*(char**)((char*)&data_020fdc4c + FIELD_OFFSET) + 0x14) = v;
    return 1;
}
