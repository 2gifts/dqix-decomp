#include <globaldefs.h>

#include "Combat/WorkRecord.h"
#include "Combat/NodeLookup.h"

#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"



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
    ClearWorkRecord0206bf2c(rec);
    rec->field2 = (unsigned short)id;
    rec->field0 = (unsigned char)params[1].ToInt();
    if (count < 3) {
        UnlinkNodeByByteId0206dd68(data_02108cec.field0x10, rec->field0);
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
