#include <globaldefs.h>

#include "Combat/ObjectStateInitialization.h"

// USA: func_02032e58
extern "C" ARM void func_02032e58(void *receiver) {
    ObjectStatePrefix *state = (ObjectStatePrefix*)receiver;

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
