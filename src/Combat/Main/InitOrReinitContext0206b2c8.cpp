#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_0206ac94(void* obj);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(void* self);
extern "C" void func_0206b104(void* obj);
extern "C" void func_0206aa28(void* p);
extern "C" void func_0206b974(void* p, int a1, void* a2, void* a3, void* a4, int a5, int a6, int a7);
int StringLength_020d2ff0(const char* s);

struct Ctx0206b2c8 {
    char pad0[0x4c];
    void* field4c;
    void* field50;
    void* field54;
    void* field58;
    char pad5c[4];
    void* field60;
    char pad64[0x93c];
    int field9a0;
};

// USA: func_0206b2c8
ARM void InitOrReinitContext0206b2c8(Ctx0206b2c8* obj, int, void*) {
    void* r = func_0206ac94(obj);
    if (r == NULL) {
        ReinitController02043204((char*)obj);
        func_02043124(obj);
        return;
    }

    func_0206b104(obj);
    memset(obj->field4c, 0, 0x280);
    memset(obj->field50, 0, 0x280);
    obj->field58 = r;
    obj->field54 = r;
    obj->field9a0 = 5;
    func_0206aa28(obj);
    func_0206b974(obj, 1, obj->field50, obj->field60, (void*)0xe3, 0, 1, 1);
    int len = StringLength_020d2ff0((const char*)obj->field60);
    memcpy(obj->field50, obj->field60, len);
}
