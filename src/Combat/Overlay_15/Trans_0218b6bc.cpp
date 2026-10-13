#include <globaldefs.h>
#include "Resource/Script.h"

struct List8_0218b9ac;
void InitList8_0218b9ac(List8_0218b9ac* obj, int n);

extern List8_0218b9ac* data_ov015_02194560;

// USA: func_ov015_0218b6bc  (semantic: Trans_0218b6bc)
extern "C" ARM int func_ov015_0218b6bc(Script::Parameter* params, int count) {
    List8_0218b9ac* list = data_ov015_02194560;
    InitList8_0218b9ac(list, params->ToInt());
    return 1;
}
