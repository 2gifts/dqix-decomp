#if defined(jpn)
#define R(j,u) (j)
#define func_0205c96c func_0205dcd4
#define func_ov013_02186cac func_ov013_02187fc0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Resource/Brightness.h"
#include "System/OverlayId.h"

extern "C" GameResources* func_ov017_0218b5b0();
extern "C" void func_020a1940(unsigned int id);
extern "C" void func_ov008_021843f8(void* obj);
extern "C" void func_ov008_021842a0(void* obj, void* arg);
extern "C" void _Z30SetByteB10AndClearB11_02184a3cPch(char* obj, unsigned char value);
void OrGlobalFlag0x40();

struct Manager0218af80 {
    char pad0[0x228];
    char f228[0x288 - 0x228];
    char f288[0x2a8 - 0x288];
    char f2a8[0xdcc - 0x2a8];
    int dcc;
    char pad1[R(0xdd4 - 0xdd0, 0xdd8 - 0xdd0)];
    char* dd8;
    char* ddc;
    char pad2[0xde4 - 0xde0];
    char* de4;
    char pad3[0xdf6 - 0xde8];
    char df6[0xe04 - 0xdf6];
    char e04[0xe9b - 0xe04];
    unsigned char e9b;
    signed char e9c;
    char pad4[R(0xeb4 - 0xe99, 0xebc - 0xe9d)];
    char* ebc;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char rest : 5;
};

// USA: func_ov008_0218af80
extern "C" ARM void func_ov008_0218af80(Manager0218af80* self) {
    GameResources* res = func_ov017_0218b5b0();
    if (self->e9c == 0 && self->bit1 && !IsBrightnessTransitionActive(res)) {
        func_020a1940(OVERLAY_ID(8));
        func_ov008_021843f8(self->f2a8);
        self->dcc = 1;
        func_ov008_021842a0(self->f2a8, self->f228);
        _Z30SetByteB10AndClearB11_02184a3cPch(self->f2a8, 1);
        self->de4 = self->f288;
        char* first = self->ebc;
        char* second;
        if (first == NULL) {
            first = self->df6;
            second = self->e04;
        } else {
            second = first + 0x38;
        }
        self->dd8 = first;
        self->ddc = second;
        self->e9c = self->e9c + 1;
        return;
    }
    if (self->e9c == 1 && self->bit1 && self->bit2) {
        OrGlobalFlag0x40();
        SetSubBrightness(res, -16, 15);
        self->e9b = 1;
        self->e9c = 0;
    }
}
