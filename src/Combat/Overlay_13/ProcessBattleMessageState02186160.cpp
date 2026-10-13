#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02186160 func_ov013_02187178
struct TouchInput {
    char unknown0[0x20];
    unsigned short x;
    unsigned short y;
    unsigned short touching;
    char unknown26[0x44 - 0x26];
    unsigned int holdTicks;
    char unknown48[0x54 - 0x48];
    unsigned char released;
    unsigned char pressed;
    char unknown56[0x5c - 0x56];
    unsigned char repeat;
};
extern TouchInput data_02114e54;
extern "C" int func_020124b0(void*, int, int, int, int);
int IsWithinRect(unsigned char*, int, int, int, int);
extern "C" void func_ov013_02186964(void*);
#endif

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
#if defined(jpn)
    enum Prompt { NoPrompt = -1, PointLimit = 2, ConfirmAllocation = 3, DiscardAllocation = 4 };
    void ResetPromptWindow();
#endif
};

extern "C" void* __clear(void* dst, int count);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8* obj, int val);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" void func_0205d7a0(unsigned char* obj, int val);
struct Struct_0205d81c;
extern "C" int func_0205d97c(Struct_0205d81c* window);
struct Obj0201248c;
extern "C" int func_0201248c(struct Obj0201248c* obj, int mask);
extern "C" int func_ov013_021842a0(void* obj, int index);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern int data_02108760;
void SetupBattleMessage02185774(void* obj);
void InitTag02185828(unsigned char* obj);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
extern "C" void func_ov013_02186c64(void* obj, int a, int b);
extern "C" void func_ov013_02186bd4(void* obj);

#if defined(jpn)
inline void SkillPointMenu::ResetPromptWindow() {
    SetFieldB0AndUpdate0205dee8((Obj0205dee8*)window, 4);
    ResetEntryList0205d6a0((Entry_0205d6a0*)window, 0);
}
#endif

// USA: func_ov013_02186160  (semantic: ProcessBattleMessageState02186160)
extern "C" ARM void func_ov013_02186160(SkillPointMenu* menu) {
#if defined(jpn)
    menu->flags |= 1;
    menu->unknownStateBytes[0] = 0;
    menu->unknownStateBytes[1] = 0;
    SetFieldB0AndUpdate0205dee8((Obj0205dee8*)menu->window, 0);

    int previousAllocatedPoints[5];
    for (int j = 0; j < 5; j++)
        previousAllocatedPoints[j] = menu->allocatedPoints[j];
    bool redraw = false;
    bool transitioned = false;
    if (func_0201248c((Obj0201248c*)&data_02114e30, 0x80)) {
        ++menu->selectedSkill;
        redraw = true;
    }
    if (func_0201248c((Obj0201248c*)&data_02114e30, 0x40)) {
        --menu->selectedSkill;
        redraw = true;
    }
    if (menu->selectedSkill < 0) menu->selectedSkill = 5;
    if (menu->selectedSkill >= 6) menu->selectedSkill = 0;
    int confirmationHit = func_020124b0(&data_02114e54, 0x1e, 0x5a, 0x2a, 0xa);
    if (menu->windowInput == 2) {
        menu->selectedSkill = (signed char)GetActiveScaledSum0205d794((Struct_0205c570*)menu->window);
        redraw = true;
    }
    if (menu->remainingPoints >= 0 && menu->selectedSkill < 5) {
        if (func_0201248c((Obj0201248c*)&data_02114e30, 0x20) ||
            func_0201248c((Obj0201248c*)&data_02114e30, 2) ||
            (data_02114e54.repeat && IsWithinRect((unsigned char*)&data_02114e54, 0x52, menu->selectedSkill * 0xd + 0x12, 0xe, 0xb))) {
            if (menu->lockedSkills[menu->selectedSkill] == 0) {
                menu->allocatedPoints[menu->selectedSkill]--;
                redraw = true;
                if (menu->allocatedPoints[menu->selectedSkill] < 0)
                    menu->allocatedPoints[menu->selectedSkill] = 0;
                else
                    DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 0x5d, 0);
            }
        } else if (menu->remainingPoints > 0 && menu->skillPoints[menu->selectedSkill] != 0x64) {
            if (menu->skillPoints[menu->selectedSkill] > menu->pointCap) {
                if (func_0201248c((Obj0201248c*)&data_02114e30, 0x611) ||
                    (data_02114e54.repeat && IsWithinRect((unsigned char*)&data_02114e54, 0x8c, menu->selectedSkill * 0xd + 0x14, 0xe, 0xb))) {
                    menu->flags &= ~1;
                    menu->state = SkillPointMenu::PointLimit;
                    transitioned = true;
                    redraw = true;
                    if (menu->subScreen) InitTag02185828((unsigned char*)menu);
                    else func_ov013_02186964(menu);
                    if (!menu->subScreen) {
                        menu->ResetPromptWindow();
                    }
                }
            } else {
                bool pointsAdded = false;
                if (func_0201248c((Obj0201248c*)&data_02114e30, 0x611) ||
                    (data_02114e54.repeat && IsWithinRect((unsigned char*)&data_02114e54, 0x84, menu->selectedSkill * 0xd + 0x14, 0xe, 0xb))) {
                    if (menu->lockedSkills[menu->selectedSkill] == 0) {
                        menu->allocatedPoints[menu->selectedSkill]++;
                        pointsAdded = true;
                        redraw = true;
                    }
                }
                if (menu->allocatedPoints[menu->selectedSkill] + menu->skillPoints[menu->selectedSkill] > menu->pointCap) {
                    menu->allocatedPoints[menu->selectedSkill]--;
                    pointsAdded = false;
                    if (menu->pointCap != 0x64) {
                        menu->flags &= ~1;
                        menu->state = SkillPointMenu::PointLimit;
                        transitioned = true;
                        redraw = true;
                        if (menu->subScreen) InitTag02185828((unsigned char*)menu);
                        else func_ov013_02186964(menu);
                        if (!menu->subScreen) {
                            menu->ResetPromptWindow();
                        }
                    }
                }
                if (pointsAdded)
                    DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 0x5d, 0);
            }
        }
    }
    SkillPointMenu::Prompt nextPrompt = SkillPointMenu::NoPrompt;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601) && menu->state != SkillPointMenu::PointLimit) {
        if (menu->selectedSkill != 5 && menu->remainingPoints == 0) {
            menu->selectedSkill = 5;
            redraw = true;
        } else if (menu->selectedSkill == 5) {
            nextPrompt = SkillPointMenu::ConfirmAllocation;
        } else if (func_0205d97c((Struct_0205d81c*)menu->window) == 2) {
            nextPrompt = SkillPointMenu::DiscardAllocation;
        }
    } else {
        if ((func_0201248c((Obj0201248c*)&data_02114e30, 0x611) ||
             (data_02114e54.repeat && IsWithinRect((unsigned char*)&data_02114e54, 0x84, menu->selectedSkill * 0xd + 0x14, 0xe, 0xb))) &&
            menu->selectedSkill != 5 && menu->remainingPoints == 0) {
            menu->selectedSkill = 5;
            redraw = true;
        } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) && menu->state != SkillPointMenu::PointLimit) {
            if (previousAllocatedPoints[menu->selectedSkill] == 0 || menu->selectedSkill == 5 || menu->selectedSkill == 6)
                nextPrompt = SkillPointMenu::DiscardAllocation;
        } else if (menu->selectedSkill == 5 && menu->state != SkillPointMenu::PointLimit && data_02114e54.released &&
                   data_02114e54.holdTicks < 0x14 && menu->confirmationPressed == 1) {
            if (confirmationHit) {
                menu->confirmationPressed = 0;
                nextPrompt = SkillPointMenu::ConfirmAllocation;
            }
        } else if (func_0205d97c((Struct_0205d81c*)menu->window) == 2 && menu->state != SkillPointMenu::PointLimit) {
            nextPrompt = SkillPointMenu::DiscardAllocation;
        }
    }
    if (nextPrompt == SkillPointMenu::ConfirmAllocation || nextPrompt == SkillPointMenu::DiscardAllocation) {
        if (nextPrompt == SkillPointMenu::ConfirmAllocation) menu->state = SkillPointMenu::ConfirmAllocation;
        else menu->state = SkillPointMenu::DiscardAllocation;
        menu->flags &= ~1;
        transitioned = true;
        redraw = true;
        if (menu->subScreen == 0) {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, transitioned, 0);
            menu->ResetPromptWindow();
        } else {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 5, 0);
        }
        if (menu->subScreen) InitTag02185828((unsigned char*)menu);
                        else func_ov013_02186964(menu);
    } else {
        if (menu->selectedSkill == 5 && data_02114e54.released && confirmationHit)
            menu->confirmationPressed = 1;
        else if (data_02114e54.pressed && !confirmationHit)
            menu->confirmationPressed = 0;
    }
    int sum = 0;
    for (int k = 0; k < 5; k++)
        sum += menu->allocatedPoints[k];
    menu->remainingPoints = menu->availablePoints - sum;
    if (transitioned)
        func_ov013_02186c64(menu, 0, 1);
    else if (redraw)
        func_ov013_02186bd4(menu);
#else

    menu->flags |= 1;
    menu->unknownStateBytes[0] = 0;
    menu->unknownStateBytes[1] = 0;
    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)menu->window, 0);

    int previousAllocatedPoints[6];
    __clear(previousAllocatedPoints, 0x18);
    for (int j = 0; j < 5; j++) {
        previousAllocatedPoints[j] = menu->allocatedPoints[j];
    }

    int redraw, transitioned, nextState, previousSelection;
    previousSelection = menu->selectedSkill;
    redraw = 0;
    transitioned = redraw;
    nextState = redraw - 1;
    menu->selectedSkill = GetActiveScaledSum0205d794((struct Struct_0205c570*)menu->window);

    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601) != 0) {
        if (menu->selectedSkill != 5) {
            if (menu->remainingPoints == 0) {
                menu->selectedSkill = 5;
                func_0205d7a0(menu->window, 5);
                menu->previousWindowInput = redraw;
                redraw = 1;
            }
        } else {
            nextState = 3;
        }
    } else {
        int b = func_0205d97c((Struct_0205d81c*)menu->window);
        if (b == 2) {
            nextState = 4;
        } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) != 0) {
            if (previousAllocatedPoints[menu->selectedSkill] == 0) {
                nextState = 4;
            }
        }
    }

    int windowInput = menu->windowInput;
    if (windowInput == 0) {
        if (menu->remainingPoints >= 0 && menu->selectedSkill < 5) {
            if (func_0201248c((struct Obj0201248c*)&data_02114e30, 0x20) != 0 ||
                func_0201248c((struct Obj0201248c*)&data_02114e30, 2) != 0 ||
                func_ov013_021842a0((void*)menu->window, 0xa) != 0) {
                menu->previousWindowInput = 0;
                if (menu->lockedSkills[menu->selectedSkill] == 0) {
                    menu->allocatedPoints[menu->selectedSkill]--;
                    redraw = 1;
                    if (menu->allocatedPoints[menu->selectedSkill] >= 0) {
                        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x5d, 0);
                    } else {
                        menu->allocatedPoints[menu->selectedSkill] = 0;
                    }
                }
            } else if (menu->remainingPoints > 0) {
                int pointsAdded = 0;
                menu->previousWindowInput = 0;
                int skillPoints = menu->skillPoints[menu->selectedSkill];
                if (skillPoints != 0x64) {
                    int allocatedPoints = menu->allocatedPoints[menu->selectedSkill];
                    if (skillPoints + allocatedPoints < 0x64) {
                        if (func_0201248c((struct Obj0201248c*)&data_02114e30, 0x611) != 0 ||
                            func_ov013_021842a0((void*)menu->window, 0xb) != 0) {
                            if (menu->lockedSkills[menu->selectedSkill] == 0) {
                                menu->allocatedPoints[menu->selectedSkill]++;
                                pointsAdded = 1;
                                redraw = pointsAdded;
                            }
                        }
                        if (pointsAdded != 0) {
                            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x5d, 0);
                        }
                    }
                }
            }
        }
    } else {
        redraw = 1;
        if (windowInput == 2 && menu->previousWindowInput == windowInput && previousSelection == 5 && menu->selectedSkill == 5) {
            nextState = 3;
        }
        menu->previousWindowInput = windowInput;
    }

    if (nextState >= 0) {
        menu->previousWindowInput = 0;
        menu->state = (unsigned char)nextState;
        menu->confirmationPressed = 0;
        menu->flags &= ~1;
        transitioned = 1;
        redraw = 1;
        if (menu->subScreen == 0) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, transitioned, 0);
            SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)menu->window, 4);
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)menu->window, 0);
        } else {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 5, 0);
        }
        if (menu->subScreen != 0) {
            InitTag02185828((unsigned char*)menu);
        } else {
            SetupBattleMessage02185774(menu);
        }
    }

    int sum = 0;
    for (int k = 0; k < 5; k++) {
        sum += menu->allocatedPoints[k];
    }
    menu->remainingPoints = menu->availablePoints - sum;

    if (transitioned != 0) {
        func_ov013_02186c64(menu, 0, 1);
    } else if (redraw != 0) {
        func_ov013_02186bd4(menu);
    }
#endif
}
