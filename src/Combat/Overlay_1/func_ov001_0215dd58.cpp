#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov001_02158f64(void* node, EventVec3 v1, EventVec3 v2, int d, int one, int ip);
extern "C" void func_ov001_02159168(void* node, int a, int b, int c, int d, int e, int f);

struct Data24_0215dd58 { char pad[0x24]; void* field24; };
extern Data24_0215dd58 data_ov001_02165880;

// USA: func_ov001_0215dd58
extern "C" ARM int func_ov001_0215dd58(void* self, int mode) {
    EventVec3 v1;
    memset(&v1, 0, 0xc);
    EventVec3 v2;
    memset(&v2, 0, 0xc);
    EventVec3 v3;
    memset(&v3, 0, 0xc);
    v2.a = (int)(4096.0f * func_ov017_021d6110(self));
    v2.b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    v2.c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    int a = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x18));
    int b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x20));
    int c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x28));
    int e;
    int d = func_ov017_021d60f4((char*)self + 0x30);
    e = -1;
    if (mode >= 8) {
        e = func_ov017_021d60f4((char*)self + 0x38);
    }
    func_ov001_02158f64(data_ov001_02165880.field24, v1, v2, d, 1, 0);
    func_ov001_02159168(data_ov001_02165880.field24, a, b, c, d, e, 0);
    return 1;
}
