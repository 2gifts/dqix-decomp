#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Entry021820fc { unsigned char a; unsigned char b; short c; short d; };
void ClearEntry021820fc(struct Entry021820fc* obj);

struct BattleResources {
    Foo02048004 resources[13];
    Entry021820fc state;
};

// USA: func_ov000_02182114
#if defined(jpn)
extern "C" ARM void func_ov000_02183360(char* storage)
#else
ARM void ResetArrayAndEntry02182114(char* storage)
#endif
{
    BattleResources* battle = (BattleResources*)storage;
    int i;
    for (i = 0; i < 13; i++) {
        func_0204719c(&battle->resources[i]);
    }
    ClearEntry021820fc(&battle->state);
}
