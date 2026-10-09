#include <globaldefs.h>
#include "System/Matrix.h"

struct DirectionEntry { unsigned char animation_, mirrored_; };
struct DirectionObject {
    char pad0[0x50]; int flags_, rotation_, field58_, motionFlags_, angle_;
    char pad64[0x90 - 0x64]; int angleOffset_;
    unsigned char field94_, fourDirections_;
};
struct Obj0203f1e4;
int GetField0x70(void*);
extern "C" void _Z24SelectNamedEntry0203f1e4P11Obj0203f1e4PKc(Obj0203f1e4*, const char*);
extern DirectionEntry data_020e7920[4], data_020e7918[4], data_020e7938[8], data_020e7928[8];
extern const char* data_020efd00[];
static inline DirectionEntry* DirectionAt(DirectionEntry* table, int index) { return &table[index]; }
static inline DirectionEntry* RotatedDirection(DirectionEntry* table, int index, DirectionObject* self, int rotation) {
    self->rotation_ = rotation;
    return &table[index];
}

// USA: func_0203cbd8
extern "C" ARM void func_0203cbd8(DirectionObject* self, void* other) {
    int angle = self->angle_ - GetField0x70(other);
    int offset = self->flags_ & 8;
    if (offset) angle += self->angleOffset_;
    while (angle < 0) angle += 0x6488;
    while (angle >= 0x6488) angle -= 0x6488;
    DirectionEntry* entry;
    if (self->fourDirections_) {
        entry = DirectionAt(data_020e7920, (fix32_Divide((angle + 0x6488) * 4 + 0x3244, 0x6488) >> 12) & 3);
    } else if (!offset) {
        if ((self->motionFlags_ & 1) || (self->motionFlags_ & 8)) {
            entry = DirectionAt(data_020e7918, (fix32_Divide((angle + 0x6488) * 4 + 0x3244, 0x6488) >> 12) & 3);
        } else {
            entry = DirectionAt(data_020e7938, (fix32_Divide((angle + 0x6488) * 8 + 0x3244, 0x6488) >> 12) & 7);
        }
    } else {
        entry = RotatedDirection(data_020e7928, (fix32_Divide((angle + 0x6488) * 8 + 0x3244, 0x6488) >> 12) & 7, self, -angle);
    }
    if (!entry) return;
    if (entry->mirrored_) self->flags_ |= 2;
    else self->flags_ &= ~2;
    _Z24SelectNamedEntry0203f1e4P11Obj0203f1e4PKc((Obj0203f1e4*)self, data_020efd00[entry->animation_]);
}
