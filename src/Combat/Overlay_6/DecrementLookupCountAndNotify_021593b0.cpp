#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215fffe data_ov006_02161350
#define func_ov006_0215f3d8 func_ov006_021607f8
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Container02080fa8;
extern "C" void func_ov006_02159274(void* obj, unsigned char* a, unsigned char* b, unsigned char* c);
extern "C" void func_ov006_0215f4dc(void* obj);
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);
extern "C" void func_020813ec(void* obj, int flag);

struct Struct021593b0 {
    unsigned char pad0[R(0xc, 0x14)];
    void* f14;
    unsigned char pad1[0x38b - R(0x10, 0x18)];
    unsigned char f38b;
    unsigned char pad2[0x431 - 0x38c];
    unsigned char f431;
};

// USA: func_ov006_021593b0  (semantic: DecrementLookupCountAndNotify_021593b0)
extern "C" ARM void func_ov006_021593b0(struct Struct021593b0* obj) {
    unsigned char buf[3];
    func_ov006_02159274(obj, &buf[1], &buf[2], &buf[0]);
    if (buf[0] > 9) buf[0] = 9;
    if (buf[0] != 0) {
        unsigned char old = obj->f38b;
        obj->f38b = old - 1;
        if (obj->f38b == 0) obj->f38b = 1;
        if (old != obj->f38b) obj->f431 = 1;
    }
    func_ov006_0215f4dc(obj);
    SetEntryFirstField02080fa8((struct Container02080fa8*)obj->f14, 0x1f, obj->f38b);
    func_020813ec(obj->f14, 6);
}
