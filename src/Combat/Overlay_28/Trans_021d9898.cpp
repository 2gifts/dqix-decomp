#include <globaldefs.h>
#include "Resource/Script.h"

extern float* data_ov028_021d9bc4;

// USA: func_ov028_021d9898  (semantic: Trans_021d9898)
extern "C" ARM int func_ov028_021d9898(Script::Parameter* params, int count) {
    *data_ov028_021d9bc4 = params->ToFloat();
    return 1;
}
