#include <globaldefs.h>

#if defined(jpn)
#define SetScaledFieldFromTaggedValue0201f600 func_0201f38c
enum { ObjectSlotOffset = 0xc };
#else
enum { ObjectSlotOffset = 0x10 };
#endif

struct TaggedValue02030b44;
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);
extern int data_020fdc4c;

#if defined(jpn)
extern "C" int func_0201f38c(struct TaggedValue02030b44* v);
#endif

// USA: func_0201f600
ARM int SetScaledFieldFromTaggedValue0201f600(struct TaggedValue02030b44* v) {
    float scaled = 4096.0f * _ZNK6Script9Parameter7ToFloatEv(v);
    *(int*)(*(char**)((char*)&data_020fdc4c + ObjectSlotOffset) + 0x38) = (int)scaled;
    return 1;
}
