#include <globaldefs.h>

#if defined(jpn)
enum { kSecondFadeOffset = 0x484 };
#else
enum { kSecondFadeOffset = 0x4f4 };
#endif

void EncodeSignFlaggedHalfword_020c39a0(short* out, int value);
int GetSignedField020c39c8(volatile unsigned short* p);

struct MasterBrightnessFade {
    float currentBrightness;
    int targetBrightness;
    int remainingMilliseconds;
};

struct FieldGroup4f4_0218d800 {
    char unknown0[kSecondFadeOffset];
    MasterBrightnessFade subFade;
};

// USA: func_ov020_0218d800
ARM void UpdateFieldGroup4f4_0218d800(struct FieldGroup4f4_0218d800* display, int targetBrightness, int durationMilliseconds) {
    if (durationMilliseconds == 0) {
        EncodeSignFlaggedHalfword_020c39a0((short*)0x400106c, targetBrightness);
        display->subFade.currentBrightness = (float)targetBrightness;
        display->subFade.targetBrightness = targetBrightness;
        display->subFade.remainingMilliseconds = 0;
    } else {
        int currentBrightness = GetSignedField020c39c8((volatile unsigned short*)0x400106c);
        display->subFade.currentBrightness = (float)currentBrightness;
        display->subFade.targetBrightness = targetBrightness;
        display->subFade.remainingMilliseconds = durationMilliseconds;
    }
}
