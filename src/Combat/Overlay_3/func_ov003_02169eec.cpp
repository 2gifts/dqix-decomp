#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kMenuPrefix = 0xe0, kCellWidth = 12, kRectXIndex = 1, kResetOffset = 0x134 };
#else
enum { kMenuPrefix = 0xe4, kCellWidth = 8, kRectXIndex = 0, kResetOffset = 0x138 };
#endif

struct Struct_0205bbcc;
struct Struct_0205ba68;
struct Node0205bacc;
struct Struct_0205bcdc;
struct Struct_0205bd58;
struct S0216a85c;
struct Struct_0205d81c;
struct Struct_0205bc2c;
struct Struct_0205bd04;
struct Struct_0205bc10;
struct Struct_0205c570;
struct Struct_0205bf3c;
struct Struct_0205bb84;
struct Struct0200fb08;
struct Obj0205eaa0;
struct Struct0205cf1c;

extern "C" void func_ov003_02169594(void* self);
extern "C" void func_ov003_021696f4(void* self, int v);
extern "C" int func_ov003_02169674(void* self, int x, int y, void* rects);
extern "C" void func_0205bb04(void* obj, int v);
extern "C" int func_0205bf58(void* obj, int v);

extern "C" void _Z23SetChannelAFlag0205cef8Pv(void* chan);
extern "C" void _Z23SetChannelBFlag0205cf04Pv(void* chan);
extern "C" void _Z12Init0205bbccP15Struct_0205bbcc(Struct_0205bbcc* obj);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(Struct_0205ba68* obj, int a, int b, int c);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(Node0205bacc* obj, int v);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(Struct_0205bcdc* obj, int v);
extern "C" void _Z17SetFields0205bd58P15Struct_0205bd58iiiii(Struct_0205bd58* obj, int a, int b, int c, int d, int e);
extern "C" void _Z20ClearFields_0216a85cP9S0216a85c(S0216a85c* obj);
unsigned char* FindElementForFieldB0(Struct_0205d81c* chan);
void GetFourSubstructPointers(unsigned char* elem, unsigned char** a, unsigned char** b, unsigned char** c,
                              unsigned char** d);
void SelectCoordsByFlag0x24(unsigned char* input, int* x, int* y);
void SetFieldAt0x30(void* obj, int v);
extern "C" int _Z25UpdateActiveState0205bc2cP15Struct_0205bc2c(Struct_0205bc2c* obj, int v);
extern "C" int _Z28GetScaledSumIfActive0205bd04P15Struct_0205bd04(Struct_0205bd04* obj);
extern "C" int _Z18GetField0_0205bafcPv(void* obj);
extern "C" void _Z24ClearFlagFields_02169658Pv(void* self);
void ClearBytes0x4cTo0x4e(Struct_0205bc10* obj);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570* chan);
extern "C" void _Z31UpdateEntryAndField4ea_021694b8Pvi(void* self, int v);
int TestFlagMask(unsigned short* flags, int mask);
int TestFlag0SetAndFlag1Clear(unsigned short* flags, int mask);
int TestFlagInSecondWord(unsigned short* flags, unsigned int mask);
extern "C" void _Z18ResetState0205bf3cP15Struct_0205bf3c(Struct_0205bf3c* obj);
extern "C" int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(Struct_0205bb84* obj);
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08* gs);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* obj, int a, int b);
extern "C" void _Z25ClearChannelAFlag0205cf10Pv(void* chan);
extern "C" void _Z21ClearFlagByte0205cf1cP14Struct0205cf1c(Struct0205cf1c* chan);

struct InputState {
    char pad0[0x24];
    unsigned short h24;
    char pad26[0x2e];
    unsigned char b54;
    unsigned char b55;
    char pad56[9];
    unsigned char b5f;
};

extern InputState data_02114e54;
extern unsigned short data_02114e30;
extern unsigned char data_ov003_0217f544[];
extern unsigned char data_ov003_0217f545[];
extern unsigned char data_ov003_0217f546[];
extern unsigned char data_ov003_0217f547[];
extern unsigned char data_ov003_0217f548[];
extern Obj0205eaa0 data_02108760;

struct Rects02169674 {
    short originX;
    short originY;
    signed char count;
    char pad5;
    short* xMinArr;
    short* yMinArr;
    short* xWidthArr;
    short* yWidthArr;
};

struct Menu02169eec {
    char pad0[kMenuPrefix];
    char chan[0x179 - 0xe4];
    unsigned char b179;
    char pad17a[0x4e9 - 0x17a];
    unsigned char state;
    unsigned char code;
    char pad4eb[3];
    signed char cursor;
    signed char cells[4];
    signed char alt[4];
    char pad4f7;
    unsigned int limit;
    char list[0x53c - 0x4fc];
    char node[4];
    int w540;
    char pad544[0x574 - 0x544];
    short h574;
    short h576;
    char pad578[0x588 - 0x578];
    unsigned char b588;
    char pad589[3];
    short h58c[8];
    signed char step;
    unsigned char b59d;
    signed char b59e;
    char pad59f;
    unsigned int w5a0;
    char pad5a4[2];
    unsigned char b5a6;
    unsigned char b5a7;
    Rects02169674 rectA;
    Rects02169674 rectB;
};

static inline short GetBX(Menu02169eec* m) {
    return m->rectB.originX;
}
static inline short GetBY(Menu02169eec* m) {
    return m->rectB.originY;
}
static inline short* GetYMin(Menu02169eec* m) {
    return m->rectB.yMinArr;
}

static inline short ElemX(unsigned char* e) {
    return *(short*)(e + 0xac);
}
static inline short ElemY(unsigned char* e) {
    return *(short*)(e + 0xae);
}

// USA: func_ov003_02169eec
// JPN: func_ov003_02169c0c
extern "C" ARM int func_ov003_02169eec(Menu02169eec* self, unsigned int sb) {
    int ax;
    int ay;
    int px;
    int py;

    if (self->state == 0) {
        func_ov003_02169594(self);
        _Z23SetChannelAFlag0205cef8Pv(self->chan);
        _Z23SetChannelBFlag0205cf04Pv(self->chan);
        func_ov003_021696f4(self, self->cursor);
        _Z12Init0205bbccP15Struct_0205bbcc((Struct_0205bbcc*)self->node);
        _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)self->node, 1, 2, 0);
        self->w540 = 1;
        _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)self->node, 2);
        _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((Struct_0205bcdc*)self->node, 0);
        self->h58c[0] = 0;
        self->h58c[1] = 0;
        self->h58c[2] = 0;
        self->h58c[3] = 0x10;
        self->h58c[4] = kCellWidth;
        self->h58c[5] = kCellWidth;
        self->h58c[6] = 0x10;
        self->h58c[7] = 0x10;
        _Z17SetFields0205bd58P15Struct_0205bd58iiiii((Struct_0205bd58*)self->node, 2, (int)&self->h58c[0], (int)&self->h58c[2],
                          (int)&self->h58c[4], (int)&self->h58c[6]);
        _Z20ClearFields_0216a85cP9S0216a85c((S0216a85c*)&self->rectA);
        self->rectA.count = 2;
        self->rectA.xMinArr = &self->h58c[kRectXIndex];
        self->rectA.yMinArr = &self->h58c[2];
        self->rectA.xWidthArr = &self->h58c[4];
        self->rectA.yWidthArr = &self->h58c[6];
        _Z20ClearFields_0216a85cP9S0216a85c((S0216a85c*)&self->rectB);
        unsigned char* elem = FindElementForFieldB0((Struct_0205d81c*)self->chan);
        short ex = ElemX(elem);
        short ey = ElemY(elem);
        self->rectB.originX = ex << 3;
        self->rectB.originY = ey << 3;
        self->rectB.count = 4;
        GetFourSubstructPointers(elem, (unsigned char**)&self->rectB.xMinArr, (unsigned char**)&self->rectB.yMinArr,
                                 (unsigned char**)&self->rectB.xWidthArr, (unsigned char**)&self->rectB.yWidthArr);
        self->state++;
    } else if (self->state == 1) {
        signed char cur;
        signed char* cells = self->cells;
        cur = self->cursor;
        if (data_02114e54.b55 != 0 || (data_02114e54.b5f != 0 && data_02114e54.h24 != 0) ||
            data_02114e54.b54 != 0) {
            SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &ax, &ay);
            int r8 = (FindElementForFieldB0((Struct_0205d81c*)self->chan)[0xc5] & 2) != 0;
            unsigned char r7 = 0;
            if (data_02114e54.b55 != 0) {
                short bx = GetBX(self);
                short by = GetBY(self);
                int idx = self->cursor;
#if defined(jpn)
                short x = (short)(bx + self->rectB.xMinArr[idx]);
                short y = (short)(by + self->rectB.yMinArr[idx]);
                if (r8 == 0) {
                    x = (short)(x - 1);
                    y = (short)(y - 10);
                }
#else
                short x = (short)(bx + (idx * 8 + 0x24));
                short y = (short)(by + self->rectB.yMinArr[idx]);
                if (r8 == 0) {
                    y = (short)(y - 10);
                }
#endif
                self->h574 = x;
                self->h576 = y;
                self->rectA.originX = x;
                self->rectA.originY = y;
                SetFieldAt0x30(self->node, func_ov003_02169674(self, ax, ay, &self->rectA));
                if (func_ov003_02169674(self, ax, ay, &self->rectA) >= 0) {
                    r7 = 1;
                    if (_Z25UpdateActiveState0205bc2cP15Struct_0205bc2c((Struct_0205bc2c*)self->node, sb) != 0) {
                        self->b59d = r7;
                        self->code = 2;
                        self->b59e = 0x14;
                        int dir = _Z28GetScaledSumIfActive0205bd04P15Struct_0205bd04((Struct_0205bd04*)self->node);
                        int n = (signed char)_Z18GetField0_0205bafcPv(self->list);
                        if (dir == 0) {
                            cells[cur]++;
                            signed char cv = cells[cur];
                            if (cv == n) {
                                cells[cur] = 0;
                            }
                            self->step = 1;
                            self->b5a6 = 1;
                            self->b5a7 = 0;
                        } else if (dir == 1) {
                            cells[cur]--;
                            if (cells[cur] == -1) {
                                cells[cur] = n - 1;
                            }
                            self->step = -1;
                            self->b5a6 = 0;
                            self->b5a7 = 1;
                        }
                    }
                }
            } else {
                int active = (data_02114e54.b5f != 0 && data_02114e54.h24 != 0);
                unsigned char b5f = data_02114e54.b5f;
                if (!(active == 0 && data_02114e54.b54 == 0)) {
                    if (self->b59d != 0) {
                        r7 = 1;
                        if (b5f != 0 && data_02114e54.h24 != 0) {
                            if (sb < (unsigned int)self->b59e) {
                                self->b59e -= sb;
                            } else {
                                self->b59e = 10;
                                cells[cur] += self->step;
                                signed char n = _Z18GetField0_0205bafcPv(self->list);
                                if (cells[cur] > n - 1) {
                                    cells[cur] = n - 1;
                                }
                                if (cells[cur] < 0) {
                                    cells[cur] = 0;
                                }
                                self->code = 2;
                            }
                        }
                        if (data_02114e54.b54 != 0) {
                            if (self->b588 != 0) {
                                self->code = 4;
                            } else {
                                self->code = 3;
                            }
                            _Z24ClearFlagFields_02169658Pv(self);
                            ClearBytes0x4cTo0x4e((Struct_0205bc10*)self->node);
                        }
                    }
                }
            }
            if (r7 == 0) {
                int before = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->chan);
                self->b179 = 0;
                _Z31UpdateEntryAndField4ea_021694b8Pvi(self, sb);
                self->b179 = 1;
                int after = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->chan);
                if (before != after) {
                    func_ov003_021696f4(self, after);
                }
            }
            if (r8 != 0 && data_02114e54.b54 != 0) {
                if (func_ov003_02169674(self, ax, ay, &self->rectB) < 0) {
                    self->code = 3;
                }
            }
        } else {
            if (TestFlagMask(&data_02114e30, 0x40) || TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40) ||
                TestFlagInSecondWord(&data_02114e30, 0x40) || TestFlagMask(&data_02114e30, 0x80) ||
                TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80) ||
                TestFlagInSecondWord(&data_02114e30, 0x80)) {
                _Z18ResetState0205bf3cP15Struct_0205bf3c((Struct_0205bf3c*)((char*)self + kResetOffset));
                int old = cells[cur];
                int n = _Z18GetField0_0205bafcPv(self->list);
                func_0205bb04(self->list, n - 1 - cells[cur]);
                if (func_0205bf58(self->list, sb) != 0) {
                    cells[cur] = n - 1 - _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((Struct_0205bb84*)self->list);
                    if (old != cells[cur]) {
                        self->code = 1;
                    }
                }
            } else {
                int before = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->chan);
                _Z31UpdateEntryAndField4ea_021694b8Pvi(self, sb);
                int after = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->chan);
                if (before != after) {
                    func_ov003_021696f4(self, after);
                }
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x10) && self->cursor == 3) {
                    for (int i = 0; i < 4; i++) {
                        self->cells[i] = 0;
                    }
                    self->code = 1;
                } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x20) && self->cursor == 0) {
                    for (int i = 0; i < 4; i++) {
                        self->cells[i] = self->alt[i];
                    }
                    self->code = 1;
                }
            }
        }

        self->cursor = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->chan);
        unsigned int total = 0;
        unsigned int mul = 1000;
        for (int i = 3; i >= 0; i--) {
            total += mul * self->cells[i];
            mul *= 10;
        }
        if (total > self->limit) {
            for (int i = 0; i < 4; i++) {
                self->cells[i] = self->alt[i];
            }
        }

        int hit1 = 0;
        int hit2 = 0;
        if (data_02114e54.b55 != 0) {
            SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &px, &py);
            if (py >= 0x60 && py < 0x6b) {
#if defined(jpn)
                short lox = 0x8f;
                short hix = 0xbb;
                short loy = 0xc8;
                short hiy = 0xec;
#else
                int key = _Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)GameState::GetInstance());
                short lox = 0x8f;
                short hix = 0xba;
                short loy = 0xc5;
                short hiy = 0xed;
                for (int i = 0; i < 5; i++) {
                    if (key == data_ov003_0217f544[i * 5]) {
                        lox = data_ov003_0217f545[i * 5] - 1;
                        hix = data_ov003_0217f546[i * 5] + lox + 2;
                        loy = data_ov003_0217f547[i * 5] - 1;
                        hiy = data_ov003_0217f548[i * 5] + loy + 2;
                        break;
                    }
                }
#endif
                if (px >= lox && px < hix) {
                    hit1 = 1;
                } else if (px >= loy && px < hiy) {
                    hit2 = 1;
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, hit2, 0);
                }
            }
        }
        int a = TestFlag0SetAndFlag1Clear(&data_02114e30, 1);
        int b = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400);
        if ((a | b) != 0) {
            hit1 = 1;
        } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) != 0) {
            hit2 = 1;
        }
        if (hit1 != 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
            unsigned int m = 1000;
            for (int i = 3; i >= 0; i--) {
                self->w5a0 += m * self->cells[i];
                m *= 10;
            }
            _Z25ClearChannelAFlag0205cf10Pv(self->chan);
            _Z21ClearFlagByte0205cf1cP14Struct0205cf1c((Struct0205cf1c*)self->chan);
            self->state = 0;
            return self->w5a0 == 0 ? -2 : 0;
        }
        if (hit2 != 0) {
            _Z25ClearChannelAFlag0205cf10Pv(self->chan);
            _Z21ClearFlagByte0205cf1cP14Struct0205cf1c((Struct0205cf1c*)self->chan);
            self->state = 0;
            return -2;
        }
    }
    return -1;
}
