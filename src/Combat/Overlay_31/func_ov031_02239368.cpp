#include <globaldefs.h>
#include "System/RequestSubmission.h"

extern "C" ARM void func_ov031_02239368(int val);
ARM void SetField54IfTagNot9Or10_ov031_022393e4(int v);

struct Outer02239920 { unsigned char pad[4]; unsigned char* inner; };
extern Outer02239920 data_ov031_02290d18;

// USA: func_ov031_022398e8
ARM int InvokeMaskAndSetField54_022398e8(void) {
    func_ov031_02239368(6);
    int r = InvokeWithFullMaskType2_020d68b4(data_ov031_02290d18.inner + 0x1e00, 0xd);
    if (r == 2) {
        return 1;
    }
    SetField54IfTagNot9Or10_ov031_022393e4(r);
    return 0;
}
