#include <globaldefs.h>

#include "System/VRAM.h"

// USA: func_020937f0
extern "C" ARM int func_020937f0(int engine) {
    int kilobytes = 0;
    if (engine == 0) {
        switch (GetMainObjVRAMBanks()) {
            case 0: kilobytes = 0; break;
            case VRAM_BANK_F:
            case VRAM_BANK_G: kilobytes = 16; break;
            case VRAM_BANK_E: kilobytes = 64; break;
            case VRAM_BANK_E | VRAM_BANK_F:
            case VRAM_BANK_E | VRAM_BANK_G: kilobytes = 80; break;
            case VRAM_BANK_A:
            case VRAM_BANK_B: kilobytes = 128; break;
            case VRAM_BANK_A | VRAM_BANK_B: kilobytes = 256; break;
            case VRAM_BANK_F | VRAM_BANK_G: kilobytes = 32; break;
            case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G: kilobytes = 96; break;
        }
    } else {
        switch (GetSubObjVRAMBanks()) {
            case 0: break;
            case VRAM_BANK_D: kilobytes = 128; break;
            case VRAM_BANK_I: kilobytes = 16; break;
        }
    }
    return kilobytes << 10;
}
