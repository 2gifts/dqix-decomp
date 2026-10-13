#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/BufferedScriptResult.h"

extern int data_020f0d2c;
extern BufferedScriptResult* data_02108dd8;

// USA: func_02074060
extern "C" ARM int func_02074060(Script::Parameter* parameters, int) {
    int key = (parameters++)->ToInt();
    if (key != data_020f0d2c) return 1;
    data_02108dd8->key = (short)key;
    for (int i = 0; i < 3; i++) {
        data_02108dd8->values[i] = (short)parameters->ToInt();
        Script::Parameter* attribute = parameters + 1;
        parameters += 2;
        data_02108dd8->attributes[i] = (short)attribute->ToInt();
    }
    data_02108dd8->resultId = (short)parameters->ToInt();
    data_02108dd8->unknown10 = (short)(parameters + 1)->ToInt();
    data_02108dd8->unknown12 = 0;
    return 1;
}
