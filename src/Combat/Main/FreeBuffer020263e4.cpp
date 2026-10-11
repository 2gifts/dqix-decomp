#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct020263e4 {
#if defined(jpn)
    char pad[0x6c0];
#else
    char pad[0x76c];
#endif
    SafeAllocator* alloc;
    void* data;
    int unk774;
};

// USA: func_020263e4
ARM void FreeBuffer020263e4(struct Struct020263e4* obj) {
    if (obj->alloc != NULL && obj->data != NULL) {
        obj->alloc->Free(obj->data);
    }
    obj->alloc = NULL;
    obj->data = NULL;
    obj->unk774 = 0;
}
