#include <globaldefs.h>

struct ListNode02167434 {
    short id;
    unsigned short flags;
    char pad4[4];
    struct ListNode02167434* next;
};

struct BattleList02167434 {
    char pad0[8];
    struct ListNode02167434* head;
    char padc[0x3c];
    short field_0x48;
    short field_0x4a;
    short count;
    char pad4e[3];
    unsigned char nibbles[1];
};

struct Ctx0205ec34 {
    char pad[0x2cc];
    unsigned char nibbles[1];
};

struct GetTableByteOrFFData;
struct Obj0208bf28;

extern "C" short _Z28GetScaledFieldValue_02166684i(int a);
extern "C" short func_ov004_021666bc(void* a1, char* outFlag);
struct GetTableByteOrFFData* GetGlobal02109418(void);
extern "C" struct Ctx0205ec34* func_0205ec34(void);
unsigned char GetTableByteOrFF(struct GetTableByteOrFFData* s, unsigned int idx);
extern "C" int func_02095d30(struct GetTableByteOrFFData* list, int value, int mode);
extern "C" void func_ov004_02166198(void);
extern "C" void func_ov004_02165f2c(void);
extern "C" void func_ov004_02165ef4(void* a1);
extern "C" void func_ov004_02166730(void* a1, int a2);
extern "C" void* _Z40CheckTypeAndReturnNode_02165e70_02165e70Pvi(void* a, int key);
extern "C" void _Z18SetFieldD20208bf28P11Obj0208bf28ih(struct Obj0208bf28* obj, int value, unsigned char b);
extern "C" void func_ov004_02166bd8(void* a1);
extern "C" void func_ov011_021848a0(void* obj, int val);

extern struct BattleList02167434* data_ov004_0217101c;
static inline BattleList02167434* GetBattleList02167434() {
#if defined(jpn)
    return *(BattleList02167434**)((char*)&data_ov004_0217101c + 4);
#else
    return data_ov004_0217101c;
#endif
}

static inline unsigned char* GetNibbles(struct Ctx0205ec34* c) { return c->nibbles; }

// USA: func_ov004_02167434
extern "C" ARM int func_ov004_02167434(void* a1) {
    short target = _Z28GetScaledFieldValue_02166684i((int)a1);
    short id;
    char flag;
    short key = func_ov004_021666bc(a1, &flag);
    struct GetTableByteOrFFData* table = GetGlobal02109418();
    struct Ctx0205ec34* ctx = func_0205ec34();
    unsigned char slot = GetTableByteOrFF(table, (unsigned char)key);
    func_02095d30(table, slot, 1);

    unsigned char idx = slot >> 1;
    unsigned char* src = GetNibbles(ctx);
    unsigned char mask = (unsigned char)(slot & 1) == 0 ? 0xf0 : 0xf;
    unsigned char saved = src[idx] & ~mask;
    GetBattleList02167434()->nibbles[idx] &= mask;
    GetBattleList02167434()->nibbles[idx] |= saved;

    func_ov004_02166198();
    func_ov004_02165f2c();

    struct BattleList02167434* list = GetBattleList02167434();
    struct ListNode02167434* node = list->head;
    if (list->count != 0 && node != 0) {
        func_ov004_02165ef4(a1);
        short i = 0;
        while (node != 0 && target != i) {
            if (node->next == 0) {
                break;
            }
            i++;
            node = node->next;
        }
        func_ov004_02166730(a1, node->id);
        unsigned char b = flag;
        id = node->id;
        void* obj = _Z40CheckTypeAndReturnNode_02165e70_02165e70Pvi(a1, 7);
        if (obj != 0) {
            _Z18SetFieldD20208bf28P11Obj0208bf28ih((struct Obj0208bf28*)((char*)obj + 0x34), id, b);
        }
        func_ov004_02166bd8(a1);
        func_ov011_021848a0(a1, 0x6c);
    } else {
        unsigned char b = flag;
        void* obj = _Z40CheckTypeAndReturnNode_02165e70_02165e70Pvi(a1, 7);
        if (obj != 0) {
            _Z18SetFieldD20208bf28P11Obj0208bf28ih((struct Obj0208bf28*)((char*)obj + 0x34), 9999, b);
        }
        func_ov004_02166bd8(a1);
        if (list->field_0x48 == 0 && list->field_0x4a == 0) {
            func_ov011_021848a0(a1, 0x6b);
        } else {
            func_ov011_021848a0(a1, 0x12c);
        }
    }
    return 0;
}
