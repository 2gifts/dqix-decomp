#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/ZoneFeatures.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
struct Vector3i;

int fix32ReduceAngle0To2Pi(int value);

struct RecordArray0201e710 { char pad[0x24]; void* items; int count; int capacity; };
extern "C" void* _ZN12ZoneFeatures19CreateOpcode6aEntryERKNS_13Opcode6aEntryE(struct RecordArray0201e710* arr, void* src);

static inline int FixedMulRound0201d530(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

struct Record0201d530 {
    short f0;
    int f4;
    int vecA[3];
    int vecB[3];
    short f20;
    short f22;
    int f24;
    char pad28[0x74 - 0x28];
};

struct GlobalCtx0201d530 {
    void* lastEntry;
    int pad4;
    struct RecordArray0201e710* arr;
};
extern struct GlobalCtx0201d530 data_020fdc20;

// USA: func_0201d530
ARM int WarpScript_Opcode_73(Script::Parameter* arg0, int) {
    struct Variant02030b0c* param0 = (struct Variant02030b0c*)arg0;
    struct Record0201d530 rec;
    int tmp[3];

    ((ZoneFeatures::Opcode6aEntry*)((char*)&rec))->Reset();
    rec.f4 = ((Script::Parameter*)param0)->ToInt();

    struct TaggedValue02030b44* next = (extern TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)((char*)param0 + 8)))->ToVec3fix((Vector3i*)tmp);
    *(Vector3i*)rec.vecA = *(Vector3i const*)tmp;

    next = (extern TaggedValue02030b44*)((Script::Parameter*)next)->ToVec3fix((Vector3i*)tmp);
    *(Vector3i*)rec.vecB = *(Vector3i const*)tmp;

    rec.f22 = (short)fix32ReduceAngle0To2Pi((int)(4096.0f * ((Script::Parameter*)next)->ToFloat()));
    rec.f20 = (short)(int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)next + 8)))->ToFloat());

    int halfX = rec.vecB[0] / 2;
    int halfZ = rec.vecB[2] / 2;
    int qz = FixedMulRound0201d530(halfZ, halfZ);
    int qx = FixedMulRound0201d530(halfX, halfX);
    rec.f24 = qx + qz;

    data_020fdc20.lastEntry = _ZN12ZoneFeatures19CreateOpcode6aEntryERKNS_13Opcode6aEntryE(data_020fdc20.arr, &rec);
    return 1;
}
