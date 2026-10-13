#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct Obj02046e08 {
    int field0_;
    int field4_;
    int field8_;
    float fieldC_;
    int field10_;
    int field14_;
    int field18_;
    unsigned char field1c_;
    unsigned char field1d_;
    int field20_;
    SafeAllocator allocator_;
    int field38_;
    Object3D object_;
    int fieldE8_;
    int fieldEC_;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02046e08
ARM void InitBattleContext02046e08(Obj02046e08* obj) {
    obj->field0_ = 0;
    obj->field4_ = 0;
    obj->field20_ = 0;
    obj->field8_ = 0;
    obj->fieldC_ = 15.0f;
    obj->fieldEC_ = -1;
    obj->field1c_ = 1;
    obj->field1d_ = 1;
    obj->object_.Initialize();
    obj->allocator_.ResetAllocatorPointer();
    obj->field38_ = 0;
    obj->fieldE8_ = 0;
    obj->field10_ = 0;
    obj->field14_ = 0;
    obj->field18_ = 0;
}
