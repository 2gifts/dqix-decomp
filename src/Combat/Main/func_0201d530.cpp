#include <globaldefs.h>

struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" extern struct TaggedValue02030b44* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct TaggedValue02030b44* obj, int* outVec);
extern "C" extern float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

extern "C" extern void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" extern void _ZN12ZoneFeatures13Opcode6aEntry5ResetEv(char* obj);
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
extern "C" ARM int _Z20WarpScript_Opcode_73PN6Script9ParameterEi(struct Variant02030b0c* param0) {
    struct Record0201d530 rec;
    int tmp[3];

    _ZN12ZoneFeatures13Opcode6aEntry5ResetEv((char*)&rec);
    rec.f4 = _ZNK6Script9Parameter5ToIntEv(param0);

    struct TaggedValue02030b44* next = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct TaggedValue02030b44*)((char*)param0 + 8), tmp);
    _ZN8Vector3iaSERKS_(rec.vecA, tmp);

    next = _ZN6Script9Parameter9ToVec3fixEP8Vector3i(next, tmp);
    _ZN8Vector3iaSERKS_(rec.vecB, tmp);

    rec.f22 = (short)fix32ReduceAngle0To2Pi((int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(next)));
    rec.f20 = (short)(int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)next + 8)));

    int halfX = rec.vecB[0] / 2;
    int halfZ = rec.vecB[2] / 2;
    int qz = FixedMulRound0201d530(halfZ, halfZ);
    int qx = FixedMulRound0201d530(halfX, halfX);
    rec.f24 = qx + qz;

    data_020fdc20.lastEntry = _ZN12ZoneFeatures19CreateOpcode6aEntryERKNS_13Opcode6aEntryE(data_020fdc20.arr, &rec);
    return 1;
}
