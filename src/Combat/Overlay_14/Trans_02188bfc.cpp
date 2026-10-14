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

struct HandleState_02188d10;
bool ResetHandle_02188d10(HandleState_02188d10*);
struct HandleState_02188bd0;
bool InitHandleState_02188bd0(HandleState_02188bd0*);
extern "C" bool func_ov014_02188c34(HabitatTable* habitats);

// USA: func_ov014_02188bfc  (semantic: Trans_02188bfc)
extern "C" ARM bool func_ov014_02188bfc(HabitatTable* habitats, SafeAllocator* allocator, short monsterID) {
    ResetHandle_02188d10((HandleState_02188d10*)habitats);
    InitHandleState_02188bd0((HandleState_02188bd0*)habitats);
    habitats->monsterID_ = monsterID;
    habitats->allocator_ = allocator;
    habitats->state_ = 1;
    return func_ov014_02188c34(habitats);
}
