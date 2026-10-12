#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021ea378 func_ov023_021ea2dc
#endif

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, unsigned int);

struct Bitfield24_021ea378 { unsigned int v : 24; };

// USA: func_ov023_021ea378  (semantic: SetFieldFromBlock8c_021ea378)
extern "C" ARM int func_ov023_021ea378(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    struct Bitfield24_021ea378* bf = (struct Bitfield24_021ea378*)(buf + 0x8c);
    func_ov017_021d6134(obj, bf->v);
    return 1;
}
