#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/TextQueue.h"

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern int data_02108760;
extern "C" void func_ov017_0218d644(GameResources* ov, void* a, int b);
void* GetGlobalResetObj020d7a50(void);
extern "C" void func_ov017_021b6090(void* self);
void SetByteField0x253(void* obj);
extern "C" void func_ov017_021b5a30(void* self);

struct SelfState_021b5f00 {
    unsigned char pad0[0x1];
    unsigned char field1;
    unsigned char pad1[0x1a];
    void* field1c;
    unsigned char pad2[0x1c];
    short* field3c;
    unsigned char pad3[0x14];
    unsigned char field54;
};

// USA: func_ov017_021b5f00  (semantic: CheckStateAndDispatchResetOrAdvance_021b5f00)
extern "C" ARM int func_ov017_021b5f00(SelfState_021b5f00* self) {
    GameResources* ov = func_ov017_0218b5b0();
    if (self->field54 != 0) {
        func_ov017_0218d644(ov, (char*)self + 0x2c, 0);
        void* reset = GetGlobalResetObj020d7a50();
#if defined(jpn)
        func_020d7e10(reset, self->field3c, 0, 0, 1);
#else
        func_020d7e10(reset, self->field3c, 0, 0, 1, 0);
#endif
        return 5;
    }
    func_ov017_021b6090(self);
    SetByteField0x253(self->field1c);
    if (*self->field3c != 0) {
        void* reset = GetGlobalResetObj020d7a50();
#if defined(jpn)
        func_020d7e10(reset, self->field3c, 0, 0, 1);
#else
        func_020d7e10(reset, self->field3c, 0, 0, 1, 0);
#endif
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0xe, 0);
        return 5;
    }
    func_ov017_021b5a30(self);
    self->field1 = 1;
    return 6;
}
