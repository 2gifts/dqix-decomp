// JPN: func_ov017_021c0b9c
#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, RegionOffset18c = 0x180, RegionOffset998 = 0x868, RegionOffsetb3c = 0x91c };
#else
enum { RegionOffset6fc = 0x6fc, RegionOffset18c = 0x18c, RegionOffset998 = 0x998, RegionOffsetb3c = 0xb3c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetGlobalField0x1c020421a0(void);
void* GetDataPtr02114e04_020d6c00(void);
extern "C" void* func_0205ec34(void);
int TestBitInByteArray(int a, unsigned char* p, int bit);
int IsField0Null(void** p);
int GetByteField0x252(void* obj);
int CheckSubstructByte0x7cPositive(signed char* p);
struct BitField0203402c;
int CheckField0xc4Low15BitsNonZero(BitField0203402c* p);
struct FlagWord02046708;
int TestFlags02046708(FlagWord02046708* w, unsigned int mask);
int GetByte0x26c(char* p);
int GetSignedField020c39c8(volatile unsigned short* p);
extern "C" int _Z25TestFlag0SetAndFlag1ClearPti(int* flags, int mask);
struct Obj0205eaa0;
int DispatchWithShortB4_0205eaa0(Obj0205eaa0* obj, int a, int b);
void ReinitController02043204(char* p);
void* GetGlobalResetObj020d7a50(void);
struct Obj020d7aa0;
void TeardownAndResetState020d7aa0(Obj020d7aa0* obj);
extern "C" void* func_02012fe4(void);
extern "C" void* func_02017c58(void* a);
void InitObjWithFlag_021c0760(unsigned char* obj, unsigned char flag);
extern "C" void _Z19InsertNodeAfterHeadP12List02046a3cP12Node02046a3c(void* list, void* node);

extern int data_02114e30;
extern Obj0205eaa0 data_02108760;

// USA: func_ov017_021c05f4  (semantic: ProcessEncounterTickOrReinit_021c05f4)
extern "C" ARM void func_ov017_021c05f4(void* p9, unsigned char p8, unsigned char p7, int p6) {
    void* g = GetGlobalField0x1c020421a0();
    if (p6 != 0) {
        GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();
        void* d = GetDataPtr02114e04_020d6c00();
        void* f = func_0205ec34();
        if (TestBitInByteArray((int)f, (unsigned char*)f + 0x8c, 0x119a) == 0) return;
        if (IsField0Null((void**)*(void**)((char*)p9 + 0x3000 + RegionOffset6fc)) == 0) return;
        if (GetByteField0x252(combatant) == 0) return;
        if (CheckSubstructByte0x7cPositive((signed char*)combatant) != 0) return;
        if (*(int*)((char*)combatant + RegionOffset18c) & 1) return;
        if (CheckField0xc4Low15BitsNonZero((BitField0203402c*)combatant) != 0 ||
            *(short*)((char*)combatant + 0xac) != 0 ||
            *(int*)((char*)g + RegionOffset998) != 0) return;
        if (TestFlags02046708((FlagWord02046708*)d, 0x800) != 0) return;
        if (GetByte0x26c((char*)combatant) != 0) return;
        if (GetSignedField020c39c8((volatile unsigned short*)0x400006c) != 0) return;
        if (_Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 4) == 0) return;
        *(unsigned short*)((char*)combatant + 0xb2) = 0;
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    } else {
        if (*(int*)((char*)g + RegionOffset998) != 0) ReinitController02043204((char*)g);
    }

    void* reset = GetGlobalResetObj020d7a50();
    TeardownAndResetState020d7aa0((Obj020d7aa0*)reset);
    func_02017c58(func_02012fe4());

    InitObjWithFlag_021c0760((unsigned char*)*(void**)((char*)p9 + 0x3000 + RegionOffsetb3c), p8);
    char* base = (char*)p9 + 0x3000;
    *((unsigned char*)*(void**)(base + RegionOffsetb3c) + 0x24) = p7;
    _Z19InsertNodeAfterHeadP12List02046a3cP12Node02046a3c(*(void**)(base + RegionOffset6fc), *(void**)(base + RegionOffsetb3c));
}
