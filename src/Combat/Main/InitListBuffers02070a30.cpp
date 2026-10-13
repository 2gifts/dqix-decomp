#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct02070af4;
extern int GetListDataSize(struct Struct02070af4*);

struct Struct02070a30 {
    unsigned int count : 12;
    unsigned int size2 : 19;
    unsigned int flag  : 1;
    void* buf1;
    void* buf2;
};

// USA: func_02070a30
ARM void InitListBuffers02070a30(struct Struct02070a30* obj, SafeAllocator* alloc, void* src, unsigned int sourceLength) {
    if (alloc == NULL || src == NULL) return;
    memcpy(obj, src, 4);
    int size1 = GetListDataSize((struct Struct02070af4*)obj);
    int size2 = obj->size2;
    if (size1 != 0) obj->buf1 = alloc->Allocate(size1);
    else obj->buf1 = NULL;
    if (size2 != 0) obj->buf2 = alloc->Allocate(size2);
    else obj->buf2 = NULL;
    if (obj->buf1) memcpy(obj->buf1, (char*)src + 4, size1);
    if (obj->buf2) memcpy(obj->buf2, (char*)src + (GetListDataSize((struct Struct02070af4*)obj) + 4), size2);
    obj->flag = 1;
}
