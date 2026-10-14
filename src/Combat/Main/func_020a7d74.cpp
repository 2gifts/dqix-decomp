#include <globaldefs.h>
#include "GameState/GameState.h"

int GetBit6At0xe0_02033f5c(unsigned char* p);
void* GetFieldPtrAt0x11c_02033fc4(void* obj);
int CheckBits5To9NonZero_0204be78(unsigned short* obj);
struct BitFlag02033f44;
void* GetField0xe4IfFlag0x40(BitFlag02033f44*);
int PackColorChannelsToDecimal_0204bea0(unsigned short* obj);
int GetBits10To14_0204be90(unsigned short* obj);

struct F02033f44 {
    char pad0[0x24];
    Vector3fix f24;
};

struct Obj020a7d74 {
    char pad0[0x50];
    Vector3fix f50;
    char pad5c[0x134 - 0x5c];
    int f134;
    int f138;
};

// USA: func_020a7d74
extern "C" ARM int func_020a7d74(struct Obj020a7d74* self, int* out1, int* out2) {
    GameState* gameState = GameState::GetInstance();
    int ok = 1;
    if (self->f134 == 0) {
        ok = 0;
    }
    if (GetBit6At0xe0_02033f5c((unsigned char*)self) == 0) {
        ok = 0;
    }
    unsigned short* p = (unsigned short*)GetFieldPtrAt0x11c_02033fc4(self);
    if (p == 0) {
        ok = 0;
    }
    if (CheckBits5To9NonZero_0204be78(p) == 0) {
        ok = 0;
    }
    if (ok == 0) {
        self->f138 = 0;
        return 0;
    }

    Vector3fix dir;
    Vector3fix t;
    Vector3fix src = self->f50;
    int angle = src.y;
    int cz = fix32cos(angle);
    dir.x = fix32sin(angle);
    dir.y = 0;
    dir.z = cz;
    Vector3fix_Normalize(&dir, &dir);

    struct F02033f44* f = (struct F02033f44*)GetField0xe4IfFlag0x40((BitFlag02033f44*)self);
    int tz = f->f24.z;
    int tx = f->f24.x;
    t.y = 0;
    t.x = tx;
    t.z = tz;
    Vector3fix_Normalize(&t, &t);

    int dot = Vector3fix_InnerProduct(&t, &dir);
    if (dot >= -0xc00) {
        self->f138 = 0;
    } else {
        self->f138 = self->f138 + (int)gameState->GetTickCount();
    }
    if (self->f138 < 0x28) {
        return 0;
    }
    *out1 = PackColorChannelsToDecimal_0204bea0(p);
    *out2 = GetBits10To14_0204be90(p);
    return 1;
}
