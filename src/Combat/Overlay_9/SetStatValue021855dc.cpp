#include <globaldefs.h>

struct CharacterCreation {
#if defined(jpn)
    char unknown0[0xc1c];
#else
    char unknown0[0xc58];
#endif
    signed char state;
    unsigned char step;
    char unknownAfterStep[0xd9c - 0xc5a];
    unsigned int flags;
    signed char furthestState[2];
    unsigned char vocation;
    unsigned char sex;
};

// USA: func_ov009_021855dc
#if defined(jpn)
extern "C" ARM void func_ov009_021867bc(unsigned char* storage, int state) {
#else
ARM void SetStatValue021855dc(unsigned char* storage, int state) {
#endif
    CharacterCreation* editor = (CharacterCreation*)storage;
    signed char selectedState = (signed char)state;
    editor->state = selectedState;
    editor->step = 0;
    int sex = editor->sex;
    if (editor->furthestState[sex] < state)
        editor->furthestState[sex] = selectedState;
    editor->flags |= 0x1100;
    if (state != 9 && state != 11 && state != 12)
        editor->flags |= 0x80;
}
