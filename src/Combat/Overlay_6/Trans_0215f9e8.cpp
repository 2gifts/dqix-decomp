#include <globaldefs.h>

#if defined(jpn)
enum { kMenuPointerOffset = 0xc };
#else
enum { kMenuPointerOffset = 0x14 };
#endif

struct Container02080fa8;
struct MenuEntryUpdate {
    unsigned char unknown[kMenuPointerOffset];
    Container02080fa8* menu;
    unsigned char unknownAfterMenu[0x36e - kMenuPointerOffset - 4];
    unsigned short group;
    unsigned char unknownAfterGroup[0x38b - 0x370];
    unsigned char value;
};

extern "C" void _Z26SetEntryFirstField02080fa8P17Container02080fa8ii(Container02080fa8*, int, int);
extern "C" int func_020813ec(void*, int);

// USA: func_ov006_0215f9e8
extern "C" ARM void func_ov006_0215f9e8(MenuEntryUpdate* self) {
    _Z26SetEntryFirstField02080fa8P17Container02080fa8ii(self->menu, 0x3d, self->value);
    func_020813ec(self->menu, 10);
    self->group = 10;
}
