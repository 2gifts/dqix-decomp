#include <globaldefs.h>
#include "World/Object3D.h"

struct Param02048850 {
    char pad0[0xc];
    short fieldC;
    short fieldE;
};

struct Obj02048850 {
    char pad0[0x144];
    struct Param02048850* field144;
};

// USA: func_02048850
ARM void SetupFieldsFromParam02048850(struct Obj02048850* obj, struct Param02048850* p) {
    obj->field144 = p;
    ((Object3D*)((struct IntField0x64_020377c4*)(obj)))->SetRadius((int)(p->fieldC << 2));
    ((Object3D*)((struct IntField0x68_020377b4*)(obj)))->SetHeight((int)(obj->field144->fieldE));
}
