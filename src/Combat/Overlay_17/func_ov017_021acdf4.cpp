#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"
#include "World/Object3D.h"

struct Obj020397cc;
struct StateFlags3c9;
struct Foo0207df50;
struct Base02010834;
struct S021b2ba0;
struct S021b2bf4;
struct S021b2c0c;
struct S021b2bdc;
struct TailList020469b4;
struct TailNode020469b4;
struct HeadList020469f8;
struct HeadNode020469f8;
struct Struct021b11b0;

#if defined(jpn)
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
extern "C" void func_0204500c(void* obj, const char* text, int value);
extern "C" char data_ov017_021d7f3b;
enum { ResourceClearA = 0x41fe, ResourceClearB = 0x4200, MessageDone = 0x17e2, MessageActive = 0x868, GameEvent = 0x7cb4, GameEventData = 0x7ca8 };
#else
enum { ResourceClearA = 0x44ae, ResourceClearB = 0x44b0, MessageDone = 0x19b2, MessageActive = 0x998, GameEvent = 0x7f88, GameEventData = 0x7f7c };
#endif

struct ObjParams02078484 {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    short f12;
    short f14;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3i position;
    int f38;
    int f3c;
    int f40;
    Vector3i scale;
};

struct Battle021acdf4 {
    char pad0;
    unsigned char done;
    char pad2[6];
    SafeAllocator allocator;
    char pad8[0x1c - 8 - sizeof(SafeAllocator)];
    unsigned char state;
    unsigned char timer;
    unsigned char members;
    unsigned char savedField;
    Vector3i savedPos;
    char pad2c[0x14];
    short task;
    char pad42[2];
#if defined(jpn)
    unsigned char sub44[0x20c - 0x44];
#else
    unsigned char sub44[0x27c - 0x44];
#endif
    unsigned char skipIntro;
    unsigned char mode;
    unsigned char shortPath;
    unsigned char noEvent;
    unsigned char special;
    unsigned char initCtx;
    unsigned char initPair;
};

extern "C" void* func_0202ae18(void);
extern "C" void* func_02057924(void);
void SetupAndDispatch0205c904(unsigned char* obj, int value);
void CancelPendingAction020397cc(Obj020397cc* obj, int arg1);
StateFlags3c9* GetGlobal02109030_020936f8(void);
int CheckFlag0x3c9Bit0OrByteNonPositive_0209494c(StateFlags3c9* g);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void func_020a0c0c(void);
void InitCombatPairAndResetGlobal_021adb50(char* self);
unsigned char* GetField0x3f8Address_0200fd0c(GameState* gs);
void InitStruct02070378(char* obj);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* flags, int mask);
void CopyInternalFields0207df50(Foo0207df50* p);
void ResetGlobalObjAndInitSelfPointer0205ce94(unsigned char* obj);
extern "C" int func_02057e6c(void* mgr, int id, SafeAllocator* alloc, void* data, unsigned int length, Foo0207df50* fields);
void CopyCountedBytesToIntArray02010834(Base02010834* base, int index, int* out, int* outCount);
extern "C" int func_0202c508(void* p);
extern "C" void _ZN8Vector3iaSERKS_(Vector3i* dst, const Vector3i& src);
unsigned int GetBitsInField4_0203b4fc(unsigned int* obj, unsigned int mask);
void FindNodeAndProcess02057fb4(void* list, int id, int params);
int CheckField0NonZero_0202b7d8(int* p);
void EnqueueEventTag17_021ce014(int id, unsigned short a, unsigned short b, unsigned short c);
void SetForwardAndStore0205ebc0(void* obj, int arg1, int arg2);
void DispatchIfField0xc4NonNeg_0205ebfc(void* obj, int a, int b);
void SetBrightness(GameResources* resources, int brightness, int duration);
void InitAndAppendState61_021a65c4(void* obj, unsigned char mode, int arg);
void InitAndResetHeader_0219e310(unsigned char* obj, int arg);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void ClearSubstructBytes_0200fb40(void* obj);
int CheckBitsInField0x63dc_02011b50(void* obj, int mask);
void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* name);
void SetFields30And34_021b2bd0(void* obj, int a, int b);
void SetBit4_021b2bf4(S021b2bf4* obj, unsigned int v);
void SetBit5_021b2c0c(S021b2c0c* obj, unsigned int v);
void SetBit3_021b2bdc(S021b2bdc* obj, unsigned int v);
void AllocateAndCopyBuf20_021689d8(SafeAllocator* a, void* target);
extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_02057f00(void* mgr, int id);
void ForwardField0xc0_0205ebec(void* obj);
void CallListIfFlagsSet_02197528(void);
void SetByteField0x253_020397c0(void* obj);
void ClearFlag0x1ceBit0x4_02039d58(unsigned char* obj);
extern "C" void func_ov017_021c37a4(void);
void InitState39_021b11b0(Struct021b11b0* obj);
void PrependNodeToHead(HeadList020469f8* list, HeadNode020469f8* node);
int GetGlobalField0x1c020421a0(void);
void InitObjFromCombatant020e4c74(void* out, GameObject* obj);
int CallFunc020e0434With02153694_020e51cc(int value);
#if !defined(jpn)
extern "C" void func_0204500c(void* obj, int a, int b, int c);
#endif
int GetFieldIfFlag4_020100f8(char* gs);
void StoreFields0x1e4And0x1e8IfNonZero_0202ea10(unsigned char* obj, int a, int b);
int GetField0x21c020a277c(void* obj);
void SetField0x21c_020a2770(void* obj, short v);
void Forward0205ec20(void* obj, void* a, int b);
extern "C" void func_ov017_02191108(GameResources* res, int a, int b, int c, int d);
void ReinitController02043204(char* obj);
extern "C" int _ZNK8Object3D10GetField06Ev(GameObject* obj);
extern "C" void func_ov017_021adb1c(Battle021acdf4* self);

extern AllocatorUnion data_02114e20;
extern char data_ov017_021d795c;
extern char data_ov017_021d7978;
extern unsigned short data_02114e30;
extern unsigned char data_02114e54[];
extern char data_02108760;
extern char data_ov017_021d798f;

struct BattleHud021acdf4 {
    char pad[0xa];
    unsigned char visible;
    void SetVisible(unsigned char v) { visible = v; }
};

static inline BattleHud021acdf4* GetBattleHud(GameResources* res) {
    return (BattleHud021acdf4*)res->unknown_ptr_array_3afc[0x24];
}

// USA: func_ov017_021acdf4
extern "C" ARM void func_ov017_021acdf4(Battle021acdf4* self, HeadList020469f8* list) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    GameObject* leader = gs->GetUnknownGameObject();
    void* mgr = func_02057924();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (leader == NULL) {
        self->done = 1;
        func_ov017_021adb1c(self);
    }
    unsigned int tick = gs->GetTickCount();
    SetupAndDispatch0205c904(self->sub44, tick ? tick : 1);
    CancelPendingAction020397cc((Obj020397cc*)leader, 1);
    *(short*)((char*)leader + 0xb2) = 0;

    if (self->state == 0) {
        if (self->special && !CheckFlag0x3c9Bit0OrByteNonPositive_0209494c(GetGlobal02109030_020936f8())) {
            return;
        }
        func_020a0cc4(0x7000);
        if (self->initPair) {
            InitCombatPairAndResetGlobal_021adb50((char*)self);
        }
        if (self->initCtx) {
            unsigned char* ctx = GetField0x3f8Address_0200fd0c(gs);
            InitStruct02070378((char*)ctx);
            ctx[2] = 1;
            *(unsigned short*)ctx = 0xc3b5;
            ctx[7] = 1;
            *(short*)(ctx + 0x1c) = 0;
            *(int*)(ctx + 0x10) = 0x48cc;
            *(int*)(ctx + 0x14) = 0x199;
            *(int*)(ctx + 0x18) = -0x733;
            ctx[0x66] = 1;
            ctx[0x65] = 1;
        }
        self->allocator.CreateTypeA(AllocateAligned4_02012d88(&data_02114e20, 0x7000), 0x7000);
        self->allocator.Reset();
        if (self->special) {
            self->task = loader->QueueLoadFile(&data_ov017_021d795c, &self->allocator);
        } else {
            self->task = loader->QueueLoadFile(&data_ov017_021d7978, &self->allocator);
        }
        self->state = 0xe;
    } else if (self->state == 0xe) {
        if (loader->GetTaskStatus(self->task) == 0) {
            return;
        }
        if (self->special && !self->noEvent) {
            if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x401) == 0 && data_02114e54[0x54] == 0) {
                return;
            }
        }
        Foo0207df50* fields = (Foo0207df50*)((char (*)[0x70])res->unknown_2cc)[0x1c];
        CopyInternalFields0207df50(fields);
        unsigned int length;
        void* data;
        loader->GetLoadedFileByID(self->task, &data, &length);
        if (data == NULL) {
            loader->RemoveTask(self->task);
            func_ov017_021adb1c(self);
            func_020a0c0c();
            self->done = 1;
            return;
        }
        if (self->special && !self->noEvent) {
            ResetGlobalObjAndInitSelfPointer0205ce94(self->sub44);
        }
        func_02057e6c(mgr, 8, &self->allocator, data, length, fields);
        loader->RemoveTask(self->task);
        self->state = 1;
    } else if (self->state == 1) {
        int count = 0;
        int ids[5];
        ObjParams02078484 params[5];
        Vector3i scale;
        void* search = func_0202ae18();
        CopyCountedBytesToIntArray02010834((Base02010834*)gs, *(short*)((char*)leader + 4), ids, &count);
        for (int i = 0; i < count; i++) {
            self->members |= 1 << ids[i];
        }
        if (gs->GetGameObjectByIndex(0xce) && func_0202c508(search)) {
            ids[count] = 0xce;
            self->members |= 0x10;
            count++;
        }
        GameObject* unk = gs->GetUnknownGameObject();
        int leaderId = -1;
        if (unk) {
            leaderId = *(short*)((char*)unk + 4);
        }
        for (int k = 0; k < count; k++) {
            GameObject* member = gs->GetGameObjectByIndex(ids[k]);
            if (member && ((Object3D*)member)->IsVisible() && ((Object3D*)member)->GetInheritedAlpha()) {
                if (GetBitsInField4_0203b4fc((unsigned int*)res, 4) == 0 || leaderId == ids[k]) {
                    params[k].f00 = 0;
                    params[k].f10 = 1;
                    params[k].f12 = 0;
                    params[k].f14 = -1;
                    params[k].f16 = -1;
                    params[k].f18 = -1;
                    params[k].f1a = -1;
                    params[k].f1c = -0x1000;
                    params[k].f20 = 0;
                    params[k].f24 = 0;
                    params[k].f28 = 0;
                    params[k].position.x = 0;
                    params[k].position.y = 0;
                    params[k].position.z = 0;
                    params[k].f38 = 0;
                    params[k].f3c = 0;
                    params[k].f40 = 0;
                    params[k].scale.x = 0x1000;
                    params[k].scale.y = 0x1000;
                    params[k].scale.z = 0x1000;
                    params[k].b0 = 0;
                    params[k].b1 = 0;
                    params[k].b2 = 1;
                    params[k].b3 = 0;
                    params[k].b4 = 0;
                    params[k].b5 = 0;
                    params[k].b6 = 0;
                    params[k].b7 = 0;
                    _ZN8Vector3iaSERKS_(&params[k].position, ((Object3D*)member)->position_);
                    _ZN8Vector3iaSERKS_(&params[k].scale, ((Object3D*)member)->GetScale());
                    FindNodeAndProcess02057fb4(mgr, 8, (int)&params[k]);
                }
            }
        }
        int id;
        unsigned char members;
        if (CheckField0NonZero_0202b7d8((int*)func_0202ae18()) && (members = self->members) != 0) {
            id = *(short*)((char*)leader + 4);
            EnqueueEventTag17_021ce014(id, 3, _ZNK8Object3D10GetField06Ev(leader), members);
        }
        if (self->special) {
            SetForwardAndStore0205ebc0(&data_02108760, 0xa3, 0xa3);
            DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, 5, 0);
        } else {
            SetForwardAndStore0205ebc0(&data_02108760, 0xb2, 0xb2);
            DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, 0, 0);
        }
        self->state++;
    } else if (self->state == 2) {
        self->timer += gs->GetTickCount();
        unsigned int limit = self->special ? 0x19 : 0x28;
        if (limit < self->timer) {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                    if (member) {
                        ((Object3D*)member)->EnableFlag(1);
                    }
                }
            }
            if (self->shortPath) {
                self->state = 0xa;
            } else {
                self->state++;
            }
        }
    } else if (self->state == 3) {
        self->timer += gs->GetTickCount();
        if (self->timer > 0x64) {
            if (self->noEvent) {
                SetBrightness(res, 0x10, 0x1e);
            } else {
                SetBrightness(res, -0x10, 0x1e);
            }
            self->state++;
        }
    } else if (self->state == 4) {
        self->timer += gs->GetTickCount();
        if (self->timer > 0x8c) {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                    if (member) {
                        ((Object3D*)member)->DisableFlag(1);
                    }
                }
            }
            if (!self->skipIntro) {
                if (self->special) {
                    InitAndAppendState61_021a65c4(res, 2, self->mode);
                } else {
                    InitAndAppendState61_021a65c4(res, 0, self->mode);
                }
                if (self->special && !self->noEvent) {
                    GetBattleHud(res)->SetVisible(1);
                }
            }
            if (self->skipIntro) {
                unsigned char* ctx;
                GameResources* res2;
                GameState* gs2;
                Battle021acdf4* other;
                gs2 = GameState::GetInstance();
                ctx = GetField0x3f8Address_0200fd0c(gs2);
                res2 = func_ov017_0218b5b0();
                other = (Battle021acdf4*)res2->unknown_ptr_array_3afc[9];
                InitStruct02070378((char*)ctx);
                ctx[4] = 0;
                ctx[5] = 1;
                *(unsigned short*)ctx = *(unsigned short*)((char*)gs2 + GameEvent);
                _ZN8Vector3iaSERKS_((Vector3i*)(ctx + 0x10), *(Vector3i*)((char*)gs2 + GameEventData));
                ctx[7] = 1;
                ctx[0x62] = 1;
                ctx[0x63] = other->mode;
                if (*(unsigned short*)((char*)gs2 + GameEvent) == 0x2710) {
                    *(short*)ctx = 0x170c;
                    *(int*)(ctx + 0x10) = -0x7000;
                    *(int*)(ctx + 0x14) = 0x2e1;
                    *(int*)(ctx + 0x18) = 0;
                    if (ctx[0x63]) {
                        ctx[0x64] = 1;
                    }
                }
                InitAndResetHeader_0219e310((unsigned char*)res2->unknown_ptr_array_36fc[4], 0);
                AppendNodeToTail((TailList020469b4*)res2->unknown_ptr_array_36fc[0], (TailNode020469b4*)res2->unknown_ptr_array_36fc[4]);
                ClearSubstructBytes_0200fb40(gs2);
                InitAndAppendState61_021a65c4(res, 0, self->mode);
            } else if (CheckBitsInField0x63dc_02011b50(gs, 1)) {
                TailList020469b4* tail;
                unsigned char* node = (unsigned char*)res->unknown_ptr_array_3afc[0x14];
                tail = (TailList020469b4*)res->unknown_ptr_array_36fc[0];
                InitObjState_021b2174(node);
                SetNameChecked_021b2ba0((S021b2ba0*)node, &data_ov017_021d798f);
                SetFields30And34_021b2bd0(node, (int)AllocateAndCopyBuf20_021689d8, OVERLAY_ID(4));
                SetBit4_021b2bf4((S021b2bf4*)node, 1);
                SetBit5_021b2c0c((S021b2c0c*)node, 1);
                SetBit3_021b2bdc((S021b2bdc*)node, 0);
                AppendNodeToTail(tail, (TailNode020469b4*)node);
            }
            if (func_0202c508(func_0202ae18())) {
                unsigned char* flags = (unsigned char*)func_0205ec34();
                SetOrClearBitInArray_0206df6c(flags, flags + 0x8c, 0x113d, 1);
            }
            if (self->noEvent) {
                self->state = 6;
            } else {
                self->state++;
            }
        }
    } else if (self->state == 5) {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        func_02057f00(mgr, 8);
        ForwardField0xc0_0205ebec(&data_02108760);
        CallListIfFlagsSet_02197528();
        self->done = 1;
        SetByteField0x253_020397c0(leader);
        ((Object3D*)leader)->SetInheritedAlpha(0x1f);
        ClearFlag0x1ceBit0x4_02039d58((unsigned char*)leader);
        func_ov017_021adb1c(self);
        func_020a0c0c();
        if (self->special) {
            func_ov017_021c37a4();
        }
        *(short*)((char*)res + ResourceClearA) = 0;
        *(short*)((char*)res + ResourceClearB) = 0;
    } else if (self->state == 6) {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        Struct021b11b0* node = (Struct021b11b0*)res->unknown_ptr_array_3afc[0xe];
        InitState39_021b11b0(node);
        PrependNodeToHead(list, (HeadNode020469f8*)node);
        self->state = 5;
    } else if (self->state == 0xa) {
        self->timer += gs->GetTickCount();
        if (self->timer > 0x37) {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    char* member = (char*)gs->GetPartyMemberByIndex(i != 4 ? i : 0xce);
                    if (member) {
                        ((Object3D*)member)->DisableFlag(1);
                        *(short*)(member + 0x12c) = 0;
                        *(int*)(member + 0x124) = *(int*)(member + 0x48) + 0x9ccc;
                        *(int*)(member + 0x128) = *(int*)(member + 0x48);
                    }
                }
            }
            char* g = (char*)GetGlobalField0x1c020421a0();
#if defined(jpn)
            SetIndexedName02046574((Obj02046574*)g, 0, *(char**)((char*)gs->GetUnknownGameObject() + 0x134));
            func_0204500c(g, &data_ov017_021d7f3b, 0);
#else
            char combatant[0xc];
            InitObjFromCombatant020e4c74(combatant, gs->GetUnknownGameObject());
            *(char**)g = combatant;
            func_0204500c(g, CallFunc020e0434With02153694_020e51cc(0x39), 0, 0xe3);
#endif
            g[MessageDone] = 0;
            *(int*)(g + MessageActive) = 1;
            unsigned char* obj = (unsigned char*)GetFieldIfFlag4_020100f8((char*)gs);
            StoreFields0x1e4And0x1e8IfNonZero_0202ea10(obj, 0xcc, 0x3e8);
            _ZN8Vector3iaSERKS_(&self->savedPos, *(Vector3i*)(obj + 0x10));
            self->savedField = GetField0x21c020a277c(obj);
            SetField0x21c_020a2770(obj, -1);
            _ZN8Vector3iaSERKS_((Vector3i*)(obj + 0x10), self->savedPos);
            Forward0205ec20(&data_02108760, 0, 0);
            DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, 1, 0);
            self->state++;
        }
    } else if (self->state == 0xb) {
        _ZN8Vector3iaSERKS_((Vector3i*)((char*)GetFieldIfFlag4_020100f8((char*)gs) + 0x10), self->savedPos);
        int settled = 1;
        for (int i = 0; i < 5; i++) {
            if (self->members & (1 << i)) {
                char* member = (char*)gs->GetPartyMemberByIndex(i != 4 ? i : 0xce);
                if (member && *(int*)(member + 0x124)) {
                    settled = 0;
                }
            }
        }
        if (settled) {
            self->timer = 0;
            self->state++;
        }
        return;
    } else if (self->state == 0xc) {
        self->timer += gs->GetTickCount();
        if (self->timer > 10) {
            self->state++;
        }
    } else if (self->state == 0xd) {
        char* g = (char*)GetGlobalField0x1c020421a0();
        SetField0x21c_020a2770((void*)GetFieldIfFlag4_020100f8((char*)gs), self->savedField);
        func_02057f00(mgr, 8);
        ForwardField0xc0_0205ebec(&data_02108760);
        for (int i = 0; i < 5; i++) {
            if (self->members & (1 << i)) {
                GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                if (member) {
                    ((Object3D*)member)->DisableFlag(1);
                }
            }
        }
        self->done = 1;
        func_ov017_02191108(res, 1, 1, 1, 1);
        SetByteField0x253_020397c0(leader);
        ReinitController02043204(g);
        func_ov017_021adb1c(self);
        func_020a0c0c();
    }
}
