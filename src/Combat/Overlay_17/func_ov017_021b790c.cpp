#include <globaldefs.h>

#if defined(jpn)
#define SCENE_NODES_021b790c 0x4ec
#define SCENE_NODE_021b790c 0x93c
#define SCENE_ID_BASE_021b790c 0x4200
#define SCENE_ID_OFFSET_021b790c 0x12
#define SCENE_EVENT_FLAG_021b790c 0xc2
#define SCENE_COMBATANT_FLAGS_021b790c 0x180
#define SCENE_ZONE_LOCKS_021b790c 0x444
#define SCENE_ZONE_FLAG_021b790c 0x125
#define SCENE_COMBATANT_ID_021b790c 0x1a6
extern "C" char data_ov017_021d8358[];
extern "C" char data_ov017_021d8395[];
extern "C" char data_ov017_021d83c0[];
#else
#define SCENE_NODES_021b790c 0x6fc
#define SCENE_NODE_021b790c 0xb5c
#define SCENE_ID_BASE_021b790c 0x4400
#define SCENE_ID_OFFSET_021b790c 0xc2
#define SCENE_EVENT_FLAG_021b790c 0x2e2
#define SCENE_COMBATANT_FLAGS_021b790c 0x18c
#define SCENE_ZONE_LOCKS_021b790c 0x424
#define SCENE_ZONE_FLAG_021b790c 0x105
#define SCENE_COMBATANT_ID_021b790c 0x1b2
#endif
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Zone3D.h"
#include "Graphics/LightingManager.h"

struct HeadList020469f8;
struct HeadNode020469f8;
struct ListHead02046b60;
struct Actor0209c20c;
struct Actor0209c678;
struct Bytes02033b88;
struct S_a0810;
struct S_a01ec;
struct MainBlock0205859c;
struct Struct020a27cc;
struct Struct020A2800;
struct AxisFloats0203b57c;
struct EffectParam02070900;
struct Rgb02070900;
struct Timer020707c8;

struct Context021b790c {
    char pad0[0x8e14];
    signed char mode;
};

struct Controller021b790c {
    void* obj;
#if defined(jpn)
    char pad4[0x868 - 0x4];
    int ready;
    char pad86c[0x1789 - 0x86c];
    unsigned char flags195b;
    char pad178a[0x17e1 - 0x178a];
#else
    char pad4[0x998 - 0x4];
    int ready;
    char pad99c[0x195b - 0x99c];
    unsigned char flags195b;
    char pad195c[0x19b1 - 0x195c];
#endif
    unsigned char field_19b1;
    unsigned char field_19b2;
};

struct Search021b790c {
    char pad0[0xfc0];
    int busy;
};

struct BattleScene021b790c {
    unsigned char field_0;
    unsigned char done;
    char pad2[0x1c - 0x2];
    unsigned char info[0x24 - 0x1c];
    unsigned short id;
    char pad26[0x28 - 0x26];
    int field_28;
    char pad2c[0x3e - 0x2c];
    unsigned short field_3e;
    char pad40[0x46 - 0x40];
    unsigned char member;
    char pad47;
    int field_48;
    char pad4c[0x6ac - 0x4c];
    void* field_6ac;
    Context021b790c* context;
    unsigned short state;
    unsigned short flags;
    unsigned int timer;
    char pad6bc[0x6c6 - 0x6bc];
    unsigned char field_6c6;
    unsigned char field_6c7;
    unsigned short field_6c8;
};

struct BattleBlock021b790c {
    char pad0[0x68];
    char sub[0xb0 - 0x68];
};

struct Party021b790c {
    char pad0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct ZoneInfo021b790c {
    char pad0[0xc];
    unsigned char lo : 5;
    unsigned char mode : 2;
    unsigned char hi : 1;
};

struct Desc021b790c {
    char pad0[0x18];
    int field_18;
    char pad1c[0x34 - 0x1c];
};

struct Obj021b790c {
    char data[0xc];
};

struct Hud021b790c {
#if defined(jpn)
    char pad[0x97];
#else
    char pad[0x9b];
#endif
    unsigned char active;
    void SetActive(unsigned char v) { active = v; }
};

static inline Hud021b790c* GetHud(GameResources* res) {
    return (Hud021b790c*)res->unknown_ptr_array_371c[6];
}

extern char data_02109bf4[];

extern "C" Search021b790c* func_0202ae18(void);
Controller021b790c* GetGlobalField0x1c020421a0(void);
unsigned int* GetDataPtr02114e04_020d6c00(void);
void PushInputLogA(int id);
void ResetInputLogB();
extern "C" void func_ov017_021b71d8(BattleScene021b790c* self);
extern "C" void func_ov017_021b7284(BattleScene021b790c* self);
int GetState0209ca68(char* p);
extern "C" void func_ov017_021b621c(void* node, void* allocator, void* obj);
void PrependNodeToHead(HeadList020469f8* list, HeadNode020469f8* node);
extern "C" void func_ov000_02160620(void* p);
int IsCombatWorkFlag0x400Set(void* p);
GameObject* GetCombatantWithFlag0x100(GameState* gs, int id);
void ApplyFlag0x80ToBit0x1ClearFlag0x100(void* obj);
unsigned char GetField0x5729Value(char* gs);
void SetField0x5729Value(char* gs, unsigned char value);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
extern "C" void func_ov017_021aa4cc(void* res, int flag);
int LoadBattleBlock020ac4c0(void* dst);
void AddClamped24BitFieldAt0x40(S_a0810* s, unsigned int v);
void AddClamped16BitFieldAt0x18(S_a01ec* s, unsigned int v);
int CopyInBattleField0x7540(void* src);
extern "C" unsigned char* func_02012fe4(void);
void SetOrClearBit(unsigned char* obj, int bit, int set);
extern "C" int func_ov000_0215e9fc(void* battle, short* buf, int max, int start);
extern "C" int func_ov017_021959b4(void);
extern "C" void* func_0205ec34(void);
extern "C" int _Z25ClearField0x498Dispatch10Pvi(void* p, Desc021b790c* desc);
extern "C" int _Z25ClearField0x498Dispatch0FPvi(void* p, Desc021b790c* desc);
extern "C" void func_0206f81c(void* p);
int IsField0xcNonNegative(int* obj);
void ResetMpForFlaggedCombatants02010604(GameState* gs, int a, int b, int c);
extern "C" void func_0209c530(void* p);
int ListContainsId(ListHead02046b60* list, int id);
void InitActorContext0209c20c(Actor0209c20c* actor);
void DispatchContextByState0209c678(Actor0209c678* actor, int arg);
extern "C" int func_0202c540(void* p);
extern "C" void func_02048150(GameObject* m, int a, int b);
int SetByte0xbeShiftPrev(Bytes02033b88* p, int val);
int GetField0x3acValue(GameState* gs);
extern "C" void func_ov017_021cedf4(int id, int a, int b);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_02191108(void* self, int a, int b, int c, int d);
void SetByteField0x253(void* obj);
extern "C" void _ZN6Zone3D10SwitchZoneEt(Zone3D* zone, int id, int flag);
extern "C" void func_02015438(void* zone);
extern "C" MainBlock0205859c* func_02057924(void);
void ResetBattleEncounterState0205859c(MainBlock0205859c* p);
int GetFieldIfFlag4(char* gs);
void SetVec3ComponentsAndApply020a27cc(Struct020a27cc* s);
void ConfigureVec3AndApply020a2800(Struct020A2800* s);
void InitVec3ParamsVariant8b33(void* s);
void SetMainBrightness(GameResources* res, int level, int b);
void SetFieldForMatchingCombatant_021c98f4(int target, int flag);
extern "C" void func_ov017_021b6f9c(BattleScene021b790c* self);
void* GetGlobalResetObj020d7a50(void);
extern "C" void func_02046380(void* obj);
extern "C" void __clear(void* buf, int n);
void InitObjFromCombatant020e4c74(void* out, GameObject* obj);
int CallFunc020e0434With02153694(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void func_02046608(void* ctrl, int a, char* fmt, char* dst, int b, int c, int d);
int GetAxisIntValue(AxisFloats0203b57c* s, int axis);
extern "C" int abs(int x);
extern "C" void* func_020704fc(void);
void SetColoredEffectParam02070900(EffectParam02070900* p, Rgb02070900* rgb, unsigned int v);
void UpdateInterpTimer020707c8(Timer020707c8* t);
#if defined(jpn)
extern "C" void func_0204500c(void* obj, char* buffer, int a);
#else
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
#endif
void InitFields02042b3c(void* obj);
#if defined(jpn)
extern "C" void func_020d7e10(void* receiver, char* input, int style, int flag, int a);
#else
extern "C" void func_020d7e10(void* receiver, char* input, int style, int flag, int a, int b);
#endif
void OrBitsIntoField0(unsigned int* obj, unsigned int mask);
void EnqueueEventTag128_021cbf18(unsigned char a, unsigned short b);
extern "C" void func_ov017_021b86f8(BattleScene021b790c* self, int id, int showMessage, int arg3);
extern "C" int func_ov017_02195658(void* res);
void ClearBitAt0x34(unsigned char* obj, int index);
void SetIntField0x264(void* obj, int v);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(void* obj);
int GetField0x397cValue(GameState* gs);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
int GetSignedByte0x1ca(void* obj);

// USA: func_ov017_021b790c
extern "C" ARM void func_ov017_021b790c(BattleScene021b790c* self, ListHead02046b60* list) {
    GameState* gs = GameState::GetInstance();
    char* res = (char*)func_ov017_0218b5b0();
    GameObject* obj = gs->GetUnknownGameObject();
    Controller021b790c* ctrl = GetGlobalField0x1c020421a0();
    Search021b790c* search = func_0202ae18();
    unsigned int* flagWord = GetDataPtr02114e04_020d6c00();

    if (!(self->flags & 0x100)) {
        PushInputLogA(0);
        ResetInputLogB();
        self->flags |= 0x800;
        func_ov017_021b71d8(self);
        func_ov017_021b7284(self);
    }

    unsigned short state = self->state;
    if (state == 6) {
        if (GetState0209ca68(data_02109bf4) != 2) {
            HeadList020469f8* nodes = *(HeadList020469f8**)(res + 0x3000 + SCENE_NODES_021b790c);
            HeadNode020469f8* node = *(HeadNode020469f8**)(res + 0x3000 + SCENE_NODE_021b790c);
            func_ov017_021b621c(node, 0, 0);
            *(unsigned short*)((char*)node + 0xfe) = self->field_28;
            PrependNodeToHead(nodes, node);
        }
        self->state = 0;
    } else if (state == 0) {
        func_ov000_02160620(self->field_6ac);
        if (IsCombatWorkFlag0x400Set(self->field_6ac) == 0) return;
        void* search2 = func_0202ae18();
        self->flags |= 0x1000;
        *(unsigned short*)(res + SCENE_ID_BASE_021b790c + SCENE_ID_OFFSET_021b790c) = self->id;
        Party021b790c* party = (Party021b790c*)GetPtrField0x2a04(gs);
        GameState* gs2 = GameState::GetInstance();
        int i;
        for (i = 0; i < 4; i++) {
            GameObject* c = GetCombatantWithFlag0x100(gs2, i);
            if (c != NULL) {
                ApplyFlag0x80ToBit0x1ClearFlag0x100(c);
            }
        }
        if (self->context->mode == 2) {
            if (GetField0x5729Value((char*)gs) == 0) {
                SetField0x5729Value((char*)gs, 1);
                for (i = 0; i < 4; i++) {
                    GameObject* m = gs->GetPartyMemberByIndex(i);
                    if (m != NULL && !(**(int**)((char*)m + 0x130) & 1) &&
                        TestBitAt0x34(self->info, (unsigned char)i) == 0) {
                        SetField0x5729Value((char*)gs, 0);
                    }
                }
            }
            if (GetField0x5729Value((char*)gs) == 0) {
                func_ov017_021aa4cc(res, 1);
            }
        }
        int allOk = 1;
        for (int j = 0; j < party->count; j++) {
            GameObject* m = gs->GetPartyMemberByIndex(party->ids[j]);
            if (m != NULL && !(**(int**)((char*)m + 0x130) & 1)) {
                allOk = 0;
            }
        }
        if (allOk) {
            BattleBlock021b790c block;
            LoadBattleBlock020ac4c0(&block);
            AddClamped24BitFieldAt0x40((S_a0810*)&block, 1);
            AddClamped16BitFieldAt0x18((S_a01ec*)block.sub, 1);
            CopyInBattleField0x7540(&block);
            SetOrClearBit(func_02012fe4(), 3, 1);
        }
        short ids[4];
        int count = func_ov000_0215e9fc(self->context, ids, 4, 0);
        for (int k = 0; k < count; k++) {
            GameObject* m = gs->GetPartyMemberByIndex(ids[k]);
            if (m != NULL) {
                *((unsigned char*)m + 0xc3) = 0x96;
            }
        }
        if (self->field_28 >= 0 && func_ov017_021959b4() == 0) {
            void* p = func_0205ec34();
            Desc021b790c desc;
            memset(&desc, 0, sizeof(desc));
            desc.field_18 = self->field_28;
            if (self->context->mode == 2) {
                if (_Z25ClearField0x498Dispatch10Pvi(p, &desc)) {
                    func_0206f81c(&desc);
                }
            } else {
                if (_Z25ClearField0x498Dispatch0FPvi(p, &desc)) {
                    func_0206f81c(&desc);
                }
            }
        }
        if (GetField0x5729Value((char*)gs) != 0) {
            if (IsField0xcNonNegative((int*)self->info)) {
                ResetMpForFlaggedCombatants02010604(gs, 1, 1, self->field_3e);
                self->flags |= 0x2000;
            } else {
                ResetMpForFlaggedCombatants02010604(gs, 1, 1, 0);
                self->flags |= 0x2000;
            }
        }
        func_0209c530(data_02109bf4);
        if (self->context->mode == 2 || ListContainsId(list, 4) != 0) {
            InitActorContext0209c20c((Actor0209c20c*)data_02109bf4);
        }
        if (ListContainsId(list, 4) != 0) {
            self->flags &= ~0x1000;
            GetHud((GameResources*)res)->SetActive(1);
            DispatchContextByState0209c678((Actor0209c678*)data_02109bf4, 0);
            if (allOk && self->field_28 >= 0 && func_0202c540(search2) != 0) {
                GameObject* hero = gs->GetProtagonist();
                if (hero != NULL && (**(int**)((char*)hero + 0x130) & 1)) {
                    func_02048150(hero, 0, 1);
                    *(unsigned short*)(*(char**)((char*)hero + 0x130) + 4) = 1;
                    *(unsigned int*)((char*)hero + SCENE_COMBATANT_FLAGS_021b790c) &= ~1;
                    SetByte0xbeShiftPrev((Bytes02033b88*)hero, 0);
                }
                unsigned char id = GetField0x3acValue(gs);
                func_ov017_021cedf4(id, 1, 0);
                func_ov017_021c9e00(id, 0, 0, 1);
            }
        }
        func_ov017_02191108(res, 1, 1, 1, 1);
        if (obj != NULL) {
            SetByteField0x253(obj);
        }
        unsigned char* zone = func_02012fe4();
        if (self->flags & 0x400) {
            BackgroundLoader* loader = BackgroundLoader::GetInstance();
            _ZN6Zone3D10SwitchZoneEt((Zone3D*)zone, *(unsigned short*)zone, 0);
            while (*(int*)(zone + SCENE_ZONE_LOCKS_021b790c) != 0) {
                loader->RemoveAllLocks();
                func_02015438(zone);
            }
        }
        ResetBattleEncounterState0205859c(func_02057924());
        zone[SCENE_ZONE_FLAG_021b790c] &= ~1;
        int flagObj = GetFieldIfFlag4((char*)gs);
        switch ((*(ZoneInfo021b790c**)(zone + 8))->mode) {
        case 0:
            SetVec3ComponentsAndApply020a27cc((Struct020a27cc*)flagObj);
            break;
        case 1:
            ConfigureVec3AndApply020a2800((Struct020A2800*)flagObj);
            break;
        case 2:
            InitVec3ParamsVariant8b33((void*)flagObj);
            break;
        default:
            ConfigureVec3AndApply020a2800((Struct020A2800*)flagObj);
            break;
        }
        char* lighting = (char*)LightingManager::GetInstance();
        *(float*)(lighting + 0x94) = gs->GetDayTimer();
        *(int*)(lighting + 0x98) = gs->GetTimeOfDay();
        ((LightingManager*)lighting)->RecomputeAdvancedLighting();
        ((LightingManager*)lighting)->SubmitToRenderConfig();
        self->state = 5;
    } else if (state == 5) {
        if (self->flags & 0x1000) {
            if (ListContainsId(*(ListHead02046b60**)(res + 0x3000 + SCENE_NODES_021b790c), 3) == 0) {
                SetMainBrightness((GameResources*)res, 0, 0x1e);
            }
        }
        SetFieldForMatchingCombatant_021c98f4(*(unsigned short*)((char*)gs->GetUnknownGameObject() + SCENE_COMBATANT_ID_021b790c), 0);
        func_ov017_021b6f9c(self);
        self->done = 1;
    } else if (state == 2) {
        unsigned short prev = self->timer;
        if (self->timer < 500) {
            self->timer += gs->GetEffectiveDeltaTime();
        }
        if (prev < 500 && self->timer >= 500) {
            GameObject* unk = gs->GetUnknownGameObject();
            void* reset = GetGlobalResetObj020d7a50();
#if defined(jpn)
            char text[0x64];
            __clear(text, sizeof(text));
            if (unk != NULL) {
                sprintf(text, data_ov017_021d8358, *(char**)((char*)unk + 0x134));
            }
#else
            func_02046380(ctrl);
            char text[0x64];
            char name[0x64];
            __clear(text, sizeof(text));
            __clear(name, sizeof(name));
            if (unk != NULL) {
                Obj021b790c who;
                InitObjFromCombatant020e4c74(&who, gs->GetUnknownGameObject());
                ctrl->obj = &who;
                sprintf(name, (const char*)CallFunc020e0434With02153694(0x20));
                func_02046608(ctrl, 0xc, name, text, 0xe3, 0, 1);
            }
#endif
            if (abs(GetAxisIntValue((AxisFloats0203b57c*)res, 0)) == 0x10) {
                void* effect = func_020704fc();
                Obj021b790c rgb;
                __clear(&rgb, sizeof(rgb));
                SetMainBrightness((GameResources*)res, 0, 1);
                SetColoredEffectParam02070900((EffectParam02070900*)effect, (Rgb02070900*)&rgb, 0);
                UpdateInterpTimer020707c8((Timer020707c8*)effect);
#if defined(jpn)
                func_0204500c(ctrl, text, 0);
#else
                func_0204500c(ctrl, text, 0, 0xe3);
#endif
                ctrl->ready = 1;
                InitFields02042b3c(ctrl);
            } else {
#if defined(jpn)
                func_020d7e10(reset, text, 0, 0, 1);
#else
                func_020d7e10(reset, text, 0, 0, 1, 1);
#endif
            }
            if (IsField0xcNonNegative((int*)self->info)) {
                OrBitsIntoField0(flagWord, 0x200);
            }
        }
        if (self->field_6c7 == 0) {
            EnqueueEventTag128_021cbf18(0, self->id);
            self->field_6c7 = 1;
            self->field_6c8 = 0;
        } else if (self->field_6c7 != 0 && search->busy == 0) {
            self->field_6c8 += gs->GetEffectiveDeltaTime();
            if (self->field_6c8 > 3000) {
                if (self->field_6c7 == 1) {
                    func_ov017_021b86f8(self, self->id, 1, 0);
                }
                if (self->field_6c7 == 2) {
                    self->field_6c7 = 0;
                }
            }
        }
        int idx = func_ov017_02195658(res);
        if (idx >= 0) {
            ClearBitAt0x34(self->info, (unsigned char)idx);
        }
        if (*(unsigned char*)(res + 0x4000 + SCENE_EVENT_FLAG_021b790c) != 0) {
            func_ov017_021b86f8(self, self->id, 0, 0);
            SetIntField0x264(obj, 0);
            func_ov017_021b6f9c(self);
            self->done = 1;
        }
    } else if (state == 3) {
        if (ctrl->ready == 0) return;
        SetByteField0x253(obj);
        SetIntField0x264(obj, 0);
        func_ov017_021b6f9c(self);
        self->done = 1;
    } else if (state == 1) {
        if (*(unsigned char*)(res + 0x4000 + SCENE_EVENT_FLAG_021b790c) != 0) {
            func_ov017_021b6f9c(self);
            self->done = 1;
        }
        int idx = func_ov017_02195658(res);
        if (idx >= 0) {
            ClearBitAt0x34(self->info, (unsigned char)idx);
        }
    } else if (state == 4) {
        if (self->field_6c6 != 0) {
            Controller021b790c* c = GetGlobalField0x1c020421a0();
            ReinitController02043204((char*)c);
            func_02043124(c);
            unsigned char member;
            unsigned char useLeader;
            useLeader = self->field_48;
            member = self->member;
#if defined(jpn)
            char text[0x64];
            __clear(text, sizeof(text));
            if (useLeader != 0) {
                GameObject* m = GetCombatantWithFlag0x100(gs, GetField0x397cValue(gs));
                if (m != NULL) {
                    sprintf(text, data_ov017_021d8395, *(char**)((char*)m + 0x134));
                }
            } else {
                GameObject* m = gs->GetPartyMemberByIndex(member);
                if (m != NULL) {
                    GameObject* m2 = gs->GetPartyMemberByIndex(GetSignedByte0x1ca(m));
                    if (m2 != NULL) {
                        sprintf(text, data_ov017_021d83c0, *(char**)((char*)m2 + 0x134));
                    }
                }
            }
            func_0204500c(c, text, 0);
#else
            char text[0x100];
            Obj021b790c who;
            __clear(text, sizeof(text));
            if (useLeader != 0) {
                if (GetCombatantWithFlag0x100(gs, GetField0x397cValue(gs)) != NULL) {
                    InitObjFromCombatantId020e4bf4(&who, GetField0x397cValue(gs));
                    c->obj = &who;
                    sprintf(text, (const char*)CallFunc020e0434With02153694(0x21));
                }
            } else {
                GameObject* m = gs->GetPartyMemberByIndex(member);
                if (m != NULL) {
                    GameObject* m2 = gs->GetPartyMemberByIndex(GetSignedByte0x1ca(m));
                    if (m2 != NULL) {
                        InitObjFromCombatantId020e4bf4(&who, *(short*)((char*)m2 + 4));
                        c->obj = &who;
                        sprintf(text, (const char*)CallFunc020e0434With02153694(0x22));
                    }
                }
            }
            func_0204500c(c, text, 0, 0xe3);
            InitFields02042b3c(c);
#endif
            c->ready = 1;
            c->field_19b2 = 1;
            c->field_19b1 = 0;
            c->flags195b |= 2;
            self->field_6c6 = 0;
        }
        self->timer += gs->GetEffectiveDeltaTime();
        if (self->timer > 1000) {
            ReinitController02043204((char*)ctrl);
            func_02043124(ctrl);
            self->state = 6;
        }
    }
}
