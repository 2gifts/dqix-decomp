#include <globaldefs.h>

struct Vec3PairRecord020a0db8;
int InitVec3PairRecordType2(struct Vec3PairRecord020a0db8*, int*, int*, int);

// USA: func_0202ee58
ARM void CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58(char* obj, int a, int b) {
    InitVec3PairRecordType2((struct Vec3PairRecord020a0db8*)(obj + 0x194), (int*)(obj + 0x10), (int*)a, b);
    *(int*)(obj + 0x168) &= ~0x2;
}
