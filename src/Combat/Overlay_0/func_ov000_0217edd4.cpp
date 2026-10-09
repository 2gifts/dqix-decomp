#include <globaldefs.h>
#include "GameState/GameState.h"

unsigned char CopyOutRegion0x571d(char* obj, void* dst);
extern "C" void* func_ov000_02161318(void* obj, int index);

struct SlotIdList0217edd4 {
    signed char ids[4];
};

extern SlotIdList0217edd4 data_ov000_02183650;

// USA: func_ov000_0217edd4
extern "C" ARM void func_ov000_0217edd4(void* obj, signed char* out, signed char* outCount) {
    SlotIdList0217edd4 list = data_ov000_02183650;
    signed char buf[4];
    int n = (signed char)CopyOutRegion0x571d((char*)GameState::GetInstance(), buf);
    memcpy(&list, buf, n);
    *outCount = 0;
    for (int i = 0; i < n; i++) {
        if (func_ov000_02161318(obj, list.ids[i]) != NULL) {
            out[*outCount] = list.ids[i];
            (*outCount)++;
        }
    }
}
