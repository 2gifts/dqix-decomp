#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Foo02048004;
void MaybeInvoke0204719c(struct Foo02048004* obj);

// USA: func_02012fa4
ARM void ResetFourSubStructs(char* base) {
    signed char i;
    for (i = 0; i < 4; i++) {
        MaybeInvoke0204719c((struct Foo02048004*)(base + i * 0x88));
        func_0204719c((struct Foo02048004*)(base + i * 0x88));
    }
}
