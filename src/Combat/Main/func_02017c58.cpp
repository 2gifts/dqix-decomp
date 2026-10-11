#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0205ec34(void);
void* GetField0x3f8Address(GameState* battleStruct);
extern "C" void _Z16CallLoop0206eb20PvS_ii(void* a, void* b, int c, int limit);
extern "C" void func_0206ea8c(void* obj, unsigned char a, short b, int flag);

struct SubElem_02017c58 {
    unsigned short value;
    unsigned short flags;
    char pad[0x70 - 4];
};

struct ListNode_02017c58 {
    int id;
    char pad0[0x14 - 4];
    int count;
    char pad1[0x44 - 0x14 - 4];
    SubElem_02017c58* elems;
    char pad2[0x54 - 0x44 - 4];
    ListNode_02017c58* next;
};

// USA: func_02017c58
extern "C" ARM void func_02017c58(void* obj) {
    GameState* gs = GameState::GetInstance();
    if (gs == NULL) {
        return;
    }
    char* f3f8 = (char*)GetField0x3f8Address(gs);
    if (f3f8 == NULL) {
        return;
    }
    void* ctx = func_0205ec34();
    if (ctx == NULL) {
        return;
    }

    int i;
    for (i = 0; i < 2; i++) {
        _Z16CallLoop0206eb20PvS_ii(ctx, (void*)(unsigned char)i, 0, 0x7f);
        _Z16CallLoop0206eb20PvS_ii(ctx, (void*)(unsigned char)(unsigned int)i, 0x80, 0xff);
    }

    int count;
    int id;
    ListNode_02017c58* node = *(ListNode_02017c58**)((char*)obj + 0x41c);
    int j;
    while (node != NULL) {
        count = node->count;
        id = node->id;
        for (j = 0; j < count; j++) {
            SubElem_02017c58* e = &node->elems[j];
            if (e != NULL && (e->flags & 4) != 0) {
                func_0206ea8c(ctx, id, (short)(e->value + 0x80), 1);
            } else {
                func_0206ea8c(ctx, id, (short)e->value, 1);
            }
        }
        node = node->next;
    }
}
