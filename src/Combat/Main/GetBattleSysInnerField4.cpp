#include <globaldefs.h>

struct BattleSysInner020d06d4 {
    int field0;
    int field4;
    char pad8[0x14];
    int field1c;
};

extern BattleSysInner020d06d4* data_021118e0;

// USA: func_020d06d4
ARM int GetBattleSysInnerField4_020d06d4() {
    return data_021118e0->field4;
}
