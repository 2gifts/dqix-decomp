#include <globaldefs.h>
#include "GameState/GameState.h"

struct Stat021570a4 { char pad[0x5c]; short field5c; };
extern "C" Stat021570a4* func_ov004_02156ed0(void* obj, int key);

// USA: func_ov004_021570a4
ARM void* GetEntryFor_021570a4(void* obj, int index) {
#if defined(jpn)
    enum { fieldOffset = 0xc };
#else
    enum { fieldOffset = 0x26c };
#endif
    if ((unsigned)index >= 6) return NULL;
    char* base = (char*)GameState::GetInstance() + fieldOffset + 0x5c00;
    Stat021570a4* stat = func_ov004_02156ed0(obj, 0x5b);
    int mult = stat->field5c * 6 + index;
    return (base + 4) + mult * 0x28;
}
