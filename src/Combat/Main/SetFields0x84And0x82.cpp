#include <globaldefs.h>
#include "World/ZoneFeatures.h"

struct SetFieldsStruct {
    char unk0[0x80];
    unsigned short field80;
    unsigned short field82;
    int field84;
};

// USA: func_0201e878
ARM void ZoneFeatures::SetOpcode7bAllocation_0201e878(ZoneFeatures::Opcode7bEntry* arg0, unsigned short arg1) {
    struct SetFieldsStruct* p = (struct SetFieldsStruct*)this;
    int value = (int)arg0;
    short id = (short)arg1;
    p->field84 = value;
    p->field82 = id;
    p->field80 = 0;
}
