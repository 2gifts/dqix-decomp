#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct StatusBits {
    unsigned short fieldA : 2;
    unsigned short fieldB : 4;
    unsigned short fieldC : 3;
    unsigned short state : 3;
    unsigned short : 4;
};

struct StatusMsgFields {
    unsigned short searchId;
    unsigned short index;
    struct StatusBits bits;
    unsigned char field6;
    unsigned char pad7;
    unsigned short maxHP;
    unsigned short maxMP;
    unsigned int fieldC;
};

struct StatusMsg {
    unsigned char tag;
    unsigned char pad[3];
    struct StatusMsgFields fields;
};

static inline struct StatusBits* GetStatusBits(GameObject* c) {
    return (struct StatusBits*)((unsigned char*)c->currentStats_ + 0x22);
}
static inline unsigned char GetFieldA(GameObject* c) { unsigned char v = GetStatusBits(c)->fieldA; return v; }
static inline unsigned char GetFieldB(GameObject* c) { unsigned char v = GetStatusBits(c)->fieldB; return v; }
static inline unsigned char GetFieldC(GameObject* c) { unsigned char v = GetStatusBits(c)->fieldC; return v; }
static inline unsigned char GetState(GameObject* c) { unsigned char v = GetStatusBits(c)->state; return v; }

// USA: func_ov017_021c6d50
extern "C" ARM void func_ov017_021c6d50() {
    GameState* bs = GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)func_ov017_0218b5b0() + 0x3000 + 0x718);
    unsigned char* search = (unsigned char*)func_ov017_021b8478(table);
    void* data = GetData02100044();

    struct StatusMsg msg;
    msg.tag = 0x6f;
    struct StatusMsgFields* fp = &msg.fields;

    for (int i = 0; i < 4; i++) {
        if (!TestBitAt0x34(search, (unsigned char)i)) {
            continue;
        }
        GameObject* c = bs->GetCombatantByIndex(i);
        if (*((unsigned char*)c->currentStats_ + 0x26) == 0) {
            continue;
        }
        fp->searchId = *(unsigned short*)(search + 0x8);
        fp->index = (unsigned short)i;
        fp->bits.fieldA = GetFieldA(c);
        fp->bits.fieldB = GetFieldB(c);
        fp->bits.fieldC = GetFieldC(c);
        fp->bits.state = GetState(c);
        fp->field6 = *((unsigned char*)c->currentStats_ + 0x24);
        fp->maxHP = c->baseStats_->primaryStats.maxHP;
        fp->maxMP = c->baseStats_->primaryStats.maxMP;
        func_0205e330(data, &msg, 0);
    }
}
