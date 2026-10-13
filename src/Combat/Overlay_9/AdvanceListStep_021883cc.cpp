// USA: func_ov009_021883cc
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/CharacterCreationUI.h"
#include "System/ColorEffects.h"

int GetWord0x0(int*);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
#if defined(jpn)
extern "C" void func_ov009_021867bc(unsigned char*, int);
#else
void SetStatValue021855dc(unsigned char*, int);
#endif

extern "C" ARM void func_ov009_021883cc(unsigned char* storage) {
    CharacterCreationUI* editor = (CharacterCreationUI*)storage;
    GameResources* resources = (GameResources*)GetWord0x0((int*)GameState::GetInstance());
    unsigned char step = editor->step;
    if (step == 0) {
        SetBrightness(resources, -16, 15);
        ++editor->step;
        return;
    }
    if (step != 1 || IsBrightnessTransitionActive(resources))
        return;
    ResetEntryList0205d6a0((Entry_0205d6a0*)&editor->windows[0], 1);
    ResetEntryList0205d6a0((Entry_0205d6a0*)&editor->windows[1], 1);
    ColorEffect_ConfigureBrightnessAdjust(0x04001050, 1, 0);
#if defined(jpn)
    func_ov009_021867bc(storage, 12);
#else
    SetStatValue021855dc(storage, 12);
#endif
}
