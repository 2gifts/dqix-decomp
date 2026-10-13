#include <globaldefs.h>
#include "Combat/LootPointEvent.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"


struct Node021986fc {
    unsigned int unk0 : 16;
    unsigned int id : 7;
    unsigned int unk23 : 9;
    unsigned int unk4_0 : 17;
    unsigned int count : 4;
    unsigned int mask : 8;
    unsigned int unk4_29 : 3;
    LootPointState* entry;
    Vector3fix pos[8];
    struct Node021986fc* next;
};

struct Obj0208e7d0 {
    char pad0[4];
    struct Node021986fc* head;
};



struct Cursor021986fc {
    unsigned char padding0[0x38];
    int x, y;
    unsigned int field40, mode;
    unsigned char padding48[12];
    unsigned char active;
};

struct Event021986fc {
    unsigned char kind;
    unsigned char padding1[19];
};

struct Obj021ae800 {
    unsigned char pad0[0xc];
    unsigned short id;
    unsigned char pad0e[6];
    Vector3fix position;
    int field20;
    int field24;
};

struct TailList020469b4;
struct TailNode020469b4;
struct Vec3copy0202ec84;
struct Cont0208f3b4;
struct SearchStruct0202c1a4;


extern "C" Zone3D* func_02012fe4(void);
extern "C" Obj0208e7d0* func_0208e0a8(void);
extern "C" int _Z22IsMatchingName0208e824PvPc(void*, char*);
int CheckSubstructByte0x7cPositive(signed char*);
Cont0208f3b4* GetData02109020(void);
void* GetField0x3b0Value(GameState*);
extern "C" void _Z15InitObj0219a674Ph(unsigned char*);
extern "C" void func_ov017_0219b33c(void*, Event021986fc*);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" int _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(void*, Vec3copy0202ec84*, int*, int*);
extern "C" SearchStruct0202c1a4* func_0202ae18(void);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray(void*, unsigned char*, int, int);
extern "C" void _Z23RemoveNodeByKey0208f3b4P12Cont0208f3b4i(Cont0208f3b4*, int);
extern "C" int _Z27GetRandomTableEntry0208e7d0P11Obj0208e7d0(Obj0208e7d0*);
extern "C" void _Z32ResetHeaderAndAllocator_021ae800P11Obj021ae800(Obj021ae800*);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);

extern unsigned short data_02114e30[];
extern Cursor021986fc data_02114e54;

// JPN: func_ov017_021992ac
// USA: func_ov017_021986fc
extern "C" ARM void func_ov017_021986fc(GameResources* self) {
    Zone3D* zone = func_02012fe4();
    Zone3D_StructPtr_8* info = zone->pUnknownStruct_8_;
    Obj0208e7d0* list = func_0208e0a8();
    if (!_Z22IsMatchingName0208e824PvPc(list, info->mapShortName_)) return;
    GameState* gs = GameState::GetInstance();
    GameObject* actor = gs->GetUnknownGameObject();
    if (CheckSubstructByte0x7cPositive((signed char*)actor)) return;
    GetData02109020();
    Node021986fc* node = list->head;
    void* camera = GetField0x3b0Value(gs);

    int found = 0;
    unsigned int mask = 0;
    unsigned char idx = 0;
    unsigned char key = 0;
    for (; node != NULL; node = node->next, idx++) {
        if (node->entry != NULL) {
            for (unsigned int i = 0; i < node->count; i++) {
                unsigned int bit = 1 << i;
                if ((node->mask & bit) == 0) continue;
                if (node->pos[i].x - 2867 >= actor->obj3D_.position_.x) continue;
                if (node->pos[i].x + 2867 <= actor->obj3D_.position_.x) continue;
                if (node->pos[i].z - 2867 >= actor->obj3D_.position_.z) continue;
                if (node->pos[i].z + 2867 <= actor->obj3D_.position_.z) continue;
                key = i + idx * 8;
                found = 1;
                mask = bit;
                Event021986fc event;
                _Z15InitObj0219a674Ph((unsigned char*)&event);
                event.kind = 3;
                func_ov017_0219b33c(self, &event);
                break;
            }
            if (found) break;
        }
    }
    if (!found) return;

    int proceed = 0;
    if (TestFlag0SetAndFlag1Clear(data_02114e30, 1)) proceed = 1;
    int cursorX = -1;
    int cursorY = -1;
    if (data_02114e54.active && data_02114e54.mode < 10) { cursorX = data_02114e54.x; cursorY = data_02114e54.y; }
    int screenX, screenY;
    _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(camera, (Vec3copy0202ec84*)&actor->obj3D_.position_, &screenX, &screenY);
    if (cursorX > 0x70 && cursorX < 0x90 && cursorY > 0x28 && cursorY < 0x60) proceed = 1;
    else if (screenX - 12 < cursorX && cursorX < screenX + 12 && screenY - 12 < cursorY && cursorY < screenY + 12) proceed = 1;
    if (!proceed) return;

    EnqueueEventTag183_021d38f8(1, GetSearchStructCurrentArrEntry(func_0202ae18()), mask, node->id, node->entry);
    node->entry->fields.flags = ~mask & node->entry->fields.flags;
    node->mask = ~mask & node->mask;
    node->entry->fields.timer = node->entry->fields.count * 30;
    void* base = func_0205ec34();
    SetOrClearBitInArray(base, (unsigned char*)base + 0x8c, node->id + 0xc12, 1);
    _Z23RemoveNodeByKey0208f3b4P12Cont0208f3b4i(GetData02109020(), key);
    if (node->id >= 0x62) node->unk0 = _Z27GetRandomTableEntry0208e7d0P11Obj0208e7d0(list);
    _Z32ResetHeaderAndAllocator_021ae800P11Obj021ae800(static_cast<Obj021ae800*>(self->unknown_ptr_array_3afc[11]));
    static_cast<Obj021ae800*>(self->unknown_ptr_array_3afc[11])->id = node->unk0;
    static_cast<Obj021ae800*>(self->unknown_ptr_array_3afc[11])->position = actor->obj3D_.position_;
    static_cast<Obj021ae800*>(self->unknown_ptr_array_3afc[11])->field20 = 0;
    static_cast<Obj021ae800*>(self->unknown_ptr_array_3afc[11])->field24 = 0x1f;
    AppendNodeToTail(static_cast<TailList020469b4*>(self->unknown_ptr_array_36fc[0]), (TailNode020469b4*)static_cast<Obj021ae800*>(self->unknown_ptr_array_3afc[11]));
}
