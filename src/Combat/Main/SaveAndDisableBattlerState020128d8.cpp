#include <globaldefs.h>

extern "C" void func_020cdbe4(void);
void WaitWhileFlagsSet_020ce0fc(int mask);
int GetMaskedStatus_020ce114(int mask);
void StoreValueWithInterruptsDisabled020cdac4(int value);
void ResetBattlerState0201289c(unsigned char* obj);

struct Obj020128d8 {
    unsigned char pad0[0x30];
    int field30;
    int field34;
    unsigned char pad38[0x40 - 0x38];
    int field40;
    unsigned char pad44[0x5f - 0x44];
    unsigned char field5f;
    unsigned char field60;
    unsigned char pad61[0x63 - 0x61];
    unsigned char field63;
    int field64;
    int field68;
    int field6c;
};

// USA: func_020128d8
ARM void SaveAndDisableBattlerState020128d8(struct Obj020128d8* obj) {
    obj->field63 = obj->field5f;
    obj->field64 = obj->field40;
    if (obj->field30 >= 0) {
        obj->field68 = obj->field30;
    }
    if (obj->field34 >= 0) {
        obj->field6c = obj->field34;
    }
    func_020cdbe4();
    WaitWhileFlagsSet_020ce0fc(4);
    GetMaskedStatus_020ce114(4);
    StoreValueWithInterruptsDisabled020cdac4(0);
    ResetBattlerState0201289c((unsigned char*)obj);
    obj->field60 = 1;
}
