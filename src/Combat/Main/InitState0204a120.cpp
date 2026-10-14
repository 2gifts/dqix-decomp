#include <globaldefs.h>

struct Struct020A2CF0;
void ResetState020a2cf0(struct Struct020A2CF0*);
ARM void SetBitsInField0_0202e08c(unsigned int* obj, unsigned int mask);

struct Obj0204a120 {
    char pad0[0x21c];
    int field_21c;
    int field_220;
    unsigned char field_224;
    char pad1[0xf];
    unsigned char field_234;
    char pad2[0xf];
    unsigned char field_244;
    char pad3[0xf];
    int field_254;
    int field_258;
    int field_25c;
    int field_260;
    unsigned char field_264;
    unsigned char field_265;
};

// USA: func_0204a120
ARM void InitState0204a120(struct Obj0204a120* obj) {
    ResetState020a2cf0((struct Struct020A2CF0*)obj);
    SetBitsInField0_0202e08c((unsigned int*)obj, 0x10);
    obj->field_21c = 0;
    obj->field_220 = 0;
    obj->field_224 = 0;
    obj->field_234 = 0;
    obj->field_244 = 0;
    obj->field_254 = -1;
    obj->field_258 = -1;
    obj->field_25c = -1;
    obj->field_260 = -1;
    obj->field_264 = 0;
    obj->field_265 = 0;
}
