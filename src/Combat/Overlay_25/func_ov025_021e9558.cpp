#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Graphics/LightingManager.h"
#include "World/Object3D.h"

struct Flags02033fdc;
void ClearFlag0x4At0xe0(struct Flags02033fdc* p);
void ClearCombatantSlot(GameState* battleStruct, int id);
void* GetActiveCombatWork(void);
extern "C" void _Z25ForwardField0xc0_0205ebecPv(void* obj);
extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* obj, int index);

struct CombatNode021e9558 {
    char pad0[0x20];
    unsigned short id;
    char pad22[0xe];
    struct CombatNode021e9558* next;
};

struct CombatSlot021e9558 {
    char pad0[0x10];
    struct CombatNode021e9558* head;
};

struct CombatWork021e9558 {
    char pad0[0x5954];
    Object3D actors[2];
};

struct Obj021e9558 {
    char pad0[0x1c4];
    int field_0x1c4;
    char pad1c8[0x582 - 0x1c8];
    unsigned char taskCount;
    char pad583;
    unsigned short taskIds[8];
    char pad594[0x880 - 0x594];
    int loadTaskId;
};

extern "C" CombatSlot021e9558* _Z18GetSlotPtr02160f20Pv(void* work);
extern "C" void func_ov025_021e8bc4(struct Obj021e9558* obj, int priority);

extern unsigned int data_ov025_021ef990;
extern const char data_ov025_021ef8dc[];
extern char data_02108760[];

// USA: func_ov025_021e9558
extern "C" ARM void func_ov025_021e9558(struct Obj021e9558* obj) {
    GameState* gs = GameState::GetInstance();
    CombatWork021e9558* work = (CombatWork021e9558*)GetActiveCombatWork();
    CombatSlot021e9558* slot = _Z18GetSlotPtr02160f20Pv(work);
    void* list = func_02057924();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    for (int i = 0; i < obj->taskCount; i++) {
        loader->RemoveTask(obj->taskIds[i]);
    }
    obj->taskCount = 0;

    if (obj->loadTaskId >= 0) {
        loader->RemoveTask(obj->loadTaskId);
        obj->loadTaskId = -1;
    }

    func_ov025_021e8bc4(obj, 0);

    for (unsigned int i = 0; i < data_ov025_021ef990; i++) {
        func_02057f00(list, i + 100);
    }
    func_02057f00(list, 4);
    func_02057f00(list, 0x20);
    func_02057f00(list, 0x21);
    func_02057f00(list, 0x1b);
    func_02057f00(list, 0x19);
    func_02057f00(list, 0x1a);
    func_02057f00(list, 0x1f);
    func_02057f00(list, 0x21);
    func_02057f00(list, 0x22);
    func_02057f00(list, 0x23);
    func_02057f00(list, 0x24);
    data_ov025_021ef990 = 0;

    for (CombatNode021e9558* node = slot->head; node != NULL; node = node->next) {
        GameObject* c = gs->GetCombatantByIndex(node->id);
        if (c != NULL) {
            c->obj3D_.DisableFlag(0x800);
            ClearFlag0x4At0xe0((struct Flags02033fdc*)c);
        }
    }

    GameObject* holder = gs->GetGameObjectByIndex(200);
    if (holder != NULL) {
        GameObject* target = gs->GetGameObjectByIndex(holder->obj3D_.unknown_2_ * 12 + 0x1c);
        if (target != NULL) {
            target->obj3D_.MakeVisible();
        }
        holder->obj3D_.Detach();
        ClearCombatantSlot(gs, 200);
    }

    work->actors[0].MaybeSetRegularAnimation(data_ov025_021ef8dc, 1);
    work->actors[1].MaybeSetRegularAnimation(data_ov025_021ef8dc, 1);
    _Z25ForwardField0xc0_0205ebecPv(data_02108760);
    LightingManager::GetInstance()->BeginFade(0x1000, 1000);
    obj->field_0x1c4 = 0;
}
