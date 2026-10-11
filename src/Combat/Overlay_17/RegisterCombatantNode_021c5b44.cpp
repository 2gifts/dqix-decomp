#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* FindCombatantByField16a_021a278c(void* unused, int val);
struct ListHead02046b38;
struct ListNode02046b38;
int ListContainsNode(struct ListHead02046b38* list, struct ListNode02046b38* target);
extern "C" void func_ov017_021b6f18(void* node);
void InitStruct_02196c08(unsigned char* obj);
extern "C" bool func_ov017_021b6e70(void* obj, int combatantId);
extern "C" void func_ov017_021b7104(unsigned char* dst, void* src);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Ctx021c5b44 {
#if defined(jpn)
    unsigned char pad0[0x4ec];
#else
    unsigned char pad0[0x6fc];
#endif
    void* list6fc;
    unsigned char pad2[0x718 - 0x6fc - 4];
    void* node718;
};

struct Buf021c5b44 {
    unsigned char field0;
    unsigned char field1;
    unsigned short field2;
    unsigned short field4;
    unsigned char pad6[2];
    unsigned int field8;
    unsigned char fieldc;
    unsigned char fieldd;
    unsigned char fielde;
    unsigned char fieldf;
    short field10;
    unsigned char field12;
    unsigned char pad13;
    unsigned int field14;
};

// JPN: func_ov017_021c5ff4
// USA: func_ov017_021c5b44  (semantic: RegisterCombatantNode_021c5b44)
extern "C" ARM void func_ov017_021c5b44(unsigned char arg0, int combatantId, unsigned int arg2, unsigned char arg3, unsigned char arg4) {
    GameState::GetInstance();
    void* baseRaw = (void*)(int)((int)func_ov017_0218b5b0());
    struct Ctx021c5b44* ctx = (struct Ctx021c5b44*)((char*)baseRaw + 0x3000);
    int id2 = -1;
    void* list = ctx->list6fc;
    void* node = ctx->node718;

    GameObject* combatant = FindCombatantByField16a_021a278c(baseRaw, combatantId);
    if (combatant != 0) {
        id2 = *(short*)((char*)combatant + 4);
    }

    if (!ListContainsNode((struct ListHead02046b38*)list, (struct ListNode02046b38*)node)) {
        func_ov017_021b6f18(node);

        struct Buf021c5b44 buf;
        InitStruct_02196c08((unsigned char*)&buf);

        buf.field0 = 0;
        buf.field1 = arg0;
        buf.field4 = combatantId;
        buf.field2 = id2;
        buf.field8 = arg2;
        buf.fieldf = arg3;

        func_ov017_021b6e70(&buf, id2);

        buf.field12 = arg4;

        func_ov017_021b7104((unsigned char*)node, &buf);

        AppendNodeToTail((struct TailList020469b4*)list, (struct TailNode020469b4*)node);
    }
}
