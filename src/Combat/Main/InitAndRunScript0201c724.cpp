#include <globaldefs.h>
#include "Resource/Script.h"

struct StreamHeader;

extern int data_020ef2bc;
extern Script::OpcodeLookupEntry data_020ef2c0[];

struct Data020fdc14 {
    int field0;
    void* field4;
    int field8;
};
extern struct Data020fdc14 data_020fdc14;

// USA: func_0201c724  (semantic: InitAndRunScript0201c724)
extern "C" ARM void func_0201c724(int param0, void* param1, struct StreamHeader* param2, int param3) {
    Script local;
    data_020fdc14.field4 = param1;
    data_020ef2bc = param0;
    local.Initialize();
    local.SetOpcodeLookup(data_020ef2c0);
    local.Load(param2, param3);
    local.Execute();
    data_020fdc14.field4 = 0;
    data_020ef2bc = -1;
}
