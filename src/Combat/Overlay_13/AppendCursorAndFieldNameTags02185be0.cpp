#include <globaldefs.h>

#if defined(jpn)
#define AppendSizeTag func_02042428
#endif

#if defined(jpn)
#define func_ov013_02185be0 func_ov013_02186db0
#endif

struct SkillPointMenu {
#if defined(jpn)
    char unknown0[0x5ac];
#else
    char unknown0[0x620];
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
    unsigned char unknownAfterChoice[4];
    int availablePoints;
    int remainingPoints;
    int pointCap;
    int skillPoints[5];
    int allocatedPoints[5];
    unsigned char lockedSkills[5];
    char unknownAfterLocks[8];
    unsigned char skillIds[5];
};

struct Container020e0310;
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" void* __clear(void* dst, int count);
#if defined(jpn)
extern "C"
#endif
int AppendSizeTag(char* dst, int size);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
int AppendNameTag(char* dst, int n, const char* name);

// USA: func_ov013_02185be0  (semantic: AppendCursorAndFieldNameTags02185be0)
extern "C" ARM void func_ov013_02185be0(SkillPointMenu* menu, char* dst) {
    char choiceText[0x20];
    int choice;

    if (menu->windowInput == 2) {
        AppendFrameTag02041c08(dst, menu->confirmationChoice, 9, 3, 6, 2);
    }
    AppendCursorTag(dst, menu->confirmationChoice);

    for (choice = 0; choice < 2; choice++) {
        __clear(choiceText, 0x20);
        AppendSizeTag(choiceText, 0xc);
        AppendString02042058(choiceText, (const char*)GetFieldByKey020e0434((Container020e0310*)menu->texts, (short)(choice + 0xa)));
        AppendNameTag(dst, choice, choiceText);
        if (choice < 1) {
            AppendString02042058(dst, (const char*)GetFieldByKey020e0434((Container020e0310*)menu->texts, 0));
        }
    }
}
