// JPN: func_ov025_021dbfd0
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Foo02033b58;
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);
void ClearFlag320_02195540(unsigned char* obj);
int GetGlobalField0x1c020421a0(void);
void InitQueueStruct_021ed124(unsigned char* obj);
void SetField_021e8a4c(char* obj, int v);
void SetFieldNeg1_021e8d14(void* obj);
void ResetFields_021df9b0(void* obj);
void Init021eed58(char* obj);

extern "C" ARM void func_ov025_021e88d8(void* obj);
extern "C" ARM void func_ov025_021dfbfc(void* obj);
extern "C" int func_ov000_0215ec1c(void* obj, short* buf, int max, int start);

#if defined(jpn)
enum { RegionOffset2a8 = 0x224, RegionOffset29c = 0x218, RegionOffset5ab0 = 0x5ca0, RegionOffsetb30 = 0xaac, RegionOffseteb0 = 0xe2c, RegionOffset19be = 0x17ee, RegionOffset2a0 = 0x21c, RegionOffset890 = 0x80c, RegionOffseteac = 0xe28, RegionOffset6fd5 = 0x71c5 };
#else
enum { RegionOffset2a8 = 0x2a8, RegionOffset29c = 0x29c, RegionOffset5ab0 = 0x5ab0, RegionOffsetb30 = 0xb30, RegionOffseteb0 = 0xeb0, RegionOffset19be = 0x19be, RegionOffset2a0 = 0x2a0, RegionOffset890 = 0x890, RegionOffseteac = 0xeac, RegionOffset6fd5 = 0x6fd5 };
#endif

// USA: func_ov025_021db6dc  (semantic: InitBattleState_021db6dc)
extern "C" ARM void func_ov025_021db6dc(void* arg) {
    char* obj = (char*)arg;
    GameState* bs = GameState::GetInstance();
    int g = GetGlobalField0x1c020421a0();
    int handle = ((int)func_ov017_0218b5b0());

    func_ov025_021e88d8(obj + RegionOffset2a8);
    SetField_021e8a4c(obj + RegionOffset2a8, *(int*)(obj + RegionOffset29c));
    SetFieldNeg1_021e8d14(obj + RegionOffset2a8);
    ResetFields_021df9b0(obj + RegionOffset5ab0);
    Init021eed58(obj + RegionOffsetb30);
    *(int*)(obj + RegionOffseteb0) = 0;
    ClearFlag320_02195540((unsigned char*)handle);
    *(unsigned char*)((char*)g + RegionOffset19be) = 1;
    *(unsigned char*)(*(char**)(obj + RegionOffset29c) + 0x8e49) = 0;
    *(unsigned char*)(*(char**)(obj + RegionOffset2a0) + 0x35) = 0;
    func_ov025_021dfbfc(obj);

    short buf[16];
    int n = 0;
    n = n + func_ov000_0215ec1c(*(void**)(obj + RegionOffset29c), buf, 0x10, n);
    for (int i = 0; i < n; i++) {
        GameObject* c = bs->GetCombatantByIndex(buf[i]);
        if (c != 0) {
            int f = *(int*)((char*)c->currentStats_ + 0x14);
            if (!(f & 1)) {
                SetByteSavingPrevious((struct Foo02033b58*)c, 0);
            }
        }
    }

    InitQueueStruct_021ed124((unsigned char*)(obj + RegionOffset890));
    *(int*)(obj + RegionOffseteac) = 1;
    *(unsigned char*)(obj + RegionOffset6fd5) = 0;
}
