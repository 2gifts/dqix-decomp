#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"

extern "C" void _Z29ProcessCurrentContext020bdc60v();
extern "C" int func_020bd99c(void* obj);
extern "C" int func_020bdc24(void* objPtr);

struct Obj020bdb0c {
    HMRFAllocator* allocator;
    SignedAllocatorList list;
};

typedef void (*Callback020bdb0c)(void*, int, int, int);

// USA: func_020bdb0c
extern "C" ARM void func_020bdb0c(struct Obj020bdb0c* obj, int arg2) {
    SignedAllocatorList* childList;
    int anyInvoked;
    SignedAllocatorHeader* entry;
    entry = NULL;
    anyInvoked = 0;
    if (arg2 == 0) {
        func_020bd99c(obj);
        return;
    }
    if (arg2 < obj->list.numElements) {
        do {
            childList = (SignedAllocatorList*)obj->list.ElementBefore(NULL);
            entry = childList->ElementBefore(entry);
            if (entry != NULL) {
                do {
                    Callback020bdb0c cb = *(Callback020bdb0c*)((char*)entry + 0xc);
                    if (cb != NULL) {
                        cb((char*)entry + 0x20, *(int*)((char*)entry + 8), *(int*)((char*)entry + 0x10), *(int*)((char*)entry + 0x14));
                        anyInvoked = 1;
                    }
                    entry = childList->ElementBefore(entry);
                } while (entry != NULL);
            }
            obj->list.Remove((SignedAllocatorHeader*)childList);
        } while (arg2 < obj->list.numElements);
    }
    obj->allocator->RestoreState(arg2);
    if (anyInvoked) {
        _Z29ProcessCurrentContext020bdc60v();
    }
    obj->allocator->SaveCurrentState(obj->list.numElements);
    func_020bdc24(obj);
}