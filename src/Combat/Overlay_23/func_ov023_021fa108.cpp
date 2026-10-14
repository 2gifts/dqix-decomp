#include <globaldefs.h>
#include <System/Matrix.h>

ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Obj021f9eb4;
void ClearFields0To3_021f9eb4(struct Obj021f9eb4* o);

struct Slot021fa108 {
    unsigned short field0;
    unsigned char field2;
    unsigned char field3;
    int field4;
    int field8;
    int fieldc;
    Vector3i field10;
    Vector3i field1c;
};

class VNode021fa108 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void v07(Vector3i* pos);
};

extern "C" VNode021fa108* func_ov023_021f6880(void* base, int val);
extern "C" void* func_ov011_021849c8(void* ctx);

// USA: func_ov023_021fa108
extern "C" ARM void func_ov023_021fa108(void* unused, void* ctx, struct Slot021fa108* slot) {
    Vector3i diff;
    Vector3fix_Subtract(&slot->field1c, &slot->field10, &diff);
    Vector3fix_Normalize(&diff, &diff);

    int resetFlag = 0;
    if (slot->field3 == 0) {
        int t = slot->field4 + slot->field8;
        slot->field4 = t;
        if (slot->fieldc < t) {
            slot->field4 = slot->fieldc;
        }
        Vector3i scaled;
        Vector3fixMultiplyScalar(&diff, slot->field4, &scaled);
        Vector3fix_Add(&slot->field10, &scaled, &slot->field10);
        int dist = Vector3fix_Distance(&slot->field1c, &slot->field10);
        float a = (float)slot->field4 / 4096.0f;
        float aSquared = a * a;
        float c = (float)slot->field8 / 4096.0f;
        int result = (int)((aSquared / (2.0f * c)) * 4096.0f);
        if (dist < result) {
            slot->field3 = 1;
        }
    } else if (slot->field3 == 1) {
        int dist2 = Vector3fix_Distance(&slot->field1c, &slot->field10);
        int diff2;
        if (slot->field8 < slot->field4 && (diff2 = slot->field4 - slot->field8) < dist2) {
            slot->field4 = diff2;
            Vector3i scaled2;
            Vector3fixMultiplyScalar(&diff, diff2, &scaled2);
            Vector3fix_Add(&slot->field10, &scaled2, &slot->field10);
        } else {
            slot->field10 = slot->field1c;
            resetFlag = 1;
        }
    }

    void* base = func_ov011_021849c8(ctx);
    VNode021fa108* node = func_ov023_021f6880(base, slot->field0);
    if (node != NULL) {
        node->v07(&slot->field10);
    }
    if (resetFlag) {
        ClearFields0To3_021f9eb4((struct Obj021f9eb4*)slot);
    }
}
