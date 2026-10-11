#include <globaldefs.h>
#include "GameState/GameState.h"


struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);


struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

struct TailNode020469b4;
struct TailList020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

void InitObj021c2b28(void* objRaw, unsigned char a, unsigned char b);

struct Node021d24f0 {
    char pad0[4];
    unsigned char field4;
    char pad1[3];
    int field8;
};

// JPN: func_ov017_021d2974
// USA: func_ov017_021d24f0
extern "C" ARM void func_ov017_021d24f0(void* unused0, Node021d24f0* node, GameState* battleStruct) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec, regionalOffset1=0x990};
#else
 enum {regionalOffset0=0x6fc, regionalOffset1=0xbb0};
#endif
    int base = ((int)func_ov017_0218b5b0());
    struct TailList020469b4* list = *(struct TailList020469b4**)((char*)base + 0x3000 + regionalOffset0);
    if (ListContainsId((struct ListHead02046b60*)list, 0xa)) return;
    GameObject* c = battleStruct->GetUnknownGameObject();
    unsigned short u = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)c);
    if (node->field8 != u) return;
    if (ListContainsId((struct ListHead02046b60*)list, 0x1a)) return;
    struct TailNode020469b4* n2 = *(struct TailNode020469b4**)((char*)base + 0x3000 + regionalOffset1);
    if (*((unsigned char*)n2 + 2) != 0) return;
    InitObj021c2b28((void*)n2, 1, node->field4);
    AppendNodeToTail(list, n2);
}
