#include <globaldefs.h>

struct EquipmentMenu;

// USA: func_ov005_021553b4
extern "C" ARM void func_ov005_021553b4(EquipmentMenu* self, int slot, int* x, int* y) {
    if (slot >= 0 && slot < 8) {
        *x = 0x85;
        *y = 0x17;
        return;
    }
    if (slot >= 8 && slot < 24) {
        int i = slot - 8;
        *x = (i % 4) * 26 + 0x8d;
        *y = (i / 4) * 26 + 0x34;
        return;
    }
}
