#include <globaldefs.h>

int GetPositionVectorMtxStackLevel_020c5650(int* out);
int GetProjectionMtxStackLevel_020c5680(int* out);

// USA: func_020c537c
ARM void ResetMatrixStacks020c537c(void) {
    int posLevel;
    int projLevel;
    *(volatile unsigned int*)0x4000600 |= 0x8000;
    while (GetPositionVectorMtxStackLevel_020c5650(&posLevel) != 0) {}
    while (GetProjectionMtxStackLevel_020c5680(&projLevel) != 0) {}
    *(volatile unsigned int*)0x4000440 = 3;
    *(volatile unsigned int*)0x4000454 = 0;
    *(volatile unsigned int*)0x4000440 = 0;
    if (projLevel != 0) *(volatile unsigned int*)0x4000448 = projLevel;
    *(volatile unsigned int*)0x4000454 = 0;
    *(volatile unsigned int*)0x4000440 = 2;
    *(volatile unsigned int*)0x4000448 = posLevel;
    *(volatile unsigned int*)0x4000454 = 0;
}
