// JPN: func_ov017_021c8dfc
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

void* GetData02100044(void);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int flag);
extern "C" int func_ov000_0215eb1c(void* obj, short* buf, int max, int flag);
int GetSubstructByte0x1c(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct MsgBody021c894c {
    unsigned char partyBytes[4];
    unsigned char monsterBytes[8];
    unsigned short value;
    unsigned char pad[2];
};

struct Msg021c894c {
    unsigned char tag;
    unsigned char pad[3];
    struct MsgBody021c894c body;
};

// USA: func_ov017_021c894c
extern "C" ARM void func_ov017_021c894c(unsigned short value) {
    GameState* battleStruct = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    void* data = GetData02100044();
    void* field = _Z20GetField6b0_021b8470Pv(res->unknown_ptr_3718);
    if (field == NULL) {
        return;
    }

    struct Msg021c894c msg;
    short ids[8];
    memset(&msg, 0, sizeof(msg));
    struct MsgBody021c894c* body = &msg.body;
    msg.tag = 0x79;
    body->value = value;
    int i;
    for (i = 0; i < 4; i++) {
        body->partyBytes[i] = 0xff;
    }
    int j;
    for (j = 0; j < 8; j++) {
        body->monsterBytes[j] = 0xff;
    }

    int count = func_ov000_0215e9fc(field, ids, 8, 0x10);
    int k;
    for (k = 0; k < count; k++) {
        GameObject* c = battleStruct->GetCombatantByIndex(ids[k]);
        if (c != NULL) {
            body->partyBytes[ids[k]] = GetSubstructByte0x1c((unsigned char*)c);
        }
    }

    count = func_ov000_0215eb1c(field, ids, 8, 0x10);
    int m;
    for (m = 0; m < count; m++) {
        GameObject* c = battleStruct->GetCombatantByIndex(ids[m]);
        if (c != NULL) {
            int idx = ids[m] - 0xc0;
            body->monsterBytes[idx] = GetSubstructByte0x1c((unsigned char*)c);
        }
    }

    func_0205e330(data, &msg, 0);
}
