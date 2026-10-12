#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct Obj020bd984;
void DestroyAllocator020bd984(struct Obj020bd984* obj);

struct Child020bc820 {
    char pad0[8];
    void* backref;   /* 0x08 */
};

struct ListEntry020bc820 {
    char pad0[0xc];
    SignedAllocatorList list;  /* 0x0c */
    char pad2[0xc];
};
extern struct ListEntry020bc820 data_0210f824[];

struct Obj020bc820 {
    char pad0[8];
    struct Obj020bd984* alloc;    /* 0x08 */
    struct Child020bc820* child;  /* 0x0c */
    int index;                    /* 0x10 */
};

#if defined(jpn)
#define ReleaseActorAndUnlink020bc820 func_020be2ec
extern "C" ARM void func_020be2ec(struct Obj020bc820* obj);
#endif

// USA: func_020bc820
ARM void ReleaseActorAndUnlink020bc820(struct Obj020bc820* obj) {
    struct Obj020bd984* a = obj->alloc;
    if (a == NULL) return;
    DestroyAllocator020bd984(a);
    if (obj->child != NULL) {
        obj->child->backref = NULL;
        return;
    }
    data_0210f824[obj->index].list.Remove((SignedAllocatorHeader*)obj);
}
