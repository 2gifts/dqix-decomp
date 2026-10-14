#include <globaldefs.h>
int EnterCombatMode020cf08c(int, int, int);

extern char data_02111818;
extern "C" void func_020cf864(void);
void StoreValueAt0x2c_020cf854(int val);

// USA: func_020cf0fc
ARM int RegisterSlotA020cf0fc(int a) {
    int result = EnterCombatMode020cf08c((int)(a), (int)(StoreValueAt0x2c_020cf854), (int)(0));
    *(int*)(&data_02111818 + 0x2c) = result;
    if (result == 0) {
        func_020cf864();
    }
    return *(int*)(&data_02111818 + 0x2c);
}
