#include <globaldefs.h>
#if defined(jpn)
enum { kRegion90 = 0x8c };
#else
enum { kRegion90 = 0x90 };
#endif


struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
struct Cont0205d228;
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
void ProcessScaleEntry0217e100(void* obj);

// JPN: func_ov003_0217c6e8
// USA: func_ov003_0217da48  (semantic: ResetBuffersAndProcessScale_0217da48)
extern "C" ARM void func_ov003_0217da48(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    void* sub = *(void**)(o + kRegion90);
    if (sub != 0) {
        signed char tag = *(signed char*)(o + 4);
        if (tag == 2 || *(signed char*)(o + 5) == 0) {
            ClearBuffers0204b010OverList0x98((Cont0205d1e0*)sub);
            CallFunc0204c8f0OverList0x9c((Cont0205d228*)(*(void**)(o + kRegion90)));
            func_0205da88(*(void**)(o + kRegion90), 2, 1, 1);
            CallFunc0204b04cOverList0x98((Cont0205d274*)(*(void**)(o + kRegion90)));
        }
    }
    ProcessScaleEntry0217e100(obj);
}
