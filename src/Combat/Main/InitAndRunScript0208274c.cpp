#include <globaldefs.h>

#include "Combat/ResourceScriptEntry.h"

struct StreamHeader;

// USA: func_0208274c
ARM int InitAndRunScript0208274c(void *param0, StreamHeader *param1, int param2, int param3) {
    Script script;
    memset(param0, 0, sizeof(ResourceScriptEntry));
    data_02108ee8.field10 = 0;
    data_02108ee8.field4  = 0;
    data_02108ee8.field8  = param3;
    data_02108ee8.fieldC  = param0;
    data_02108ee8.field0  = 0;
    script.Initialize();
    script.SetOpcodeLookup(data_020f0ff8);
    script.Load(param1, (unsigned int) param2);
    script.Execute();
    return 0;
}
