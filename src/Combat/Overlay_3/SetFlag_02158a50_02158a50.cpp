// USA: func_ov003_02158a50
#include <globaldefs.h>
#include "World/Object3D.h"
#if defined(jpn)
enum { kRegion280 = 0x27c };
enum { kRegion32c = 0x328 };
#else
enum { kRegion280 = 0x280 };
enum { kRegion32c = 0x32c };
#endif

extern unsigned char data_ov003_0217fe16;

ARM void SetFlag_02158a50_02158a50(unsigned char* obj) {
    ((Object3D*)(obj + kRegion280))->MaybeSetRegularAnimation((char const*)&data_ov003_0217fe16, 9);
    ((Object3D*)(obj + kRegion280))->DisableFlag(0x40000);
    *(int*)(obj + kRegion32c) = 1;
}
