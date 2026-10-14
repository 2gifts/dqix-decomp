#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);
struct Obj021fb25c;
void SetShorts_021fb25c(Obj021fb25c* obj, unsigned int a, unsigned int b, unsigned int c, int d);

// USA: func_ov004_0216a810  (semantic: SetStatShortsByLanguage_0216a810)
extern "C" ARM int func_ov004_0216a810(void* a) {
    GameState* battle = GameState::GetInstance();
    void* base = func_ov011_021849c8(a);
    struct Obj021fb25c* obj1 = (struct Obj021fb25c*)func_ov023_021f6880(base, 0x1e);
    if (!obj1) return 0;
    if (ScaleStatsIfType12_021f6f10(obj1) != 1) return 0;
    switch (NormalizeField5_0200fb08((struct Struct0200fb08*)battle)) {
        case 1: SetShorts_021fb25c(obj1, 0, 0, 0x58, 0x10); break;
        case 2: SetShorts_021fb25c(obj1, 0, 0, 0x50, 0x10); break;
        case 3: SetShorts_021fb25c(obj1, 0, 0, 0x50, 0x10); break;
        case 4: SetShorts_021fb25c(obj1, 0, 0, 0x60, 0x10); break;
        case 5: SetShorts_021fb25c(obj1, 0, 0, 0x60, 0x10); break;
    }
    struct Obj021fb25c* obj2 = (struct Obj021fb25c*)func_ov023_021f6880(base, 0x1f);
    if (!obj2) return 0;
    if (ScaleStatsIfType12_021f6f10(obj2) != 1) return 0;
    switch (NormalizeField5_0200fb08((struct Struct0200fb08*)battle)) {
        case 1: SetShorts_021fb25c(obj2, 8, 0, 0x58, 0x10); break;
        case 2: SetShorts_021fb25c(obj2, 0x10, 0, 0x50, 0x10); break;
        case 3: SetShorts_021fb25c(obj2, 0x10, 0, 0x50, 0x10); break;
        case 4: SetShorts_021fb25c(obj2, 0, 0, 0x60, 0x10); break;
        case 5: SetShorts_021fb25c(obj2, 0, 0, 0x60, 0x10); break;
    }
    return 0;
}
