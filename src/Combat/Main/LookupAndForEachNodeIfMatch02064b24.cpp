#include <globaldefs.h>

struct Node02064b24 {
    unsigned short id;      // 0x0
    char pad2[0x12];        // 0x2..0x13
    struct Node02064b24* next; // 0x14
};

struct Obj02064b24 { char pad0[0xc]; void* nodeHead; };

extern "C" struct Obj02064b24* func_02064490(void*, int, void*);
extern "C" int func_02061c04(void*, struct Node02064b24*, void*);

#if defined(jpn)
#define LookupAndForEachNodeIfMatch02064b24 func_02065e10
extern "C" ARM int LookupAndForEachNodeIfMatch02064b24(void* a, int mode, unsigned short id, void* c);
#endif

// USA: func_02064b24
ARM int LookupAndForEachNodeIfMatch02064b24(void* a, int mode, unsigned short id, void* c) {
    struct Obj02064b24* root = func_02064490(a, mode, c);
    if (root == NULL) return 0;
    *(int*)((char*)c + 0x30) = 0;
    struct Node02064b24* node = (struct Node02064b24*)root->nodeHead;
    for (; node != NULL; node = node->next) {
        if (node != NULL && node->id == id) {
            if (func_02061c04(a, node, c) == 0) return 0;
        }
    }
    return 1;
}
