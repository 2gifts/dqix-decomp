#include <globaldefs.h>

struct CombatWork021e6340 {
    char pad[0x6f04];
    unsigned short id;
};

struct Obj021e6340 {
    char pad[0x8];
    unsigned short id;
};

extern int data_02108760;
CombatWork021e6340* GetActiveCombatWork(void);
void DispatchIfField0xc4NonNeg_0205ebfc(void* obj, int a, int b);

// USA: func_ov025_021e6340  (semantic: Trans_021e6340)
extern "C" ARM int func_ov025_021e6340(struct Obj021e6340* obj) {
    GetActiveCombatWork()->id = obj->id;
    DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, obj->id, 0);
    return 1;
}
