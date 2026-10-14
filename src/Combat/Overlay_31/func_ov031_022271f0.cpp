#include <globaldefs.h>
#include "System/Graphics.h"
#include "System/VRAM.h"
#include "System/ColorEffects.h"

#define REG_MASTER_BRIGHTNESS (*(volatile short*)0x0400006c)
#define REG_MASTER_BRIGHTNESS_SUB (*(volatile short*)0x0400106c)
#define REG_BG0_SCROLL (*(volatile unsigned int*)0x04000010)
#define REG_BG1_SCROLL (*(volatile unsigned int*)0x04000014)
#define REG_BG2_SCROLL (*(volatile unsigned int*)0x04000018)
#define REG_BG3_SCROLL (*(volatile unsigned int*)0x0400001c)
#define REG_BG0_SCROLL_SUB (*(volatile unsigned int*)0x04001010)
#define REG_BG1_SCROLL_SUB (*(volatile unsigned int*)0x04001014)
#define REG_BG2_SCROLL_SUB (*(volatile unsigned int*)0x04001018)
#define REG_BG3_SCROLL_SUB (*(volatile unsigned int*)0x0400101c)
#define REG_POWER_CONTROL (*(volatile unsigned short*)0x04000304)

void SetVBlankIrqEnable_020c3864(int);
void SetDispcntModeAndFlags020c391c(int, int, int);
void EncodeSignFlaggedHalfword_020c39a0(short*, int);
void SetSubBgMode_020c3984(unsigned int);
void RestoreDisplayMode_020c38d4();
extern "C" void func_ov031_0223c308();
extern "C" void func_ov031_0223d928();
extern "C" void func_ov031_0223dabc();
extern "C" void func_ov031_0223b79c();

static inline unsigned int SubDisplayWithClearedLayers(unsigned int mask) {
    return DISPCNTSUB & ~mask;
}

// USA: func_ov031_022271f0
extern "C" ARM void func_ov031_022271f0() {
    SetVBlankIrqEnable_020c3864(0);
    MapVRAMBanksToMainBG(1);
    MapVRAMBanksToMainObj(2);
    SetDispcntModeAndFlags020c391c(1, 0, 0);
    DISPCNT &= ~0x1f00;
    DISPCNT &= ~0xe000;
    EncodeSignFlaggedHalfword_020c39a0((short*)&REG_MASTER_BRIGHTNESS, 0);
    DISPCNT = (DISPCNT & 0xffcfffef) | 0x200010;
    BG0CNT &= ~0x40;
    BG1CNT &= ~0x40;
    BG2CNT &= ~0x40;
    BG3CNT &= ~0x40;
    REG_BG0_SCROLL = 0;
    REG_BG1_SCROLL = 0;
    REG_BG2_SCROLL = 0;
    REG_BG3_SCROLL = 0;
    ColorEffect_ConfigureBrightnessAdjust(0x04000050, 0x3f, 0x10);
    MapVRAMBanksToSubBG(0x80);
    MapVRAMBanksToSubObj(0x100);
    SetSubBgMode_020c3984(0);
    DISPCNTSUB = SubDisplayWithClearedLayers(0x1f00);
    DISPCNTSUB = SubDisplayWithClearedLayers(0xe000);
    EncodeSignFlaggedHalfword_020c39a0((short*)&REG_MASTER_BRIGHTNESS_SUB, 0);
    DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
    BG0CNTSUB &= ~0x40;
    BG1CNTSUB &= ~0x40;
    BG2CNTSUB &= ~0x40;
    BG3CNTSUB &= ~0x40;
    REG_BG0_SCROLL_SUB = 0;
    REG_BG1_SCROLL_SUB = 0;
    REG_BG2_SCROLL_SUB = 0;
    REG_BG3_SCROLL_SUB = 0;
    ColorEffect_ConfigureBrightnessAdjust(0x04001050, 0x3f, 0x10);
    BG0CNT = (BG0CNT & 0x43) | 0xc00;
    BG1CNT = (BG1CNT & 0x43) | 0xd08;
    BG2CNT = (BG2CNT & 0x43) | 0xe10;
    BG3CNT = (BG3CNT & 0x43) | 0xf10;
    BG0CNTSUB = (BG0CNTSUB & 0x43) | 0xc00;
    BG1CNTSUB = (BG1CNTSUB & 0x43) | 0xd00;
    BG2CNTSUB = (BG2CNTSUB & 0x43) | 0xe00;
    BG3CNTSUB = (BG3CNTSUB & 0x43) | 0xf00;
    DISPCNT &= ~0x38000000;
    DISPCNT &= ~0x07000000;
    REG_POWER_CONTROL &= ~0x8000;
    func_ov031_0223c308();
    func_ov031_0223d928();
    func_ov031_0223dabc();
    func_ov031_0223b79c();
    RestoreDisplayMode_020c38d4();
    DISPCNTSUB |= 0x10000;
    SetVBlankIrqEnable_020c3864(1);
}
