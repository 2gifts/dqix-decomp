#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct HabitatTable {
    char unk_0[0x14];
    short monsterID_;
    short state_;
    int taskID_;
    SafeAllocator* allocator_;
};

extern "C" bool _Z20ResetHandle_02188d10P20HandleState_02188d10(HabitatTable* s);
extern "C" bool _Z24InitHandleState_02188bd0P20HandleState_02188bd0(HabitatTable* s);
extern "C" bool func_ov014_02188c34(HabitatTable* habitats);

// USA: func_ov014_02188bfc  (semantic: Trans_02188bfc)
extern "C" ARM bool func_ov014_02188bfc(HabitatTable* habitats, SafeAllocator* allocator, short monsterID) {
    _Z20ResetHandle_02188d10P20HandleState_02188d10(habitats);
    _Z24InitHandleState_02188bd0P20HandleState_02188bd0(habitats);
    habitats->monsterID_ = monsterID;
    habitats->allocator_ = allocator;
    habitats->state_ = 1;
    return func_ov014_02188c34(habitats);
}
