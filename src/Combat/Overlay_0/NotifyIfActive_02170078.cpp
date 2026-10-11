#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x47d
#else
#define REGION_OFFSET_0 0x43d
#endif


extern "C" int func_ov000_02176e3c(int flag, void* obj, int byteVal, int val0, int field4, int one);

struct Data02184288 { int field0; int field4; int field8; };
extern struct Data02184288 data_ov000_02184288;
extern int data_ov000_02183ff0;

// USA: func_ov000_02170078
ARM void NotifyIfActive_02170078(char* obj) {
    signed char byteVal = *(signed char*)(obj + REGION_OFFSET_0);
    if (byteVal >= 0) {
        int flag = data_ov000_02184288.field8;
        if (flag != 0) {
            func_ov000_02176e3c(flag, obj, byteVal, data_ov000_02183ff0, data_ov000_02184288.field4, 1);
        }
        *(signed char*)(obj + REGION_OFFSET_0) = -1;
    }
}
