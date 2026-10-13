#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/BufferedScriptResult.h"

#if defined(jpn)
#define data_020f0d30 data_020f0e28
#endif

extern BufferedScriptResult* data_02108dd8;
extern int data_020f0d2c;
extern Script::OpcodeLookupEntry data_020f0d30[];

// KEEP-NAME
// USA: func_0207416c
ARM int RunBufferedStream0207416c(BufferedScriptResult* result, int key, const void* bytecode, unsigned int length) {
    Script script;
    data_02108dd8 = result;
    data_020f0d2c = key;
    script.Initialize();
    script.SetOpcodeLookup(data_020f0d30);
    script.Load(bytecode, length);
    script.Execute();
    return 1;
}
