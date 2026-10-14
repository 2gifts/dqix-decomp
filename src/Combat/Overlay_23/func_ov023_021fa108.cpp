#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void Vector3fix_Normalize(struct Vec3* a, struct Vec3* b);

struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Vector3i;
ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Vec3s32_020c3030 { int x; int y; int z; };
extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

struct Obj021f9eb4;
void ClearFields0To3_021f9eb4(struct Obj021f9eb4* o);

struct Slot021fa108 {
    unsigned short field0;
    unsigned char field2;
    unsigned char field3;
    int field4;
    int field8;
    int fieldc;
    int field10[3];
    int field1c[3];
};

class VNode021fa108 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void v07(int* pos);
};

extern "C" VNode021fa108* func_ov023_021f6880(void* base, int val);
extern "C" void* func_ov011_021849c8(void* ctx);

// USA: func_ov023_021fa108
extern "C" ARM void func_ov023_021fa108(void* unused, void* ctx, struct Slot021fa108* slot) {
    struct Vec3 diff;
    Vector3fix_Subtract((struct Vec3*)slot->field1c, (struct Vec3*)slot->field10, &diff);
    Vector3fix_Normalize(&diff, &diff);

    int resetFlag = 0;
    if (slot->field3 == 0) {
        int t = slot->field4 + slot->field8;
        slot->field4 = t;
        if (slot->fieldc < t) {
            slot->field4 = slot->fieldc;
        }
        struct Vec3Fixed02030e2c scaled;
        Vector3fixMultiplyScalar((Vector3i const*)&diff, slot->field4, (Vector3i*)&scaled);
        Vector3fix_Add((struct Vec3*)slot->field10, (struct Vec3*)&scaled, (struct Vec3*)slot->field10);
        int dist = Vector3fix_Distance((struct Vec3s32_020c3030*)slot->field1c, (struct Vec3s32_020c3030*)slot->field10);
        float a = (float)slot->field4 / 4096.0f;
        float aSquared = a * a;
        float c = (float)slot->field8 / 4096.0f;
        int result = (int)((aSquared / (2.0f * c)) * 4096.0f);
        if (dist < result) {
            slot->field3 = 1;
        }
    } else if (slot->field3 == 1) {
        int dist2 = Vector3fix_Distance((struct Vec3s32_020c3030*)slot->field1c, (struct Vec3s32_020c3030*)slot->field10);
        int diff2;
        if (slot->field8 < slot->field4 && (diff2 = slot->field4 - slot->field8) < dist2) {
            slot->field4 = diff2;
            struct Vec3Fixed02030e2c scaled2;
            Vector3fixMultiplyScalar((Vector3i const*)&diff, diff2, (Vector3i*)&scaled2);
            Vector3fix_Add((struct Vec3*)slot->field10, (struct Vec3*)&scaled2, (struct Vec3*)slot->field10);
        } else {
            _ZN8Vector3iaSERKS_(slot->field10, slot->field1c);
            resetFlag = 1;
        }
    }

    void* base = func_ov011_021849c8(ctx);
    VNode021fa108* node = func_ov023_021f6880(base, slot->field0);
    if (node != NULL) {
        node->v07(slot->field10);
    }
    if (resetFlag) {
        ClearFields0To3_021f9eb4((struct Obj021f9eb4*)slot);
    }
}
