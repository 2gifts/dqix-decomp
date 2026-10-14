#include <globaldefs.h>

struct RebaseStruct {
    char pad[8];
    char* off8;
    char* offc;
};

// USA: func_02042998
ARM void RebaseOffsets_02042998(struct RebaseStruct* p) {
    if (p != 0) {
        p->off8 = (char*)p + (int)p->off8;
        p->offc = (char*)p + (int)p->offc;
    }
}
