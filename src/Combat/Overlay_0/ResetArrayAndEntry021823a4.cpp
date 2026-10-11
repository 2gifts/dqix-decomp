#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

void MaybeInvoke0204719c(struct Foo02048004* obj);

struct Entry021820fc { unsigned char a; unsigned char b; short c; short d; };
void ClearEntry021820fc(struct Entry021820fc* obj);

// USA: func_ov000_021823a4
ARM void ResetArrayAndEntry021823a4(char* p) {
    int i;
    for (i = 0; i < 13; i++) {
        MaybeInvoke0204719c((struct Foo02048004*)(p + i * 0x88));
    }
    ClearEntry021820fc((struct Entry021820fc*)(p + 0x6e8));
}
