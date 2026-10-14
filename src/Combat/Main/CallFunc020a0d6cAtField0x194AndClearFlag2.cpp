#include <globaldefs.h>

struct Vec3PairRecord020a0d6c;
int InitVec3PairRecordType1(struct Vec3PairRecord020a0d6c*, int*, int*, int, int, int);

// USA: func_0202edb4
ARM void CallFunc020a0d6cAtField0x194AndClearFlag2_0202edb4(char* obj, int a, int b, int c, int d) {
    InitVec3PairRecordType1((struct Vec3PairRecord020a0d6c*)(obj + 0x194), (int*)(obj + 0x10), (int*)a, b, c, d);
    *(int*)(obj + 0x168) &= ~0x2;
}
