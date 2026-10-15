#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);

struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);

int GetFieldAt0x150_02053c6c(unsigned char* obj);

extern "C" void __clear(void* buf, int len);

int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);

struct Obj53dfc;
int GetField8FromField19c_02053dfc(struct Obj53dfc* obj);

unsigned short GetTableValue_0202053c(void* obj);

int CheckField0NonZero_0202b7d8(int* obj);

struct SearchStruct;
int TestBitBySignedByteIndex_0202c1c0(struct SearchStruct* obj, int value);

int GetShiftedOrDefault_021f5578(void* a, void* b, int def);

int AnySlotHasBit16At0x2f4_0208538c(unsigned char* obj);

struct DataOv023_021ffefc { void* field0; int field4; };
extern "C" struct DataOv023_021ffefc _ZZ17GetGlobal021ffefcvE1s;

// USA: func_ov023_021f4098  (semantic: ComputeCombatantScaleFactor_021f4098)
extern "C" ARM int func_ov023_021f4098(void* obj, int id, int flag) {
#if defined(jpn)
 enum {regionalOffset0=0xab0, regionalOffset1=0x5a00, regionalOffset2=0xbc, regionalOffset3=0x21c, regionalOffset4=0x144};
#else
 enum {regionalOffset0=0x8c0, regionalOffset1=0x5800, regionalOffset2=0xcc, regionalOffset3=0x2a0, regionalOffset4=0x150};
#endif
    GameState* battleStruct = GameState::GetInstance();
    struct SearchStruct* p = (struct SearchStruct*)func_0202ae18();
    GameObject* c9 = GetCombatantWithFlag0x100_0200ff1c(battleStruct, id);
    if (c9 == 0 || CheckField0x56bLowNibble((struct Obj02061bd8*)c9) != 0) {
        return 0;
    }
    if (GetFieldAt0x150_02053c6c((unsigned char*)c9) == 0) {
        return 0;
    }

    float flagF = (float)(unsigned int)*(unsigned int*)((char*)obj + 0x5000 + regionalOffset0);
    float unusedB = (float)(unsigned short)*(unsigned short*)((char*)obj + regionalOffset1 + regionalOffset2);
    float arrB[4];
    float arrC[4];
    __clear(arrB, 0x10);
    __clear(arrC, 0x10);

    int i;
    for (i = 0; i < 4; i++) {
        if (TestBitAt0x34_020a35e0(*(unsigned char**)((char*)obj + regionalOffset3), i)) {
            GameObject* ci = GetCombatantWithFlag0x100_0200ff1c(battleStruct, i);
            if (ci != 0 && CheckField0x56bLowNibble((struct Obj02061bd8*)ci) == 0) {
                arrC[i] = (float)(unsigned int)GetField8FromField19c_02053dfc((struct Obj53dfc*)ci);
                arrB[i] = (float)(unsigned int)GetTableValue_0202053c(ci);
            }
        }
    }

    float countF = 1.0f;
    if (CheckField0NonZero_0202b7d8((int*)p)) {
        countF = 0.0f;
        for (i = 0; i < 4; i++) {
            if (TestBitAt0x34_020a35e0(*(unsigned char**)((char*)obj + regionalOffset3), i) && TestBitBySignedByteIndex_0202c1c0(p, i)) {
                countF += 1.0f;
            }
        }
    }

    if (flag != 0) {
        flagF = (float)(unsigned int)flag;
    }

    float scaledFlag = flagF * (1.0f + (countF - 1.0f) / 10.0f);
    int intScaled = (int)scaledFlag;
    int shiftVal = GetShiftedOrDefault_021f5578((char*)_ZZ17GetGlobal021ffefcvE1s.field0 + 0xf4, (void*)intScaled, 4);

    float term1 = arrC[3] * (arrB[3] + (float)shiftVal);
    float temp2 = arrC[2] * (arrB[2] + (float)shiftVal);
    float temp3 = arrC[0] * (arrB[0] + (float)shiftVal);
    float temp4 = arrC[1] * (arrB[1] + (float)shiftVal);
    float total = term1 + ((temp3 + temp4) + temp2);

    if (total == 0.0f) {
        total = 1.0f;
    }

    float scaledFlag2 = flagF * (1.0f + (countF - 1.0f) / 10.0f);
    float normalized = ((float)shiftVal + arrB[id]) * arrC[id] / total;
    float result = scaledFlag2 * normalized;

    if (AnySlotHasBit16At0x2f4_0208538c(*(unsigned char**)((char*)c9 + regionalOffset4))) {
        result *= 1.05f;
    }

    int truncated = (int)result;
    float fracCheck = result - (float)truncated;
    if (0.0f < fracCheck) {
        result += 1.0f;
    }

    if (flag == 0) {
        for (flag = 0; flag < 4; flag++) {
            if (TestBitAt0x34_020a35e0(*(unsigned char**)((char*)obj + regionalOffset3), flag)) {
                GetCombatantWithFlag0x100_0200ff1c(battleStruct, flag);
            }
        }
    }

    return (int)result;
}
