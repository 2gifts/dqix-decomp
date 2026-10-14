#include <globaldefs.h>

#if defined(jpn)
enum { kFirstFadeOffset = 0x478 };
#else
enum { kFirstFadeOffset = 0x4e8 };
#endif

void EncodeSignFlaggedHalfword_020c39a0(short* out, int value);
int GetSignedField020c39c8(volatile unsigned short* p);

struct MasterBrightnessFade {
    float currentBrightness;
    int targetBrightness;
    int remainingMilliseconds;
};

struct FieldGroup4e8_0218d7ac {
    char unknown0[kFirstFadeOffset];
    MasterBrightnessFade mainFade;
};

// USA: func_ov020_0218d7ac
ARM void UpdateFieldGroup4e8_0218d7ac(struct FieldGroup4e8_0218d7ac* display, int targetBrightness, int durationMilliseconds) {
    if (durationMilliseconds == 0) {
        EncodeSignFlaggedHalfword_020c39a0((short*)0x400006c, targetBrightness);
        display->mainFade.currentBrightness = (float)targetBrightness;
        display->mainFade.targetBrightness = targetBrightness;
        display->mainFade.remainingMilliseconds = 0;
    } else {
        int currentBrightness = GetSignedField020c39c8((volatile unsigned short*)0x400006c);
        display->mainFade.currentBrightness = (float)currentBrightness;
        display->mainFade.targetBrightness = targetBrightness;
        display->mainFade.remainingMilliseconds = durationMilliseconds;
    }
}
