#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021ea884 func_ov023_021ea7e8
#endif

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, unsigned int);

struct Bitfield16_021ea884 { unsigned int v : 16; };

// USA: func_ov023_021ea884  (semantic: SetFieldFromBlock20_021ea884)
extern "C" ARM int func_ov023_021ea884(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    struct Bitfield16_021ea884* bf = (struct Bitfield16_021ea884*)(buf + 0x20);
    func_ov017_021d6134(obj, bf->v);
    return 1;
}
