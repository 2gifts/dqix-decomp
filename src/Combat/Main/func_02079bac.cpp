#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct S02079ce8 {
    unsigned int f : 12;
};

struct Elem02079bac {
    unsigned char pad[8];
};

struct Header02079bac {
    unsigned int count : 12;
    unsigned int hi : 19;
    unsigned int flag : 1;
    struct Elem02079bac* arr;
    unsigned char* extra;
};

typedef void (*ElemFn02079bac)(struct Header02079bac*, void*);
typedef void (*ObjFn02079bac)(struct Header02079bac*);

int GetLow12BitsTimes8(struct S02079ce8* p);

// USA: func_02079bac
// JPN: func_02079bac
extern "C" ARM int func_02079bac(struct Header02079bac* obj, SafeAllocator* alloc, void* src, ElemFn02079bac cb, ObjFn02079bac cb2
#if !defined(jpn)
    , SafeAllocator* alloc2
#endif
) {
#if defined(jpn)
    SafeAllocator* alloc2 = alloc;
#endif
    int size1;
    unsigned int size2;
    int i;
    struct Elem02079bac* e;
    int cnt;

    if (alloc == 0 || src == 0) {
        return 0;
    }
#if !defined(jpn)
    if (alloc2 == 0) {
        alloc2 = alloc;
    }
#endif
    memcpy(obj, src, 4);
    size1 = GetLow12BitsTimes8((struct S02079ce8*)obj);
    size2 = obj->hi;
    obj->arr = size1 ? (struct Elem02079bac*)alloc->Allocate(size1) : 0;
    obj->extra = size2 ? (unsigned char*)alloc2->Allocate(size2) : 0;
    if (obj->arr != 0) {
        memcpy(obj->arr, (char*)src + 4, size1);
    }
    if (obj->extra != 0) {
        memcpy(obj->extra, (char*)src + (GetLow12BitsTimes8((struct S02079ce8*)obj) + 4), size2);
    }
    if (cb != 0) {
        if (obj->arr != 0) {
            cnt = (short)obj->count;
            if (cnt != 0 && cb != 0) {
                for (i = 0, e = obj->arr; i < cnt; i++, e++) {
                    cb(obj, e);
                }
            }
        }
    }
    if (cb2 != 0) {
        cb2(obj);
    }
    obj->flag = 1;
    return 1;
}
