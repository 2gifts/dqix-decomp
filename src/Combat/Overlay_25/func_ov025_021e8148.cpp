#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02057924(void);
extern "C" int _Z23DispatchByIndex021820bcPviii(void* obj, int unused, int index, int arg);
extern "C" void* _Z28GetSlotPtr_021e8cf0_021e8cf0Pci(char* base, int idx);
extern "C" short _Z24ClampScaledStat_0216352ciff(int id, float a, float b);

struct Globals021ef988 {
    char pad0[0xc];
    char* slotTable;
};
extern Globals021ef988 data_ov025_021ef988;

struct Param021e8148 {
    char pad0[8];
    int index;
    unsigned short slot;
    unsigned char mode;
};

// USA: func_ov025_021e8148
extern "C" ARM int func_ov025_021e8148(Param021e8148* p, int b, int unused, void* c) {
    GameState* gs = GameState::GetInstance();
    void* g = func_02057924();
    if (gs == NULL || g == NULL) {
        return 0;
    }
    int ids[8];
    if (_Z23DispatchByIndex021820bcPviii(c, b, p->index, (int)ids) != 1) {
        return 0;
    }
    void* slot = _Z28GetSlotPtr_021e8cf0_021e8cf0Pci(data_ov025_021ef988.slotTable, p->slot);
    if (slot == NULL) {
        return 0;
    }
    GameObject* obj = gs->GetGameObjectByIndex(*(int*)slot);
    if (obj == NULL) {
        return 0;
    }
    fix32_t scale = 0x10a;
    switch (p->mode) {
    case 0:
        break;
    case 1:
        scale = _Z24ClampScaledStat_0216352ciff(ids[0], 1.0f, 0.5f);
        break;
    }
    obj->obj3D_.SetScale(scale, scale, scale);
    return 1;
}
