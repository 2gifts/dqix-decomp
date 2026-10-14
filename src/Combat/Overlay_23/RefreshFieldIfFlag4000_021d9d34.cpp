#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"
#include "Combat/TryApplyElemFields.h"

int GetFieldByKey020e0434(Container020e0310*, int);
int AppendString02042058(char*, const char*);

// USA: 021d9d34; JPN: 021da5d8.
ARM void RefreshFieldIfFlag4000_021d9d34(char* obj) {
    CharacterCreationUI* self = (CharacterCreationUI*)obj;
    if (!(self->flags & 0x4000)) return;
#if defined(jpn)
    memset(self->textBuffer, 0, 0x800);
    int fieldVal = GetFieldByKey020e0434(&self->texts, 0x4274);
    AppendString02042058(self->textBuffer, (const char*)fieldVal);
    TryApplyElemFields0205d5d0((StructA0205d5d0*)&self->windows[1], 2,
                             (int)self->textBuffer, 1);
#else
    char* buf = self->textBuffer;
    memset(buf, 0, 0x960);
    int fieldVal = GetFieldByKey020e0434(&self->texts, 0x4274);
    AppendString02042058(buf, (const char*)fieldVal);
    TryApplyElemFields0205d5d0((StructA0205d5d0*)&self->windows[1], 2, (int)buf, 1, 0);
#endif
    self->flags &= ~0x4000;
}
