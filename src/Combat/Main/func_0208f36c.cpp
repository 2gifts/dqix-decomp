#include <globaldefs.h>

class Object3D {
public:
    void SetScale(int x, int y, int z);
    bool MaybeSetBCFGAnimation(int index, int flags);
};

struct Self0208f36c {
    char pad0[8];
    Object3D* obj_;
};

// USA: func_0208f36c
extern "C" ARM void func_0208f36c(Self0208f36c* self, Object3D* obj) {
    self->obj_ = obj;
    if (!self->obj_) return;
    self->obj_->SetScale(0x10a, 0x10a, 0x10a);
    self->obj_->MaybeSetBCFGAnimation(0, 0);
}
