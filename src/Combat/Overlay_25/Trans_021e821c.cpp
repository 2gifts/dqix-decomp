#include <globaldefs.h>

void* GetActiveCombatWork_ov000_02160130();
void SetShortTriple0x6e44_ov000_02163440(void*, short, unsigned short, unsigned short);

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
    SetShortTriple0x6e44_ov000_02163440(GetActiveCombatWork_ov000_02160130(), a, b, c);
    return 1;
}
