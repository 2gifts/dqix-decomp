#include <globaldefs.h>
#if defined(jpn)
enum { pointerArrayBaseOffset = 0x8c };
#else
enum { pointerArrayBaseOffset = 0x6c };
#endif

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_02012fe4(void);
void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index);
extern "C" void func_02018300(void* a, void* b, int c, int d, int e);
struct Owner02018b34;
struct Param02018b34;
struct Entry02018b34;
struct Entry02018b34* FindEntryByNodeIdAndKey(struct Owner02018b34* owner, struct Param02018b34* p);

struct ListNode_0215fb44 {
    char pad0[0x2c];
    unsigned char keyA;
    unsigned char keyB;
    unsigned short lowNibble2e : 4;
    unsigned short flags2e : 12;
    char pad30[0x40];
    struct ListNode_0215fb44* next;
};

// USA: func_ov001_0215fb44  (semantic: SetNodeFlagAndNotifyVariantB_0215fb44)
extern "C" ARM int func_ov001_0215fb44(char* args, int count) {
    int key0 = func_ov017_021d60f4(args);
    char* p = args + 0x8;
    args += 0x10;
    int key1 = func_ov017_021d60f4(p);
    int key2 = 1;
    int key3 = 1;
    if (count > 2) {
        key2 = func_ov017_021d60f4(args);
        args += 0x8;
    }
    if (count > 3) {
        key3 = func_ov017_021d60f4(args);
    }

    void* base = func_02012fe4();
    struct ListNode_0215fb44* node = (struct ListNode_0215fb44*)GetPointerFromArray0x3c((unsigned char*)base + pointerArrayBaseOffset, 2);
    while (node != NULL) {
        if (!(node->flags2e & 1) && node->keyA == key0 && node->keyB == key1) {
            node->flags2e = node->flags2e | 0x280;
            func_02018300(base, node, key2, key3, 0);
            struct Entry02018b34* entry = FindEntryByNodeIdAndKey((struct Owner02018b34*)base, (struct Param02018b34*)node);
            *(unsigned short*)((char*)entry + 2) |= 0x40;
        }
        node = node->next;
    }
    return 1;
}
