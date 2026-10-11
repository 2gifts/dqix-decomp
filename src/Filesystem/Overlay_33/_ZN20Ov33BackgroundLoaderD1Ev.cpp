#include <globaldefs.h>
#include "Filesystem/Overlay_33/Ov33BackgroundLoader.h"

extern "C" int _ZTV16BackgroundLoader[];

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag. Defined under
// extern "C" because an out-of-line ~Ov33BackgroundLoader makes mwccarm emit THREE symbols
// (_ZN20Ov33BackgroundLoaderD0Ev + D1 + D2 = 0x28 + 0x20 + 0x20 = 0x68 bytes); the ROM has
// exactly one, D1, 0x20 bytes. Same convention as the sibling _ZN20Ov33BackgroundLoaderC1Ev.
// USA: func_ov033_022a2998
extern "C" ARM Ov33BackgroundLoader* _ZN20Ov33BackgroundLoaderD1Ev(Ov33BackgroundLoader* self)
{
    // destructor prologue: vptr -> BackgroundLoader's vtable address point, then the body,
    // then ~BackgroundLoader() { InitializeOrReset(); }.
    *(int**)self = &_ZTV16BackgroundLoader[2];
    self->InitializeOrReset();
    return self;
}