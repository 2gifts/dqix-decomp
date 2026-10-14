#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct Struct02030b7c {
    int field0;
    void* field4;
};
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

int StringLength(const char* s);

struct Struct0215e498 {
    short f0;
    short f2;
    int f4;
    int f8;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    short f10;
};
void ResetStruct_0215e498(struct Struct0215e498* s);

struct Entry0215e790 {
    short f0;
    short f2;
    int f4;
    int f8;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    short f10;
    unsigned char f12;
    unsigned char f13;
};
struct Self0215e790;
void AppendEntryToArray_0215e790(struct Self0215e790* self, struct Entry0215e790* src);

struct Args0215e510 {
    struct Variant02030b0c v0;
    struct Variant02030b0c v1;
    struct Variant02030b0c v2;
    struct Struct02030b7c v3;
    struct Struct02030b7c v4;
    struct Variant02030b0c v5;
    struct Variant02030b0c v6;
    struct Variant02030b0c v7;
};

struct Globals02180cb8 {
    void* allocator;
    struct Self0215e790* target;
};
extern struct Globals02180cb8 data_ov003_02180cb8;

// USA: func_ov003_0215e510  (semantic: BuildAndAppendLogEntry_0215e510)
extern "C" ARM int func_ov003_0215e510(struct Args0215e510* obj) {
    struct Entry0215e790 local;
    ResetStruct_0215e498((struct Struct0215e498*)&local);

    local.f10 = (short)_ZNK6Script9Parameter5ToIntEv(&obj->v0);
    local.f0 = (short)_ZNK6Script9Parameter5ToIntEv(&obj->v1);
    local.f2 = (short)_ZNK6Script9Parameter5ToIntEv(&obj->v2);

    char* text1 = (char*)_ZNK6Script9Parameter8ToStringEv(&obj->v3);
    if (text1 != NULL) {
        int len1 = StringLength(text1);
        if (len1 != 0) {
            char* buf1 = (char*)((SafeAllocator*)data_ov003_02180cb8.allocator)->Allocate(len1 + 1);
            local.f4 = (int)buf1;
            sprintf(buf1, text1);
        }
    }

    char* text2 = (char*)_ZNK6Script9Parameter8ToStringEv(&obj->v4);
    if (text2 != NULL) {
        int len2 = StringLength(text2);
        if (len2 != 0) {
            char* buf2 = (char*)((SafeAllocator*)data_ov003_02180cb8.allocator)->Allocate(len2 + 1);
            local.f8 = (int)buf2;
            sprintf(buf2, text2);
        }
    }

    local.fc = (unsigned char)_ZNK6Script9Parameter5ToIntEv(&obj->v5);
    local.fd = (unsigned char)_ZNK6Script9Parameter5ToIntEv(&obj->v6);
    local.fe = (unsigned char)_ZNK6Script9Parameter5ToIntEv(&obj->v7);

    AppendEntryToArray_0215e790(data_ov003_02180cb8.target, &local);
    return 1;
}
