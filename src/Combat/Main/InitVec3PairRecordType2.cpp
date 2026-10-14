#include <globaldefs.h>
#include "System/Matrix.h"

struct Vec3PairRecord020a0db8 {
    int type;
    Vector3i from;
    Vector3i to;
    int pad;
    int f20;
    int f24;
};

// USA: func_020a0db8
ARM void InitVec3PairRecordType2(struct Vec3PairRecord020a0db8* rec, int* from, int* to, int a3) {
    rec->from = *(const Vector3i*)from;
    rec->to = *(const Vector3i*)to;
    rec->f24 = a3;
    rec->type = 2;
}
