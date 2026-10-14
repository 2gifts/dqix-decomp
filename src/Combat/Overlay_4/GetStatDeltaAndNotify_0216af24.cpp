#include <globaldefs.h>

struct TableA68;
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
int IsValueEqual12_02042190(int x);

struct Node0216af24 {
    char pad0[0x20];
    void* field20;
    char pad1[0x36 - 0x24];
    unsigned short field36;
    short field38;
    char pad2[0x44 - 0x3a];
    unsigned char field44 : 4;
};

extern "C" void* func_ov011_021849c8(void* a);
extern "C" Node0216af24* func_ov023_021f6880(void* obj, int key);
int ScaleStatsIfType12_021f6f10(void* self);
extern "C" void* func_ov023_021fa598(void* p);
extern "C" int func_020420e8(void* value, int flag);

// USA: func_ov004_0216af24  (semantic: GetStatDeltaAndNotify_0216af24)
extern "C" ARM int func_ov004_0216af24(void* a, int key) {
    void* obj = func_ov011_021849c8(a);
    Node0216af24* node = func_ov023_021f6880(obj, key);
    if (!node) {
        return 0;
    }
    void* entry = node->field20;
    if (!entry) {
        Node0216af24* node2 = func_ov023_021f6880(obj, node->field36);
        if (ScaleStatsIfType12_021f6f10(node2) == 4) {
            struct TableA68* table = (struct TableA68*)func_ov023_021fa598(node2);
            entry = FindEntryByKey_02072a68(table, node->field38);
        }
    }
    int result = 0;
    if (entry) {
        result = func_020420e8(entry, IsValueEqual12_02042190(node->field44));
    }
    return result;
}
