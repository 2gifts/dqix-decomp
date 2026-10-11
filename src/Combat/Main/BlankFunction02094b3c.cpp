#include <globaldefs.h>

#if defined(jpn)
struct RegionalState02094b3c {
    char pad00[0x3c];
    int firstIndex;
    int secondIndex;
};

extern "C" void _Z21BlankFunction02094b38v(RegionalState02094b3c*, int);
#endif

// USA: func_02094b3c
// JPN: func_02095ac8
extern "C" ARM void _Z21BlankFunction02094b3cv(
#if defined(jpn)
    RegionalState02094b3c* self, int event
#else
    void
#endif
) {
#if defined(jpn)
    switch (event) {
    case 8:
        _Z21BlankFunction02094b38v(self, self->secondIndex);
        break;
    case 10:
        _Z21BlankFunction02094b38v(self, self->firstIndex);
        break;
    case 12:
        _Z21BlankFunction02094b38v(self, self->secondIndex);
        break;
    }
#endif
}
