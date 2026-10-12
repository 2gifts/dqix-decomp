#include <globaldefs.h>
#include "GameState/GameState.h"

struct Node02154974 {
    unsigned char kind : 4;
    unsigned char index;
    short slot;
    char pad4[4];
    int key;
    char padc[0x11 - 0xc];
    char name[0x34 - 0x11];
    struct Node02154974* next;
};

struct Other02154974 {
    unsigned char type;
    char pad1[0x28 - 1];
    struct Other02154974* next;
};

struct Self02154974 {
    char pad0[0xd0];
    struct Node02154974* nodes;
    struct Other02154974* others;
    char padd8[0xf8 - 0xd8];
    unsigned int mode : 27;
};

struct Global02154974 {
    char pad0[0x98];
    unsigned int flags;
};

struct Emitter02154974 {
    unsigned int flags;
    char pad4[0x18 - 4];
    GameObject* object;
};

struct Active02154974 {
    char pad0[0xd4];
    unsigned char active : 1;
};

extern "C" {
struct Global02154974* _Z20GetGlobalPtr021075f4v(void);
void _Z18ClearCombatantSlotP9GameStatei(GameState* gs, int id);
struct Emitter02154974* _Z29FindEntryPointerByKey0203df78Pvi(void* list, int key);
int* _Z24GetEntryUnlessFlag0x8000P17EntryList_203dce4i(void* list, int id);
void* _Z17EmptyStub0203d004v(void* list);
int _Z28FindEntryIndexByName02040404P17Container02040404PKc(void* container, const char* name);
void _Z30ReleaseOrDecrementSlot0204039cP17Container0204039ci(void* container, int index);
void _Z13Reset02040504Pi(int* entry);
void _Z21SetSlotIfIndexBelow32P17SlotArray0203dd10ji(void* list, int index, int arg);
void _Z20CallByIndex_0215acd4i(int index);
void _Z17ClearBitsInField4Pjj(unsigned int* obj, unsigned int bits);
}

extern char data_ov001_02164bd1[];

// USA: func_ov001_02154974
extern "C" ARM void func_ov001_02154974(struct Self02154974* self) {
    GameState* gs = GameState::GetInstance();
    struct Global02154974* global = _Z20GetGlobalPtr021075f4v();
    GameResources* base = func_ov017_0218b5b0();
    struct Other02154974* other;
    struct Node02154974* node;
    struct Node02154974* walk;
    int i;

    for (other = self->others; other != 0; other = other->next) {
        for (walk = self->nodes; walk != 0; walk = walk->next) {
            if (walk->index != other->type) {
                continue;
            }
            if (walk->kind == 0 || walk->kind == 1 || walk->kind == 9 || walk->kind == 0xb || walk->kind == 0xc ||
                walk->kind == 0xd || walk->kind == 0xa || walk->kind == 4) {
                GameObject* obj = gs->GetGameObjectByIndex(walk->slot);
                if (obj != 0) {
                    Object3D* o = (Object3D*)obj;
                    unsigned char animFlags = o->animationFlags_;
                    const char* animName = (const char*)o->activeAnimationRecord_;
                    o->RemoveAnimationPackageByID(3);
                    if (o->MaybeSetRegularAnimation(animName, animFlags) == false) {
                        o->MaybeSetRegularAnimation(data_ov001_02164bd1, 0);
                    }
                }
            }
            break;
        }
    }

    i = 0;
    for (node = self->nodes; node != 0; node = node->next) {
        switch (node->kind) {
        case 5: {
            struct Emitter02154974* em = _Z29FindEntryPointerByKey0203df78Pvi(global, node->key);
            if (em != 0) {
                em->flags &= ~0x10000;
            }
            break;
        }
        case 4: {
            _Z18ClearCombatantSlotP9GameStatei(gs, node->slot);
            struct Emitter02154974* em = _Z29FindEntryPointerByKey0203df78Pvi(global, node->key);
            if (em != 0 && em->object != 0) {
                ((struct Active02154974*)em->object)->active = 0;
                em->flags &= ~0x10000;
            }
            break;
        }
        case 2:
        case 6:
        case 7:
        case 8:
            if (gs->GetGameObjectByIndex(node->slot) != 0) {
                _Z18ClearCombatantSlotP9GameStatei(gs, node->slot);
            }
            break;
        case 3: {
            int* entry = _Z24GetEntryUnlessFlag0x8000P17EntryList_203dce4i(global, node->slot);
            if (entry != 0) {
                void* container = _Z17EmptyStub0203d004v(global);
                _Z30ReleaseOrDecrementSlot0204039cP17Container0204039ci(
                    container, _Z28FindEntryIndexByName02040404P17Container02040404PKc(container, node->name));
                _Z13Reset02040504Pi(entry);
                _Z21SetSlotIfIndexBelow32P17SlotArray0203dd10ji(global, node->slot, i);
            }
            break;
        }
        case 13:
        case 12:
        case 11:
        case 10:
            break;
        }
        _Z20CallByIndex_0215acd4i(node->index);
    }

    if (self->mode == 0) {
        return;
    }
    if (self->mode & 1) {
        _Z17ClearBitsInField4Pjj((unsigned int*)base, 8);
    }
    if (self->mode & 2) {
        _Z17ClearBitsInField4Pjj((unsigned int*)base, 0x10);
    }
    if (self->mode & 4) {
        int j;
        for (j = 0; j < 4; j++) {
            GameObject* obj = gs->GetGameObjectByIndex(j);
            if (obj != 0) {
                ((Object3D*)obj)->DisableFlag(1);
            }
        }
    }
    if (self->mode & 8) {
        _Z17ClearBitsInField4Pjj((unsigned int*)base, 0x400);
    }
    if (self->mode & 0x20) {
        _Z20GetGlobalPtr021075f4v()->flags &= ~2;
    }
}