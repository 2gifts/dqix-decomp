#include <globaldefs.h>

struct EquipmentMenu;

// USA: func_ov005_02155670
extern "C" ARM int func_ov005_02155670(EquipmentMenu* self, int x, int y) {
    for (int i = 0; i < 16; i++) {
        int left = (i % 4) * 26 + 0x8d;
        int top = (i / 4) * 26 + 0x34;
        int right = left + 0x18;
        int bottom = top + 0x18;
        if (x >= left && y >= top && x <= right && y <= bottom)
            return i + 8;
    }
    return -1;
}
