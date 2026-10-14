#include <globaldefs.h>
void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4*, int);

void ApplyVec3Tail_0202e694(void*, int*);

struct Struct020a2868 {
    unsigned char pad[0x220];
    int vec[3];
};

// USA: func_020a2868
ARM void SetVec3ComponentsAndApply020a2868(struct Struct020a2868* obj) {
    obj->vec[1] = 0xc666;
    obj->vec[2] = 0xe666;
    ApplyVec3Tail_0202e694(obj, obj->vec);
    SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)(obj), (int)(0x19000));
}
