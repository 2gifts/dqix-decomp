// USA: func_ov009_02184ca4
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Obj0205d2bc;
void InitEntries0205d2bc(Obj0205d2bc*);
extern "C" void func_0204b088(CreationTileMap*, void*);
#if defined(jpn)
extern "C" void func_ov009_02186158(unsigned char*);
extern "C" void func_ov023_021da264(char*);
extern "C" void func_ov023_021da5d8(char*);
extern "C" void func_ov023_021da6f0(char*);
extern "C" void func_ov023_021da9a8(unsigned char*);
#else
extern "C" void func_ov009_02184e58(unsigned char*);
extern "C" void func_ov023_021d9a6c(char*);
void RefreshFieldIfFlag4000_021d9d34(char*);
void BuildFieldTag_021d9e60(char*);
extern "C" void func_ov023_021da1dc(unsigned char*);
#endif

extern "C" ARM void func_ov009_02184ca4(unsigned char* storage) {
    CharacterCreationUI* editor = (CharacterCreationUI*)storage;
#if defined(jpn)
    func_ov009_02186158(storage);
#else
    func_ov009_02184e58(storage);
#endif
    signed char state = editor->state;
    if (state == 0 || state == 12)
        return;
    if (editor->flags & 0x80)
        return;
    InitEntries0205d2bc((Obj0205d2bc*)&editor->windows[0]);
    InitEntries0205d2bc((Obj0205d2bc*)&editor->windows[1]);
    if (editor->flags & 0x1000) {
        func_0204b088(&editor->tileMaps[0], 0);
        editor->flags &= ~0x1000;
    }
    if (editor->flags & 0x2000) {
        func_0204b088(&editor->tileMaps[3], 0);
#if defined(jpn)
        if (editor->state == 8 || editor->state == 9)
#else
        signed char range = state - 8;
        if ((unsigned char)range <= 1)
#endif
            func_0204b088(&editor->tileMaps[2], 0);
        editor->flags &= ~0x2000;
    }
#if defined(jpn)
    func_ov023_021da264((char*)storage);
    func_ov023_021da5d8((char*)storage);
    func_ov023_021da6f0((char*)storage);
    func_ov023_021da9a8(storage);
#else
    func_ov023_021d9a6c((char*)storage);
    RefreshFieldIfFlag4000_021d9d34((char*)storage);
    BuildFieldTag_021d9e60((char*)storage);
    func_ov023_021da1dc(storage);
#endif
}
