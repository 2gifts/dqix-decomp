#include <globaldefs.h>

#if defined(jpn)
#define func_020e0f74 func_020e2b6c
#endif

#include "GameState/GameState.h"
#include "System/Graphics.h"

struct FlagWord02046708;

void *GetData02105254();
extern "C" void *func_02012fe4();
void *GetDataPtr02114e04_020d6c00();
int TestFlags02046708(FlagWord02046708 *flags, unsigned int mask);
extern "C" void *func_0202ae18();
int CheckField0NonZero(int *value);
void SetElementFields0202756c(void *receiver, int x, int y, int index, unsigned char field5, unsigned char field6,
                              unsigned short field7, unsigned char field8, int scaleX, int scaleY);

struct CombatMarkerReceiverView {
#if defined(jpn)
    unsigned char unknown0[0x6b9];
#else
    unsigned char unknown0[0x765];
#endif
    unsigned char markerElementsEnabled;
    unsigned short markerValue;
    unsigned char extendedDisplayMode;
};

#if defined(jpn)
enum { kSecondMarkerId = 0x2b, kThirdMarkerId = 0x38, kFourthMarkerId = 0x3b, kThirdX = 161, kThirdY = 20, kFourthY = 159 };
#else
enum { kSecondMarkerId = 0x26, kThirdMarkerId = 0x33, kFourthMarkerId = 0x41, kThirdX = 5, kThirdY = 30, kFourthY = 129 };
#endif

// USA: func_020e0f74
extern "C" ARM void func_020e0f74(void *receiver) {
    CombatMarkerReceiverView *state = static_cast<CombatMarkerReceiverView *>(receiver);
    GameState::GetInstance();
    GetData02105254();
    func_02012fe4();
    if (TestFlags02046708(static_cast<FlagWord02046708 *>(GetDataPtr02114e04_020d6c00()), 0x41)) {
        return;
    }

    if (state->extendedDisplayMode) {
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1300;
    } else {
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x200;
    }
    if (!state->markerElementsEnabled) {
        return;
    }

    int *value = static_cast<int *>(func_0202ae18());
    int x      = 5;
    if (CheckField0NonZero(value)) {
        x += 14;
    }
    SetElementFields0202756c(receiver, x << 12, 5 << 12, 0, 0x1f, 1, 0xff, 0xff, 0x1000, 0x1000);
    SetElementFields0202756c(receiver, 106 << 12, 130 << 12, 1, kSecondMarkerId, 1, 0xff, 0xff, 0x1000, 0x1000);

    if (state->markerValue < 1000 && state->markerValue != 0) {
        int y = kThirdY;
        if (CheckField0NonZero(value)) {
            y += 11;
        }
        SetElementFields0202756c(receiver, kThirdX << 12, y << 12, 2, kThirdMarkerId, 1, 0xff, 0xff, 0x1000, 0x1000);
    }
    SetElementFields0202756c(receiver, 0, kFourthY << 12, 3, kFourthMarkerId, 1, 0xff, 0xff, 0x1000, 0x1000);
}
