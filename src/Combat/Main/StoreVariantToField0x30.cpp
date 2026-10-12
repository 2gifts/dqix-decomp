#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x50 };
#else
enum { FIELD_OFFSET = 0x30 };
#endif

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern void* data_02108740[];

#if defined(jpn)
#define StoreVariantToField0x30 func_0205f348
extern "C" ARM int func_0205f348(struct Variant02030b0c* p);
#endif

// USA: func_0205e05c
ARM int StoreVariantToField0x30(struct Variant02030b0c* p) {
    *(int*)((char*)data_02108740[1] + FIELD_OFFSET) = _ZNK6Script9Parameter5ToIntEv(p);
    return 1;
}
