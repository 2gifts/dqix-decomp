#include <globaldefs.h>

void InitModule020c9288();

struct ClearFields0And8And0x20Struct;
void ClearFields0And8And0x20_020c93bc(struct ClearFields0And8And0x20Struct* p);

extern "C" void func_020dbc0c(void);
extern "C" void func_020c93d0(void*, int, int, void*, void*);

// USA: func_020db228
ARM void InitSubstructAndRegisterHandler0x14_020db228(void* obj) {
    InitModule020c9288();
    struct ClearFields0And8And0x20Struct* sub = (struct ClearFields0And8And0x20Struct*)((char*)obj + 0x14);
    ClearFields0And8And0x20_020c93bc(sub);
    func_020c93d0(sub, 0xe1, 0x1e, (void*)func_020dbc0c, obj);
}
