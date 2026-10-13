#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_02157030(void* self, unsigned int id, short* x, short* y, short* w, short* h);
extern "C" void func_ov002_0215be00(void* obj, int val, int a2, int a3);
extern "C" void func_ov002_0215c52c(void* obj, void* ptr, int flag);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

// USA: func_ov002_0215c474  (semantic: InitBattleTagWithFields_0215c474)
extern "C" ARM void func_ov002_0215c474(char* base) {
    short valAc = 0;
    short valAe = 0;
    short valA8 = 1;
    short valAa = 1;
    func_ov002_02157030(base, 1, &valAc, &valAe, &valA8, &valAa);

    func_ov002_0215be00(base, (*(int*)(base + 0x1000 + 0xbb8)) & 0xff, valAc, valAe);

    memset(*(void**)(base + 0x1000 + 0xbd0), 0, 0x960);

    func_ov002_0215c52c(base, *(void**)(base + 0x1000 + 0xbd0), 0);

    func_0205d304(base + 0x2c8 + 0xc00, *(void**)(base + 0x1000 + 0xbd0), 0, 1, 0, 1, 0, 0);
}
