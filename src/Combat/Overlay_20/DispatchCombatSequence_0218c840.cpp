#if defined(jpn)
#define REGION(j,u) (j)
#define _Z35CheckGlobalObjState2AndInit0205cde8Ph func_0205e118
#define data_ov020_0218d974 data_ov020_0218e1c4
#define data_ov020_0218d990 data_ov020_0218e1e0
#define func_0205c96c func_0205dcd4
#else
#define REGION(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0();
struct ResetBytesAndSetByte0x16Data;
void ResetBytesAndSetByte0x16(struct ResetBytesAndSetByte0x16Data* p, int val);
void SetupGlobalObjType1AndInitSelfPointer(unsigned char* obj);
void SetupAndDispatch0205c904(unsigned char* p, int a1);
struct Container0205a330;
void IterateEntries0205a330(struct Container0205a330* c, int arg);
extern "C" int _Z35CheckGlobalObjState2AndInit0205cde8Ph(unsigned char* p);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
int GetScaledSumIfActive0205cecc(void* s);
int CallFunc0205c570AtField0x1c(void* obj);
unsigned char GetByte0x4(char* obj);
void SetByte0x4(char* obj, unsigned char value);
int CheckSaveBufferStatus(int flag);
extern "C" int func_0205c96c(unsigned char* p, int a1);
extern unsigned short data_02114e30;
extern int data_ov020_0218d990[8];
extern int data_ov020_0218d974[7];

struct DispatchState_0218c840 {
    int f0;
    int f4;
    char pad[REGION(0x1cf, 0x23f) - 0x8];
    unsigned char byte23f;
    unsigned char byte240;
};

// USA: func_ov020_0218c840  (semantic: DispatchCombatSequence_0218c840)
extern "C" ARM void func_ov020_0218c840(struct DispatchState_0218c840* obj) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();

    if (obj->f4 == 0) {
        obj->byte23f = 1;
        obj->byte240 = 1;
        ResetBytesAndSetByte0x16((struct ResetBytesAndSetByte0x16Data*)((char*)obj + 0x10), 1);
        SetupGlobalObjType1AndInitSelfPointer((unsigned char*)obj + 0xc);
    }

    SetupAndDispatch0205c904((unsigned char*)obj + 0xc, 1);

    struct Container0205a330* container = *(struct Container0205a330**)(g + REGION(0x230, 0x2e0));
    if (container != 0) {
        IterateEntries0205a330(container, 1);
    }

    if (_Z35CheckGlobalObjState2AndInit0205cde8Ph((unsigned char*)obj + 0xc) != 0) {
        if (obj->f4 > 5) {
            volatile unsigned int* ime = (volatile unsigned int*)0x4000000;
            *ime = (*ime & ~0x1f00) | 0x1300;
        }

        int hasFlag = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x401);
        int active = GetScaledSumIfActive0205cecc((unsigned char*)obj + 0xc) >= 0;
        if ((hasFlag | active) != 0) {
            int idx = CallFunc0205c570AtField0x1c((unsigned char*)obj + 0xc);
            if (GetByte0x4((char*)battleStruct) == 6) return;

            if (CheckSaveBufferStatus(1) == 4) {
                SetByte0x4((char*)battleStruct, (unsigned char)data_ov020_0218d990[idx]);
                obj->f0 = -1;
                obj->f4 = -1;
                return;
            } else {
                SetByte0x4((char*)battleStruct, (unsigned char)data_ov020_0218d974[idx]);
                obj->f0 = -1;
                obj->f4 = -1;
                return;
            }
        }
    }

    func_0205c96c((unsigned char*)obj + 0xc, 0);
}
