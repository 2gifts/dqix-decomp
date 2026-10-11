#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

int GetSharedHalfwordOrBattleDefault(void);

struct Obj021db3c0 {
    unsigned char pad0[4];
    unsigned short field4;
};

// USA: func_ov027_021db3c0  (semantic: FindAvailablePosition_021db3c0)
extern "C" ARM int func_ov027_021db3c0(Obj021db3c0* obj) {
    unsigned int mask = GetSharedHalfwordOrBattleDefault();
    if (mask == 0) return 0;
    unsigned short i = 0;
    unsigned short start = obj->field4;
    unsigned short cur = start;
    do {
        if ((mask & (1 << (cur - 1))) && start != cur) {
            obj->field4 = cur;
            goto found;
        }
        i = i + 1;
        cur = (cur == 16) ? 1 : cur + 1;
    } while (i < 16);
found:
    return 1;
}
