#include <globaldefs.h>

// USA: func_02012390
ARM int IsFlag0x20Set_02012390(unsigned short* flags) { return (*flags & 0x20) != 0; }

// USA: func_020123a4
ARM int IsFlag0x10Set_020123a4(unsigned short* flags) { return (*flags & 0x10) != 0; }

// USA: func_020123b8
ARM int IsFlag0x40Set_020123b8(unsigned short* flags) { return (*flags & 0x40) != 0; }

// USA: func_020123cc
ARM int IsFlag0x80Set_020123cc(unsigned short* flags) { return (*flags & 0x80) != 0; }

// USA: func_020123e0
ARM int IsFlag0x1Set_020123e0(unsigned short* flags) { return (*flags & 0x1) != 0; }

// USA: func_020123f4
ARM int IsFlag0x2Set_020123f4(unsigned short* flags) { return (*flags & 0x2) != 0; }

// USA: func_02012408
ARM int IsFlag0x400Set_02012408(unsigned short* flags) { return (*flags & 0x400) != 0; }

// USA: func_0201241c
ARM int IsFlag0x800Set_0201241c(unsigned short* flags) { return (*flags & 0x800) != 0; }
