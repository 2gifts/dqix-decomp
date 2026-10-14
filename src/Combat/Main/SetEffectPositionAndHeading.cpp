#include <globaldefs.h>
extern "C" void* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct TaggedValue02030b44*, int*);

struct TaggedValue02030b44 {
    int type;
    union { int i; float f; } value;
};
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);
short fix32ReduceAngle0To2Pi(int);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Global020fdc20_d494 {
    int pad0;
    int pad4;
    unsigned char* obj;
};
extern struct Global020fdc20_d494 data_020fdc20;

// USA: func_0201d494
extern "C" ARM int _Z29WarpScript_Opcode_6e_0201d494PN6Script9ParameterEi(void* arg0) {
    int vec[3];
    struct TaggedValue02030b44* v = (struct TaggedValue02030b44*)_ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct TaggedValue02030b44*)(arg0), (int*)(vec));
    float f = _ZNK6Script9Parameter7ToFloatEv(v);
    int angle = (int)(4096.0f * f);
    short heading = fix32ReduceAngle0To2Pi(angle);
    unsigned char* obj = data_020fdc20.obj;
    _ZN8Vector3iaSERKS_((int*)(obj + 0x70), vec);
    *(short*)(obj + 0x7c) = heading;
    return 1;
}
