#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct S_e830;

struct Ov004Config_0216ea74 {
    unsigned int lo12 : 12;
    unsigned int n4 : 4;
    unsigned int m5 : 5;
    unsigned int k5 : 5;
    unsigned int j6 : 6;
};

struct Ov004Block_0216ea74 {
    unsigned int word00;
    unsigned int word04;
    unsigned int word08;
    unsigned short half0c;
    unsigned char pad0e[0x20];
    unsigned char flags2e[6];
    signed char flag34;
    struct Ov004Config_0216ea74 cfg;
    unsigned char pad3c[0xc];
    unsigned int word48;
};

struct Struct02171048_0216ea74 { char pad[4]; struct Ov004Block_0216ea74* ptr; };
extern Struct02171048_0216ea74 data_ov004_02171048;

extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_021b2090(unsigned int a, unsigned int b);
unsigned short GetFieldAt0x7e(struct S_e830* p);
unsigned int GetWord(unsigned int* obj);
unsigned int GetField4(unsigned int* obj);
unsigned int GetField8(unsigned int* obj);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void Set3DClearColor(int, int, int, int, int);
void SetFogState(int, unsigned int, unsigned int, unsigned short);
extern "C" void _Z21RegisterSlotA020cf0fci(int);
extern "C" void _Z21RegisterSlotB020cf1a8i(int);

// USA: func_ov004_0216ea74
extern "C" ARM int func_ov004_0216ea74(SafeAllocator* a) {
    GameState* bs = GameState::GetInstance();
    data_ov004_02171048.ptr = 0;
    void* ctx = func_ov011_021845f8(a, 0);
    if (!ctx) return 0;
    SafeAllocator* alloc = (SafeAllocator*)((char*)ctx + 4);
    struct Ov004Block_0216ea74* blk = (struct Ov004Block_0216ea74*)alloc->Allocate(0x4c);
    data_ov004_02171048.ptr = blk;
    if (!blk) return 0;

    blk->word00 = 0;
    blk->word04 = 0;
    blk->word08 = 0;
    blk->half0c = 0x3def;
    memset(blk->pad0e, 0, 0x20);
    blk->flags2e[0] = 0;
    blk->flags2e[1] = 0;
    blk->flags2e[2] = 0;
    blk->flags2e[3] = 0;
    blk->flags2e[4] = 0;
    blk->flags2e[5] = 0;
    blk->flag34 = -1;
    memset(blk->pad3c, 0, 0xc);
    blk->word48 = 0;

    void* v = func_02012fe4();
    if (!v) return 0;
    void* p = (char*)v + 0x6c;
    if (!p) return 0;
    data_ov004_02171048.ptr->half0c = GetFieldAt0x7e((struct S_e830*)p);

    unsigned int* obj = (unsigned int*)func_ov017_0218b5b0();
    data_ov004_02171048.ptr->word00 = GetWord(obj);
    data_ov004_02171048.ptr->word04 = GetField4(obj);
    data_ov004_02171048.ptr->word08 = GetField8(obj);
    SetBitsInWord(obj, 4);
    SetBitsInField4(obj, 0x8de);

    Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
    SetFogState(0, 0, 0, 0);

    int slotA[4];
    int slotB[3];
    _Z21RegisterSlotA020cf0fci((int)slotA);
    _Z21RegisterSlotB020cf1a8i((int)slotB);

    data_ov004_02171048.ptr->cfg.lo12 = slotA[0] + 0x7d0;
    data_ov004_02171048.ptr->cfg.n4 = slotA[1];
    data_ov004_02171048.ptr->cfg.m5 = slotA[2];
    data_ov004_02171048.ptr->cfg.k5 = slotB[0];
    data_ov004_02171048.ptr->cfg.j6 = slotB[1];

    unsigned int* sub = (unsigned int*)((char*)bs + 0x2380 + 0x4000);
    if (sub[0x50 / 4] & 1) {
        if (func_ov017_021b2090(sub[0x44 / 4], *(unsigned int*)&data_ov004_02171048.ptr->cfg) != 0) {
            data_ov004_02171048.ptr->flags2e[2] = 1;
        }
    }
    return 0;
}
