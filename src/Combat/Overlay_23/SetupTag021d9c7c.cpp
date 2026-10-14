#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"

int GetFieldByKey020e0434(Container020e0310*, int);
struct Ctx0205d304;
extern "C" void func_0205d304(Ctx0205d304* renderer, const char* text, int mode,
                            unsigned char border, unsigned char flagBit3,
                            unsigned char fullWidth, void* extraStyle
#if !defined(jpn)
                            , unsigned char font
#endif
);

// USA: 021d9c7c; JPN: 021da52c.
ARM void SetupTag021d9c7c(void* objRaw) {
    CharacterCreationUI* self = (CharacterCreationUI*)objRaw;
#if defined(jpn)
    self->windows[1].layout[0] = 0xd;
    self->windows[1].layout[1] = 2;
    self->windows[1].layout[2] = 2;
    self->windows[1].layout[3] = 0x13;
    self->windows[1].layout[4] = 2;
    self->windows[1].layout[5] = 2;
    self->windows[1].layout[6] = 0xa;
    self->windows[1].layout[7] = 0xc;
    self->windows[1].nextWindow = 2;
    self->windows[1].fontHeight = 0xa;
    self->windows[1].flags = 1;
    self->windows[1].noHorizontalInset = 1;
    memset(self->textBuffer, 0, 0x800);
    int fmt = GetFieldByKey020e0434(&self->texts, 0x4274);
    sprintf(self->textBuffer, (const char*)fmt);
    func_0205d304((Ctx0205d304*)&self->windows[1], self->textBuffer, 0, 0, 0, 1, 0);
#else
    CreationWindow* tag = &self->windows[1];
    tag->layout[0] = 0xd;
    tag->layout[1] = 2;
    tag->layout[2] = 2;
    tag->layout[3] = 0x13;
    tag->layout[4] = 2;
    tag->layout[5] = 2;
    tag->layout[6] = 0xa;
    tag->layout[7] = 0xc;
    tag->nextWindow = 2;
    tag->fontHeight = 0xa;
    tag->flags = 1;
    tag->noHorizontalInset = 1;
    char* buf = self->textBuffer;
    memset(buf, 0, 0x960);
    int fmt = GetFieldByKey020e0434(&self->texts, 0x4274);
    sprintf(buf, (const char*)fmt);
    func_0205d304((Ctx0205d304*)tag, buf, 0, 0, 0, 1, 0, 0);
#endif
}
