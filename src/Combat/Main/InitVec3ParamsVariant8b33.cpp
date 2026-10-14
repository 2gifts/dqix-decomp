#include <globaldefs.h>
void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4*, int);

void ApplyVec3Tail_0202e694(void*, int*);

// USA: func_020a2830
ARM void InitVec3ParamsVariant8b33_020a2830(void* obj) {
    *(int*)((char*)obj + 0x224) = 0x8b33;
    *(int*)((char*)obj + 0x228) = 0xe666;
    ApplyVec3Tail_0202e694(obj, (int*)((char*)obj + 0x220));
    SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)(obj), (int)(0x19000));
}
