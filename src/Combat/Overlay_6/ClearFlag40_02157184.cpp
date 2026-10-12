#include <globaldefs.h>

#if defined(jpn)
#define ClearFlag40_02157184 func_ov006_0215878c
enum { kFlags = 0x962, kInner = 0x164 };
#define func_ov023_021dcd90 func_ov023_021dd698
#define func_ov006_02155508 func_ov006_02156bf0
#else
enum { kFlags = 0xae2, kInner = 0x2e4 };
#endif



extern "C" void func_ov023_021dcd90(void* p, int x);
extern "C" void func_ov006_02155508(void* s);

struct ClearFlag40_02157184Struct {
    unsigned char pad[kFlags];
    unsigned short flags;
};

// USA: func_ov006_02157184
#if defined(jpn)
extern "C"
#endif
ARM void ClearFlag40_02157184(struct ClearFlag40_02157184Struct* s) {
    s->flags &= ~0x40;
    func_ov023_021dcd90((char*)s + kInner + 0x800, 0);
    func_ov006_02155508(s);
}
