#include <globaldefs.h>

#if defined(jpn)
enum { kContextSlot = 0xc };
#else
enum { kContextSlot = 0x10 };
#endif


struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c* p);
extern "C" void func_02027b10(void* obj, int value);
extern int data_020fdc4c;

#if defined(jpn)
#define StoreDecodedIntViaHandler0201f390 func_0201f11c
extern "C" ARM int func_0201f11c(Variant02030b0c* arg);
#endif

// USA: func_0201f390
ARM int StoreDecodedIntViaHandler0201f390(Variant02030b0c* arg) {
    int value = _ZNK6Script9Parameter5ToIntEv(arg);
    func_02027b10(*(char**)((char*)&data_020fdc4c + kContextSlot), value);
    return 1;
}
