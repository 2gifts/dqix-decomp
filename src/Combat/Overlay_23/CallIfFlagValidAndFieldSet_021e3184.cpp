#include <globaldefs.h>
#if defined(jpn)
#define func_ov023_021e3184 func_ov023_021e34dc
#endif

struct EquipmentMenu;
struct EquipmentMenuHost {
    EquipmentMenu* equipmentMenu;
#if defined(jpn)
    char unknown004[0x4e2 - 4];
#else
    char unknown004[0x4e6 - 4];
#endif
    signed char state;
};

void RunTurnStartHooks02155108(void* menu);

// USA: func_ov023_021e3184
extern "C" ARM void func_ov023_021e3184(EquipmentMenuHost* host) {
    if (host->state == 0) return;
    if (host->state == -1) return;
    EquipmentMenu* menu = host->equipmentMenu;
    if (menu == NULL) return;
    RunTurnStartHooks02155108(menu);
}
