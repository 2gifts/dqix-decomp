#include <globaldefs.h>

struct Foo0207df50;

extern "C" void func_0207de48(void* state, int a, int b);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(struct Foo0207df50* p);

struct VRAMManagerState {
    char unk_0[0x70];
};

struct EquipmentMenu {
    char unk_0[0x294];
    VRAMManagerState vramState_;
    VRAMManagerState slotVramStates_[24];
    VRAMManagerState dragVramState_;
};

// USA: func_ov005_02153b20
extern "C" ARM void func_ov005_02153b20(EquipmentMenu* self) {
    for (int i = 0; i < 24; i++) {
        func_0207de48(&self->slotVramStates_[i], 0x120, 0x20);
        _Z26CopyInternalFields0207df50P11Foo0207df50((struct Foo0207df50*)&self->slotVramStates_[i]);
    }
    func_0207de48(&self->dragVramState_, 0x120, 0x20);
    _Z26CopyInternalFields0207df50P11Foo0207df50((struct Foo0207df50*)&self->dragVramState_);
    func_0207de48(&self->vramState_, 0x3000, 0x400);
    _Z26CopyInternalFields0207df50P11Foo0207df50((struct Foo0207df50*)&self->vramState_);
}
