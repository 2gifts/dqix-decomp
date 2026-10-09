#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj0205eaa0;
struct Obj0203a48c;
struct Obj0203a588;
struct Obj02176150;

struct InitStruct02078484Struct {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char flags11;
    short f12;
    short objectId;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3fix offset;
    Vector3fix rotation;
    Vector3fix scale;
};

struct Damage021e9d14 {
    char pad0[0xc];
    short amount;
};

struct ActionNode021e9d14 {
    char pad0[0x14];
    struct Damage021e9d14* damage;
    char pad18[0x1c - 0x18];
    short targetId;
    unsigned short targetValue;
    unsigned short actorId;
    char pad22[0x24 - 0x22];
    unsigned short value;
    char pad26[0x30 - 0x26];
    struct ActionNode021e9d14* next;
};

struct Slot021e9d14 {
    char pad0[0x10];
    struct ActionNode021e9d14* head;
};

struct Gauge021e9d14 {
    char pad0[6];
    unsigned short value;
};

struct Combatant021e9d14 {
    char pad0[0x130];
    struct Gauge021e9d14* gauge;
};

struct Entry021e9d14 {
    char pad0[0xe];
    unsigned short value;
};

void* GetActiveCombatWork(void);
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* work);
extern "C" int _Z16GetWord_021def24Pv(void* work);
extern "C" void* _Z20GetOffsetPtr02160f08Pv(void* work);
extern "C" void* _Z22GetNodeAtIndex0215feb4Pcii(char* base, int threshold, int slot);
extern "C" struct Entry021e9d14* _Z22FindEntryById_021dafd0Pci(char* obj, int id);
struct Obj0203a588* GetData02104b6c(void);
extern "C" void _Z23QueuePopupEntry0203a48cP11Obj0203a48ctP15Vec3Int0203a48chii(
    struct Obj0203a48c* obj, int id, Vector3fix* pos, int style, int field4, int field2);
extern "C" void* func_02057924(void);
extern "C" void _Z18InitStruct02078484P24InitStruct02078484Struct(struct InitStruct02078484Struct* p);
extern "C" void _Z26FindNodeAndProcess02057fb4Pvii(void* list, int id, int a3);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void _Z24SetShortField0xE02176150P11Obj02176150s(struct Obj02176150* obj, unsigned short val);

extern struct Obj0205eaa0 data_02108760;

// USA: func_ov025_021e9d14
extern "C" ARM void func_ov025_021e9d14(void) {
    void* work = GetActiveCombatWork();
    struct Slot021e9d14* slot = (struct Slot021e9d14*)_Z18GetSlotPtr02160f20Pv(work);
    if (_Z16GetWord_021def24Pv(work) != 0) {
        return;
    }
    GameState* battle = GameState::GetInstance();
    char* entries = (char*)_Z20GetOffsetPtr02160f08Pv(GetActiveCombatWork());
    struct ActionNode021e9d14* node = slot->head;
    if (_Z22GetNodeAtIndex0215feb4Pcii((char*)node, 0, 5) != NULL) {
        return;
    }
    for (; node != NULL; node = node->next) {
        int id = node->actorId;
        unsigned short value = node->value;
        struct Entry021e9d14* entry = _Z22FindEntryById_021dafd0Pci(entries, id);
        GameObject* actor = battle->GetCombatantByIndex(id);
        if (actor == NULL) {
            continue;
        }
        if (node->damage != NULL) {
            int amount = -node->damage->amount;
            if (amount > 0) {
                struct Obj0203a48c* popups = (struct Obj0203a48c*)GetData02104b6c();
                Vector3fix pos = actor->obj3D_.position_;
                pos.y += actor->obj3D_.GetHeight();
                _Z23QueuePopupEntry0203a48cP11Obj0203a48ctP15Vec3Int0203a48chii(popups, amount, &pos, 3, 0, 0);
                void* list = func_02057924();
                struct InitStruct02078484Struct req;
                _Z18InitStruct02078484P24InitStruct02078484Struct(&req);
                req.offset.y += actor->obj3D_.GetHeight() / 2;
                req.objectId = id;
                _Z26FindNodeAndProcess02057fb4Pvii(list, 0x10, (int)&req);
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x65, 0);
            }
        }
        int isPartyMember = (id >= 0 && id <= 3) ? 1 : 0;
        if (!isPartyMember && node->damage != NULL) {
            value = node->targetValue;
            entry = _Z22FindEntryById_021dafd0Pci(entries, node->targetId);
            actor = battle->GetCombatantByIndex(node->targetId);
        }
        if (entry != NULL && actor != NULL) {
            _Z24SetShortField0xE02176150P11Obj02176150s((struct Obj02176150*)entry, value);
            entry->value = value;
            ((struct Combatant021e9d14*)actor)->gauge->value = value;
        }
    }
}
