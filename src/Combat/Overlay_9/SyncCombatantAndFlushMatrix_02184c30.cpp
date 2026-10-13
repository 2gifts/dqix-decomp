// USA: func_ov009_02184c30
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

extern "C" void func_ov023_021e5628(void*, void*);

extern "C" ARM void func_ov009_02184c30(void* storage) {
    CharacterCreationUI* editor = (CharacterCreationUI*)storage;
    if (editor->state == 0 || editor->state == 12)
        return;
    *(volatile unsigned int*)0x04000444 = 0;
    func_ov023_021e5628(editor->character, 0);
    if (editor->flags & 0x200) {
        editor->model.Draw(true);
        editor->secondModel.Draw(true);
    }
    *(volatile unsigned int*)0x04000448 = 1;
}
