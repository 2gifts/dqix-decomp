#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" int func_ov017_021d60f4(void* arg);
GameResources* GetWord0x0(int* obj);

// USA: func_ov001_0215b074
extern "C" ARM int func_ov001_0215b074(int mode, char* args, int count) {
    int brightness;
    int setFlag;
    int duration = func_ov017_021d60f4(args);
    brightness = -16;
    if (count >= 2) {
        brightness = func_ov017_021d60f4(args + 8);
    }
    GameResources* res = GetWord0x0((int*)GameState::GetInstance());
    if (res == NULL) return 0;
    setFlag = 0;
    if (mode == 0) {
        SetBrightness(res, 0, duration);
    } else if (mode == 1) {
        SetBrightness(res, brightness, duration);
    } else if (mode == 2) {
        SetSubBrightness(res, 0, duration);
    } else if (mode == 3) {
        SetSubBrightness(res, brightness, duration);
    } else if (mode == 4) {
        SetMainBrightness(res, 0, duration);
    } else if (mode == 5) {
        SetMainBrightness(res, brightness, duration);
    } else if (mode == 6) {
        SetAndLockBrightness(res, 0, duration);
    } else if (mode == 7) {
        SetAndLockBrightness(res, brightness, duration);
    } else if (mode == 8) {
        SetAndLockSubBrightness(res, 0, duration);
    } else if (mode == 9) {
        SetAndLockSubBrightness(res, brightness, duration);
    } else if (mode == 10) {
        SetAndLockMainBrightness(res, 0, duration);
    } else if (mode == 11) {
        SetAndLockMainBrightness(res, brightness, duration);
    } else if (mode == 12) {
        UnlockAndSetBrightness(res, 0, duration);
    } else if (mode == 13) {
        UnlockAndSetBrightness(res, brightness, duration);
    } else if (mode == 14) {
        UnlockAndSetSubBrightness(res, 0, duration);
    } else if (mode == 15) {
        UnlockAndSetSubBrightness(res, brightness, duration);
    } else if (mode == 16) {
        UnlockAndSetMainBrightness(res, 0, duration);
    } else if (mode == 17) {
        UnlockAndSetMainBrightness(res, brightness, duration);
    }
    int isOdd = (mode % 2 == 1);
    if (mode % 6 < 4 && isOdd) {
        setFlag = 1;
    }
    char* work = (char*)func_ov017_0218b5b0()->unknown_ptr_array_371c[6];
    if (setFlag) {
        if (*(unsigned short*)(work + 0xa) <= 3) {
            work[0x102] = 1;
        }
    }
    return 1;
}
