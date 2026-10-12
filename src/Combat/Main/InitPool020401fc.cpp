#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02040258;
ARM void Init02040258(struct Struct_02040258* obj);

struct Pool020401fc {
    unsigned int count;
    unsigned char field4;
    unsigned char field5;
    unsigned char pad6[2];
    void* elements;
};

#if defined(jpn)
#define InitPool020401fc func_020406f8
extern "C" ARM void InitPool020401fc(struct Pool020401fc* pool, unsigned int count, SafeAllocator* alloc);
#endif

// USA: func_020401fc
ARM void InitPool020401fc(struct Pool020401fc* pool, unsigned int count, SafeAllocator* alloc) {
    unsigned int i;
    pool->field4 = 0;
    pool->count = count;
    pool->field5 = 0;
    pool->elements = alloc->Allocate(pool->count * 0x3c);
    for (i = 0; i < pool->count; i++) {
        Init02040258((struct Struct_02040258*)((char*)pool->elements + i * 0x3c));
    }
}
