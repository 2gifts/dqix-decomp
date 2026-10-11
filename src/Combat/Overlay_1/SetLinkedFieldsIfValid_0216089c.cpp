#include <globaldefs.h>

struct Node021d6148;
void SetLinkIfType3_021d6148(Node021d6148* o, unsigned int v);
void* GetFieldPtrA0_021bbbe4(void* obj);
extern "C" char* func_ov017_0218b5b0(void);

struct TaggedPtr_021d6134 { int type; int *ptr; };
extern "C" void func_ov017_021d6134(TaggedPtr_021d6134* a, int val);

// USA: func_ov001_0216089c  (semantic: SetLinkedFieldsIfValid_0216089c)
extern "C" ARM int func_ov001_0216089c(void* self) {
#if defined(jpn)
    enum { queueOffset = 0x524 };
#else
    enum { queueOffset = 0x734 };
#endif
    char* node = (char*)GetFieldPtrA0_021bbbe4(*(void**)(func_ov017_0218b5b0() + 0x3000 + queueOffset));
    if (*(signed char*)node < 0) {
        return 0;
    }
    func_ov017_021d6134((TaggedPtr_021d6134*)self, *(unsigned char*)(node + 0x14));
    SetLinkIfType3_021d6148((Node021d6148*)((char*)self + 8), *(unsigned int*)(node + 0x18));
    return 1;
}
