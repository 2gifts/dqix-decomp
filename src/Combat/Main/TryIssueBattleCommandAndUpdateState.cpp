#include <globaldefs.h>

int ClearBattleSubEffectAt0x800_020d5f88(void* p);
void SetField0x48UnlessState9Or10_0202c848(int arg);
int IssueBattleCommandSlot1_020d5004(int arg);
void SetState9DispatchOrInvokeCallback_0202d614(unsigned short* obj);

extern char data_021015a0;
extern char data_02102be0;

// USA: func_0202dd28
ARM void TryIssueBattleCommandAndUpdateState_0202dd28(void) {
    if (*(int*)(&data_021015a0 + 0x10) == 5) {
        int r = ClearBattleSubEffectAt0x800_020d5f88(&data_02102be0);
        if (r) {
            SetField0x48UnlessState9Or10_0202c848(r);
        }
    }

    *(int*)(&data_021015a0 + 0x10) = 3;
    int result = IssueBattleCommandSlot1_020d5004((int)SetState9DispatchOrInvokeCallback_0202d614);
    if (result == 2) {
        result = 1;
    } else {
        SetField0x48UnlessState9Or10_0202c848(result);
        result = 0;
    }

    if (result == 0) {
        *(int*)(&data_021015a0 + 0x10) = 10;
    }
}
