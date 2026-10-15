#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Obj020a8f60;
int GetElementsByteSize020a8f60(struct Obj020a8f60* obj);

struct Header020a8e9c {
    unsigned int count1 : 12;
    unsigned int count2 : 19;
    unsigned int flag : 1;
};

struct Obj020a8e9c {
    Header020a8e9c header;
    void* buf1;
    void* buf2;
};

// USA: func_020a8e9c
ARM void DeserializeElementBuffers020a8e9c(Obj020a8e9c* obj, SafeAllocator* allocator, void* src, unsigned int) {
    if (allocator == 0 || src == 0) return;
    memcpy(obj, src, 4);
    int size1 = GetElementsByteSize020a8f60((struct Obj020a8f60*)obj);
    unsigned int size2 = obj->header.count2;
    if (size1 != 0) obj->buf1 = allocator->Allocate(size1); else obj->buf1 = 0;
    if (size2 != 0) obj->buf2 = allocator->Allocate(size2); else obj->buf2 = 0;
    if (obj->buf1 != 0) {
        memcpy(obj->buf1, (char*)src + 4, size1);
    }
    if (obj->buf2 != 0) {
        memcpy(obj->buf2, (char*)src + (GetElementsByteSize020a8f60((struct Obj020a8f60*)obj) + 4), size2);
    }
    obj->header.flag = 1;
}
