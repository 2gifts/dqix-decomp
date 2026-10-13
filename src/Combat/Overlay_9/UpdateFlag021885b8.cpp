// KEEP-NAME
// USA: func_ov009_021885b8
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

extern "C" int func_ov023_021e5974(void*, void*, int, int, int);

struct Struct021885b8;
struct CreationData021885b8 {
    unsigned char unknown[0x568];
    short value568;
};

ARM void UpdateFlag021885b8(Struct021885b8* storage) {
    CharacterCreationUI* editor = (CharacterCreationUI*)storage;
    if (editor->flags & 2) {
        void* character = editor->nextCharacter;
        CreationData021885b8* data = (CreationData021885b8*)editor->characterData;
        func_ov023_021e5974(character, data, data->value568, 0, 0);
        editor->flags = (editor->flags | 4) & ~2;
    }
}
