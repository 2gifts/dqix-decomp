#include <globaldefs.h>

struct Container0205a3d0;
struct Elem0205a3d0;
#if defined(jpn)
void SetEntryPosition(Container0205a3d0*, int, short, short);
#endif
extern "C" void func_ov003_021703f0(void*, short*, short*);
void SetEntryFlag2ByKey0205a370(Container0205a3d0*, int);
Elem0205a3d0* FindEntryByHalfword0205a3d0(Container0205a3d0*, int);
struct Container0205a330;
void IterateEntries0205a330(Container0205a330*, int);
extern "C" void func_0205ae8c(void*);

// JPN: func_ov003_0216fc08
// USA: func_ov003_0217033c  (semantic: UpdateEntryFlagsAndPosition_0217033c)
extern "C" ARM void func_ov003_0217033c(char* base) {
    Container0205a3d0* cont = *(Container0205a3d0**)(base + 0xa4);
    if (cont == NULL) return;

    short outA, outB;
    func_ov003_021703f0(base, &outA, &outB);

    Elem0205a3d0* e;
    if (outA != 0 && outB != 0) {
        SetEntryFlag2ByKey0205a370(cont, 0);
        e = FindEntryByHalfword0205a3d0(cont, 0);
        if (e != NULL) {
            *(unsigned char*)((char*)e + 0x15) |= 8;
        }
        IterateEntries0205a330((Container0205a330*)cont, 2);
#if defined(jpn)
        SetEntryPosition(cont, 0, outA, outB);
#else
        short a, b;
        b = outB;
        a = outA;
        e = FindEntryByHalfword0205a3d0(cont, 0);
        if (e != NULL) {
            *(short*)((char*)e + 0x4) = a;
            *(short*)((char*)e + 0x6) = b;
        }
#endif
        func_0205ae8c(base + 0x68);
        return;
    }
    e = FindEntryByHalfword0205a3d0(cont, 0);
    if (e != NULL) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }
}
