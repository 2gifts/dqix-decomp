// JPN: func_ov017_021bcd74
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

struct AllocatorUnion;

extern "C" void* func_0202ae18();
extern "C" void* _Z15GetFieldIfFlag4Pc(GameState* gs);
extern "C" unsigned short* func_02012fe4();
extern "C" unsigned char* func_0205ec34();
extern "C" unsigned int* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" void func_02019678(unsigned short* p, int v);
extern "C" void _Z18ClearCombatantSlotP9GameStatei(GameState* gs, int idx);
extern "C" Object3D* _Z21GetField4334_021bdbc0Ph(void* res);
extern "C" int _Z19TestFlagBitAt0x2744Phi(unsigned short* p, int bit);
extern "C" void _Z19InitContext020e1154Pv(int v);
extern "C" void _Z17SetField0x238TruePv(void* p);
extern "C" void _Z22ApplyVecFromField0x21ePc(void* p);
extern "C" void _Z20SetOrClearBitInArrayPvPhii(unsigned char* bits, unsigned char* arr, int idx, int set);
extern "C" void func_ov017_0219b624(void* res);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* a, void* p);
extern "C" int _Z15GetBitsInField0Pjj(void* res, unsigned int bits);
extern "C" void* _Z16AllocateAligned4P14AllocatorUnionj(AllocatorUnion* a, unsigned int size);
extern "C" void func_ov017_021a2fa0(void* res);
extern "C" int _Z18CheckField0NonZeroPi(void* p);
extern "C" int _Z15IsByte0x63d6SetP20FieldBlock63d6_11590(GameState* gs);
extern "C" void _Z17SetHalfword0x63d8Pvt(GameState* gs, unsigned short v);
extern "C" void func_ov017_021bb27c(void* self);
extern "C" void _Z20ClearFields_021bb0c4Ph(void* self);
extern "C" int _Z28LookupAndForEachNode020649b0PviS_(unsigned char* bits, int kind, void* node);
extern "C" void func_0206f81c(void* node);
extern "C" int func_0202c540(void* p);
extern "C" int _Z18TestBitInByteArrayiPhi(unsigned char* bits, unsigned char* arr, int idx);
extern "C" unsigned char* func_ov017_021b8478(unsigned char* p);
extern "C" void func_02046a8c(void* a, unsigned char* b);
extern "C" int _Z16GetState0209ca68Pc(void* p);
extern "C" void func_0209c530(void* p);
extern "C" void _Z17ClearBitsInField4Pjj(void* res, unsigned int bits);
extern "C" void _Z15ClearBitsInWordPjj(void* res, unsigned int bits);
extern "C" unsigned char* _Z20GetField0x3f8AddressP9GameState(GameState* gs);
extern "C" void* _Z15GetData02153660v();
extern "C" int _Z18GetField0x3acValueP9GameState(GameState* gs);
extern "C" void _Z35SetOrClearEntryBitAndNotify020e3a50P21TagValueEntry020e385ciii(void* e, int a, int b, int c);
extern "C" void _Z40ResetTaggedEntryAndNotifyOverlay020e3994P21TagValueEntry020e385cii(void* e, int a, int b);
extern "C" void _Z13SetFields0x44P14Fields020407b4iii(GameObject* o, int a, int b, int c);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(GameObject* o, int v);
extern "C" void _Z18SetFlag0x1ceBit0x4Ph(GameObject* o);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void* res, int level, int b);
extern "C" int func_0209cd50(unsigned short id);
extern "C" void _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(void* a, int state);
extern "C" void func_ov017_021bd704(void* p);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void* res, int level, int b);
extern "C" void _Z27EnqueueEventTag107_021cdd70tttttth(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e, unsigned short f, unsigned char g);
extern "C" void func_ov017_021b6728(void* res, int a, int b);
extern "C" void _Z17SetByteField0x253Pv(GameObject* o);
extern "C" void _Z25CopyByteField0x253To0x252Pv(GameObject* o);
extern "C" int func_ov017_0219bddc(unsigned char* p);
extern "C" void func_ov017_0219bf04(int a, int b);
extern "C" void _Z21SetByte1True_021c178cPh(unsigned char* p);
extern "C" void func_ov017_021b8bb0(unsigned short id);
extern "C" void _Z18InitStruct02070378Pc(unsigned char* p);
extern "C" void _ZN8Vector3iaSERKS_(void* dst, const Vector3i& src);
extern "C" void _Z20SetFlagBytes02017d68Pv(void* p);
extern "C" int _Z13PeekInputLogAv();
#if defined(jpn)
extern "C" void _Z31ClearMultipleFieldBits_02156b20v(void);
#else
extern "C" void _Z20IsFlag0x14Bit0x40SetP10GameObject(void* p);
#endif
extern "C" void _Z35SetByteIfDataAndCheckClear_021a01bcPh(void* res);
extern "C" void func_0209c2e0(void* p, int a, int b);
extern "C" void _Z32InitFieldsFromCombatant_0219bcach(unsigned char v);

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
    sa->CreateTypeA(_Z16AllocateAligned4P14AllocatorUnionj(&data_02114e20, size), size);
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
    void* f28 = _Z15GetFieldIfFlag4Pc(gs);
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
    _Z27GetDataPtr02114e04_020d6c00v();
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
                _Z18ClearCombatantSlotP9GameStatei(gs2, i + 0xa0);
            }
        }
        ((ResView_021bc77c*)res2)->sub.i630 = 0;
        Object3D* obj = _Z21GetField4334_021bdbc0Ph(res2);
        if (obj != 0) {
            obj->MakeVisible();
        }
        if (_Z19TestFlagBitAt0x2744Phi(p2, 1) || _Z19TestFlagBitAt0x2744Phi(p2, 0)) {
            _Z19InitContext020e1154Pv(0x1388);
        }
    }
    _Z17SetField0x238TruePv(f28);
    _Z22ApplyVecFromField0x21ePc(f28);
    if (self->blk.s46 > -1) {
        _Z20SetOrClearBitInArrayPvPhii(bits, bits + 0x8c, self->blk.s46 + 0x38e, 1);
    }
    if (self->sa0 > -1 && self->b9c) {
        _Z20SetOrClearBitInArrayPvPhii(bits, bits + 0x8c, self->sa0 + 0xbea, 1);
    }
    if (self->b9a) {
        func_ov017_0219b624(res);
    }
    if (self->alloc138) {
        SignedAllocatorHeader* h = self->alloc138->GetSignedAllocator();
        if (h) {
            self->alloc138->Destroy();
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, h);
        }
        self->alloc138 = 0;
    }
    if (!_Z15GetBitsInField0Pjj(res, 0x1000) || self->u11a == 0) {
        int size = self->i90;
        if (size) {
            SafeAllocator* sa = GetAllocator_021bc77c(res, 7);
            sa->CreateTypeA(_Z16AllocateAligned4P14AllocatorUnionj(&data_02114e20, size), size);
            func_ov017_021a2fa0(res);
            self->i90 = 0;
        } else if (self->blk.flags & 4) {
            func_ov017_021a2fa0(res);
        }
    }
    if (!_Z18CheckField0NonZeroPi(x34) && _Z15IsByte0x63d6SetP20FieldBlock63d6_11590(gs)) {
        if (self->u11a) {
            _Z17SetHalfword0x63d8Pvt(gs, self->u11a);
        }
        func_ov017_021bb27c(self);
        self->done = 1;
        return self->fa;
    }
    if (self->u11a) {
        self->f8 = self->u11a;
        self->bfd = 1;
        _Z20ClearFields_021bb0c4Ph(self);
        return 0;
    }
    if (*((unsigned char*)res + kResourceFlagOffset) == 0) {
        Node_021bc77c node;
        node.id = self->f8;
        if (_Z28LookupAndForEachNode020649b0PviS_(bits, 0xb, &node)) {
            func_0206f81c(&node);
        }
        if (func_0202c540(x34)) {
            int flag = 0;
            if (self->b13c == 2) {
                if (r8[2]) flag = 1;
            } else if (self->b13c == 1) {
                if (r8[2] && !_Z18TestBitInByteArrayiPhi(bits, bits + 0x8c, self->u148 + 0x38e)) {
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
                if (_Z16GetState0209ca68Pc(data_02109bf4) == 2) {
                    func_0209c530(data_02109bf4);
                }
                _Z17ClearBitsInField4Pjj(res, 4);
                _Z17ClearBitsInField4Pjj(res, 0x10);
                _Z17ClearBitsInField4Pjj(res, 2);
                _Z15ClearBitsInWordPjj(res, 4);
                _Z15ClearBitsInWordPjj(res, 0x800);
            }
        }
    } else {
        self->b13c = 2;
    }
    unsigned char* f = _Z20GetField0x3f8AddressP9GameState(gs);
    void* tags = _Z15GetData02153660v();
    if (r8[2]) {
        _Z35SetOrClearEntryBitAndNotify020e3a50P21TagValueEntry020e385ciii(tags, _Z18GetField0x3acValueP9GameState(gs), 1, *(unsigned short*)((unsigned char*)self + 0x18));
    } else if (*(int*)(f + 0x20) <= 0 || f[2] == 0) {
        _Z40ResetTaggedEntryAndNotifyOverlay020e3994P21TagValueEntry020e385cii(tags, 1, *(unsigned short*)((unsigned char*)self + 0x18));
    }
    if (self->bcc && self->bcf == 3) {
        _Z13SetFields0x44P14Fields020407b4iii(unk, 0x48cc, 0x199, -0x733);
        _Z24SetVecYFromValue02033874P11Obj02033874i(unk, 0);
        for (int i = 1; i < 4; i++) {
            GameObject* m = gs->GetPartyMemberByIndex(i);
            if (m) {
                _Z13SetFields0x44P14Fields020407b4iii(m, 0x48cc, 0x199, -0x733);
                _Z24SetVecYFromValue02033874P11Obj02033874i(m, 0x3244);
                _Z18SetFlag0x1ceBit0x4Ph(m);
            }
        }
    }
    if (f[2]) {
        _Z13SetBrightnessP13GameResourcesii(res, -16, 0);
    } else if (p14[2]) {
        _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(data_02109bf4, func_0209cd50(*p));
        func_ov017_021bd704(&self->blk);
        _Z17SetMainBrightnessP13GameResourcesii(res, 0, 0x28);
    } else if (r8[2]) {
        _Z13SetBrightnessP13GameResourcesii(res, -16, 0);
        *(unsigned short*)(r8 + 0x6c4) = self->u184;
        if (func_0202c540(x34)) {
            self->u14e = *(int*)(func_ov017_021b8478(*(unsigned char**)((unsigned char*)res + kResourceNodeOffset)) + 0xc);
            _Z27EnqueueEventTag107_021cdd70tttttth(self->u14e, 0, 0, 0, 0, 0, 0);
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
            _Z17SetByteField0x253Pv(unk);
            _Z25CopyByteField0x253To0x252Pv(unk);
        }
        _Z17SetMainBrightnessP13GameResourcesii(res, 0, 0x28);
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
            if (_Z18TestBitInByteArrayiPhi(bits3, bits3 + 0x8c, self->u148 + 0x38e)) { ok = 0; goto checked; }
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
                    _Z21SetByte1True_021c178cPh(q);
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
                _Z15ClearBitsInWordPjj(res3, 0x10);
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
        _Z20ClearFields_021bb0c4Ph(self);
        return 0;
    } else if (_Z18CheckField0NonZeroPi(x34) && func_0202c540(x34) && party0 && (mapId = *p, mapId == party0->obj3D_.GetField06()) &&
               self->b13c == 0 && (short)self->u146 >= 0) {
        func_ov017_021b8bb0((short)self->u146);
    } else if (self->b9c && self->ua2 != *p) {
        _Z18InitStruct02070378Pc(f);
        f[2] = 1;
        *(unsigned short*)f = self->ua2;
        f[7] = 1;
        _ZN8Vector3iaSERKS_(f + 0x10, self->vbc);
        *(short*)(f + 0x1c) = self->sc8;
        _Z13SetBrightnessP13GameResourcesii(res, -16, 0);
    } else if (*(int*)((unsigned char*)gs + kGamePositionState) > 0) {
        _Z18InitStruct02070378Pc(f);
        f[2] = 1;
        *(unsigned short*)f = *(int*)((unsigned char*)gs + kGamePositionState);
        f[7] = 1;
        _ZN8Vector3iaSERKS_(f + 0x10, GetPos_021bc77c(gs));
        *(short*)(f + 0x1c) = *(int*)((unsigned char*)gs + kGamePositionY);
        *(int*)((unsigned char*)gs + kGamePositionState) = 0;
        _Z13SetBrightnessP13GameResourcesii(res, -16, 0);
        _Z20SetFlagBytes02017d68Pv(func_02012fe4());
    } else {
        if (_Z13PeekInputLogAv() == 1) {
#if defined(jpn)
            ((void (*)(void*))_Z31ClearMultipleFieldBits_02156b20v)(self);
#else
            _Z20IsFlag0x14Bit0x40SetP10GameObject(self);
#endif
        }
        _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(data_02109bf4, func_0209cd50(*p));
        func_ov017_021bd704(&self->blk);
        _Z35SetByteIfDataAndCheckClear_021a01bcPh(res);
        if (p10[2]) {
            _Z13SetBrightnessP13GameResourcesii(res, -16, 0);
        } else if (!self->b10b) {
            _Z17SetMainBrightnessP13GameResourcesii(res, 0, 0x28);
        }
        _Z17SetByteField0x253Pv(unk);
        _Z25CopyByteField0x253To0x252Pv(unk);
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
                _Z13SetBrightnessP13GameResourcesii(res, -16, 0);
                _Z32InitFieldsFromCombatant_0219bcach(0);
            }
        }
    }
    }
    *(int*)((unsigned char*)gs + kGamePositionState) = 0;
    func_ov017_021bb27c(self);
    self->done = 1;
    return self->fa;
}
