#include <globaldefs.h>

#if defined(jpn)
struct RegionalState02094b44 {
    void* firstTable;
    void* secondTable;
    char pad08[0x34];
    int firstIndex;
    int secondIndex;
};
#endif

// USA: func_02094b44
// JPN: func_02095b40
extern "C" ARM void* _Z19AlwaysFalse02094b44v(
#if defined(jpn)
    RegionalState02094b44* self, int event
#else
    void
#endif
) {
    void* table = 0;
#if defined(jpn)
    switch (event) {
    case 8:
        if (self->secondIndex >= 0) table = self->secondTable;
        break;
    case 10:
        if (self->firstIndex >= 0) table = self->firstTable;
        break;
    case 12:
        if (self->secondIndex >= 0) table = self->secondTable;
        break;
    }
#endif
    return table;
}
