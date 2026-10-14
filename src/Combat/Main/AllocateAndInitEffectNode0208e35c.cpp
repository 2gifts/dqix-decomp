#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

extern "C" int func_ov017_0218b5b0(void);

struct TaggedValue02030b44;
struct Vector3i;

struct Cont0208e778;
struct Node0208e778;
void AppendNodeToCountedList0208e778(struct Cont0208e778*, struct Node0208e778*);

extern int data_02108fe4;

struct EffectNode0208e35c {
    struct {
        unsigned int reserved0 : 16;
        unsigned int val1 : 7;
        unsigned int val2 : 2;
        unsigned int pad0 : 7;
    } dw0;
    struct {
        unsigned int fieldA : 4;
        unsigned int reserved1 : 13;
        unsigned int fieldB : 4;
        unsigned int fieldC : 8;
        unsigned int pad1 : 3;
    } dw1;
    unsigned int dw2;
    int vec[7][3];
    char pad2[0xc];
    struct Node0208e778* next;
};

// USA: func_0208e35c
ARM int AllocateAndInitEffectNode0208e35c(char* v) {
    SafeAllocator* alloc = (SafeAllocator*)(func_ov017_0218b5b0() + 0x1a0);
    struct EffectNode0208e35c* node = (struct EffectNode0208e35c*)alloc->Allocate(0x70);
    node->next = NULL;
    int tag = ((Script::Parameter*)((struct Variant02030b0c*)v))->ToInt();
    node->dw0.val1 = tag;
    node->dw1.fieldB = 8;
    node->dw0.val2 = 1;
    v += 8;
    node->dw1.fieldA = 9;
    node->dw0.reserved0 = 0;
    for (int i = 0; i < 7; i++) {
        v = (char*)(TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)v))->ToVec3fix((Vector3i*)node->vec[i]);
    }
    node->dw2 = 0;
    node->dw1.fieldC = 0;
    AppendNodeToCountedList0208e778((struct Cont0208e778*)&data_02108fe4, (struct Node0208e778*)node);
    return 1;
}
