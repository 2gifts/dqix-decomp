#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

int* GetWord0x0(int*);
struct GameResources;
int IsBrightnessTransitionActive(GameResources*);
void OrGlobalFlag0x40();

#define REG_DISPCNT_SUB (*(volatile unsigned int*)0x04001000)
#define REG_BG0CNT_SUB (*(volatile unsigned short*)0x04001008)
#define REG_BG1CNT_SUB (*(volatile unsigned short*)0x0400100a)
#define REG_BG2CNT_SUB (*(volatile unsigned short*)0x0400100c)
#define REG_BG3CNT_SUB (*(volatile unsigned short*)0x0400100e)

// USA: func_ov008_0218599c
extern "C" ARM void func_ov008_0218599c(void* obj) {
    int* word = GetWord0x0((int*)GameState::GetInstance());
    BackgroundLoader::GetInstance();
    unsigned char flag = *((unsigned char*)obj + 0xb11);
    if (flag == 0) {
        if (IsBrightnessTransitionActive((GameResources*)word) == 0) {
            *((unsigned char*)obj + 0xb11) = *((unsigned char*)obj + 0xb11) + 1;
        }
    }
    if (flag != 1) {
        return;
    }
    OrGlobalFlag0x40();

    REG_BG0CNT_SUB = (REG_BG0CNT_SUB & 0x43) | 0x600;
    REG_BG1CNT_SUB = (REG_BG1CNT_SUB & 0x43) | 0x304 | 0x400;
    REG_BG0CNT_SUB = (REG_BG0CNT_SUB & ~3) | 2;
    REG_BG1CNT_SUB = (REG_BG1CNT_SUB & ~3) | 3;
    REG_BG2CNT_SUB = (REG_BG2CNT_SUB & ~3) | 1;
    REG_BG3CNT_SUB = (REG_BG3CNT_SUB & ~3);
    REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1300;

    *((unsigned char*)obj + 0xb10) = 0;
    *((unsigned char*)obj + 0xb11) = 0;
}
