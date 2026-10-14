#include <globaldefs.h>
#include "GameState/GameState.h"

struct U16Field0x6_020375f8;
void* FilterByTypeAndBytes020a86b8(int unused, int flag, unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4, unsigned char b5);

struct Evt021d18d8 {
    unsigned char pad0[4];
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char pad1[2];
    int extra;
};

// USA: func_ov017_021d18d8  (semantic: Dispatch021d18d8)
extern "C" ARM void* func_ov017_021d18d8(int id, struct Evt021d18d8* evt, GameState* battleStruct, int unused3) {
    GameObject* self = battleStruct->GetGameObjectByIndex(id);
    int flag = 1;
    GameObject* other = battleStruct->GetUnknownGameObject();
    if (((Object3D*)((struct U16Field0x6_020375f8*)self))->GetField06() != ((Object3D*)((struct U16Field0x6_020375f8*)other))->GetField06()) flag = 0;
    typedef void* (*Fn9)(int, int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, int);
    return ((Fn9)FilterByTypeAndBytes020a86b8)(id, flag, evt->b0, evt->b1, evt->b2, evt->b3, evt->b4, evt->b5, evt->extra);
}
