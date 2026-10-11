#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"
#include "std_library_functions.h"

void* GetData02100044(void);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int flag);
extern "C" int func_ov000_0215eb1c(void* obj, short* buf, int max, int flag);
extern "C" void func_0205e330(void* a, void* b, int c);

struct PositionMsgFields {
    Vector3i position;
    short index;
    unsigned short id;
};

struct PositionMsg {
    unsigned char tag;
    unsigned char pad[3];
    struct PositionMsgFields fields;
};

// JPN: func_ov017_021c8c08
// USA: func_ov017_021c8758
extern "C" ARM void func_ov017_021c8758(unsigned short id) {
#if defined(jpn)
 enum { regionalOffset=0x508 };
#else
 enum { regionalOffset=0x718 };
#endif
    GameState* bs = GameState::GetInstance();
    unsigned char* base = (unsigned char*)func_ov017_0218b5b0();
    void* data = GetData02100044();
    void* field = _Z20GetField6b0_021b8470Pv(*(void**)(base + 0x3000 + regionalOffset));
    if (field == NULL) {
        return;
    }

    short ids[8];
    struct PositionMsg msg1;
    struct PositionMsg msg2;

    int count = func_ov000_0215e9fc(field, ids, 8, 0x10);
    for (int i = 0; i < count; i++) {
        GameObject* c = bs->GetCombatantByIndex(ids[i]);
        unsigned char* obj;
        if (c == NULL || (obj = *(unsigned char**)((unsigned char*)c + 0x13c)) == NULL) {
            continue;
        }
        memset(&msg1, 0, sizeof(msg1));
        msg1.tag = 0x78;
        struct PositionMsgFields* fp = &msg1.fields;
        fp->id = id;
        fp->index = ids[i];
        fp->position = *(Vector3i*)(obj + 0x10);
        func_0205e330(data, &msg1, 0);
    }

    count = func_ov000_0215eb1c(field, ids, 8, 0x10);
    for (int i = 0; i < count; i++) {
        GameObject* c = bs->GetCombatantByIndex(ids[i]);
        unsigned char* obj;
        if (c == NULL || (obj = *(unsigned char**)((unsigned char*)c + 0x13c)) == NULL) {
            continue;
        }
        memset(&msg2, 0, sizeof(msg2));
        msg2.tag = 0x78;
        struct PositionMsgFields* fp = &msg2.fields;
        fp->id = id;
        fp->index = ids[i];
        fp->position = *(Vector3i*)(obj + 0x10);
        func_0205e330(data, &msg2, 0);
    }
}
