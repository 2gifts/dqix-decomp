#include <globaldefs.h>
#include "std_library_functions.h"

struct GameState;
struct GameObject;
struct SearchStruct;

extern "C" GameState* _ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int _ZNK9GameState21GetEffectiveDeltaTimeEv(GameState* gs);
extern "C" int _ZNK9GameState12GetTickCountEv(GameState* gs);
char* GetGlobalField0x1c020421a0(void);
extern "C" SearchStruct* func_0202ae18(void);
char* GetCombatantWithFlag0x100(GameState* gs, int id);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, const void* src);
int TestFlagBitAt0xe(SearchStruct* s, int bit);
int DecrementOrClearCounterC74_0216c628(unsigned char*, int);
extern "C" void func_ov002_0215b6c0(char* self);
extern "C" void func_ov002_0215a7b4(char* self, int a, int b, int c, int d);
extern "C" void func_ov002_02159900(char* self, char* arr, int flag);
extern "C" void func_ov002_0215a0a4(char* self, char* arr, int flag);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
void InitStateArray02157ce0(char* arr);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(Struct0205de24*, unsigned char, unsigned char);
void InitBattleTag02161174(char* self);
extern "C" void func_ov002_0216bfd4(char* self, int v);
int CheckFlagOrThreshold_02161b48(char* self, int v);
void EnqueueEventTag170_021d0198(int a, int b, int c, int d);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
extern "C" void func_ov002_0216c28c(char* self, int v);
struct Struct020444bc;
void SetField9a0AndIncrementField78(Struct020444bc*);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov017_0218b5f8(int a);
struct Struct0205d888;
char* GetLastEntry0205d888(Struct0205d888*);
void ClearMatchingEntry_02156ff0(unsigned char*, int);
int GetCountByType02157108(void*, int);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(Obj0205dee8*, int);
struct Struct_0205d81c;
void SetElementFieldC2(Struct_0205d81c*, int, int);
extern "C" void func_ov002_02161cf0(char* self);
extern "C" void func_ov023_021dca88(char* obj);
extern "C" void func_0205d7a0(char* obj, int v);
extern "C" void func_ov002_0215c988(char* self, void* buf, int v);
struct StructA0205d5d0;
void TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int, unsigned char);
extern "C" void func_ov002_0215b9a4(char* self, int key, int flag);
void SetForwardAndStore0205ebc0(void* obj, int a, int b);
void DispatchIfField0xc4NonNeg_0205ebfc(void* obj, int a, int b);
void ReinitController02043204(char* g);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
char* FindElementByC40205d81c(Struct_0205d81c*, int);

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
    char* g = GetGlobalField0x1c020421a0();
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
        char* c = GetCombatantWithFlag0x100(gs, S8(0x1c21));
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
                if (TestFlagBitAt0xe(search, *(signed char*)(self + i + 0x1ccc))) {
                    found = 1;
                    break;
                }
            }
            if (DecrementOrClearCounterC74_0216c628((unsigned char*)self, ticks) == 0 || found != 0) {
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
                DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 100, 0);
                if (S32(0x1d00) != 0) {
                    S32(0x1bb8) = 0x26;
                    S32(0x1bbc) = 0x2b;
                } else {
                    S32(0x1bb8) = 0x26;
                    S32(0x1bbc) = 0x11;
                }
            }
            InitStateArray02157ce0(self + 0xc8 + 0x1c00);
            U8(0x1c7a) = 0;
            U8(0x1c7b) = 0;
        }
        return;
        {
        reset:
            S32(0x247c) &= ~4;
            S16(0x1c16) = 0;
            S16(0x1c18) = 0;
            FindAndLinkMatchingEntry0205de24((Struct0205de24*)(self + 0x2c8 + 0xc00), 0, 3);
            InitBattleTag02161174(self);
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
            if (DecrementOrClearCounterC74_0216c628((unsigned char*)self, ticks) != 0) {
                return;
            }
            switch (U8(0x1c79)) {
            case 1:
                func_ov002_0216bfd4(self, 6);
                break;
            case 2:
                if (*(int*)(g + 0x9a0) == 3) {
                    if (CheckFlagOrThreshold_02161b48(self, 0) != 0 || data_02114e54[0x55] != 0) {
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
                EnqueueEventTag170_021d0198(3, S8(0x1c20), S8(0x1c21), S16(0x1c22));
                func_ov002_0216bfd4(self, 9);
                break;
            }
            return;
        }
        if (U8(0x1c7a) != 0) {
            int ticks = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
            if (ticks == 0) ticks = 1;
            int ok = 0;
            int flag = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
            if (AnySet(flag, IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + 0x2c8 + 0xc00), 0x14)) ||
                CheckFlagOrThreshold_02161b48(self, 1) != 0 ||
                TestFlag0SetAndFlag1Clear(&data_02114e30, 0xf0) != 0 || data_02114e54[0x55] != 0) {
                ok = 1;
            }
            switch (U8(0x1c7b)) {
            case 10:
                if (DecrementOrClearCounterC74_0216c628((unsigned char*)self, ticks) == 0) {
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
            char* c = GetCombatantWithFlag0x100(gs, S8(0x1c21));
            if (c != 0) {
                int pos[3];
                _ZN8Vector3iaSERKS_(pos, c + 0x44);
                if (pos[0] != S32(0x2524) || pos[1] != S32(0x2528) || pos[2] != S32(0x252c) || U8(0x2523) != 0) {
                    *(unsigned int*)(c + 0x18c) &= ~1;
                    U8(0x2523) = 1;
                    if (*(int*)(g + 0x9a0) == 2 && S32(0x2530) >= 1000) {
                        SetField9a0AndIncrementField78((Struct020444bc*)g);
                        DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 1, 0);
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
            char* e = GetLastEntry0205d888((Struct0205d888*)(self + 0x2c8 + 0xc00));
            if (e != 0) {
                int next = S32(0x1bbc);
                if (next != *(unsigned char*)(e + 0xc4) && next != 0x26 && next != 0x10 && next != 0x11) {
                    ClearMatchingEntry_02156ff0((unsigned char*)self, next);
                }
            }
            S32(0x1bb8) = S32(0x1bbc);
            S32(0x1bc0) = 1;
            if (S32(0x1bb8) == 5) {
                if (U8(0x2478) != 0) {
                    int count = GetCountByType02157108(self, S8(0x1c20));
                    if (count == 0) {
                        S16(0x1c22) = -1;
                        S16(0x1be8) = -1;
                        S32(0x1bb8) = 4;
                        S32(0x1bc0) = 1;
                        SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + 0x2c8 + 0xc00), 4);
                        SetElementFieldC2((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 4, 0);
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
                    TryApplyElemFields0205d5d0((StructA0205d5d0*)(self + 0x2c8 + 0xc00), (unsigned char)S32(0x1bb8), (int)(*(void**)(self + 0x1bd0)), 1, 0);
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
            ClearMatchingEntry_02156ff0((unsigned char*)self, 0x26);
            func_ov002_0215b9a4(self, S32(0x1bb8) & 0xff, 1);
            S32(0x1bb8) = 0x26;
            S16(0x1c28) = S16(0x2488);
            S16(0x2488) = -1;
            U8(0x248a) = 0;
            S32(0x1bc0) = 0;
            if (S16(0x1c28) == 0x7532 || S16(0x1c28) == 0x7531) {
                SetForwardAndStore0205ebc0(&data_02108760, 0x75, 0x75);
                DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, 0, 0);
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
            ReinitController02043204(g);
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
            if (S8(0x1caf) == 4) {
                U8(0x1cae) = 5;
                U8(0x1caf) = 0;
            }
            if (S16(0x1c28) == 0x7530) {
                SetForwardAndStore0205ebc0(&data_02108760, 0x75, 0x75);
                DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, 0, 0);
            }
            char* e = GetLastEntry0205d888((Struct0205d888*)(self + 0x2c8 + 0xc00));
            if (U8(0x2521) != 0) {
                S32(0x1bb8) = S32(0x1bbc);
                SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + 0x2c8 + 0xc00), 4);
                SetElementFieldC2((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 4, 0);
                func_ov002_02161cf0(self);
                U8(0x2521) = 0;
            } else if (e != 0) {
                int next = S32(0x1bbc);
                if (next != *(unsigned char*)(e + 0xc4) && next != 0x26 && next != 0x10 && next != 0x11 &&
                    next != 9 && next != 0xb) {
                    ClearMatchingEntry_02156ff0((unsigned char*)self, next);
                }
            }
            S32(0x1bb8) = S32(0x1bbc);
            S32(0x1bc0) = 1;
        }
        if (U8(0x248c) != 0) {
            ResetEntryList0205d6a0((Entry_0205d6a0*)(self + 0x2c8 + 0xc00), 1);
            S32(0x1bb8) = 0x2b;
            return;
        }
        int cur = S32(0x1bb8);
        if (cur == 0xb) {
            func_ov002_0215b9a4(self, cur & 0xff, 0);
            SetElementFieldC2((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 0xb, 0);
            SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + 0x2c8 + 0xc00), 0xb);
            func_ov002_02161cf0(self);
        } else if (cur == 3) {
            short saved = S16(0x1be4);
            func_ov002_02161cf0(self);
            S16(0x1be4) = saved;
            func_ov002_0215b9a4(self, S32(0x1bb8) & 0xff, 0);
        } else if (cur == 0x10) {
            func_ov002_0215b9a4(self, cur & 0xff, 0);
            S32(0x247c) |= 4;
            SetElementFieldC2((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 0x11, 1);
            SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + 0x2c8 + 0xc00), 0x10);
            SetElementFieldC2((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 0x10, 0);
            S32(0x1bc0) = 1;
            func_ov002_02161cf0(self);
        } else if (cur == 0x15) {
            short saved = S16(0x1bfe);
            func_ov002_02161cf0(self);
            S16(0x1bfe) = saved;
            func_ov002_0215b9a4(self, S32(0x1bb8) & 0xff, 0);
        } else if (cur == 0x11) {
            if (FindElementByC40205d81c((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 7) != 0 || S16(0x1bfc) >= 0) {
                ClearMatchingEntry_02156ff0((unsigned char*)self, 0x13);
                SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + 0x2c8 + 0xc00), 0x11);
                SetElementFieldC2((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 0x11, 0);
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
            SetElementFieldC2((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 9, 0);
            SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + 0x2c8 + 0xc00), 9);
            S32(0x1bc8) = 1;
            S32(0x1bcc) = 1;
            func_ov002_0215b9a4(self, S32(0x1bb8) & 0xff, 0);
        }
        if (S32(0x1bb8) == 5) {
            if (U8(0x2478) != 0) {
                int count = GetCountByType02157108(self, S8(0x1c20));
                if (count == 0) {
                    S16(0x1c22) = -1;
                    S16(0x1be8) = -1;
                    S32(0x1bb8) = 4;
                    S32(0x1bc0) = 1;
                    SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + 0x2c8 + 0xc00), 4);
                    SetElementFieldC2((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 4, 0);
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
                TryApplyElemFields0205d5d0((StructA0205d5d0*)(self + 0x2c8 + 0xc00), (unsigned char)S32(0x1bb8), (int)(*(void**)(self + 0x1bd0)), 1, 0);
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
