#include <globaldefs.h>

#if defined(jpn)
enum { kRegion9a0 = 0x870 };
enum { kRegion9ae = 0x7de };
enum { kRegion960 = 0x800 };
#else
enum { kRegion9a0 = 0x9a0 };
enum { kRegion9ae = 0x9ae };
enum { kRegion960 = 0x960 };
#endif

#include "GameState/GameState.h"

extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(void*, int, int);
extern "C" void* _Z21GetFieldByKey020e0434P17Container020e0310i(void*, int);
extern "C" void func_ov003_02159250(void*, void*);
extern "C" void _Z25AppendFieldTwice_02159290Pvii(void*, unsigned short, int);
extern "C" void _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(void*, int);
extern "C" void _Z21ResetAndApply0215be20Pv(void*);
extern "C" int _Z24StepStateMachine0215bd34Pv(void*);
extern "C" void func_ov003_0215c01c(void*, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState*, int);
extern "C" unsigned char* _Z15GetFieldAt0x150Ph(unsigned char*);
extern "C" int _s32_div_f(int, int);
extern "C" void _Z17StoreInArray0x8b0P11StoreStructii(void*, int, int);
extern "C" void _Z14SetByteInRangePhih(unsigned char*, int, unsigned char);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void*, int);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(void*, int, char*);
extern "C" int func_ov003_0215bf18(void*, int);
extern "C" int _Z26AddCappedFieldF6c_0215b580ii(void*, int);
extern "C" void _Z27SetValueAndActivate0209c830P14Struct0209c830t(void*, int);
extern "C" int _Z25IsAnimationActive0209ca2cPv(void*);
extern "C" void func_02048150(void*, int, int);
extern "C" void _Z18TryClearFlags0x130Pht(void*, unsigned short);
extern "C" void* _Z17GetPtrField0x2a04P9GameState(GameState*);
extern "C" void func_0207c378(void*, short, int, int);
extern "C" void func_02052d7c(void*, signed char, int);
extern "C" void* func_0202ae18(void);
extern "C" int _Z18CheckField0NonZeroPi(void*);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void func_ov017_0218f5a4(void*, int, int, int, int);
extern "C" void _ZN16BackgroundLoader14RemoveAllLocksEv(void*);
extern "C" void _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498(void*);
extern "C" int _Z23GetHeadNodeIdOrMinusOnePP16HeadNode02046b24(void*);
extern "C" void func_ov017_0218b5f8(int);
extern "C" void func_ov017_021c9e00(int, int, int, int);

extern int data_02109bf4;
extern const signed char data_ov003_0217f39c[12];

struct Slot0215a740 {
    char pad0[8];
    struct {
        unsigned int lo : 4;
        unsigned int mid : 14;
        unsigned int hit : 1;
        unsigned int rest : 13;
    } bits;
    char pad1[0x18 - 0xc];
    short sv;
};

struct NameBuf0215a740 {
    char pad[0xc];
};

// USA: func_ov003_0215a740
extern "C" ARM void func_ov003_0215a740(void* self, int p1, int p2) {
    unsigned char* s = (unsigned char*)self;
    GameState* game = GameState::GetInstance();
    unsigned char* g = (unsigned char*)_Z26GetGlobalField0x1c020421a0v();

    if (*(int*)(g + kRegion9a0) == 3) {
        *(unsigned char*)(g + 0x1000 + kRegion9ae) = 0;
    }

    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 0);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 1);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 0);
        func_ov003_02159250(self,
            _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, (short)p2));
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 1) {
        if (*(int*)(g + kRegion9a0) != 3) return;
        _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(s + 0xf4, 2);
        *(unsigned char*)(s + 0x585) = 0;
        _Z21ResetAndApply0215be20Pv(self);
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 4;
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 2) {
        int r = _Z24StepStateMachine0215bd34Pv(self);
        if (r == -1) return;
        if (r == -2) {
            func_ov003_0215c01c(self, 1, 0);
            memset(*(void**)(s + 0x7c), 0, kRegion960);
            _Z25AppendFieldTwice_02159290Pvii(self, 0x424, 0x42e);
            func_ov003_02159250(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x580) = 6;
        } else if (r >= 0) {
            func_ov003_0215c01c(self, 1, 1);
            func_ov003_0215c01c(self, 2, 1);
            *(unsigned char*)(s + 0x5a1) = (unsigned char)r;
            unsigned char* combatant =
                (unsigned char*)_Z25GetCombatantWithFlag0x100P9GameStatei(game,
                    *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591));
            unsigned char* sub = _Z15GetFieldAt0x150Ph(combatant);
            int x = *(int*)(sub + 0x950);
            *(int*)(s + 0x5a4) = *(int*)(combatant + 0x134);
            *(int*)(s + 0x5a8) = *(int*)(*(int**)(combatant + 0x130));
            int flag = 0;
            switch (p2) {
            case 0x406:
                if (*(int*)(*(int**)(combatant + 0x130)) & 1) {
                    unsigned short h = *(unsigned short*)(sub + x * 2 + 0x100 + 0x6c);
                    *(int*)(s + 0x5ac) = ((h * h + 0x14) / 0x14) * 0xa;
                    flag = 1;
                }
                break;
            case 0x410:
                if (*(int*)(s + 0x5a8) & 2) {
                    *(int*)(s + 0x5ac) = 5;
                    flag = 1;
                }
                break;
            case 0x406 + 20:
                if (*(int*)(s + 0x5a8) & 4) {
                    unsigned short h = *(unsigned short*)(sub + x * 2 + 0x100 + 0x6c);
                    *(int*)(s + 0x5ac) = h * 0x1e;
                    flag = 1;
                }
            }
            if (flag != 0) {
                _Z17StoreInArray0x8b0P11StoreStructii(g, 0, *(int*)(s + 0x5ac));
                _Z14SetByteInRangePhih(g, 0, 0);
                memset(*(void**)(s + 0x7c), 0, kRegion960);
                _Z25AppendFieldTwice_02159290Pvii(self, 0x425, 0x42e);
                func_ov003_02159250(self, *(void**)(s + 0x7c));
                *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
            } else {
                NameBuf0215a740 nb;
                _Z30InitObjFromCombatantId020e4bf4Pvi(&nb,
                    *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591));
                *(void**)(g + 0x10) = &nb;
                _Z22SetIndexedName02046574P11Obj02046574iPc((void*)g, 0, *(char**)(s + 0x5a4));
                memset(*(void**)(s + 0x7c), 0, kRegion960);
                _Z25AppendFieldTwice_02159290Pvii(self, p2 + 2, 0x42e);
                func_ov003_02159250(self, *(void**)(s + 0x7c));
                *(unsigned char*)(s + 0x580) = 6;
            }
        }
    }

    if (state == 3) {
        if (*(int*)(g + kRegion9a0) != 3) return;
        int r = func_ov003_0215bf18(self, 0);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 0);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 1);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 1);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            memset(*(void**)(s + 0x7c), 0, kRegion960);
            _Z25AppendFieldTwice_02159290Pvii(self, 0x426, 0x42e);
            func_ov003_02159250(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x580) = 6;
        } else if (r == 0) {
            if (_Z26AddCappedFieldF6c_0215b580ii(self, -*(int*)(s + 0x5ac)) == 0) {
                memset(*(void**)(s + 0x7c), 0, kRegion960);
                _Z25AppendFieldTwice_02159290Pvii(self, 0x427, 0x42e);
                func_ov003_02159250(self, *(void**)(s + 0x7c));
                *(unsigned char*)(s + 0x580) = 6;
            } else {
                *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
                NameBuf0215a740 nb;
                _Z30InitObjFromCombatantId020e4bf4Pvi(&nb,
                    *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591));
                *(void**)(g + 0x10) = &nb;
                func_ov003_02159250(self,
                    _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, (short)(p2 + 1)));
                *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
            }
        }
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 0);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 1);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 0);
    }

    if (state == 4) {
        if (*(int*)(g + kRegion9a0) != 3) return;
        _Z27SetValueAndActivate0209c830P14Struct0209c830t(&data_02109bf4, 0x3b);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 5) {
        if (*(int*)(g + kRegion9a0) == 3) {
            *(unsigned char*)(g + 0x1000 + kRegion9ae) = 0;
        }
        if (_Z25IsAnimationActive0209ca2cPv(&data_02109bf4) != 0) return;
        int cid = *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591);
        unsigned char* combatant = (unsigned char*)_Z25GetCombatantWithFlag0x100P9GameStatei(game, cid);
        switch (p2) {
        case 0x406: {
            func_02048150(combatant, 0, 1);
            int f18c = *(int*)(combatant + 0x18c);
            if (f18c & 1) {
                *(int*)(combatant + 0x18c) = f18c & ~1;
            }
            break;
        }
        case 0x410:
            _Z18TryClearFlags0x130Pht(combatant, 2);
            break;
        case 0x406 + 20: {
            _Z18TryClearFlags0x130Pht(combatant, 4);
            unsigned char* c4 = (unsigned char*)_Z17GetPtrField0x2a04P9GameState(game);
            int flag = 0;
            for (int i = 0; i < 0xb; i++) {
                if (i == 2 || i == 3 || i == 4) continue;
                unsigned char j = (unsigned char)i;
                unsigned char* ep = *(unsigned char**)(combatant + 0x150) + 0x194 + j * 0x20;
                if (ep == 0) continue;
                struct Slot0215a740* e = (struct Slot0215a740*)ep;
                if (e->bits.hit == 0) continue;
                short sv = e->sv;
                int lo = e->bits.lo;
                func_0207c378(c4 + 0x1d4, sv, 1, lo);
                func_02052d7c(combatant, data_ov003_0217f39c[i], -1);
                flag = 1;
            }
            if (flag != 0) {
                if (_Z18CheckField0NonZeroPi(func_0202ae18()) != 0) {
                    func_ov017_021c3fb4(cid, 1);
                    func_ov017_021c4418(cid, -1);
                }
                void* bg = (void*)func_ov017_0218b5b0();
                void* ctxA = *(void**)((char*)bg + 0x3700);
                void* ctxB = *(void**)((char*)bg + 0x3704);
                void* loader = _ZN16BackgroundLoader11GetInstanceEv();
                func_ov017_0218f5a4(bg, cid, 1, 0, 0);
                while (_Z23GetHeadNodeIdOrMinusOnePP16HeadNode02046b24(ctxA) == 0x13) {
                    _ZN16BackgroundLoader14RemoveAllLocksEv(loader);
                    _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498(ctxA);
                    if (_Z23GetHeadNodeIdOrMinusOnePP16HeadNode02046b24(ctxB) == 0x14) {
                        _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498(ctxB);
                    }
                }
            }
        }
        }
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) & ~0x10;
        *(unsigned char*)(s + 0x583) = 1;
        func_ov017_0218b5f8(-1);
        func_ov017_021c9e00(cid, 1, 0, 1);
        func_ov003_02159250(self,
            _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x42e));
        *(signed char*)(s + 0x585) = -1;
        func_ov003_0215c01c(self, 1, 0);
        func_ov003_0215c01c(self, 2, 0);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 6 && *(int*)(g + kRegion9a0) == 3) {
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) & ~4;
        *(signed char*)(s + 0x585) = -1;
        func_ov003_0215c01c(self, 1, 0);
        func_ov003_0215c01c(self, 2, 0);
        *(signed char*)(s + 0x5a1) = -1;
        *(int*)(s + 0x5a4) = 0;
        *(int*)(s + 0x5a8) = 0;
        *(int*)(s + 0x5ac) = 0;
        *(unsigned char*)(s + 0x588) = 2;
        *(unsigned char*)(s + 0x580) = 0;
    }
}
