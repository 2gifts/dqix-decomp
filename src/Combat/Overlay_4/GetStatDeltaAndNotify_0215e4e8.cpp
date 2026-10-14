#include <globaldefs.h>

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);
int IsValueEqual12(int x);

struct Node0215e4e8 {
    char pad0[0x20];
    void* field20;
    char pad1[0x36 - 0x24];
    unsigned short field36;
    short field38;
    char pad2[0x44 - 0x3a];
    unsigned char field44 : 4;
};

extern "C" void* func_ov011_021849c8(void* a);
extern "C" Node0215e4e8* func_ov023_021f6880(void* obj, int key);
extern "C" unsigned int func_ov023_021f6f10(void* self);
int StringLength(const char* text);
extern "C" void* func_ov023_021fa598(void* p);
extern "C" int func_020420e8(void* value, int flag);

// USA: func_ov004_0215e4e8  (semantic: GetStatDeltaAndNotify_0215e4e8)
extern "C" ARM int func_ov004_0215e4e8(void* a, int key) {
    void* obj = func_ov011_021849c8(a);
    Node0215e4e8* node = func_ov023_021f6880(obj, key);
    if (!node) {
        return 0;
    }
    void* entry = node->field20;
    if (!entry) {
        Node0215e4e8* node2 = func_ov023_021f6880(obj, node->field36);
        if (func_ov023_021f6f10(node2) == 4) {
            struct TableA68* table = (struct TableA68*)func_ov023_021fa598(node2);
            entry = FindEntryByKey(table, node->field38);
        }
    }
    int result = 0;
    if (entry) {
#if defined(jpn)
        unsigned int length = StringLength((const char*)entry);
        result = (int)(length * node->field44) >> 1;
#else
        result = func_020420e8(entry, IsValueEqual12(node->field44));
#endif
    }
    return result;
}
