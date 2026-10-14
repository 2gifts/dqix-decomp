#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

extern "C" void func_ov023_021e13b0(void* obj, void* alloc, int capacity);

struct DataFA34_021e1194 {
    short count;
    short pad2;
    void* arr;
    void* field8;
    void* fieldC;
};
extern struct DataFA34_021e1194 data_ov023_021ffa34;

// USA: func_ov023_021e1194  (semantic: BuildOrResetEntryList_021e1194)
extern "C" ARM int func_ov023_021e1194(struct Variant02030b0c* objRaw) {
    short v0 = (short)((Script::Parameter*)objRaw)->ToInt();
    if (data_ov023_021ffa34.arr != 0 && data_ov023_021ffa34.count != 0) {
        func_ov023_021e13b0(data_ov023_021ffa34.fieldC, data_ov023_021ffa34.field8, data_ov023_021ffa34.count);
    } else {
        func_ov023_021e13b0(data_ov023_021ffa34.fieldC, data_ov023_021ffa34.field8, v0);
    }
    return 1;
}
