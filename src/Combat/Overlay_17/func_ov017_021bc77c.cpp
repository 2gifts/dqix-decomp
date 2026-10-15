#include <globaldefs.h>

#if defined(jpn)
enum { kGamePositionOffset = 0x6fa4, kGamePositionY = 0x6fb0, kGamePositionState = 0x6fb4, kResourceNodeOffset = 0x3508, kResourceHalfwordOffset = 0x41fc, kObject10c = 0x108, kObject114 = 0x110, kResourceFlagOffset = 0x40c2 };
#else
enum { kGamePositionOffset = 0x71e4, kGamePositionY = 0x71f0, kGamePositionState = 0x71f4, kResourceNodeOffset = 0x3718, kResourceHalfwordOffset = 0x44ac, kObject10c = 0x10c, kObject114 = 0x114, kResourceFlagOffset = 0x42e2 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/LightingManager.h"

enum { kInvalidId = -1 };

struct AllocatorUnion;

extern "C" void* func_0202ae18();
void* GetFieldIfFlag4_020100f8(char*);
extern "C" unsigned short* func_02012fe4();
extern "C" unsigned char* func_0205ec34();
unsigned int* GetDataPtr02114e04_020d6c00();
extern "C" void func_02019678(unsigned short* p, int v);
void ClearCombatantSlot_0200fd48(GameState* gs, int idx);
Object3D* GetField4334_021bdbc0(unsigned char*);
int TestFlagBitAt0x2744_0201bfc0(unsigned char*, int);
void InitContext020e1154(void*);
void SetField0x238True_020a2794(void* p);
void ApplyVecFromField0x21e_020a2744(char*);
void SetOrClearBitInArray_0206df6c(void*, unsigned char*, int, int);
extern "C" void func_ov017_0219b624(void* res);
void TailForward02012da4(AllocatorUnion* a, void* p);
int GetBitsInField0_0203b4c4(unsigned int*, unsigned int);
void* AllocateAligned4_02012d88(AllocatorUnion* a, unsigned int size);
extern "C" void func_ov017_021a2fa0(void* res);
int CheckField0NonZero_0202b7d8(int*);
struct FieldBlock63d6_11590;
int IsByte0x63d6Set_02011590(FieldBlock63d6_11590*);
void SetHalfword0x63d8_020115f4(void*, unsigned short);
extern "C" void func_ov017_021bb27c(void* self);
void ClearFields_021bb0c4(unsigned char*);
int LookupAndForEachNode020649b0(void*, int, void*);
extern "C" void func_0206f81c(void* node);
extern "C" int func_0202c540(void* p);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
extern "C" unsigned char* func_ov017_021b8478(unsigned char* p);
extern "C" void func_02046a8c(void* a, unsigned char* b);
int GetState0209ca68(char*);
extern "C" void func_0209c530(void* p);
void ClearBitsInField4_0203b4e8(unsigned int*, unsigned int);
void ClearBitsInWord_0203b4b0(unsigned int*, unsigned int);
unsigned char* GetField0x3f8Address_0200fd0c(GameState* gs);
void* GetData02153660_020e3808();
int GetField0x3acValue_020100a8(GameState* gs);
struct TagValueEntry020e385c;
void SetOrClearEntryBitAndNotify020e3a50(TagValueEntry020e385c*, int, int, int);
void ResetTaggedEntryAndNotifyOverlay020e3994(TagValueEntry020e385c*, int, int);
struct Fields020407b4;
void SetFields0x44(Fields020407b4*, int, int, int);
struct Obj02033874;
void SetVecYFromValue02033874(Obj02033874*, int);
void SetFlag0x1ceBit0x4_02039d48(unsigned char*);
void SetBrightness(GameResources*, int, int);
extern "C" int func_0209cd50(unsigned short id);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(Actor0209c3b4*, int);
extern "C" void func_ov017_021bd704(void* p);
void SetMainBrightness(GameResources*, int, int);
void EnqueueEventTag107_021cdd70(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e, unsigned short f, unsigned char g);
extern "C" void func_ov017_021b6728(void* res, int a, int b);
void SetByteField0x253_020397c0(void*);
void CopyByteField0x253To0x252_02039830(void*);
extern "C" int func_ov017_0219bddc(unsigned char* p);
extern "C" void func_ov017_0219bf04(int a, int b);
void SetByte1True_021c178c(unsigned char* p);
extern "C" void func_ov017_021b8bb0(unsigned short id);
void InitStruct02070378(char*);
void SetFlagBytes02017d68(void* p);
int PeekInputLogA_020a1eb0();
#if defined(jpn)
void ClearMultipleFieldBits_02156b20(void*);
#else
void IsFlag0x14Bit0x40Set_ov000_02156b20(GameObject*);
#endif
void SetByteIfDataAndCheckClear_021a01bc(unsigned char*);
extern "C" void func_0209c2e0(void* p, int a, int b);
void InitFieldsFromCombatant_0219bcac(unsigned char v);

extern AllocatorUnion data_02114e20;
extern char data_02109bf4[];

struct Block_021bc77c {
    int pad0[0x11];
    unsigned short flags;
    short s46;
    unsigned char pad48[0x20];
};

struct Node_021bc77c {
    int a;
    int b;
    int id;
    unsigned char pad[0x28];
};

struct Self_021bc77c {
    unsigned char unk0;
    unsigned char done;
    unsigned char pad2[6];
    unsigned short f8;
    unsigned short fa;
    Block_021bc77c blk;
    #if defined(jpn)
    unsigned char pad74[0x18];
#else
    unsigned char pad74[0x1c];
#endif
    int i90;
    unsigned char pad94[6];
    unsigned char b9a;
    unsigned char pad9b;
    unsigned char b9c;
    unsigned char pad9d[3];
    signed char sa0;
    unsigned char pada1;
    unsigned short ua2;
    unsigned char pada4[0x18];
    Vector3i vbc;
    short sc8;
    unsigned char padca[2];
    unsigned char bcc;
    unsigned char padcd[2];
    unsigned char bcf;
    unsigned char padd0[0x2d];
    unsigned char bfd;
    unsigned char padfe[0xd];
    unsigned char b10b;
    unsigned char pad10c[8];
    unsigned short u114;
    unsigned char pad116[4];
    unsigned short u11a;
    unsigned char pad11c[0x1c];
    SafeAllocator* alloc138;
    unsigned char b13c;
    unsigned char pad13d[3];
    unsigned short u140;
    unsigned short u142;
    unsigned char b144;
    unsigned char pad145;
    unsigned short u146;
    unsigned short u148;
    unsigned char pad14a[2];
    unsigned short u14c;
    unsigned short u14e;
    unsigned char pad150[0x34];
    unsigned short u184;
};

struct ResSub_021bc77c {
    #if defined(jpn)
    unsigned char pad0[0x420];
#else
    unsigned char pad0[0x630];
#endif
    int i630;
    unsigned char pad634[0xd8];
    unsigned char* p70c;
    unsigned char* p710;
    unsigned char pad714[4];
    unsigned char* p718;
    unsigned char pad71c[0x18];
    unsigned char* p734;
    #if defined(jpn)
    unsigned char pad738[0x410];
#else
    unsigned char pad738[0x420];
#endif
    unsigned char* pb58;
};

struct ResAlloc_021bc77c {
    unsigned char pad0[0xc4];
    SafeAllocator alloc;
};

struct ResView_021bc77c {
    unsigned char pad0[0x3000];
    ResSub_021bc77c sub;
};

#define RES_PTR(res, off) (((ResView_021bc77c*)(res))->sub.p##off)

static inline SafeAllocator* GetAllocator_021bc77c(GameResources* r, int i) {
    return &r->allocator_array_38[i];
}

static inline void InitAllocator_021bc77c(SafeAllocator* sa, unsigned int size) {
    sa->CreateTypeA(AllocateAligned4_02012d88(&data_02114e20, size), size);
}

static inline Vector3i GetPos_021bc77c(GameState* gs) {
    return *(Vector3i*)((unsigned char*)gs + kGamePositionOffset);
}

// USA: func_ov017_021bc77c
extern "C" ARM int func_ov017_021bc77c(Self_021bc77c* self, void* arg) {
    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
        return self->fa;
    }
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    void* x34 = func_0202ae18();
    GameObject* unk = gs->GetUnknownGameObject();
    GameObject* party0 = gs->GetPartyMemberByIndex(0);
    void* f28 = GetFieldIfFlag4_020100f8((char*)gs);
    unsigned short* p2;
    GameState* gs2;
    GameResources* res3;
    unsigned char* bits3;
    unsigned char* p14;
    unsigned char* p10;
    unsigned short* p = func_02012fe4();
    unsigned char* bits = func_0205ec34();
    p14 = RES_PTR(res, 710);
    unsigned char* r8 = RES_PTR(res, 718);
    p10 = RES_PTR(res, b58);
    GetDataPtr02114e04_020d6c00();
    {
        Block_021bc77c blk = self->blk;
        unsigned char b9c = self->b9c;
        gs2 = GameState::GetInstance();
        GameResources* res2 = func_ov017_0218b5b0();
        p2 = func_02012fe4();
        func_0202ae18();
        if (!(blk.flags & 0x400)) {
            func_02019678(p2, b9c);
        }
        for (int i = 0; i < 0x20; i++) {
            GameObject* o = gs2->GetGameObjectByIndex(i + 0xa0);
            if (o != 0) {
                o->obj3D_.Destroy();
                ClearCombatantSlot_0200fd48(gs2, i + 0xa0);
            }
        }
        ((ResView_021bc77c*)res2)->sub.i630 = 0;
        Object3D* obj = GetField4334_021bdbc0((unsigned char*)res2);
        if (obj != 0) {
            obj->MakeVisible();
        }
        if (TestFlagBitAt0x2744_0201bfc0((unsigned char*)p2, 1) || TestFlagBitAt0x2744_0201bfc0((unsigned char*)p2, 0)) {
            InitContext020e1154((void*)0x1388);
        }
    }
    SetField0x238True_020a2794(f28);
    ApplyVecFromField0x21e_020a2744((char*)f28);
    if (self->blk.s46 > kInvalidId) {
        SetOrClearBitInArray_0206df6c(bits, bits + 0x8c, self->blk.s46 + 0x38e, 1);
    }
    if (self->sa0 > kInvalidId && self->b9c) {
        SetOrClearBitInArray_0206df6c(bits, bits + 0x8c, self->sa0 + 0xbea, 1);
    }
    if (self->b9a) {
        func_ov017_0219b624(res);
    }
    if (self->alloc138) {
        SignedAllocatorHeader* h = self->alloc138->GetSignedAllocator();
        if (h) {
            self->alloc138->Destroy();
            TailForward02012da4(&data_02114e20, h);
        }
        self->alloc138 = 0;
    }
    if (!GetBitsInField0_0203b4c4((unsigned int*)res, 0x1000) || self->u11a == 0) {
        int size = self->i90;
        if (size) {
            SafeAllocator* sa = GetAllocator_021bc77c(res, 7);
            sa->CreateTypeA(AllocateAligned4_02012d88(&data_02114e20, size), size);
            func_ov017_021a2fa0(res);
            self->i90 = 0;
        } else if (self->blk.flags & 4) {
            func_ov017_021a2fa0(res);
        }
    }
    if (!CheckField0NonZero_0202b7d8((int*)x34) && IsByte0x63d6Set_02011590((FieldBlock63d6_11590*)gs)) {
        if (self->u11a) {
            SetHalfword0x63d8_020115f4(gs, self->u11a);
        }
        func_ov017_021bb27c(self);
        self->done = 1;
        return self->fa;
    }
    if (self->u11a) {
        self->f8 = self->u11a;
        self->bfd = 1;
        ClearFields_021bb0c4((unsigned char*)self);
        return 0;
    }
    if (*((unsigned char*)res + kResourceFlagOffset) == 0) {
        Node_021bc77c node;
        node.id = self->f8;
        if (LookupAndForEachNode020649b0(bits, 0xb, &node)) {
            func_0206f81c(&node);
        }
        if (func_0202c540(x34)) {
            int flag = 0;
            if (self->b13c == 2) {
                if (r8[2]) flag = 1;
            } else if (self->b13c == 1) {
                if (r8[2] && !TestBitInByteArray_0206dfb0((int)bits, bits + 0x8c, self->u148 + 0x38e)) {
                    if (self->u148 == 0xffff) {
                        if (self->u14c != *(unsigned short*)((unsigned char*)self + 0x18)) flag = 1;
                    } else {
                        flag = 1;
                    }
                }
            } else if (self->b13c == 0) {
                if (r8[2]) {
                    int v = *(int*)(func_ov017_021b8478(r8) + 0xc);
                    if (v != (short)self->u146) flag = 1;
                }
            }
            if (flag) {
                func_02046a8c(arg, r8);
                if (GetState0209ca68((char*)data_02109bf4) == 2) {
                    func_0209c530(data_02109bf4);
                }
                ClearBitsInField4_0203b4e8((unsigned int*)res, 4);
                ClearBitsInField4_0203b4e8((unsigned int*)res, 0x10);
                ClearBitsInField4_0203b4e8((unsigned int*)res, 2);
                ClearBitsInWord_0203b4b0((unsigned int*)res, 4);
                ClearBitsInWord_0203b4b0((unsigned int*)res, 0x800);
            }
        }
    } else {
        self->b13c = 2;
    }
    unsigned char* f = GetField0x3f8Address_0200fd0c(gs);
    void* tags = GetData02153660_020e3808();
    if (r8[2]) {
        SetOrClearEntryBitAndNotify020e3a50((TagValueEntry020e385c*)tags, GetField0x3acValue_020100a8(gs), 1, *(unsigned short*)((unsigned char*)self + 0x18));
    } else if (*(int*)(f + 0x20) <= 0 || f[2] == 0) {
        ResetTaggedEntryAndNotifyOverlay020e3994((TagValueEntry020e385c*)tags, 1, *(unsigned short*)((unsigned char*)self + 0x18));
    }
    if (self->bcc && self->bcf == 3) {
        SetFields0x44((Fields020407b4*)unk, 0x48cc, 0x199, -0x733);
        SetVecYFromValue02033874((Obj02033874*)unk, 0);
        for (int i = 1; i < 4; i++) {
            GameObject* m = gs->GetPartyMemberByIndex(i);
            if (m) {
                SetFields0x44((Fields020407b4*)m, 0x48cc, 0x199, -0x733);
                SetVecYFromValue02033874((Obj02033874*)m, 0x3244);
                SetFlag0x1ceBit0x4_02039d48((unsigned char*)m);
            }
        }
    }
    if (f[2]) {
        SetBrightness((GameResources*)res, -16, 0);
    } else if (p14[2]) {
        SetStateAndDispatch0209c3b4((Actor0209c3b4*)data_02109bf4, func_0209cd50(*p));
        func_ov017_021bd704(&self->blk);
        SetMainBrightness((GameResources*)res, 0, 0x28);
    } else if (r8[2]) {
        SetBrightness((GameResources*)res, -16, 0);
        *(unsigned short*)(r8 + 0x6c4) = self->u184;
        if (func_0202c540(x34)) {
            self->u14e = *(int*)(func_ov017_021b8478(*(unsigned char**)((unsigned char*)res + kResourceNodeOffset)) + 0xc);
            EnqueueEventTag107_021cdd70(self->u14e, 0, 0, 0, 0, 0, 0);
            unsigned char* q = RES_PTR(res, 70c);
            if (q[2]) {
                func_02046a8c(arg, q);
            }
            return 5;
        }
    } else if (self->bcc) {
        if (self->bcc == 1) {
            func_ov017_021b6728(res, self->bcf, -1);
        }
        if (self->bcf == 2) {
            SetByteField0x253_020397c0(unk);
            CopyByteField0x253To0x252_02039830(unk);
        }
        SetMainBrightness((GameResources*)res, 0, 0x28);
        func_ov017_021bb27c(self);
        self->done = 1;
        return self->fa;
    } else {
        int ok;
        unsigned short mapId;
        {
            unsigned short* p3;
            unsigned short id = self->f8;
            void* x = func_0202ae18();
            p3 = func_02012fe4();
            bits3 = func_0205ec34();
            res3 = func_ov017_0218b5b0();
            unsigned char* o = RES_PTR(res3, 734);
            unsigned char buf = 0;
            unsigned short cur = *p3;
            if (!func_0202c540(x)) { ok = 0; goto checked; }
            if (self->b13c != 1) { ok = 0; goto checked; }
            if (self->u140 != cur && self->u142 != cur) { ok = 0; goto checked; }
            if (!self->b144) { ok = 0; goto checked; }
            if (TestBitInByteArray_0206dfb0((int)bits3, bits3 + 0x8c, self->u148 + 0x38e)) { ok = 0; goto checked; }
            unsigned short v = self->u146;
            if (v == id) { ok = 0; goto checked; }
            if (id == 0x733c || id == 0x733f || id == 0x7342 || id == 0x7345 || id == 0x7348) {
                if (v == 0x733d || v == 0x7340 || v == 0x7343 || v == 0x7346 || v == 0x7349 || v == 0x721a ||
                    v == 0x7080) {
                    ok = 0;
                    goto checked;
                }
            }
            int r = func_ov017_0219bddc(&buf);
            if (r) {
                func_ov017_0219bf04(0, 1);
                o[kObject10c] = 1;
            }
            unsigned char* q = RES_PTR(res3, b58);
            if (q[2]) {
                if (r) {
                    SetByte1True_021c178c(q);
                    ok = 0;
                    goto checked;
                }
                if (self->u14c) {
                    *(unsigned short*)(o + kObject114) = self->u14c;
                } else {
                    *(unsigned short*)(o + kObject114) = self->u146;
                }
                ok = 0;
                goto checked;
            }
            if (!r) {
                ClearBitsInWord_0203b4b0((unsigned int*)res3, 0x10);
            }
            ok = r == 0;
        }
    checked:
        if (ok) {
        if (self->u14c) {
            self->f8 = self->u14c;
        } else {
            self->f8 = self->u146;
        }
        ClearFields_021bb0c4((unsigned char*)self);
        return 0;
    } else if (CheckField0NonZero_0202b7d8((int*)x34) && func_0202c540(x34) && party0 && (mapId = *p, mapId == party0->obj3D_.GetField06()) &&
               self->b13c == 0 && (short)self->u146 >= 0) {
        func_ov017_021b8bb0((short)self->u146);
    } else if (self->b9c && self->ua2 != *p) {
        InitStruct02070378((char*)f);
        f[2] = 1;
        *(unsigned short*)f = self->ua2;
        f[7] = 1;
        *(Vector3i*)(f + 0x10) = self->vbc;
        *(short*)(f + 0x1c) = self->sc8;
        SetBrightness((GameResources*)res, -16, 0);
    } else if (*(int*)((unsigned char*)gs + kGamePositionState) > 0) {
        InitStruct02070378((char*)f);
        f[2] = 1;
        *(unsigned short*)f = *(int*)((unsigned char*)gs + kGamePositionState);
        f[7] = 1;
        *(Vector3i*)(f + 0x10) = GetPos_021bc77c(gs);
        *(short*)(f + 0x1c) = *(int*)((unsigned char*)gs + kGamePositionY);
        *(int*)((unsigned char*)gs + kGamePositionState) = 0;
        SetBrightness((GameResources*)res, -16, 0);
        SetFlagBytes02017d68(func_02012fe4());
    } else {
        if (PeekInputLogA_020a1eb0() == 1) {
#if defined(jpn)
            ClearMultipleFieldBits_02156b20(self);
#else
            IsFlag0x14Bit0x40Set_ov000_02156b20((GameObject*)self);
#endif
        }
        SetStateAndDispatch0209c3b4((Actor0209c3b4*)data_02109bf4, func_0209cd50(*p));
        func_ov017_021bd704(&self->blk);
        SetByteIfDataAndCheckClear_021a01bc((unsigned char*)res);
        if (p10[2]) {
            SetBrightness((GameResources*)res, -16, 0);
        } else if (!self->b10b) {
            SetMainBrightness((GameResources*)res, 0, 0x28);
        }
        SetByteField0x253_020397c0(unk);
        CopyByteField0x253To0x252_02039830(unk);
        func_0209c2e0(data_02109bf4, 0x7f, 0);
        if (self->u114) {
            *(unsigned short*)((unsigned char*)res + kResourceHalfwordOffset) = self->u114;
            self->u114 = 0;
        }
        if (self->f8 == 0x6013) {
            LightingManager* lm = LightingManager::GetInstance();
            int tod = gs->GetTimeOfDay();
            if (tod != *(int*)((unsigned char*)lm + 0x98)) {
                if (p10[2]) {
                    p10[9] = 1;
                }
                SetBrightness((GameResources*)res, -16, 0);
                InitFieldsFromCombatant_0219bcac(0);
            }
        }
    }
    }
    *(int*)((unsigned char*)gs + kGamePositionState) = 0;
    func_ov017_021bb27c(self);
    self->done = 1;
    return self->fa;
}
