#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0(void);
struct ArrayContainsByteStruct;
int ArrayContainsByte(struct ArrayContainsByteStruct* s, int val);
struct Holder0209a9dc;
struct Entry0209a9dc { unsigned short id; unsigned short pad; };
struct Entry0209a9dc* FindEntryById0209a9dc(struct Holder0209a9dc* h, int i);
void* GetData02108e10(void);
void* SearchBothTables02079e2c(char* p, int key);
struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
#if defined(jpn)
extern "C" void func_02045d88(void* obj, char* buffer, int a);
#else
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
#endif

int GetFieldAt0x150(unsigned char* obj);
int CheckThresholdOverAny_021f5228(int id);
extern "C" void* func_0205ec34(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
extern "C" int func_ov023_021f4438(void* obj);
extern "C" int func_ov023_021f4fc8(void);
struct Reset_021eefac;
void ResetFields_021eefac(struct Reset_021eefac* s);
extern "C" void func_ov017_021ccea4(int a, unsigned char* b, int c);

struct Entry1c021f2368 { unsigned char attempts[0x14]; };

struct GlobalState021f2368 {
    int counter;                     // 0x0
    char pad0[0x12 - 0x4];
    unsigned char flagArr[4];        // 0x12
    char pad1[0x18 - 0x16];
    int id;                          // 0x18
    struct Entry1c021f2368 arr1c[4]; // 0x1c
    unsigned char byteArr6c[4];      // 0x6c
    int field70;                     // 0x70
    char pad2[0xe5 - 0x74];
    signed char e5;                  // 0xe5
};

extern "C" struct GlobalState021f2368* _ZZ17GetGlobal021ffefcvE1s;

struct PctBits021f2368 { unsigned short low : 7; unsigned short pct : 9; };

// JPN: func_ov023_021f1c38
// USA: func_ov023_021f2368  (semantic: ProcessEntryMatchAndDispatch_021f2368)
extern "C" ARM int func_ov023_021f2368(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x5af4, regionalOffset1=0x17e2, regionalOffset2=0x868, regionalOffset3=0x5900, regionalOffset4=0x8c, regionalOffset5=0x17fb, regionalOffset6=0x5958, regionalOffset7=0x17de, regionalOffset8=0x17df, regionalOffset9=0xe28};
#else
 enum {regionalOffset0=0x5904, regionalOffset1=0x19b2, regionalOffset2=0x998, regionalOffset3=0x5700, regionalOffset4=0x9c, regionalOffset5=0x19ca, regionalOffset6=0x5768, regionalOffset7=0x19ae, regionalOffset8=0x19af, regionalOffset9=0xeac};
#endif
    GameState* battleStruct = GameState::GetInstance();
    struct GlobalState021f2368* g = _ZZ17GetGlobal021ffefcvE1s;
    int state = GetGlobalField0x1c020421a0();
    unsigned char* stateObj = (unsigned char*)state;
    (int)BackgroundLoader::GetInstance();
    int id = g->id;
    int contains = ArrayContainsByte((struct ArrayContainsByteStruct*)GetPtrField0x2a04(battleStruct), id);

    if (g->counter == 0) {
        struct Entry0209a9dc* e = FindEntryById0209a9dc((struct Holder0209a9dc*)((char*)g + 0xf0),
            g->arr1c[id].attempts[g->field70]);
        if (e != NULL) {
            short val = *(short*)((char*)e + 2);
            void* tbl = GetData02108e10();
            void* found = SearchBothTables02079e2c((char*)tbl, val);
            if (found != NULL) {
#if defined(jpn)
                GameObject* textCombatant;
                if ((textCombatant = GetCombatantWithFlag0x100(battleStruct, id)) != 0 && contains != 0) {
#else
                if (GetCombatantWithFlag0x100(battleStruct, id) != 0 && contains != 0) {
#endif

#if defined(jpn)
                    char* combatantName = *(char**)((char*)textCombatant + 0x134);
                    char msgBuf[0x100];
                    char* e1 = (char*)FindEntryByKey((struct TableA68*)(obj + regionalOffset0), 0xc);
                    sprintf(msgBuf, e1, combatantName, *(char**)found);
                    char* e2 = (char*)FindEntryByKey((struct TableA68*)(obj + regionalOffset0), 0x22);
                    strcat(msgBuf, e2);
                    func_02045d88(stateObj, msgBuf, 1);

#else
                    char buf1[0xc];
                    char msgBuf[0x80];
                    char* e1 = (char*)FindEntryByKey((struct TableA68*)(obj + regionalOffset0), 0xc);
                    sprintf(msgBuf, e1);
                    char* e2 = (char*)FindEntryByKey((struct TableA68*)(obj + regionalOffset0), 0x22);
                    strcat(msgBuf, e2);
                    InitObjFromCombatantId020e4bf4(buf1, id);
                    *(void**)(stateObj + 0x10) = buf1;
                    char* name = *(char**)found;
                    SetIndexedName02046574((struct Obj02046574*)stateObj, 1, name);
                    func_0204500c(stateObj, msgBuf, 1, 0xe3);

#endif
                    stateObj[regionalOffset1] = 0;
                    *(int*)(stateObj + regionalOffset2) = 1;
                }
            }
        }
        g->field70 = g->field70 + 1;
        if (g->byteArr6c[id] <= g->field70) {
            void* p2a04b = GetPtrField0x2a04(battleStruct);
            GameObject* combatant = GetCombatantWithFlag0x100(battleStruct, id);
            unsigned char* field150 = (unsigned char*)GetFieldAt0x150((unsigned char*)combatant);
            struct PctBits021f2368* pb = (struct PctBits021f2368*)(obj + id * 0x54 + regionalOffset3 + regionalOffset4);
            if (pb->pct != 0) {
                g->e5 = 0xc;
            } else if (ArrayContainsByte((struct ArrayContainsByteStruct*)p2a04b, id) &&
                       CheckThresholdOverAny_021f5228(id) != 0 &&
                       *(unsigned short*)(field150 + 0x564) != 0) {
                g->e5 = 8;
                void* base = func_0205ec34();
                if (TestBitInByteArray((int)base, (unsigned char*)base + 0x8c, 0x119c)) {
                    stateObj[regionalOffset5] = 0;
                }
            } else {
                g->e5 = 7;
                int found2 = 0;
                int i;
                for (i = g->id + 1; i < 4; i++) {
                    if (g->flagArr[i] != 0) {
                        found2 = 1;
                        break;
                    }
                }
                int fieldCheck = func_ov023_021f4438(obj);
                if (found2 == 0 && fieldCheck == 0 && *(int*)(obj + regionalOffset6) == 0) {
                    stateObj[regionalOffset7] = 0;
                    stateObj[regionalOffset5] = 0;
                    stateObj[regionalOffset8] = 0;
                }
            }
        } else {
            g->e5 = -1;
        }
        g->counter = g->counter + 1;
    } else if (g->counter == 1) {
        if (func_ov023_021f4fc8() != 0) {
            signed char e5 = g->e5;
            if (e5 >= 0) {
                ResetFields_021eefac((struct Reset_021eefac*)g);
                func_ov017_021ccea4(id, (unsigned char*)&g->arr1c[id], g->byteArr6c[id]);
                return e5;
            } else {
                g->counter = 0;
            }
        }
    }
    return *(int*)(obj + regionalOffset9);
}
