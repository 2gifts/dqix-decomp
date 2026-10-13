#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e3134 func_ov023_021e348c
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

extern "C" void func_ov023_021e3fc0(void* panel);
extern "C" void func_ov023_021e4264(void* panel);
extern "C" void func_ov023_021e4358(void* panel);
extern "C" void func_ov023_021e43f0(void* panel);
extern "C" void func_ov005_02154ef0(EquipmentMenu* menu);

// USA: func_ov023_021e3134
extern "C" ARM void func_ov023_021e3134(EquipmentMenuHost* host) {
    if (host->state == 0) return;
    if (host->state == -1) return;
    func_ov023_021e3fc0(host);
    func_ov023_021e4264(host);
    func_ov023_021e4358(host);
    func_ov023_021e43f0(host);
    EquipmentMenu* menu = host->equipmentMenu;
    if (menu == NULL) return;
    func_ov005_02154ef0(menu);
}
