#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetActiveCombatWork(void);

struct Reset021e3158 { int a; int b; int c; int d; int e; int f; };
void ResetStruct_021e3158(struct Reset021e3158* p);

extern int data_ov025_021ef988;
extern struct Reset021e3158 data_ov025_021ef9a8;

struct S021e30e8 { char pad[8]; unsigned int field8; unsigned char field0xc; };

// JPN: func_ov025_021e35d8
// USA: func_ov025_021e30e8  (semantic: CheckThresholdAndReset_021e30e8)
extern "C" ARM int func_ov025_021e30e8(struct S021e30e8* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x71c0};
#else
 enum {regionalOffset0=0x6fd0};
#endif
    GameState* battle = GameState::GetInstance();
    if (obj->field8 <= *(unsigned int*)((char*)&data_ov025_021ef988 + 0x34)) {
        if (obj->field0xc != 0) {
            void* work = GetActiveCombatWork();
            *(int*)((char*)work + regionalOffset0) = obj->field8;
        }
        ResetStruct_021e3158(&data_ov025_021ef9a8);
        return 1;
    }
    int* p = &data_ov025_021ef988 + 13;
    *p += battle->GetEffectiveDeltaTime();
    return 0;
}
