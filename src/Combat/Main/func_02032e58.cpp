#include <globaldefs.h>

#include "Combat/ObjectStateInitialization.h"
#include "World/Object3D.h"

struct ObjectStatePrefix {
    Object3D object;
    unsigned short fieldAc;
    unsigned short fieldAe;
    unsigned short fieldB0;
    unsigned short fieldB2;
    unsigned short fieldB4;
    unsigned short fieldB6;
    unsigned short fieldB8;
    unsigned short fieldBa;
    unsigned short fieldBc;
    unsigned char fieldBe;
    unsigned char fieldBf;
    unsigned char fieldC0;
    unsigned char fieldC1Low : 2;
    unsigned char fieldC1Bit2 : 1;
    unsigned char fieldC1Bit3 : 1;
    unsigned char fieldC1High : 4;
    unsigned char fieldC2Low : 4;
    unsigned char fieldC2Bit4 : 1;
    unsigned char fieldC2Bit5 : 1;
    unsigned char fieldC2Bit6 : 1;
    unsigned char fieldC2Bit7 : 1;
    unsigned char fieldC3;
    unsigned short fieldC4Low : 15;
    unsigned short fieldC4High : 1;
    unsigned short fieldC6;
    unsigned char unknownC8[0x18];
    unsigned char fieldE0Bit0 : 1;
    unsigned char fieldE0Bit1 : 1;
    unsigned char fieldE0Bit2 : 1;
    unsigned char fieldE0Bit3 : 1;
    unsigned char fieldE0Bit4 : 1;
    unsigned char fieldE0Bit5 : 1;
    unsigned char fieldE0Bit6 : 1;
    unsigned char fieldE0Bit7 : 1;
    unsigned char unknownE1[0x33];
    Struct02032fb8 firstHalfwords;
    Struct02032fb8 secondHalfwords;
    unsigned int field124;
    unsigned int field128;
    unsigned short field12c;
};

// USA: func_02032e58
extern "C" ARM void func_02032e58(void *receiver) {
    ObjectStatePrefix *state = static_cast<ObjectStatePrefix *>(receiver);

    state->object.Initialize();
    state->object.unknown_0_ |= 2;
    state->object.EnableFlag(4);
    state->fieldBe     = 0;
    state->fieldBf     = 0;
    state->fieldC0     = 0;
    state->fieldAc     = 0;
    state->fieldAe     = 0;
    state->fieldB0     = 0x324;
    state->fieldB2     = 0;
    state->fieldB4     = 0x189;
    state->fieldB6     = 0x28;
    state->fieldB8     = 0;
    state->fieldC2Low  = 0;
    state->fieldC1Low  = 0;
    state->fieldC3     = 0;
    state->fieldC6     = 0;
    state->fieldC1High = 0;
    state->fieldC2Bit4 = 0;
    state->fieldBa     = 0;
    state->fieldBc     = 0;
    state->fieldE0Bit0 = 0;
    state->fieldC2Bit5 = 0;
    state->fieldC2Bit6 = 0;
    state->fieldC1Bit3 = 0;
    state->fieldC4Low  = 0;
    state->fieldC2Bit7 = 0;
    state->field124    = 0;
    state->field128    = 0;
    state->field12c    = 0;
    state->fieldBa     = 0x199;
    state->fieldE0Bit2 = 0;
    state->fieldE0Bit1 = 0;
    ClearFourHalfwords(&state->firstHalfwords);
    ClearFourHalfwords(&state->secondHalfwords);
    state->fieldC1Bit2 = 0;
    state->fieldE0Bit3 = 0;
    state->fieldE0Bit4 = 0;
    state->fieldE0Bit5 = 0;
    state->fieldC4High = 0;
}
