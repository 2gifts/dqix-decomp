#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Field0Low12_02079b94 {
    unsigned int value : 12;
};

struct Struct02079a58 {
    unsigned int count : 12;
    unsigned int size : 19;
    unsigned int flag : 1;
    void* p1;
    void* p2;
};

int GetField0Low12Times60(struct Field0Low12_02079b94* obj);

extern "C" void* memcpy(void* dst, const void* src, unsigned int len);

// USA: func_02079a58
// JPN: func_02079a58
extern "C" ARM int func_02079a58(Struct02079a58* obj, SafeAllocator* alloc, void* data,
                                 void (*cb)(Struct02079a58*, void*),
                                 void (*cb2)(Struct02079a58*)
#if !defined(jpn)
    , SafeAllocator* alloc2
#endif
) {
#if defined(jpn)
    SafeAllocator* alloc2 = alloc;
#endif
    if (alloc == NULL || data == NULL) {
        return 0;
    }

#if !defined(jpn)
    if (alloc2 == NULL) {
        alloc2 = alloc;
    }
#endif

    memcpy(obj, data, 4);

    unsigned int n = (unsigned int)GetField0Low12Times60((struct Field0Low12_02079b94*)obj);
    unsigned int m = obj->size;

    obj->p1 = (n != 0) ? alloc->Allocate(n) : NULL;
    obj->p2 = (m != 0) ? alloc2->Allocate(m) : NULL;

    if (obj->p1 != NULL) {
        memcpy(obj->p1, (unsigned char*)data + 4, n);
    }

    if (obj->p2 != NULL) {
        memcpy(obj->p2,
               (unsigned char*)data + (GetField0Low12Times60((struct Field0Low12_02079b94*)obj) + 4),
               m);
    }

    int i;
    void* p;
    int k;
    if (cb != NULL && (p = obj->p1) != NULL) {
        k = (int)obj->count;
        if (k != 0 && cb != NULL) {
            i = 0;
            while (i < k) {
                cb(obj, p);
                i++;
                #if defined(jpn)
                p = (void*)((unsigned char*)p + 0x34);
#else
                p = (void*)((unsigned char*)p + 0x3c);
#endif
            }
        }
    }

    if (cb2 != NULL) {
        cb2(obj);
    }

    obj->flag = 1;
    return 1;
}
