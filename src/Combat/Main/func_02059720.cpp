#include <globaldefs.h>
#include <GameState/GameState.h>

struct S02055080;
struct PointerField32c_ffc0;
struct PointerField330_ffd0;
struct State02059a2c;
struct AnimationSource02059720 { char pad_0[3]; unsigned char complete; };
struct Follow02059720 { char pad_0[0x130]; unsigned int flags; };
struct Animation02059720 {
    int field_0, time, duration;
    unsigned char disabled;
    char pad_d[3];
    int x, y, z;
    char pad_1c[0xc];
    S02055080* sequence;
    unsigned char active, followFirst, followSecond, field_2f;
    float timeScale, redRate, greenRate, blueRate, alphaRate, xRate, yRate, angleRate;
    char pad_50[0x2c];
    Object3D object;
    char pad_128[4];
    float red, green, blue, alpha, offsetX, offsetY, angle;
};
int CheckByte0xcZeroAndField8LeField4(State02059a2c*);
void* GetSubField0x14_02055108(S02055080*);
void* GetPointerAt0x32c_0200ffc0(PointerField32c_ffc0*);
void* GetPointerAt0x330_0200ffd0(PointerField330_ffd0*);
extern "C" void func_02058750(Animation02059720*);
extern "C" void func_020589b8(Animation02059720*);
extern "C" void func_02058b3c(Animation02059720*);

// USA: func_02059720
extern "C" ARM void func_02059720(Animation02059720* self) {
    if (!self->active) return;
    if (CheckByte0xcZeroAndField8LeField4((State02059a2c*)self)) return;
    if (self->object.HasAnimationStopped()) {
        AnimationSource02059720* source = (AnimationSource02059720*)GetSubField0x14_02055108(self->sequence);
        if (source->complete) {
            self->disabled = 0;
            self->active = 0;
            return;
        }
    }
    GameState* game = GameState::GetInstance();
    int elapsed = game->GetTickCount();
    self->time += elapsed;
    if (CheckByte0xcZeroAndField8LeField4((State02059a2c*)self)) {
        self->active = 0;
        return;
    }
    self->red += self->redRate * (float)elapsed;
    self->green += self->greenRate * (float)elapsed;
    self->blue += self->blueRate * (float)elapsed;
    self->alpha += self->alphaRate * (float)elapsed;
    if (self->red < 0.0f) self->red = 0.0f;
    if (self->green < 0.0f) self->green = 0.0f;
    if (self->blue < 0.0f) self->blue = 0.0f;
    if (self->alpha < 0.0f) self->alpha = 0.0f;
    if (self->red > 31.0f) self->red = 31.0f;
    if (self->green > 31.0f) self->green = 31.0f;
    if (self->blue > 31.0f) self->blue = 31.0f;
    if (self->alpha > 31.0f) self->alpha = 31.0f;
    self->offsetX += self->xRate * (float)elapsed;
    self->offsetY += self->yRate * (float)elapsed;
    self->angle += self->angleRate * (float)elapsed;
    if (self->angle < 0.0f) self->angle = 360.0f;
    if (self->angle > 360.0f) self->angle = 0.0f;
    func_02058750(self);
    func_020589b8(self);
    func_02058b3c(self);
    unsigned int flags = 0;
    if (self->followFirst) {
        Follow02059720* follow = (Follow02059720*)GetPointerAt0x32c_0200ffc0((PointerField32c_ffc0*)game);
        if (follow) flags = follow->flags;
    } else if (self->followSecond) {
        Follow02059720* follow = (Follow02059720*)GetPointerAt0x330_0200ffd0((PointerField330_ffd0*)game);
        if (follow) flags = follow->flags;
    }
    if (self->followFirst || self->followSecond) {
        if (flags & 1) self->x -= 0x120000;
        else if (flags & 2) self->x += 0x120000;
        if (flags & 4) self->z -= 0xe0000;
        else if (flags & 8) self->z += 0xe0000;
    }
    self->object.AdvanceEffects();
}
