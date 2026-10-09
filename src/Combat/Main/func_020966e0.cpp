#include <globaldefs.h>
struct Touch020966e0 { char pad[0x220]; unsigned char startX, startY, x, y, active, held, enabled; char pad2[9]; unsigned char suspended; };
struct Input020966e0 { char pad[0x24]; unsigned short value; char pad2[0x1a]; int duration; char pad3[0x1b]; unsigned char pressed, blocked, pad4, disabled; };
extern Input020966e0 data_02114e54;
extern "C" void func_02012538(Input020966e0*);
void SelectCoordsByFlag0x24(unsigned char*, int*, int*);
int AreCoordsOutOfBounds(unsigned char*);
extern "C" void func_02096a20(Touch020966e0*);
// USA: func_020966e0
extern "C" ARM void func_020966e0(Touch020966e0* self) {
    if (data_02114e54.blocked) { self->suspended = 1; return; }
    if (self->suspended) { self->suspended = 0; func_02012538(&data_02114e54); }
    if (data_02114e54.disabled) return;
    int x, y;
    SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &x, &y);
    int pressed = data_02114e54.pressed && data_02114e54.value;
    int duration = data_02114e54.duration;
    if (!pressed) self->enabled = 1;
    if (!self->enabled) return;
    if (self->active) {
        self->x = x; self->y = y; func_02096a20(self);
        if (!pressed) self->active = 0;
    } else if (pressed && !AreCoordsOutOfBounds((unsigned char*)&data_02114e54)) {
        self->x = x; self->startX = self->x;
        self->y = y; self->startY = self->y;
        self->active = 1;
    }
    if (self->held) { if (!pressed) self->held = 0; }
    else if (pressed && duration>= 5) self->held = 1;
}
