#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
void* SetType7AndField1c(int type, int val);

struct Data24_0215d784 { char pad[0x24]; int field24; };
extern Data24_0215d784 data_ov001_02165880;

// USA: func_ov001_0215d784  (semantic: SetType7Field1cWrapper_0215d784)
extern "C" ARM int func_ov001_0215d784(void* self) {
    int val = func_ov017_021d60f4(self);
    SetType7AndField1c(data_ov001_02165880.field24, val);
    return 1;
}
