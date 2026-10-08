#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(void* self);
extern "C" int _Z13GetBit6At0xe0Ph(unsigned char* p);
extern "C" void* _Z18GetFieldPtrAt0x11cPv(void* obj);
extern "C" int _Z20CheckBits5To9NonZeroPt(unsigned short* obj);
extern "C" short _Z8fix32cosi(int x);
extern "C" short _Z8fix32sini(int x);
extern "C" void* _Z22GetField0xe4IfFlag0x40P15BitFlag02033f44(void* p);
extern "C" void Vector3fix_Normalize(struct Vec3* in, struct Vec3* out);
extern "C" int Vector3fix_InnerProduct(struct Vec3* a, struct Vec3* b);
extern "C" int _Z26PackColorChannelsToDecimalPt(unsigned short* obj);
extern "C" int _Z13GetBits10To14Pt(unsigned short* obj);

struct F02033f44 {
    char pad0[0x24];
    struct Vec3 f24;
};

struct Obj020a7d74 {
    char pad0[0x50];
    struct Vec3 f50;
    char pad5c[0x134 - 0x5c];
    int f134;
    int f138;
};

// USA: func_020a7d74
extern "C" ARM int func_020a7d74(struct Obj020a7d74* self, int* out1, int* out2) {
    void* gameState = _ZN9GameState11GetInstanceEv();
    int ok = 1;
    if (self->f134 == 0) {
        ok = 0;
    }
    if (_Z13GetBit6At0xe0Ph((unsigned char*)self) == 0) {
        ok = 0;
    }
    unsigned short* p = (unsigned short*)_Z18GetFieldPtrAt0x11cPv(self);
    if (p == 0) {
        ok = 0;
    }
    if (_Z20CheckBits5To9NonZeroPt(p) == 0) {
        ok = 0;
    }
    if (ok == 0) {
        self->f138 = 0;
        return 0;
    }

    struct Vec3 dir;
    struct Vec3 t;
    struct Vec3 src = self->f50;
    int angle = src.y;
    int cz = _Z8fix32cosi(angle);
    dir.x = _Z8fix32sini(angle);
    dir.y = 0;
    dir.z = cz;
    Vector3fix_Normalize(&dir, &dir);

    struct F02033f44* f = (struct F02033f44*)_Z22GetField0xe4IfFlag0x40P15BitFlag02033f44(self);
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
        self->f138 = self->f138 + (int)_ZNK9GameState12GetTickCountEv(gameState);
    }
    if (self->f138 < 0x28) {
        return 0;
    }
    *out1 = _Z26PackColorChannelsToDecimalPt(p);
    *out2 = _Z13GetBits10To14Pt(p);
    return 1;
}