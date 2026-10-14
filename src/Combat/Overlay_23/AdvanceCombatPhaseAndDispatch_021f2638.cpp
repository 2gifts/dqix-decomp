#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void func_02046380(void);
int GetGlobalField0x1c020421a0(void);
extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
unsigned char CopyOutRegion0x571d_020114ec(char* obj, void* dst);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned int index);
extern "C" int func_ov023_021f4438(void* obj);
struct TableA68;
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
int IsValueInRange0201b5d8(int x);
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
extern "C" int func_ov023_021f4fc8(void);
struct Reset_021eefac;
void ResetFields_021eefac(struct Reset_021eefac* s);

extern "C" int* _ZZ17GetGlobal021ffefcvE1s;

// USA: func_ov023_021f2638  (semantic: AdvanceCombatPhaseAndDispatch_021f2638)
extern "C" ARM int func_ov023_021f2638(unsigned char* obj) {
    GameState* battleStruct = GameState::GetInstance();
    int* g = _ZZ17GetGlobal021ffefcvE1s;
    int state = GetGlobalField0x1c020421a0();
    unsigned char* stateObj = (unsigned char*)state;
    func_02046380();
    func_0202ae18();
    void* search = func_02012fe4();
    int counter = *g;

    if (counter == 0) {
        if (*(int*)(obj + 0x5768) != 0) {
            char msgBuf[0x100];
            unsigned char idBuf[4];
            GameObject* combatant;
            int n = CopyOutRegion0x571d_020114ec((char*)battleStruct, idBuf);
            unsigned char flagged = 0;
            unsigned char total = 0;
            int i;
            for (i = 0; i < n; i++) {
                combatant = battleStruct->GetCombatantByIndex(idBuf[i]);
                if (combatant == NULL) continue;
                if (!TestBitAt0x34_020a35e0(*(unsigned char**)(obj + 0x2a0), idBuf[i])) continue;
                total = total + 1;
                void* p130 = *(void**)((char*)combatant + 0x130);
                if ((*(int*)p130 & 1) == 0) flagged = flagged + 1;
            }
            stateObj[0x30] = total;
            stateObj[0x31] = flagged;
            int fieldCheck = func_ov023_021f4438(obj);
            char* e1 = (char*)FindEntryByKey_02072a68((struct TableA68*)(obj + 0x5904), 0x10);
            sprintf(msgBuf, e1);
            StoreInArray0x8b0_020465c0((struct StoreStruct*)stateObj, 0, *(int*)(obj + 0x5768));
            int inRange = 0;
            if (*(unsigned char*)(obj + 0x5900) == 0 && *(int*)(obj + 0x6e24) != 0) {
                if (IsValueInRange0201b5d8(*(unsigned short*)search) != 0) inRange = 1;
            }
            if (fieldCheck != 0 && inRange == 0) {
                char* e2 = (char*)FindEntryByKey_02072a68((struct TableA68*)(obj + 0x5904), 0x22);
                strcat(msgBuf, e2);
            }
            func_0204500c(stateObj, msgBuf, 1, 0xe3);
            stateObj[0x19b2] = 0;
            *(int*)(stateObj + 0x998) = 1;
        } else {
            *g = 2;
            return *(int*)(obj + 0xeac);
        }
        *g = *g + 1;
    } else if (counter == 1) {
        if (func_ov023_021f4fc8() != 0 || *(int*)(stateObj + 0x998) == 0) {
            *g = *g + 1;
        }
    } else if (counter == 2) {
        ResetFields_021eefac((struct Reset_021eefac*)g);
        if (*(unsigned char*)(obj + 0x5900) != 0 || *(int*)(obj + 0x6e24) != 0) {
            int fieldCheck2 = func_ov023_021f4438(obj);
            if (fieldCheck2 != 0) return 0xd;
            *(int*)(obj + 0x6e24) = 0;
        }
        return 0xe;
    }
    return *(int*)(obj + 0xeac);
}
