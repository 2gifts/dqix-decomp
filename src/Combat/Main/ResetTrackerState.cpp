#include <globaldefs.h>
#include "World/BmdjScriptNode.h"

// USA: func_0201f01c
ARM void ResetTrackerState(BmdjScriptState* state) {
    state->unknown0 = 0;
    state->unknown4 = 0;
    state->unknown8 = 0;
    state->unknownC = 0;
    state->elementCount = 0;
    state->unknown14 = 0;
    state->unknown38 = 0;
}
