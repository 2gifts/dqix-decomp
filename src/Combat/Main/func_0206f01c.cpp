#include <globaldefs.h>
#include <std_library_functions.h>

#include "Memory/SafeAllocator.h"

struct Header0206f0f8;
struct Fixup0206ef48;

#if defined(jpn)
struct Entry0206f110;
#else
struct Entry0206f110 {
    char pad[0x1c];
};
#endif

struct EntryList0206f110 {
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Entry0206f110* entries;
};

#if defined(jpn)
extern "C" int func_02070248(struct Header0206f0f8*);
typedef int (*EntryCallback0206f01c)(void*, struct Fixup0206ef48*);
extern "C" int func_02070260(struct EntryList0206f110*, EntryCallback0206f01c);
extern "C" int func_020700ac(void*, struct Fixup0206ef48*);
#define GetEntryArrayByteSize func_02070248
#define InvokeCallbackForEachEntry func_02070260
#define RelocateThreeFields func_020700ac
#else
typedef void (*EntryCallback0206f01c)(struct EntryList0206f110*, struct Entry0206f110*);
int GetEntryArrayByteSize(struct Header0206f0f8* obj);
int InvokeCallbackForEachEntry(struct EntryList0206f110* self,
                                void (*callback)(struct EntryList0206f110*, struct Entry0206f110*));
int RelocateThreeFields(void* ctx, struct Fixup0206ef48* obj);
#endif

struct List0206f01c {
    unsigned int count : 12;
    unsigned int numItems : 19;
    unsigned int flag : 1;
    void* entries;
    void* extra;
};

// USA: func_0206f01c
extern "C" ARM void func_0206f01c(struct List0206f01c* self, SafeAllocator* alloc, unsigned char* src) {
    int size;
    int numItems;
    if (alloc == NULL || src == NULL) {
        return;
    }
    memcpy(self, src, 4);
    size = GetEntryArrayByteSize((struct Header0206f0f8*)self);
    numItems = self->numItems;
    if (size) {
        self->entries = alloc->Allocate(size);
    } else {
        self->entries = NULL;
    }
    self->extra = numItems ? alloc->Allocate(numItems) : NULL;
    if (self->entries != NULL) {
        memcpy(self->entries, src + 4, size);
    }
    if (self->extra != NULL) {
        memcpy(self->extra, src + (GetEntryArrayByteSize((struct Header0206f0f8*)self) + 4), numItems);
    }
    if ((void*)RelocateThreeFields != NULL) {
        InvokeCallbackForEachEntry((struct EntryList0206f110*)self,
                                   (EntryCallback0206f01c)RelocateThreeFields);
    }
    self->flag = 1;
}
