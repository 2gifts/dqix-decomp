#include <globaldefs.h>

struct BattleSysInner020d06e8 {
    int field0;
    int field4;
    char pad8[0x14];
    int field1c;
};

extern BattleSysInner020d06e8* data_021118e0;

// USA: func_020d06e8
ARM int GetBattleSysInnerField1c_020d06e8() {
    return data_021118e0->field1c;
}
