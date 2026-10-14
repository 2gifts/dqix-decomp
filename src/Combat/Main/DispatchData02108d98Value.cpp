#include <globaldefs.h>
#include "Resource/Script.h"

struct Data02108d98 {
    unsigned short field0;
    unsigned short field2;
    int field4;
    int field8;
    int fieldC;
};
extern struct Data02108d98 data_02108d98;

struct Variant02030b0c;
extern "C" void func_02071c64(int a, int b, int c);

// USA: func_02071820
ARM int DispatchData02108d98Value_02071820(struct Variant02030b0c* variant) {
    if (data_02108d98.field4 != 0 && data_02108d98.field0 != 0) {
        func_02071c64(data_02108d98.fieldC, data_02108d98.field8, data_02108d98.field0);
    } else {
        func_02071c64(data_02108d98.fieldC, data_02108d98.field8,
                      (unsigned short)((Script::Parameter*)variant)->ToInt());
    }
    return 1;
}
