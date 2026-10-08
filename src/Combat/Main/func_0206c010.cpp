#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Rec0206bf2c {
    unsigned char field0;
    unsigned char pad1;
    unsigned short field2;
    unsigned char field4;
    unsigned char field5;
    unsigned char pad6;
    unsigned char field7;
    unsigned char field8;
    unsigned char pad9;
    unsigned char flagsA_b0 : 2;
    unsigned char flagsA_b1 : 1;
    unsigned char flagsA_b2 : 3;
    unsigned char flagsA_b3 : 1;
    unsigned char flagsA_b4 : 1;
    unsigned char fieldB;
    unsigned int fieldC;
    unsigned char pad10[0xc];
    unsigned short field1c;
    unsigned char field1e;
    unsigned char field1f;
    unsigned short field20;
    unsigned char pad22[2];
    unsigned char pad24[0x10];
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned short field44;
    unsigned short field46;
    unsigned char pad48[0xc];
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
};

extern "C" void _Z23ClearWorkRecord0206bf2cP11Rec0206bf2c(struct Rec0206bf2c* obj);
extern "C" void _Z26UnlinkNodeByByteId0206dd68Pvi(void* base, int key);
extern "C" void func_0206db48(void* base, struct Rec0206bf2c* rec);

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned short field0xc;
    void* field0x10;
    void* field0x14;
};
extern struct Data02108cec data_02108cec;

// USA: func_0206c010  (semantic: SpawnScriptEntityRecord0206c010)
extern "C" ARM int func_0206c010(Script::Parameter* params, int count) {
    struct Rec0206bf2c* rec;
    Script::Parameter* p;
    int id;

    data_02108cec.field0xa = data_02108cec.field0xa + 1;
    id = params[0].ToInt();
    if (id != data_02108cec.field0xc) {
        return 1;
    }
    rec = (struct Rec0206bf2c*)((SafeAllocator*)data_02108cec.field0x14)->Allocate(0x78);
    if (rec == 0) {
        return 0;
    }
    _Z23ClearWorkRecord0206bf2cP11Rec0206bf2c(rec);
    rec->field2 = (unsigned short)id;
    rec->field0 = (unsigned char)params[1].ToInt();
    if (count < 3) {
        _Z26UnlinkNodeByByteId0206dd68Pvi(data_02108cec.field0x10, rec->field0);
        return 1;
    }
    p = params[2].ToVec3fix((Vector3fix*)rec->pad10);
    rec->field1c = (unsigned short)(int)(4096.0f * p->ToFloat());
    if (count > 6) {
        rec->field1e = (unsigned char)p[1].ToInt();
    }
    rec->field44 = data_02108cec.field0xa;
    func_0206db48(data_02108cec.field0x10, rec);
    return 1;
}
