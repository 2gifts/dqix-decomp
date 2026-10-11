// JPN: func_ov017_021a6dc0
#include <globaldefs.h>

#include "Combat/BattleSkillEligibility.h"
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_0202c540(void* p);
extern "C" void func_0205ac40(void* a, void* b);

int GetIntField0x260(void* obj);
int GetGlobalField0x1c020421a0();
void* GetGlobalContext020daf90(void);
int IsField0Null(void** obj);

struct Something02015a2c;
int CheckSlotsForFlagState02015a2c(struct Something02015a2c* obj);

int GetField0x50(void* obj);

struct Node0x20_021a5ad0;
void FillFieldWithEncoded_021a5ad0(struct Node0x20_021a5ad0* arr, int count, int val);
void ClearAndEncodeField14_021a5b08(struct Node0x20_021a5ad0* arr, int count);

struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);


struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
void CallFunc0204b04cOverList0x98(Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
struct Obj0205d2bc;
void InitEntries0205d2bc(Obj0205d2bc*);

extern unsigned short data_ov017_021d6a9e[5];

// USA: func_ov017_021a63d0  (semantic: ResetEncounterState_021a63d0)
#if defined(jpn)
static const int OFF_41c0 = 0x3fa0;
static const int OFF_41b4 = 0x3f94;
static const int OFF_4080 = 0x3e60;
static const int OFF_36fc = 0x34ec;
static const int OFF_998 = 0x868;
static const int OFF_4094 = 0x3e74;
static const int OFF_41b8 = 0x3f98;
static const int OFF_4090 = 0x3e70;
static const int OFF_41c4 = 0x3fa4;
#else
static const int OFF_41c0 = 0x41c0;
static const int OFF_41b4 = 0x41b4;
static const int OFF_4080 = 0x4080;
static const int OFF_36fc = 0x36fc;
static const int OFF_998 = 0x998;
static const int OFF_4094 = 0x4094;
static const int OFF_41b8 = 0x41b8;
static const int OFF_4090 = 0x4090;
static const int OFF_41c4 = 0x41c4;
#endif

extern "C" ARM void func_ov017_021a63d0(unsigned char* base) {
 #if !defined(jpn)
    short buf[5];
 #endif

    if (*(int*)(base + OFF_41c0) == 0) return;
    if (*(int*)(base + OFF_41b4) == 0) return;

    void* searchObj = func_0202ae18();
    int f260 = GetIntField0x260(GameState::GetInstance()->GetProtagonist());
    int glob1c = GetGlobalField0x1c020421a0();
    void* g = func_02012fe4();
    void* ctx = GetGlobalContext020daf90();

    if (GameState::GetInstance()->GetGrottoStruct()->unknown_0[0] == 0) return;

    int f4080 = *(int*)(base + OFF_4080);
    if (f4080 != 0) return;
    if (f260 != -1) return;

    if (!IsField0Null(*(void***)(base + OFF_36fc))) return;
    if (func_0202c540(searchObj)) return;

    if (IsGlobalU16InRange(GameState::GetInstance()) != 0) return;
    if (*(int*)((char*)glob1c + OFF_998) != 0) return;
    if (CheckSlotsForFlagState02015a2c((struct Something02015a2c*)g)) return;
    if (GetField0x50(ctx)) return;

    FillFieldWithEncoded_021a5ad0((struct Node0x20_021a5ad0*)(base + OFF_4094), 2, 0x800);

 #if !defined(jpn)
    {
        unsigned short* dst = (unsigned short*)buf;
        unsigned short* src = data_ov017_021d6a9e;
        int n = 5;
        do {
            unsigned short* d = dst++;
            unsigned short t = *src++;
            *d = t;
        } while (--n);
    }

    unsigned char count = NormalizeField5_0200fb08((struct Struct0200fb08*)GameState::GetInstance());

 #endif

    if (*(int*)(base + OFF_41b8) >= 3) {
        void* sub = *(void**)(base + OFF_4090);
        ClearBuffers0204b010OverList0x98((Cont0205d1e0*)sub);
        CallFunc0204c8f0OverList0x9c((Cont0205d228*)sub);
        func_0205da88(sub, 1, 2, 1);
        CallFunc0204b04cOverList0x98((Cont0205d274*)sub);
        InitEntries0205d2bc((Obj0205d2bc*)sub);

        unsigned char* p = *(unsigned char**)(base + OFF_41c4);
        int val40 = *(int*)(p + 0x40);
        unsigned char* q = 0;
        if (val40 != 0) {
            if (*(unsigned short*)(p + 0x4e) > 6) {
                q = (unsigned char*)val40 + 0xf0;
            }
        }

        if (q) {
#if defined(jpn)
            int val = 0xb7000;
#else
            int val = (buf[count - 1] + 7) << 12;
#endif
            *(int*)(q + 0x14) = val;
            *(int*)(q + 0x18) = 0xab000;
            q[0x22] = 0x7e;
            q[0x26] = 0;
            *(int*)(q + 0xc) = 0x1000;
            *(int*)(q + 0x10) = 0x1000;
            void* p2 = *(void**)(base + OFF_41c4);
            func_0205ac40(p2, q);
        }
    }

    ClearAndEncodeField14_021a5b08((struct Node0x20_021a5ad0*)(base + OFF_4094), 2);
}
