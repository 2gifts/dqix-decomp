#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021f735c func_ov023_021f6898
#endif

extern "C" void __clear(void*, int);

struct Vec3_021f735c { int x; int y; int z; };
struct Block_021f735c { unsigned int v[3]; };

// USA: func_ov023_021f735c
extern "C" ARM void func_ov023_021f735c(struct Vec3_021f735c* dst) {
    struct Vec3_021f735c local;
    __clear(&local, 0xc);
    *(struct Block_021f735c*)dst = *(struct Block_021f735c*)&local;
}
