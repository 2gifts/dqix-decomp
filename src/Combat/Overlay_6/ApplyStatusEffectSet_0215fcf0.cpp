// USA: func_ov006_0215fcf0
// JPN: func_ov006_02161064
#include <globaldefs.h>

struct StatusOwner02081164;
struct Obj2081;
extern void SetEntryHalfword0xe(void*, int, int);
extern void SetSublistEntryField14LowBits_02080798(void*, int, int);
extern void SetEntryFlag0x2ByShortId(StatusOwner02081164*, int, int);
extern "C" int func_020813ec(void*, int);
extern void SetEntryLowNibbleAndElement02080c68(void*, int, int);
extern void ClearElementFlag0x20(Obj2081*, int);

struct Obj0215fcf0 {
#if defined(jpn)
    unsigned char unknown[0xc];
    void* menu;
    unsigned char unknownAfterMenu[0x386 - 0x10];
#else
    unsigned char unknown[0x14];
    void* menu;
    unsigned char unknownAfterMenu[0x386 - 0x18];
#endif
    unsigned char sortMode;
};

extern "C" ARM void func_ov006_0215fcf0(Obj0215fcf0* owner) {
    void* menu = owner->menu;
    int textKey = (short)(owner->sortMode + 0x29);
    SetEntryHalfword0xe(menu, 0x5a, textKey);
#if !defined(jpn)
    SetSublistEntryField14LowBits_02080798(menu, 0x5a, 1);
#endif
    SetEntryFlag0x2ByShortId((StatusOwner02081164*)menu, 0xf, 1);
    func_020813ec(menu, 0xf);
    SetEntryLowNibbleAndElement02080c68(menu, 0xf, 2);
    ClearElementFlag0x20((Obj2081*)menu, 0xf);
}
