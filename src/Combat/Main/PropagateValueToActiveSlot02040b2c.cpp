#include <globaldefs.h>
#if defined(jpn)
enum { kRegionalFieldOffset = 0x2c8 };
#else
enum { kRegionalFieldOffset = 0x2d4 };
#endif


struct State0xcda8;
void StoreAlignedValue0x60(struct State0xcda8* obj, int value);
void StoreVec3AtField0x50(unsigned char* obj, int a, int b, int c);

struct Vec3Block02040b2c { int x, y, z; };

struct Obj02040b2c {
    char pad[0x14];
    struct State0xcda8* field14;
    unsigned char* field18;
    unsigned char* field1c;
};

// USA: func_02040b2c
ARM void PropagateValueToActiveSlot02040b2c(struct Obj02040b2c* self, int value) {
    struct State0xcda8* p;
    unsigned char* q;

    p = self->field14;
    if (p != NULL) {
        StoreAlignedValue0x60(p, value);
        return;
    }
    q = self->field18;
    if (q != NULL) {
        struct Vec3Block02040b2c v = *(struct Vec3Block02040b2c*)(q + 0x50);
        StoreVec3AtField0x50(q, v.x, value, v.z);
        q = self->field18;
        *(int*)(q + 0xb0) = value;
        return;
    }
    q = self->field1c;
    if (q == NULL) return;
    {
        struct Vec3Block02040b2c v = *(struct Vec3Block02040b2c*)(q + 0x50);
        StoreVec3AtField0x50(q, v.x, value, v.z);
    }
    q = self->field1c;
    *(int*)(q + kRegionalFieldOffset) = value;
}
