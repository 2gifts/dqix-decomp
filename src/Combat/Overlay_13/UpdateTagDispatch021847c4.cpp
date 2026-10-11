#if defined(jpn)
#define R(j,u) (j)
#define func_ov013_021846a0 func_ov013_021856dc
#define func_ov013_02184d80 func_ov013_02185db4
#define func_ov013_02186160 func_ov013_02187178
#define func_ov013_021864f0 func_ov013_02187820
#define func_ov013_02186590 func_ov013_021878c0
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_0218683c func_ov013_02187b68
#define func_ov013_02186bd4 func_ov013_02187f00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0205d888;
void* GetLastEntry0205d888(struct Struct0205d888* p);
int IsField0x9cEqual3(unsigned char* obj);
void SetFieldAt0x30(void* obj, int value);
int GetGlobalField0x1c020421a0(void);
void SetupAndDispatch0205c904(unsigned char* p, int val);

struct Container0205a330;
void IterateEntries0205a330(struct Container0205a330* c, int arg);

struct Struct_0205bc10;
void ClearBytes0x4cTo0x4e(struct Struct_0205bc10* s);

struct Struct_0205ba68;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);

struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);

struct Struct_0205d81c;
void SetElementFieldC2(struct Struct_0205d81c* s, int key, int value);

extern "C" void func_0205bb04(void* s, int n);
extern "C" int func_0205d0e0(void* p, int val);
extern "C" void func_ov013_02186bd4(void* obj);
extern "C" void func_ov013_02184d80(void* obj);
extern "C" void func_ov013_02186160(void* obj);
extern "C" void func_ov013_0218678c(void* obj);
extern "C" void func_ov013_021864f0(void* obj);
extern "C" void func_ov013_0218683c(void* obj);
extern "C" void func_ov013_02186590(void* obj);
extern "C" void func_ov013_021846a0(void* obj);

// USA: func_ov013_021847c4  (semantic: UpdateTagDispatch021847c4)
extern "C" ARM unsigned char func_ov013_021847c4(void* obj, int param1) {
    unsigned char* o = (unsigned char*)obj;
    GameState* bs;
    void* last;
    int i;

    *(int*)(o + 0x14) = param1;
    bs = GameState::GetInstance();
    *(int*)(o + R(0x5d0,0x644)) = bs->GetTickCount();

    last = GetLastEntry0205d888((struct Struct0205d888*)(o + R(0x34,0x38)));
    if (last != 0) {
        if (IsField0x9cEqual3((unsigned char*)last) != 0) {
            if ((((unsigned char*)last)[0xc5] & 2) == 0) {
                SetFieldAt0x30(o + R(0x38,0x3c), -1);
            }
        }
    }

    *(int*)(o + R(0x5d4,0x648)) = func_0205d0e0(o + R(0x34,0x38), *(int*)(o + R(0x5d0,0x644)));
    SetupAndDispatch0205c904(o + R(0x3d0,0x3d4), *(int*)(o + R(0x5d0,0x644)));

    {
        int g = GetGlobalField0x1c020421a0();
        struct Container0205a330* c = *(struct Container0205a330**)(g + R(0x230,0x2e0));
        if (c != 0) {
            IterateEntries0205a330(c, bs->GetTickCount());
        }
    }

    if (o[R(0x5cb,0x63f)] != 0) {
        if (o[R(0x5cc,0x640)] != 0) {
            ClearBytes0x4cTo0x4e((struct Struct_0205bc10*)(o + R(0x38,0x3c)));
        }
        if (o[R(0x5c8,0x63c)] == 1) {
            o[R(0xe5,0xe9)] = 0;
            *(int*)(o + R(0x3c,0x40)) = 1;
            *(int*)(o + R(0x8c,0x90)) = 1;
            SetupPointerTable0205ba68((struct Struct_0205ba68*)(o + R(0x38,0x3c)), 1, 6, 0);
            SetupPointerTable0205ba68((struct Struct_0205ba68*)(o + R(0x88,0x8c)), 1, 6, 0);
            SetField0AndPropagate0205bacc((struct Node0205bacc*)(o + R(0x38,0x3c)), 6);
            SetField0AndPropagate0205bacc((struct Node0205bacc*)(o + R(0x88,0x8c)), 6);
            i = *(int*)(o + R(0x5e4,0x65c));
            SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(o + R(0x38,0x3c)), i);
            func_0205bb04(o + R(0x88,0x8c), i);
            func_ov013_02186bd4(obj);
        }
        if (o[R(0x5c8,0x63c)] == 3 && o[R(0x5cc,0x640)] != 0) {
            o[R(0xe5,0xe9)] = 3;
            *(int*)(o + R(0x3c,0x40)) = 1;
            *(int*)(o + R(0x8c,0x90)) = 1;
            SetupPointerTable0205ba68((struct Struct_0205ba68*)(o + R(0x38,0x3c)), 1, 2, 0);
            SetupPointerTable0205ba68((struct Struct_0205ba68*)(o + R(0x88,0x8c)), 1, 2, 0);
            SetField0AndPropagate0205bacc((struct Node0205bacc*)(o + R(0x38,0x3c)), 2);
            SetField0AndPropagate0205bacc((struct Node0205bacc*)(o + R(0x88,0x8c)), 2);
            SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(o + R(0x38,0x3c)), 0);
            func_0205bb04(o + R(0x88,0x8c), 0);
        }
        o[R(0x5cb,0x63f)] = 0;
        return o[R(0x5c8,0x63c)];
    }

    switch (o[R(0x5c8,0x63c)]) {
        case 0:
            func_ov013_02184d80(obj);
            break;
        case 1:
            func_ov013_02186160(obj);
            break;
        case 2:
            if (o[R(0x5cc,0x640)] != 0) func_ov013_0218678c(obj);
            else func_ov013_021864f0(obj);
            break;
        case 3:
        case 4:
            if (o[R(0x5cc,0x640)] != 0) func_ov013_0218683c(obj);
            else func_ov013_02186590(obj);
            break;
        case 5:
            func_ov013_021846a0(obj);
            break;
    }

    for (i = 0; i < 4; i++) {
        unsigned char* p = o + i;
        unsigned char v = p[R(0x5c4,0x638)];
        struct Struct_0205d81c* s = (struct Struct_0205d81c*)(o + R(0x34,0x38));
        SetElementFieldC2(s, (unsigned char)i, v);
    }

    o[R(0x5cb,0x63f)] = (o[R(0x5c8,0x63c)] != o[R(0x5c9,0x63d)]) ? 1 : 0;
    o[R(0x5c9,0x63d)] = o[R(0x5c8,0x63c)];
    return o[R(0x5c8,0x63c)];
}
