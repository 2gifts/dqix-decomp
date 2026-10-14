#include <globaldefs.h>

void StoreValueWithInterruptsDisabled020cdac4(int value);
void ResetBattlerState0201289c(unsigned char* obj);
extern "C" void func_020cdae4(int a, int b, int c, int d);
void WaitWhileFlagsSet_020ce0fc(int mask);
int GetMaskedStatus_020ce114(int mask);
void ClearByte0x62IfArg0x10_02012bbc(int arg);

// USA: func_02012938  (semantic: ResetAndSyncBattlerFields02012938)
extern "C" ARM void func_02012938(unsigned char* obj) {
    StoreValueWithInterruptsDisabled020cdac4((int)ClearByte0x62IfArg0x10_02012bbc);
    obj[0x62] = 1;
    ResetBattlerState0201289c(obj);
    func_020cdae4(0, 1, (int)obj, 4);
    WaitWhileFlagsSet_020ce0fc(2);
    GetMaskedStatus_020ce114(2);
    obj[0x60] = 0;
    obj[0x5f] = obj[0x63];
    *(int*)(obj + 0x40) = *(int*)(obj + 0x64);
    int t1 = *(int*)(obj + 0x68);
    if (t1 >= 0) *(int*)(obj + 0x30) = t1;
    int t2 = *(int*)(obj + 0x6c);
    if (t2 >= 0) *(int*)(obj + 0x34) = t2;
}
