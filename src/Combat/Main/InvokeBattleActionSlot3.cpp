#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int, int, int, int, int);
void SetBattleContextArrayEntry_020d404c(int index, int value);
void* GetBattleContext_020d41d8(void);

struct BattleContextFields020d4e58 {
    int field0;
    int field4;
    char pad[0x10 - 0x8];
    int field10;
};

// USA: func_020d4e58
#pragma optimize_for_size off
ARM int InvokeBattleActionSlot3_020d4e58(int a, int b) {
    int result = func_020d424c(1, 0);
    if (result != 0) {
        return result;
    }
    SetBattleContextArrayEntry_020d404c(3, a);
    struct BattleContextFields020d4e58* ctx = (struct BattleContextFields020d4e58*)GetBattleContext_020d41d8();
    result = func_020d40bc(3, 4, ctx->field0, ctx->field4, ctx->field10, b);
    if (result == 0) {
        result = 2;
    }
    return result;
}
