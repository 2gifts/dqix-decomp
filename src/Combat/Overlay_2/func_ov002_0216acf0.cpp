#include <globaldefs.h>
#include "std_library_functions.h"

struct GameState;
struct GameObject;
struct SearchStruct;

extern "C" GameState* _ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int _ZNK9GameState21GetEffectiveDeltaTimeEv(GameState* gs);
extern "C" int _ZNK9GameState12GetTickCountEv(GameState* gs);
extern "C" char* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" SearchStruct* func_0202ae18(void);
extern "C" char* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int id);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, const void* src);
extern "C" int _Z16TestFlagBitAt0xeP12SearchStructi(SearchStruct* s, int bit);
extern "C" int _Z35DecrementOrClearCounterC74_0216c628Phi(char* obj, int amount);
extern "C" void func_ov002_0215b6c0(char* self);
extern "C" void func_ov002_0215a7b4(char* self, int a, int b, int c, int d);
extern "C" void func_ov002_02159900(char* self, char* arr, int flag);
extern "C" void func_ov002_0215a0a4(char* self, char* arr, int flag);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(void* obj, int a, int b);
extern "C" void _Z22InitStateArray02157ce0Pc(char* arr);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(char* obj, unsigned char lo, unsigned char hi);
extern "C" void _Z21InitBattleTag02161174Pc(char* self);
extern "C" void func_ov002_0216bfd4(char* self, int v);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char* self, int v);
extern "C" void _Z27EnqueueEventTag170_021d0198iiii(int a, int b, int c, int d);
extern "C" int _Z25TestFlag0SetAndFlag1ClearPti(unsigned short* obj, int mask);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(char* obj, int v);
extern "C" void func_ov002_0216c28c(char* self, int v);
extern "C" void _Z30SetField9a0AndIncrementField78P14Struct020444bc(char* g);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov017_0218b5f8(int a);
extern "C" char* _Z20GetLastEntry0205d888P14Struct0205d888(char* list);
extern "C" void _Z27ClearMatchingEntry_02156ff0Phi(char* self, int v);
extern "C" int _Z22GetCountByType02157108Pvi(char* self, int type);
extern "C" void _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(char* obj, int v);
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(char* obj, int a, int b);
extern "C" void func_ov002_02161cf0(char* self);
extern "C" void func_ov023_021dca88(char* obj);
extern "C" void func_0205d7a0(char* obj, int v);
extern "C" void func_ov002_0215c988(char* self, void* buf, int v);
extern "C" void _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(char* obj, unsigned char a, void* b, int c, unsigned char d);
extern "C" void func_ov002_0215b9a4(char* self, int key, int flag);
extern "C" void _Z26SetForwardAndStore0205ebc0Pvii(void* obj, int a, int b);
extern "C" void _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(void* obj, int a, int b);
extern "C" void _Z24ReinitController02043204Pc(char* g);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(char* obj, int v);
extern "C" char* _Z23FindElementByC40205d81cP15Struct_0205d81ci(char* obj, int v);

struct Totals020fdcb0 {
    int a0;
    int b0;
    int a1;
    int b1;
    int pad10[2];
    int c;
    int pad1c;
};

struct Slot0216acf0 {
    unsigned char state;
    unsigned char pad1;
    unsigned short value;
    unsigned char active;
    unsigned char pad5;
};

extern Totals020fdcb0 data_020fdcb0[];
extern char data_02108760;
extern unsigned char data_02114e54[];
extern unsigned short data_02114e30;

#define U8(o) (*(unsigned char*)(self + (o)))
#define S8(o) (*(signed char*)(self + (o)))
#define S16(o) (*(short*)(self + (o)))
#define S32(o) (*(int*)(self + (o)))

static inline int AnySet(int a, int b) { return (a | b) != 0; }

static inline int IsIdle(char* g) { return *(int*)(g + 0x998) == 0; }

// USA: func_ov002_0216acf0
extern "C" ARM void func_ov002_0216acf0(char* self) {
    if (U8(0x1cc5) != 0) {
        U8(0x1cc5) = 0;
        return;
    }

    GameState* gs = _ZN9GameState11GetInstanceEv();
    char* g = _Z26GetGlobalField0x1c020421a0v();
    SearchStruct* search = func_0202ae18();

    int sumA = 0;
    int sumB = 0;
    int sumC = 0;
    for (int i = 0; i < 4; i++) {
        Totals020fdcb0* e = &data_020fdcb0[i];
        if (e->a0 >= 0) sumA += e->a0;
        if (e->b0 >= 0) sumB += e->b0;
        if (e->a1 >= 0) sumA += e->a1;
        if (e->b1 >= 0) sumB += e->b1;
        sumC += e->c;
    }
    if (!(S16(0x2548) == sumA && S16(0x254a) == sumB && S32(0x254c) == sumC)) {
        if (S32(0x1bc0) != 0) {
            func_ov002_0215b6c0(self);
        }
    }
    S16(0x2548) = sumA;
    S16(0x254a) = sumB;
    S32(0x254c) = sumC;

    if (U8(0x2522) != 0 && S32(0x1bc0) != 0) {
        if (S32(0x1bc0) != 0) {
            S32(0x2530) = S32(0x2530) + _ZNK9GameState21GetEffectiveDeltaTimeEv(gs);
            if (S32(0x2530) > 10000) {
                S32(0x2530) = 10000;
            }
        }
        char* c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, S8(0x1c21));
        if (c != 0) {
            int pos[3];
            _ZN8Vector3iaSERKS_(pos, c + 0x44);
            if (pos[0] != S32(0x2524) || pos[1] != S32(0x2528) || pos[2] != S32(0x252c) || U8(0x2523) != 0) {
                *(unsigned int*)(c + 0x18c) &= ~1;
                U8(0x2523) = 1;
            }
        }
    }

    *(unsigned char*)(g + 0x19ae) = 0;

    int state = S32(0x1bc0);
    if (state == 0) {
        if (U8(0x1c7a) == 0 || U8(0x1c7b) == 10) {
            goto reset;
        }
        int ticks = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
        if (ticks == 0) ticks = 1;
        if (U8(0x1c7b) == 0x14) {
            int found = 0;
            for (int i = 0; i < U8(0x1ccb); i++) {
                if (_Z16TestFlagBitAt0xeP12SearchStructi(search, *(signed char*)(self + i + 0x1ccc))) {
                    found = 1;
                    break;
                }
            }
            if (_Z35DecrementOrClearCounterC74_0216c628Phi(self, ticks) == 0 || found != 0) {
                Slot0216acf0* a = (Slot0216acf0*)(self + 0xcd0 + 0x1000);
                Slot0216acf0* b = (Slot0216acf0*)(self + 0xe8 + 0x1c00);
                for (int i = 0; i < U8(0x1ccb); i++) {
                    if (a[i].active != 0 || b[i].active != 0) {
                        a[i].state = 0;
                        a[i].value = 0;
                        b[i].state = 0;
                        b[i].value = 0;
                    }
                }
                U8(0x1c7b) = 0x15;
            }
        }
        if (U8(0x1c7b) == 0x15) {
            Slot0216acf0* a = (Slot0216acf0*)(self + 0xcd0 + 0x1000);
            Slot0216acf0* b = (Slot0216acf0*)(self + 0xe8 + 0x1c00);
            int any = 0;
            for (int i = 0; i < U8(0x1ccb); i++) {
                if (a[i].state == 3 || b[i].state == 3) {
                    any = 1;
                }
            }
            if (U8(0x1cc6) != 0) {
                if (any != 0) {
                    func_ov002_0215a7b4(self, S8(0x1c20), S16(0x1c22), S16(0x1be8), 1);
                }
                func_ov002_02159900(self, self + 0xc8 + 0x1c00, any);
                if (S32(0x1d00) != 0) {
                    S32(0x1bb8) = 0x26;
                    S32(0x1bbc) = 0x2b;
                } else {
                    S32(0x1bb8) = 0x26;
                    S32(0x1bbc) = 5;
                }
            }
            if (U8(0x1cc7) != 0) {
                func_ov002_0215a0a4(self, self + 0xc8 + 0x1c00, any);
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 100, 0);
                if (S32(0x1d00) != 0) {
                    S32(0x1bb8) = 0x26;
                    S32(0x1bbc) = 0x2b;
                } else {
                    S32(0x1bb8) = 0x26;
                    S32(0x1bbc) = 0x11;
                }
            }
            _Z22InitStateArray02157ce0Pc(self + 0xc8 + 0x1c00);
            U8(0x1c7a) = 0;
            U8(0x1c7b) = 0;
        }
        return;
        {
        reset:
            S32(0x247c) &= ~4;
            S16(0x1c16) = 0;
            S16(0x1c18) = 0;
            _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(self + 0x2c8 + 0xc00, 0, 3);
            _Z21InitBattleTag02161174Pc(self);
            S32(0x247c) &= ~4;
            S32(0x1bc0) = 1;
            return;
        }
        return;
    }

    if (state == 1) {
        if (U8(0x1c2e) != 0) {
            S32(0x1bb8) = 0x25;
            S32(0x1bc0) = 0;
            return;
        }
        if (S32(0x1bbc) == 0x24) {
            S32(0x1bb8) = S32(0x1bbc);
            S32(0x1bc0) = 2;
            if (U8(0x1cc2) != 0) {
                S32(0x1bc0) = 3;
            }
            return;
        }
        if (U8(0x1c30) != 0) {
            int ticks = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
            if (ticks == 0) ticks = 1;
            if (_Z35DecrementOrClearCounterC74_0216c628Phi(self, ticks) != 0) {
                return;
            }
            switch (U8(0x1c79)) {
            case 1:
                func_ov002_0216bfd4(self, 6);
                break;
            case 2:
                if (*(int*)(g + 0x9a0) == 3) {
                    if (_Z29CheckFlagOrThreshold_02161b48Pci(self, 0) != 0 || data_02114e54[0x55] != 0) {
                        func_ov002_0216bfd4(self, 3);
                    }
                }
                break;
            case 8:
                if (U8(0x1c78) == 0) {
                    func_ov002_0215a7b4(self, S8(0x1c20), S16(0x1c22), S16(0x1be8), 0);
                } else {
                    func_ov002_0215a7b4(self, 4, S16(0x1c22), S16(0x1be8), 0);
                }
                _Z27EnqueueEventTag170_021d0198iiii(3, S8(0x1c20), S8(0x1c21), S16(0x1c22));
                func_ov002_0216bfd4(self, 9);
                break;
            }
            return;
        }
        if (U8(0x1c7a) != 0) {
            int ticks = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
            if (ticks == 0) ticks = 1;
            int ok = 0;
            int flag = _Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 0x601);
            if (AnySet(flag, _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(self + 0x2c8 + 0xc00, 0x14)) ||
                _Z29CheckFlagOrThreshold_02161b48Pci(self, 1) != 0 ||
                _Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 0xf0) != 0 || data_02114e54[0x55] != 0) {
                ok = 1;
            }
            switch (U8(0x1c7b)) {
            case 10:
                if (_Z35DecrementOrClearCounterC74_0216c628Phi(self, ticks) == 0) {
                    func_ov002_0216c28c(self, 0xc);
                }
                break;
            case 11:
                if (ok != 0) {
                    U8(0x1c7a) = 0;
                    U8(0x1c7b) = 0;
                    S32(0x1bb8) = 0x26;
                    S32(0x1bbc) = 0x11;
                    U8(0x248a) = 0;
                }
                break;
            case 12:
                if (ok != 0) {
                    U8(0x1c7a) = 0;
                    U8(0x1c7b) = 0;
                    S16(0x1c28) = 0x232b;
                    S16(0x1c2a) = -1;
                    S32(0x1bb8) = 0x26;
                    S32(0x1bbc) = 0x11;
                    U8(0x248a) = 0;
                    S32(0x1bc0) = 0;
                }
                break;
            }
            return;
        }
        if (U8(0x2522) != 0 && *(int*)(g + 0x9a0) != 3) {
            char* c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, S8(0x1c21));
            if (c != 0) {
                int pos[3];
                _ZN8Vector3iaSERKS_(pos, c + 0x44);
                if (pos[0] != S32(0x2524) || pos[1] != S32(0x2528) || pos[2] != S32(0x252c) || U8(0x2523) != 0) {
                    *(unsigned int*)(c + 0x18c) &= ~1;
                    U8(0x2523) = 1;
                    if (*(int*)(g + 0x9a0) == 2 && S32(0x2530) >= 1000) {
                        _Z30SetField9a0AndIncrementField78P14Struct020444bc(g);
                        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
                        U8(0x2522) = 0;
                        U8(0x2523) = 0;
                        memset(self + 0x124 + 0x2400, 0, 0xc);
                        S32(0x2530) = 0;
                    }
                    return;
                }
            }
        }
        if (U8(0x1c31) != 0) {
            if (!IsIdle(g)) {
                return;
            }
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
            U8(0x1c31) = 0;
            char* e = _Z20GetLastEntry0205d888P14Struct0205d888(self + 0x2c8 + 0xc00);
            if (e != 0) {
                int next = S32(0x1bbc);
                if (next != *(unsigned char*)(e + 0xc4) && next != 0x26 && next != 0x10 && next != 0x11) {
                    _Z27ClearMatchingEntry_02156ff0Phi(self, next);
                }
            }
            S32(0x1bb8) = S32(0x1bbc);
            S32(0x1bc0) = 1;
            if (S32(0x1bb8) == 5) {
                if (U8(0x2478) != 0) {
                    int count = _Z22GetCountByType02157108Pvi(self, S8(0x1c20));
                    if (count == 0) {
                        S16(0x1c22) = -1;
                        S16(0x1be8) = -1;
                        S32(0x1bb8) = 4;
                        S32(0x1bc0) = 1;
                        _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(self + 0x2c8 + 0xc00, 4);
                        _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0x2c8 + 0xc00, 4, 0);
                        func_ov002_02161cf0(self);
                        if (S32(0x247c) & 1) {
                            func_ov023_021dca88(self + 0x50);
                        }
                        return;
                    }
                    if (S16(0x1be8) >= count) {
                        S16(0x1be8) = count - 1;
                        func_0205d7a0(self + 0x2c8 + 0xc00, S16(0x1be8));
                    }
                    memset(*(void**)(self + 0x1bd0), 0, 0x960);
                    func_ov002_0215c988(self, *(void**)(self + 0x1bd0), 0);
                    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(self + 0x2c8 + 0xc00, S32(0x1bb8), *(void**)(self + 0x1bd0), 1, 0);
                    U8(0x2478) = 0;
                }
            } else if (S32(0x1bb8) == 0x11) {
                if (S16(0x1c26) == 0x22 || S16(0x1c26) == 0x310) {
                    func_ov002_02161cf0(self);
                }
            } else if (S32(0x247c) & 1) {
                func_ov023_021dca88(self + 0x50);
            }
        }
        if (*(int*)(g + 0x9a0) != 3) {
            return;
        }
        U8(0x2522) = 0;
        U8(0x2523) = 0;
        memset(self + 0x124 + 0x2400, 0, 0xc);
        S32(0x2530) = 0;
        if (U8(0x248a) != 0) {
            _Z27ClearMatchingEntry_02156ff0Phi(self, 0x26);
            func_ov002_0215b9a4(self, S32(0x1bb8) & 0xff, 1);
            S32(0x1bb8) = 0x26;
            S16(0x1c28) = S16(0x2488);
            S16(0x2488) = -1;
            U8(0x248a) = 0;
            S32(0x1bc0) = 0;
            if (S16(0x1c28) == 0x7532 || S16(0x1c28) == 0x7531) {
                _Z26SetForwardAndStore0205ebc0Pvii(&data_02108760, 0x75, 0x75);
                _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, 0, 0);
            }
            return;
        }
        if (S32(0x1bbc) == 0x17) {
            if (S8(0x1caf) == 4) {
                U8(0x1cae) = 5;
                U8(0x1caf) = 0;
            }
            S32(0x1bb8) = S32(0x1bbc);
            S32(0x1bc0) = 0;
        } else {
            _Z24ReinitController02043204Pc(g);
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
            if (S8(0x1caf) == 4) {
                U8(0x1cae) = 5;
                U8(0x1caf) = 0;
            }
            if (S16(0x1c28) == 0x7530) {
                _Z26SetForwardAndStore0205ebc0Pvii(&data_02108760, 0x75, 0x75);
                _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, 0, 0);
            }
            char* e = _Z20GetLastEntry0205d888P14Struct0205d888(self + 0x2c8 + 0xc00);
            if (U8(0x2521) != 0) {
                S32(0x1bb8) = S32(0x1bbc);
                _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(self + 0x2c8 + 0xc00, 4);
                _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0x2c8 + 0xc00, 4, 0);
                func_ov002_02161cf0(self);
                U8(0x2521) = 0;
            } else if (e != 0) {
                int next = S32(0x1bbc);
                if (next != *(unsigned char*)(e + 0xc4) && next != 0x26 && next != 0x10 && next != 0x11 &&
                    next != 9 && next != 0xb) {
                    _Z27ClearMatchingEntry_02156ff0Phi(self, next);
                }
            }
            S32(0x1bb8) = S32(0x1bbc);
            S32(0x1bc0) = 1;
        }
        if (U8(0x248c) != 0) {
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(self + 0x2c8 + 0xc00, 1);
            S32(0x1bb8) = 0x2b;
            return;
        }
        int cur = S32(0x1bb8);
        if (cur == 0xb) {
            func_ov002_0215b9a4(self, cur & 0xff, 0);
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0x2c8 + 0xc00, 0xb, 0);
            _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(self + 0x2c8 + 0xc00, 0xb);
            func_ov002_02161cf0(self);
        } else if (cur == 3) {
            short saved = S16(0x1be4);
            func_ov002_02161cf0(self);
            S16(0x1be4) = saved;
            func_ov002_0215b9a4(self, S32(0x1bb8) & 0xff, 0);
        } else if (cur == 0x10) {
            func_ov002_0215b9a4(self, cur & 0xff, 0);
            S32(0x247c) |= 4;
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0x2c8 + 0xc00, 0x11, 1);
            _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(self + 0x2c8 + 0xc00, 0x10);
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0x2c8 + 0xc00, 0x10, 0);
            S32(0x1bc0) = 1;
            func_ov002_02161cf0(self);
        } else if (cur == 0x15) {
            short saved = S16(0x1bfe);
            func_ov002_02161cf0(self);
            S16(0x1bfe) = saved;
            func_ov002_0215b9a4(self, S32(0x1bb8) & 0xff, 0);
        } else if (cur == 0x11) {
            if (_Z23FindElementByC40205d81cP15Struct_0205d81ci(self + 0x2c8 + 0xc00, 7) != 0 || S16(0x1bfc) >= 0) {
                _Z27ClearMatchingEntry_02156ff0Phi(self, 0x13);
                _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(self + 0x2c8 + 0xc00, 0x11);
                _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0x2c8 + 0xc00, 0x11, 0);
                S32(0x1bc0) = 1;
                S32(0x1bb8) = 0x11;
                if (S16(0x1bfc) >= 0) {
                    S16(0x1bfc) = -1;
                    S16(0x1c26) = -1;
                    func_ov002_02161cf0(self);
                    func_ov002_0215b9a4(self, S32(0x1bb8) & 0xff, 0);
                }
            }
            func_ov002_02161cf0(self);
        } else if (cur == 9) {
            func_ov002_02161cf0(self);
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0x2c8 + 0xc00, 9, 0);
            _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(self + 0x2c8 + 0xc00, 9);
            S32(0x1bc8) = 1;
            S32(0x1bcc) = 1;
            func_ov002_0215b9a4(self, S32(0x1bb8) & 0xff, 0);
        }
        if (S32(0x1bb8) == 5) {
            if (U8(0x2478) != 0) {
                int count = _Z22GetCountByType02157108Pvi(self, S8(0x1c20));
                if (count == 0) {
                    S16(0x1c22) = -1;
                    S16(0x1be8) = -1;
                    S32(0x1bb8) = 4;
                    S32(0x1bc0) = 1;
                    _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(self + 0x2c8 + 0xc00, 4);
                    _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0x2c8 + 0xc00, 4, 0);
                    func_ov002_02161cf0(self);
                    if (S32(0x247c) & 1) {
                        func_ov023_021dca88(self + 0x50);
                    }
                    return;
                }
                if (S16(0x1be8) >= count) {
                    S16(0x1be8) = count - 1;
                    func_0205d7a0(self + 0x2c8 + 0xc00, S16(0x1be8));
                }
                memset(*(void**)(self + 0x1bd0), 0, 0x960);
                func_ov002_0215c988(self, *(void**)(self + 0x1bd0), 0);
                _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(self + 0x2c8 + 0xc00, S32(0x1bb8), *(void**)(self + 0x1bd0), 1, 0);
                U8(0x2478) = 0;
            }
        } else if (S32(0x1bb8) != 9) {
            if (S32(0x247c) & 1) {
                func_ov023_021dca88(self + 0x50);
            }
        }
        return;
    }

    if (state == 3) {
        S32(0x1bb8) = S32(0x1bbc);
        S32(0x1bc0) = 0;
    }
}
