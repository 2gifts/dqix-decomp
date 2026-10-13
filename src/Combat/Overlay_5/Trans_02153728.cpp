#include <globaldefs.h>
#include <Graphics/Vector.h>

extern "C" void func_ov005_021538fc(void* self, fix32_t* target, fix32_t* value, fix32_t rate, fix32_t threshold);

struct Trans_02153728 {
    char pad[0x18];
    fix32_t target[4];
    fix32_t value[4];
};

// USA: func_ov005_02153728  (semantic: Trans_02153728)
extern "C" ARM void func_ov005_02153728(Trans_02153728* self, int speed) {
    if (speed == 0) { speed = 1; }
    fix32_t rate = speed * 0xb33;
    fix32_t threshold = speed * 0xccc;
    func_ov005_021538fc(self, &self->target[0], &self->value[0], rate, threshold);
    func_ov005_021538fc(self, &self->target[1], &self->value[1], rate, threshold);
    func_ov005_021538fc(self, &self->target[2], &self->value[2], rate, threshold);
    func_ov005_021538fc(self, &self->target[3], &self->value[3], rate, threshold);
}
