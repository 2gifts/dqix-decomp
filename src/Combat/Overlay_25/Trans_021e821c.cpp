#include <globaldefs.h>

extern "C" void* _Z19GetActiveCombatWorkv();
extern "C" void _Z20SetShortTriple0x6e44Pvttt(void* obj, short a, unsigned short b, unsigned short c);

struct Trans021e821cArg {
    char pad[8];
    short a;
    unsigned short b;
    unsigned short c;

    short GetA() const { return a; }
    unsigned short GetB() const { return b; }
    unsigned short GetC() const { return c; }
};

// USA: func_ov025_021e821c  (semantic: Trans_021e821c)
extern "C" ARM int func_ov025_021e821c(Trans021e821cArg* arg) {
    short a = arg->GetA();
    unsigned short b = arg->GetB();
    unsigned short c = arg->GetC();
    _Z20SetShortTriple0x6e44Pvttt(_Z19GetActiveCombatWorkv(), a, b, c);
    return 1;
}
