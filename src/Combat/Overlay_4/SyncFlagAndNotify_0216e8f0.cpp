#include <globaldefs.h>
#include "GameState/GameState.h"

struct Node0216e8f0 {
    char pad[0xc];
    unsigned char field0xc;
};

struct Obj_02184ad8;
void SetField1c8True_02184ad8(struct Obj_02184ad8* obj);
void SetByte0x7f70(void* obj, unsigned char value);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" Node0216e8f0* func_ov023_021f6880(void* obj, int key);
int ScaleStatsIfType12_021f6f10(void* self);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#endif
static inline int GetSyncNodeType(void* node) {
#if defined(jpn)
    return func_ov023_021f6f10(node);
#else
    return ScaleStatsIfType12_021f6f10(node);
#endif
}

extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216e8f0  (semantic: SyncFlagAndNotify_0216e8f0)
extern "C" ARM int func_ov004_0216e8f0(void* obj) {
#if defined(jpn)
    enum { keyOffset = 0x8, stateOffset = 5 };
#else
    enum { keyOffset = 0xa, stateOffset = 3 };
#endif
    void* p = func_ov011_021849c8(obj);
    if (p) {
        Node0216e8f0* node = func_ov023_021f6880(p, *(unsigned short*)(data_ov004_02171034 + keyOffset));
        if (node) {
            node->field0xc &= ~0x10;
        }
    }
    SetField1c8True_02184ad8((struct Obj_02184ad8*)obj);
    GameState* bs = GameState::GetInstance();
    if (data_ov004_02171034[stateOffset] != 6) {
        Node0216e8f0* node2 = func_ov023_021f6880(p, 1);
        if (node2 && GetSyncNodeType(node2) == 0xb) {
            node2->field0xc &= ~0x8;
            SetByte0x7f70(bs, 1);
        }
    }
    return 0;
}
