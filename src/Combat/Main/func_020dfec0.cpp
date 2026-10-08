#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Header020dffb8 {
    unsigned int count : 12;
    unsigned int size : 19;
    unsigned int flag : 1;
};

extern "C" int _Z24GetArrayByteSize020dffb8P14Header020dffb8(struct Header020dffb8* obj);

struct Container020dffc8 {
    unsigned int count : 12;
    unsigned int size : 19;
    unsigned int flag : 1;
    void* elements;
    void* strings;
};

struct Element020dffc8;
typedef int (*ElementCallback020dffc8)(struct Container020dffc8*, struct Element020dffc8*);
extern "C" int _Z22ForEachElement020dffc8P17Container020dffc8PFiS0_P15Element020dffc8E(struct Container020dffc8* self, ElementCallback020dffc8 cb);

struct Node020dfbdc;
int UpdateNodeField4(void* a, struct Node020dfbdc* node);

// USA: func_020dfec0
extern "C" ARM int func_020dfec0(struct Container020dffc8* self, SafeAllocator* alloc, void* fileData, unsigned int size) {
    ElementCallback020dffc8 cb;
    unsigned int bytes;
    unsigned int arrSize;

    if (alloc == 0 || fileData == 0 || size == 0) {
        return 0;
    }
    if (alloc == 0 || fileData == 0) {
        return 0;
    }
    memcpy(self, fileData, 4);
    bytes = _Z24GetArrayByteSize020dffb8P14Header020dffb8((struct Header020dffb8*)self);
    arrSize = self->size;
    if (bytes) {
        self->elements = alloc->Allocate(bytes);
    } else {
        self->elements = 0;
    }
    self->strings = arrSize ? alloc->Allocate(arrSize) : 0;
    if (self->elements) {
        memcpy(self->elements, (char*)fileData + 4, bytes);
    }
    if (self->strings) {
        memcpy(self->strings, (char*)fileData + (_Z24GetArrayByteSize020dffb8P14Header020dffb8((struct Header020dffb8*)self) + 4), arrSize);
    }
    cb = (ElementCallback020dffc8)UpdateNodeField4;
    if (cb) {
        _Z22ForEachElement020dffc8P17Container020dffc8PFiS0_P15Element020dffc8E(self, cb);
    }
    self->flag = 1;
    return 1;
}