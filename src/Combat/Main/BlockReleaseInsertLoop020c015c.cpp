#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct BlockedContextList;
void BlockCurrentContext(struct BlockedContextList* p);

struct Mutex;
void* LockMutex(Mutex*);
extern "C" void func_020bf79c(void* p);

ARM SignedAllocatorHeader* PopFirstAndDecOwnerRef020bf3c8(SignedAllocatorList* list);
void InsertAllocatorHeaderLocked(SignedAllocatorHeader* header);

struct RefNode020c80f8;
extern "C" void _Z11UnlockMutexP5Mutex(struct RefNode020c80f8* node);

// USA: func_020c015c  (semantic: BlockReleaseInsertLoop020c015c)
extern "C" ARM void func_020c015c(void *obj) {
    char *base = (char*)obj;
    for (;;) {
        BlockCurrentContext((BlockedContextList*)(base + 0x4c0));
    retry:
        LockMutex((Mutex*)(base + 0x4c8));
        {
            SignedAllocatorHeader *e = PopFirstAndDecOwnerRef020bf3c8((SignedAllocatorList*)(base + 0x4e0));
            if (e == 0) {
                _Z11UnlockMutexP5Mutex((RefNode020c80f8*)(base + 0x4c8));
            } else {
                func_020bf79c(e);
                InsertAllocatorHeaderLocked(e);
                _Z11UnlockMutexP5Mutex((RefNode020c80f8*)(base + 0x4c8));
                goto retry;
            }
        }
    }
}
