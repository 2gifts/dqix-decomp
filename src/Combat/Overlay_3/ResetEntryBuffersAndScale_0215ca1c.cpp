#include <globaldefs.h>
#if defined(jpn)
enum { kRegion3bc = 0x3d4 };
enum { kRegion98 = 0xb0 };
#else
enum { kRegion3bc = 0x3bc };
enum { kRegion98 = 0x98 };
#endif

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
void CallFunc0204b04cOverList0x98(Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
void UpdateEntryAndScale_0215e2a8(char* base);

// JPN: func_ov003_0215dd38
// USA: func_ov003_0215ca1c  (semantic: ResetEntryBuffersAndScale_0215ca1c)
extern "C" ARM void func_ov003_0215ca1c(char* obj) {
    if (*(unsigned char*)(obj + kRegion3bc) == 0) return;
    ClearBuffers0204b010OverList0x98((Cont0205d1e0*)(obj + kRegion98));
    CallFunc0204c8f0OverList0x9c((Cont0205d228*)(obj + kRegion98));
    func_0205da88(obj + kRegion98, 1, 2, 1);
    CallFunc0204b04cOverList0x98((Cont0205d274*)(obj + kRegion98));
    UpdateEntryAndScale_0215e2a8(obj);
}
