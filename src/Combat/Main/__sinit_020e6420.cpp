#include <globaldefs.h>
#include "System/OverlayId.h"

#pragma define_section initcode ".init" RX

extern "C" void func_0200ee94(void* obj, int count, int size, void* cb1, void* cb2);
char* Fill6BytesWithFFAndReturn(char* p);

extern char data_01ffd364[8][6];

struct OverlayRowTable {
    unsigned char pad_00[0x22];
    unsigned char f22;
    unsigned char f23;
    unsigned char f24;
    unsigned char f25;
    unsigned char f26;
    unsigned char f27;
    unsigned char f28;
    unsigned char pad_29[0x0e];
    unsigned char f37;
    unsigned char f38;
    unsigned char f39;
    unsigned char f3a;
    unsigned char f3b;
    unsigned char f3c;
    unsigned char f3d;
};

extern struct OverlayRowTable data_020f1940;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020e6420
extern "C" __declspec(initcode) ARM void __sinit_020e6420(void) {
    func_0200ee94(data_01ffd364, 8, 6, (void*)Fill6BytesWithFFAndReturn, 0);
    data_020f1940.f22 = OVERLAY_ID(0);
    data_020f1940.f23 = OVERLAY_ID(1);
    data_020f1940.f24 = OVERLAY_ID(2);
    data_020f1940.f25 = OVERLAY_ID(3);
    data_020f1940.f26 = OVERLAY_ID(4);
    data_020f1940.f27 = OVERLAY_ID(5);
    data_020f1940.f28 = OVERLAY_ID(6);
    data_020f1940.f37 = OVERLAY_ID(22);
    data_020f1940.f38 = OVERLAY_ID(23);
    data_020f1940.f39 = OVERLAY_ID(24);
    data_020f1940.f3a = OVERLAY_ID(26);
    data_020f1940.f3b = OVERLAY_ID(25);
    data_020f1940.f3c = OVERLAY_ID(28);
    data_020f1940.f3d = OVERLAY_ID(27);
}
