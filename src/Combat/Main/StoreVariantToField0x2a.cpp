#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x4a };
#else
enum { FIELD_OFFSET = 0x2a };
#endif

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern void* data_02108740[];

#if defined(jpn)
#define StoreVariantToField0x2a func_0205f328
extern "C" ARM int func_0205f328(struct Variant02030b0c* p);
#endif

// USA: func_0205e03c
ARM int StoreVariantToField0x2a(struct Variant02030b0c* p) {
    *(short*)((char*)data_02108740[1] + FIELD_OFFSET) = _ZNK6Script9Parameter5ToIntEv(p);
    return 1;
}
