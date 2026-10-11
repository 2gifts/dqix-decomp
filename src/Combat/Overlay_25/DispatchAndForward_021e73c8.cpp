#include <globaldefs.h>
#include "GameState/GameState.h"

struct List02160094;
struct ListNode02160094;
struct ListNode020378dc;

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);
extern "C" void _ZN8Object3D6DetachEv(struct ListNode020378dc* node);
extern "C" int func_ov017_021917f0(int a, int b);

struct Obj021e73c8 {
    char pad[8];
    unsigned char field8;
};

// USA: func_ov025_021e73c8
ARM int DispatchAndForward_021e73c8(struct Obj021e73c8* obj, int v1, int unusedArg, void* a3) {
    int local[12];
    GameState* bs;
    GameObject* c;

    if (DispatchByIndex021820bc(a3, v1, obj->field8, (int)&local[0]) == 0) {
        return 1;
    }
    bs = GameState::GetInstance();
    c = bs->GetGameObjectByIndex(local[0]);
    if (c == NULL) {
        return 1;
    }
    _ZN8Object3D6DetachEv((struct ListNode020378dc*)c);
    if (obj->field8 >= 0x22 && obj->field8 <= 0x25) {
        struct ListNode02160094* node = GetNodeAtIndex02160094((struct List02160094*)v1, obj->field8 - 0x22);
        if (node != NULL) {
            func_ov017_021917f0(*(unsigned short*)((char*)node + 0x20), 1);
        }
    }
    return 1;
}
