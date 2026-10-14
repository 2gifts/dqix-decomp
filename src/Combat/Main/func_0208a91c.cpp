#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_ov000_02154a04(int field0, int id, int flag, int p3);

struct Field148_0208a91c {
    char pad[0x10];
    unsigned int skip1 : 5;
    unsigned int category : 3;
    unsigned int rest : 24;
};

struct DispatchEntry_020f10b0 {
    int field0;
    int field4;
};
extern struct DispatchEntry_020f10b0 data_020f10b0[];

typedef int (*Fn0208a91c)(void*, int, int*, int);

// USA: func_0208a91c
extern "C" ARM int func_0208a91c(int* p0, int value, int id, int* outPtr, int p3) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = GetCombatantWithFlag0x400_0200fea4(bs, id);
    struct Field148_0208a91c* field148 = *(struct Field148_0208a91c**)((char*)c + 0x148);
    *p0 = value;
    int category = field148->category;
    if (category >= 8) {
        *outPtr = func_ov000_02154a04(*p0, id, 2, p3);
        return 2;
    } else {
        struct DispatchEntry_020f10b0* entry = &data_020f10b0[category];
        int flag = entry->field4;
        void* self = (char*)p0 + (flag >> 1);
        Fn0208a91c fn;
        if (flag & 1) {
            void* vtbl = *(void**)self;
            fn = *(Fn0208a91c*)((char*)vtbl + entry->field0);
        } else {
            fn = (Fn0208a91c)entry->field0;
        }
        return fn(self, id, outPtr, p3);
    }
}
