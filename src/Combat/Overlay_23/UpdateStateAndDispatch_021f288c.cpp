#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void func_02046380(void);
int GetGlobalField0x1c020421a0(void);
extern "C" void* func_0205ec34(void);
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
extern "C" int func_ov023_021f4438(void* obj);
extern "C" int func_ov023_021f4fc8(void);
int CheckThresholdOverAny_021f5228(int id);
int TestBitInByteArray(int unused, unsigned char* arr, int index);

struct ArrayContainsByteStruct;
int ArrayContainsByte(struct ArrayContainsByteStruct* s, int val);

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);

struct Reset_021eefac;
void ResetFields_021eefac(struct Reset_021eefac* s);

struct GlobalStateOv023_021ffefc {
    int counter;
    char pad1[0x12 - 4];
    unsigned char flagArr[4];
    char pad2[0x18 - 0x16];
    int id;
};
extern "C" struct GlobalStateOv023_021ffefc* _ZZ17GetGlobal021ffefcvE1s;

struct PctBits021f288c { unsigned short low : 7; unsigned short pct : 9; };

#if defined(jpn)
extern "C" void func_02045d88(void*,char*,int);
#endif
// JPN: func_ov023_021f20a0
// USA: func_ov023_021f288c  (semantic: UpdateStateAndDispatch_021f288c)
extern "C" ARM int func_ov023_021f288c(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x5af4, regionalOffset1=0x17e2, regionalOffset2=0x868, regionalOffset3=0x17fb, regionalOffset4=0x17de, regionalOffset5=0x17df, regionalOffset6=0x5958, regionalOffset7=0xe28};
#else
 enum {regionalOffset0=0x5904, regionalOffset1=0x19b2, regionalOffset2=0x998, regionalOffset3=0x19ca, regionalOffset4=0x19ae, regionalOffset5=0x19af, regionalOffset6=0x5768, regionalOffset7=0xeac};
#endif
    char msgBuf[0x100];
    GameState* battleStruct = GameState::GetInstance();
    struct GlobalStateOv023_021ffefc* g = _ZZ17GetGlobal021ffefcvE1s;
    int id = g->id;
    int state = GetGlobalField0x1c020421a0();
    unsigned char* stateObj = (unsigned char*)state;
#if defined(jpn)

#else
    func_02046380();
#endif

    int flag8;
    if (g->counter == 0) {
        char* e1 = (char*)FindEntryByKey((struct TableA68*)(obj + regionalOffset0), 0xd);
#if defined(jpn)
        sprintf(msgBuf, e1, ((struct PctBits021f288c*)(obj + id * 0x54 + 0x5900 + 0x8c))->pct);
#else
        sprintf(msgBuf, e1);
#endif

        char* e2 = (char*)FindEntryByKey((struct TableA68*)(obj + regionalOffset0), 0x22);
        strcat(msgBuf, e2);
#if defined(jpn)

#else
        struct PctBits021f288c* pb = (struct PctBits021f288c*)(obj + id * 0x54 + 0x5700 + 0x9c);
        int percent = pb->pct;
        StoreInArray0x8b0((struct StoreStruct*)stateObj, 0, percent);
#endif

#if defined(jpn)
        func_02045d88(stateObj, msgBuf, 1);
#else
        func_0204500c(stateObj, msgBuf, 1, 0xe3);
#endif

        stateObj[regionalOffset1] = 0;
        *(int*)(stateObj + regionalOffset2) = 1;
        g->counter = g->counter + 1;
    } else if (g->counter == 1) {
        void* p2a04 = GetPtrField0x2a04(battleStruct);
        flag8 = 0;
        if (ArrayContainsByte((struct ArrayContainsByteStruct*)p2a04, id)) {
            if (CheckThresholdOverAny_021f5228(id)) {
                flag8 = 1;
                void* base = func_0205ec34();
                if (TestBitInByteArray((int)base, (unsigned char*)base + 0x8c, 0x119c)) {
                    stateObj[regionalOffset3] = 0;
                }
            }
        }
        int found = 0;
        int i;
        for (i = g->id + 1; i < 4; i++) {
            if (g->flagArr[i] != 0) {
                found = 1;
                break;
            }
        }
        int fieldCheck = func_ov023_021f4438(obj);
        if (found == 0 && fieldCheck == 0 && *(int*)(obj + regionalOffset6) == 0) {
            stateObj[regionalOffset4] = 0;
            stateObj[regionalOffset3] = 0;
            stateObj[regionalOffset5] = 0;
        }
        if (func_ov023_021f4fc8()) {
            ResetFields_021eefac((struct Reset_021eefac*)g);
            return flag8 ? 8 : 7;
        }
    }
    return *(int*)(obj + regionalOffset7);
}
