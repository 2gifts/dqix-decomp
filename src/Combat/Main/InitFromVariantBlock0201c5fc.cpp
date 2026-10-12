#include <globaldefs.h>

#if defined(jpn)
enum { kAngleOffset = 0x54, kWordAOffset = 0x58, kWordBOffset = 0x5c };
#else
enum { kAngleOffset = 0x34, kWordAOffset = 0x38, kWordBOffset = 0x3c };
#endif

#include "std_library_functions.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct Struct02030b7c;
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

struct TaggedValue02030b44;
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

extern "C" int _Z22fix32ReduceAngle0To2Pii(int v);

extern int data_020ef2bc;
extern int data_020fdc14;

#if defined(jpn)
#define InitFromVariantBlock0201c5fc func_0201c374
extern "C" ARM int func_0201c374(void* obj);
#endif

// USA: func_0201c5fc
ARM int InitFromVariantBlock0201c5fc(void* obj) {
    char* p = (char*)obj;

    if (data_020ef2bc != _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x0)))
        return 1;

    _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x8));
#if defined(jpn)
    char* extraName = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)(p + 0x10));
    strcpy(*(char**)((char*)&data_020fdc14 + 0x4) + 0x2a, extraName);
#else
    _ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)(p + 0x10));
#endif
    _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x18));
    _ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)(p + 0x20));
    _ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)(p + 0x28));
    _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x30));
    _ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)(p + 0x38));
    _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x40));
    _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x48));
    _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x50));

    char* name = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)(p + 0x58));
    if (name != NULL) {
        strcpy(*(char**)((char*)&data_020fdc14 + 0x4), name);
    }

    _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x60));

    *(unsigned short*)(*(char**)((char*)&data_020fdc14 + 0x4) + kAngleOffset) =
        (unsigned short)_Z22fix32ReduceAngle0To2Pii((int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(p + 0x68))));

    *(int*)(*(char**)((char*)&data_020fdc14 + 0x4) + kWordAOffset) =
        (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(p + 0x70)));

    *(int*)(*(char**)((char*)&data_020fdc14 + 0x4) + kWordBOffset) =
        (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(p + 0x78)));

    return 1;
}
