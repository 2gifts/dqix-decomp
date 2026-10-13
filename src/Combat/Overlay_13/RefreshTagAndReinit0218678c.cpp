#if defined(jpn)
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_02186c64 func_ov013_02187f78
#endif

#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
int CheckByteSetAndByteClear(unsigned char* obj);
void InvalidateBattlerField0x18(unsigned char* obj);

struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8* obj, int val);

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);

extern "C" void func_ov013_02186c64(void* obj, int a, int b);
extern "C" void func_ov013_02185cc0(void* obj);

extern unsigned short data_02114e30;
extern char data_02114e54;

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

// USA: func_ov013_0218678c  (semantic: RefreshTagAndReinit0218678c)
extern "C" ARM void func_ov013_0218678c(SkillPointMenu* menu) {
    menu->flags &= ~1;
    menu->unknownStateBytes[2] = 0;

    if (menu->previousState != menu->state) return;

    if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 0x613) && !CheckByteSetAndByteClear((unsigned char*)&data_02114e54)) {
        return;
    }

    menu->state = 1;
    InvalidateBattlerField0x18((unsigned char*)&data_02114e30);
    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)menu->window, 2);
    ResetEntryList0205d6a0((struct Entry_0205d6a0*)menu->window, 0);
    menu->unknownStateBytes[1] = 0;
    menu->flags &= ~1;
    func_ov013_02186c64(menu, 0, 0);
    func_ov013_02185cc0(menu);
}
