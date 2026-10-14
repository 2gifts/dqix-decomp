#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#include "std_library_functions.h"

struct StructA0205d5d0;
extern "C" void func_ov013_02185424(void*, void*);

struct SkillPointMenu {
#if defined(jpn)
    char unknown0[0x34];
    unsigned char window[0xbc];
    char unknownAfterWindow[0x5ac - 0xf0];
#else
    char unknown0[0x38];
    unsigned char window[0xbc];
    char unknownAfterWindow[0x620 - 0xf4];
#endif
    char texts[0x18];
    unsigned char unknownStateBytes[4];
    unsigned char state;
    unsigned char previousState;
    unsigned char step;
    bool stateChanged;
    bool subScreen;
    unsigned int ticks;
    int windowInput;
#if !defined(jpn)
    int previousWindowInput;
#endif
    int task;
    void* canvasPixels;
    char* text;
    int selectedSkill;
    int confirmationChoice;
    unsigned char unknownAfterChoice;
    unsigned char confirmationPressed;
    char unknownAfterPressed[2];
    int availablePoints;
    int remainingPoints;
    int pointCap;
    int skillPoints[5];
    int allocatedPoints[5];
    unsigned char lockedSkills[5];
    char unknownAfterLocks[8];
    unsigned char skillIds[5];
    char unknownAfterSkillIds[0xe];
    unsigned char flags;
};

// USA: func_ov013_02186bd4  (semantic: ApplyElemFieldsSlot0_02186bd4)
extern "C" ARM void func_ov013_02186bd4(SkillPointMenu* menu) {
    memset(menu->text, 0, LOW_REGION(0x800, 0x960));
    func_ov013_02185424(menu, menu->text);
#if defined(jpn)
    TryApplyElemFields0205d5d0((StructA0205d5d0*)menu->window, 0, (int)menu->text, 1);
#else
    TryApplyElemFields0205d5d0((StructA0205d5d0*)menu->window, 0, (int)menu->text, 1, 0);
#endif
}
