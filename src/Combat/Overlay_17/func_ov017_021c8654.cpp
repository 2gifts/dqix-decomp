#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void func_0202ae18(void);
void* GetPtrField0x2a04_02010828(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);

struct Buf021c8654 {
    unsigned char tag;
    unsigned char pad[3];
    int arr[4];
};

// USA: func_ov017_021c8654
extern "C" ARM void func_ov017_021c8654(void) {
    GameState* bs = GameState::GetInstance();
    func_0202ae18();
    void* ctx = GetData02100044_0202ae24();
    struct Buf021c8654 buf;
    buf.tag = 0x77;
    int* arr = buf.arr;
    for (int i = 0; i < 4; i++) {
        arr[i] = -1;
    }

    unsigned char* list = (unsigned char*)GetPtrField0x2a04_02010828(bs);
    for (int i = 0; i < list[0xf7c]; i++) {
        unsigned char* row = list + i;
        unsigned char id = row[0xf78];
        GameObject* c = GetCombatantWithFlag0x1000_0200ff58(bs, id);
        if (c == NULL) {
            arr[id] = *(int*)(list + 0xf6c);
        }
    }

    func_0205e330(ctx, &buf, 0);
}
