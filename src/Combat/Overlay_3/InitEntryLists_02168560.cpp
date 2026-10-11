#include <globaldefs.h>
#if defined(jpn)
enum { kRegione4 = 0xe0 };
#else
enum { kRegione4 = 0xe4 };
#endif

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0* obj);
struct Cont0205d228;
void CallFunc0204c8f0OverList0x9c(struct Cont0205d228* obj);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274* obj);
extern "C" void func_0205da88(void* p, int a, int b, int c);
void UpdateEntryPosition_0216acf0(char* base);
extern "C" void func_ov003_0216a880(char* obj);

// JPN: func_ov003_021683e8
// USA: func_ov003_02168560  (semantic: InitEntryLists_02168560)
extern "C" ARM void func_ov003_02168560(char* obj) {
    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(obj + kRegione4));
    CallFunc0204c8f0OverList0x9c((struct Cont0205d228*)(obj + kRegione4));
    func_0205da88(obj + kRegione4, 1, 2, 1);
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)(obj + kRegione4));
    UpdateEntryPosition_0216acf0(obj);
    func_ov003_0216a880(obj);
}
