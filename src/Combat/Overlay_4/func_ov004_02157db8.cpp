#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct S_e830;
struct Struct020a9ea4;

struct Nib56b_02157db8 {
    char pad[0x56b];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Combatant150_02157db8 {
    char pad[0x150];
    struct Nib56b_02157db8* f150;
};

struct Cfg02157db8 {
    unsigned int lo12 : 12;
    unsigned int n4 : 4;
    unsigned int m5 : 5;
    unsigned int k5 : 5;
    unsigned int j6 : 6;
};

struct Blk_02157db8 {
    unsigned int word00;
    unsigned int word04;
    unsigned int word08;
    unsigned short half0c;
    short half0e;
    unsigned char b10;
    unsigned char b11;
    signed char b12;
    unsigned char b13;
    unsigned char b14;
    unsigned char b15;
    unsigned char pad16[2];
    Cfg02157db8 cfg;
    unsigned char pad1c[0xc];
    unsigned int word28;
    unsigned char b2c;
    unsigned char b2d;
    unsigned char b2e;
    unsigned char b2f;
    unsigned char b30;
    unsigned char b31;
    signed short arr32[6];
    unsigned char b3e;
    unsigned char pad3f[7];
    unsigned char b46;
    unsigned char b47;
    unsigned char pad48[0x24];
    short half6c;
    unsigned char b6e;
    unsigned char b6f;
    signed char b70;
    unsigned char pad71[3];
    unsigned int word74;
    unsigned int word78;
    unsigned char map7c[8];
    unsigned char pad84[8];
    unsigned char pad8c[0xc];
    unsigned int word98;
    unsigned char b9c;
    unsigned char b9d;
    unsigned char pad9e[2];
    unsigned char padA0[0xc];
    unsigned char padAC[0xc];
};

struct Struct021707d8_02157db8 { char pad[8]; Blk_02157db8* ptr; };
extern Struct021707d8_02157db8 data_ov004_021707d8;
extern char data_02109bf4[];

extern "C" void* func_ov011_021845f8(unsigned char*, unsigned int);
void ClearStruct020a9ea4(struct Struct020a9ea4*);
void Zero4Bytes(void*);
void Clear12Bytes020e46c4(void*);
extern "C" void* func_02012fe4(void);
unsigned short GetFieldAt0x7e(struct S_e830* p);
unsigned int GetWord(unsigned int* obj);
unsigned int GetField4(unsigned int* obj);
unsigned int GetField8(unsigned int* obj);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void Set3DClearColor(int, int, int, int, int);
void SetFogState(int, unsigned int, unsigned int, unsigned short);
extern "C" void* func_ov004_02156fd4(void* a, int b);
void SetDataPtr_021f5598(void*);
void RegisterSlotA020cf0fc(int);
void RegisterSlotB020cf1a8(int);
struct Obj020397cc;
void CancelPendingAction020397cc(Obj020397cc*, int);
unsigned char GetField0xcc0209ca98(char*);
void* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0(unsigned int*, unsigned int);
unsigned char CopyOutRegion0x5718(char*, void*);
extern "C" void* _Z25GetCombatantWithFlag0x100P9GameStatei(struct GameState*, int);

// USA: func_ov004_02157db8
extern "C" ARM int func_ov004_02157db8(void* a) {
    GameState* bs = GameState::GetInstance();
    unsigned char* p26c = (unsigned char*)bs + 0x26c;
    unsigned char* p2380 = (unsigned char*)bs + 0x2380;
    unsigned char* base5 = p26c + 0x5c00;
    unsigned char* sub4000 = p2380 + 0x4000;

    data_ov004_021707d8.ptr = 0;
    void* ctx = func_ov011_021845f8((unsigned char*)a, 0);
    if (!ctx) return 0;
    SafeAllocator* alloc = (SafeAllocator*)((char*)ctx + 4);
    Blk_02157db8* blk = (Blk_02157db8*)alloc->Allocate(0xb8);
    data_ov004_021707d8.ptr = blk;
    if (!blk) return 0;

    blk->word00 = 0;
    blk->word04 = 0;
    blk->word08 = 0;
    blk->half0c = 0x3def;
    int neg = -1;
    blk->half0e = neg;
    blk->b10 = 0;
    blk->b11 = 1;
    blk->b12 = neg;
    blk->b13 = 0;
    blk->b14 = 0;
    blk->b15 = 0;
    memset(&blk->cfg, 0, 4);
    memset(blk->pad1c, 0, 0xc);
    blk->word28 = 0;
    blk->b2c = 0;
    blk->b2d = 5;
    blk->b2e = 5;
    blk->b46 = 0;
    blk->b47 = 0;
    blk->b2f = 0;
    blk->b30 = 0;
    blk->b31 = 0;
    blk->b3e = 0;
    memset(blk->pad3f, 0, 7);
    unsigned char* mp = blk->map7c;
    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 4;
    mp[3] = 2;
    mp[4] = 5;
    mp[5] = 3;
    mp[6] = 6;
    mp[7] = 7;
    int neg2 = -1;
    blk->half6c = neg2;
    blk->b6e = 0;
    blk->b6f = 0;
    blk->b70 = neg2;
    blk->word74 = neg2;
    blk->word78 = 0;
    ClearStruct020a9ea4((struct Struct020a9ea4*)blk->pad84);
    Zero4Bytes(blk->pad8c);
    blk->word98 = 0;
    blk->b9c = 0;
    blk->b9d = 0;
    Clear12Bytes020e46c4(blk->padA0);
    Clear12Bytes020e46c4(blk->padAC);

    void* v = func_02012fe4();
    if (!v) return 0;
    void* p = (char*)v + 0x6c;
    if (!p) return 0;
    data_ov004_021707d8.ptr->half0c = GetFieldAt0x7e((struct S_e830*)p);

    unsigned int* obj = (unsigned int*)func_ov017_0218b5b0();
    data_ov004_021707d8.ptr->word00 = GetWord(obj);
    data_ov004_021707d8.ptr->word04 = GetField4(obj);
    data_ov004_021707d8.ptr->word08 = GetField8(obj);
    SetBitsInWord(obj, 4);
    SetBitsInField4(obj, 0x8de);

    int pad0 = 0;
    Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
    SetFogState(0, 0, 0, 0);

    void* d = func_ov004_02156fd4(a, 5);
    if (d != 0) {
        SetDataPtr_021f5598(d);
    }
    int slotA[4];
    int slotB[3];
    RegisterSlotA020cf0fc((int)slotA);
    RegisterSlotB020cf1a8((int)slotB);

    data_ov004_021707d8.ptr->cfg.lo12 = slotA[0] + 0x7d0;
    data_ov004_021707d8.ptr->cfg.n4 = slotA[1];
    data_ov004_021707d8.ptr->cfg.m5 = slotA[2];
    data_ov004_021707d8.ptr->cfg.k5 = slotB[0];
    data_ov004_021707d8.ptr->cfg.j6 = slotB[1];

    CancelPendingAction020397cc((Obj020397cc*)bs->GetUnknownGameObject(), 1);
    data_ov004_021707d8.ptr->b2d = GetField0xcc0209ca98(data_02109bf4);
    unsigned int subword = *(unsigned int*)(sub4000 + 0x50);
    data_ov004_021707d8.ptr->b2f = (subword & 1) ? 1 : 0;
    OrBitsIntoField0((unsigned int*)GetDataPtr02114e04_020d6c00(), 0xf);

    short* pp = (short*)(base5 + 4);
    for (int i = 0; i < 6; ) {
        if (*pp > 0) {
            data_ov004_021707d8.ptr->b46++;
        }
        i++;
        pp = (short*)((char*)pp + 0x28);
    }

    void* ctx9 = func_ov011_021845f8((unsigned char*)a, 9);
    if (!ctx9) return 0;
    SafeAllocator* alloc9 = (SafeAllocator*)((char*)ctx9 + 4);
    void* big = alloc9->Allocate(0x10800);
    data_ov004_021707d8.ptr->word98 = (unsigned int)big;
    memset((void*)data_ov004_021707d8.ptr->word98, 0, 0x10800);

    unsigned char ids[4];
    unsigned char count = CopyOutRegion0x5718((char*)bs, ids);
    for (int i = 0; i < count; i++) {
        data_ov004_021707d8.ptr->arr32[i] = ids[i];
    }
    data_ov004_021707d8.ptr->arr32[4] = count;

    for (int i = 0; i < data_ov004_021707d8.ptr->arr32[4]; i++) {
        void* combatant = _Z25GetCombatantWithFlag0x100P9GameStatei(bs, data_ov004_021707d8.ptr->arr32[i]);
        if (combatant != 0) {
            struct Nib56b_02157db8* field150 = ((struct Combatant150_02157db8*)combatant)->f150;
            int flag;
            if (field150 != 0) {
                flag = field150->lo != 0;
            } else {
                flag = 0;
            }
            if (flag != 0) {
                int j = i;
                while (j < data_ov004_021707d8.ptr->arr32[4]) {
                    data_ov004_021707d8.ptr->arr32[j] = data_ov004_021707d8.ptr->arr32[j + 1];
                    data_ov004_021707d8.ptr->arr32[j + 1] = -1;
                    j++;
                }
                data_ov004_021707d8.ptr->arr32[4] = data_ov004_021707d8.ptr->arr32[4] - 1;
            }
        }
    }
    data_ov004_021707d8.ptr->arr32[5] = data_ov004_021707d8.ptr->arr32[0];
    return 0;
}
