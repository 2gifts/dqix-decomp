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
#include "Filesystem/BackgroundLoader.h"

void* GetGlobalField0x1c020421a0(void);
struct Struct_0205d81c;
void SetElementFieldC2(Struct_0205d81c*, int, int);
struct Container020e0310;
void* GetFieldByKey020e0434(Container020e0310*, int);
extern "C" void func_ov003_02159250(void*, void*);
void AppendFieldTwice_02159290(void*, int, int);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(Obj0205dee8*, int);
void ResetAndApply0215be20(void*);
int StepStateMachine0215bd34(void*);
extern "C" void func_ov003_0215c01c(void*, int, int);
extern "C" void* memset(void*, int, unsigned int);
unsigned char* GetFieldAt0x150(unsigned char*);
extern "C" int _s32_div_f(int, int);
struct StoreStruct;
void StoreInArray0x8b0(StoreStruct*, int, int);
void SetByteInRange(unsigned char*, int, unsigned char);
void InitObjFromCombatantId020e4bf4(void*, int);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
extern "C" int func_ov003_0215bf18(void*, int);
int AddCappedFieldF6c_0215b580(int, int);
struct Struct0209c830;
void SetValueAndActivate0209c830(Struct0209c830*, int);
int IsAnimationActive0209ca2c(void*);
extern "C" void func_02048150(void*, int, int);
void TryClearFlags0x130(unsigned char*, unsigned short);
void* GetPtrField0x2a04(GameState*);
extern "C" void func_0207c378(void*, short, int, int);
extern "C" void func_02052d7c(void*, signed char, int);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int*);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
extern "C" void func_ov017_0218f5a4(void*, int, int, int, int);
struct Ctx021a3498;
void ClearIfMatchAndFinalize_021a3498(Ctx021a3498*);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
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
    unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();

    if (*(int*)(g + kRegion9a0) == 3) {
        *(unsigned char*)(g + 0x1000 + kRegion9ae) = 0;
    }

    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        SetElementFieldC2((Struct_0205d81c*)(s + 0xf4), 0, 0);
        SetElementFieldC2((Struct_0205d81c*)(s + 0xf4), 1, 1);
        SetElementFieldC2((Struct_0205d81c*)(s + 0xf4), 2, 0);
        func_ov003_02159250(self,
            GetFieldByKey020e0434((Container020e0310*)(s + 0x64), (short)p2));
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 1) {
        if (*(int*)(g + kRegion9a0) != 3) return;
        SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(s + 0xf4), 2);
        *(unsigned char*)(s + 0x585) = 0;
        ResetAndApply0215be20(self);
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 4;
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 2) {
        int r = StepStateMachine0215bd34(self);
        if (r == -1) return;
        if (r == -2) {
            func_ov003_0215c01c(self, 1, 0);
            memset(*(void**)(s + 0x7c), 0, kRegion960);
            AppendFieldTwice_02159290(self, (unsigned short)0x424, 0x42e);
            func_ov003_02159250(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x580) = 6;
        } else if (r >= 0) {
            func_ov003_0215c01c(self, 1, 1);
            func_ov003_0215c01c(self, 2, 1);
            *(unsigned char*)(s + 0x5a1) = (unsigned char)r;
            unsigned char* combatant =
                (unsigned char*)(void*)GetCombatantWithFlag0x100(game, *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591));
            unsigned char* sub = GetFieldAt0x150(combatant);
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
                StoreInArray0x8b0((StoreStruct*)g, 0, *(int*)(s + 0x5ac));
                SetByteInRange(g, 0, 0);
                memset(*(void**)(s + 0x7c), 0, kRegion960);
                AppendFieldTwice_02159290(self, (unsigned short)0x425, 0x42e);
                func_ov003_02159250(self, *(void**)(s + 0x7c));
                *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
            } else {
                NameBuf0215a740 nb;
                InitObjFromCombatantId020e4bf4(&nb,
                    *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591));
                *(void**)(g + 0x10) = &nb;
                SetIndexedName02046574((Obj02046574*)g, 0, *(char**)(s + 0x5a4));
                memset(*(void**)(s + 0x7c), 0, kRegion960);
                AppendFieldTwice_02159290(self, (unsigned short)(p2 + 2), 0x42e);
                func_ov003_02159250(self, *(void**)(s + 0x7c));
                *(unsigned char*)(s + 0x580) = 6;
            }
        }
    }

    if (state == 3) {
        if (*(int*)(g + kRegion9a0) != 3) return;
        int r = func_ov003_0215bf18(self, 0);
        SetElementFieldC2((Struct_0205d81c*)(s + 0xf4), 0, 0);
        SetElementFieldC2((Struct_0205d81c*)(s + 0xf4), 1, 1);
        SetElementFieldC2((Struct_0205d81c*)(s + 0xf4), 2, 1);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            memset(*(void**)(s + 0x7c), 0, kRegion960);
            AppendFieldTwice_02159290(self, (unsigned short)0x426, 0x42e);
            func_ov003_02159250(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x580) = 6;
        } else if (r == 0) {
            if (AddCappedFieldF6c_0215b580((int)self, -*(int*)(s + 0x5ac)) == 0) {
                memset(*(void**)(s + 0x7c), 0, kRegion960);
                AppendFieldTwice_02159290(self, (unsigned short)0x427, 0x42e);
                func_ov003_02159250(self, *(void**)(s + 0x7c));
                *(unsigned char*)(s + 0x580) = 6;
            } else {
                *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
                NameBuf0215a740 nb;
                InitObjFromCombatantId020e4bf4(&nb,
                    *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591));
                *(void**)(g + 0x10) = &nb;
                func_ov003_02159250(self,
                    GetFieldByKey020e0434((Container020e0310*)(s + 0x64), (short)(p2 + 1)));
                *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
            }
        }
        SetElementFieldC2((Struct_0205d81c*)(s + 0xf4), 0, 0);
        SetElementFieldC2((Struct_0205d81c*)(s + 0xf4), 1, 1);
        SetElementFieldC2((Struct_0205d81c*)(s + 0xf4), 2, 0);
    }

    if (state == 4) {
        if (*(int*)(g + kRegion9a0) != 3) return;
        SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x3b);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 5) {
        if (*(int*)(g + kRegion9a0) == 3) {
            *(unsigned char*)(g + 0x1000 + kRegion9ae) = 0;
        }
        if (IsAnimationActive0209ca2c(&data_02109bf4) != 0) return;
        int cid = *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591);
        unsigned char* combatant = (unsigned char*)(void*)GetCombatantWithFlag0x100(game, cid);
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
            TryClearFlags0x130((unsigned char*)combatant, 2);
            break;
        case 0x406 + 20: {
            TryClearFlags0x130((unsigned char*)combatant, 4);
            unsigned char* c4 = (unsigned char*)GetPtrField0x2a04(game);
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
                if (CheckField0NonZero((int*)func_0202ae18()) != 0) {
                    func_ov017_021c3fb4(cid, 1);
                    func_ov017_021c4418(cid, -1);
                }
                void* bg = (void*)func_ov017_0218b5b0();
                void* ctxA = *(void**)((char*)bg + 0x3700);
                void* ctxB = *(void**)((char*)bg + 0x3704);
                void* loader = BackgroundLoader::GetInstance();
                func_ov017_0218f5a4(bg, cid, 1, 0, 0);
                while (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)ctxA) == 0x13) {
                    ((BackgroundLoader*)loader)->RemoveAllLocks();
                    ClearIfMatchAndFinalize_021a3498((Ctx021a3498*)ctxA);
                    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)ctxB) == 0x14) {
                        ClearIfMatchAndFinalize_021a3498((Ctx021a3498*)ctxB);
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
            GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x42e));
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
