#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct BitArrayObj0205e830;
int TestBitInArray0x1524(struct BitArrayObj0205e830* obj, int index);
extern "C" GameResources* func_ov017_0218b5b0(void);
void* GetData02100044_0202ae24(void);
extern "C" void* func_0202ae18(void);

struct Node021d48f0 { unsigned char idx; };
Node021d48f0* PopAndRequeueNode_0205e41c(void* obj, int* outPtr);

typedef void (*Handler021d7f98)(int, Node021d48f0*, GameState*, GameResources*, void*);
extern Handler021d7f98 data_ov017_021d7f98[];

// USA: func_ov017_021d48f0  (semantic: DispatchQueuedNodeEvents_021d48f0)
extern "C" ARM void func_ov017_021d48f0(void) {
    GameState* bs = GameState::GetInstance();
    GameResources* ov = func_ov017_0218b5b0();
    void* data = GetData02100044_0202ae24();
    void* extra = func_0202ae18();
    int outVal;
    Node021d48f0* node;
    while ((node = PopAndRequeueNode_0205e41c(data, &outVal)) != NULL) {
        unsigned char idx = node->idx;
        if (idx < 0xbc) {
            if (TestBitInArray0x1524((struct BitArrayObj0205e830*)data, idx)) {
                data_ov017_021d7f98[idx](outVal, node, bs, ov, extra);
            }
        }
    }
}
