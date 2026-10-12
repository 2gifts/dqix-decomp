#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"


struct Entry021820fc { unsigned char a; unsigned char b; short c; short d; };
void ClearEntry021820fc(struct Entry021820fc* obj);

// USA: func_ov000_02182114
#if defined(jpn)
extern "C" ARM void func_ov000_02183360(char* p)
#else
ARM void ResetArrayAndEntry02182114(char* p)
#endif
{
    int i;
    for (i = 0; i < 13; i++) {
        func_0204719c((struct Foo02048004*)(p + i * 0x88));
    }
    ClearEntry021820fc((struct Entry021820fc*)(p + 0x6e8));
}
