#include <globaldefs.h>
#include "GameState/GameState.h"

struct Owner021cd608 {
    char pad[8];
    unsigned short id;
};

extern "C" struct Owner021cd608* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
int GetField0x3acValue(GameState* battleStruct);
extern "C" int _Z23LoadBattleBlock020ac4c0Pv(void* dst);
int CopyInBattleField0x7540(void* src);
extern "C" void _Z26CopyFourAndSetFlag02163378PvPih(void* dst, int* src, unsigned char val);

struct S_a0858 {
    char pad[0x48];
    unsigned int value;
};

struct S_a0300 {
    char pad[0x24];
    unsigned int val : 24;
    unsigned int top : 8;
};

void AddSaturateField0x48(struct S_a0858* p, unsigned int amount);
void AddClamped24BitFieldAt0x24(struct S_a0300* p, unsigned int amount);

struct BattleBlock021cd608 {
    struct S_a0858 head;
    char pad0[0x68 - sizeof(struct S_a0858)];
    struct S_a0300 tail;
    char pad1[0xb0 - 0x68 - sizeof(struct S_a0300)];
};

struct Payload021cd608 {
    unsigned short id;
    unsigned short low[4];
    unsigned char high[4];
    unsigned char val;
    unsigned char apply;
};

struct Evt021cd608 {
    unsigned char tag;
    unsigned char pad[3];
    struct Payload021cd608 payload;
};

// USA: func_ov017_021cd608
extern "C" ARM void func_ov017_021cd608(int unused0, struct Evt021cd608* evt, int unused2, unsigned char* base) {
    int i;
    void* table = *(void**)(base + 0x3000 + 0x718);
    struct Payload021cd608* p = &evt->payload;
    int amounts[4];
    struct BattleBlock021cd608 block;

    struct Owner021cd608* owner = func_ov017_021b8478(table);
    if (owner->id != p->id) {
        return;
    }
    void* b = func_ov017_021b8468(table);
    if (b == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        amounts[i] = p->low[i] + (p->high[i] << 16);
    }
    if (p->apply) {
        int idx = GetField0x3acValue(GameState::GetInstance());
        _Z23LoadBattleBlock020ac4c0Pv(&block);
        AddSaturateField0x48(&block.head, amounts[idx]);
        AddClamped24BitFieldAt0x24(&block.tail, amounts[idx]);
        CopyInBattleField0x7540(&block);
    } else {
        _Z26CopyFourAndSetFlag02163378PvPih(b, amounts, p->val);
    }
}
