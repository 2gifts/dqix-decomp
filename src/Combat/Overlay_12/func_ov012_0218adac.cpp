#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218adac func_ov012_0218bba0
#endif
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct ProfileData {
    unsigned int year : 12;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int design : 4;
    unsigned int female : 1;
    unsigned int initialized : 1;
    unsigned int designChosen : 1;
    unsigned int birthdayChosen : 1;
    unsigned int accoladeChosen : 1;
    unsigned int vocationAccolade : 1;
    unsigned int showBirthday : 1;
    char remainingData[0x78];
};

struct SavedProfileState {
    char unknown0[LOW_REGION(0x543c, 0x569c)];
    ProfileData profile;
};

struct ProfileEditor {
    char unknown0[LOW_REGION(0xd0c, 0xd28)];
#if defined(jpn)
    char controller[0x608];
    char unknown1314[0x1344 - 0x1314];
#else
    char controller[0x60c];
    unsigned char pageVisible;
    char unknown1335[0x1374 - 0x1335];
#endif
    char* text;
    char unknownAfterText[LOW_REGION(0x1408 - 0x1348, 0x13b0 - 0x1378)];
    const char* playerName;
    void* messageScript;
    unsigned int messageScriptSize;
    char* outputText;
    char unknownAfterOutput[LOW_REGION(0x1458 - 0x1418, 0x1400 - 0x13c0)];
    char accoladeText[0x40];
    char titleText[0x40];
#if !defined(jpn)
    char unknown1480[0x14bd - 0x1480];
    unsigned char secondPage;
#endif
};

extern "C" void func_ov023_021e6594(ProfileEditor* obj);
extern "C" void func_ov023_021e66ac(void* obj);

class PMFObj021e7bc4;
class PMFObj021e7c58;
void DispatchEntryByIndex_021e7bc4(PMFObj021e7bc4* obj, unsigned int selector, int idx);
void DispatchEntryByIndex_021e7c58(PMFObj021e7c58* obj, unsigned int selector, int idx);

#if !defined(jpn)
extern "C" int func_ov012_0218ae74(ProfileEditor* self, const ProfileData* profile);
#endif

#if defined(jpn)
extern "C" void func_02042428(char*, int);
extern "C" int func_0209b000(const ProfileData*, const char*, const void*, unsigned int, char*, unsigned int, unsigned char, const char*, const char*);
#endif

// USA: func_ov012_0218adac
#if defined(jpn)
extern "C" ARM void func_ov012_0218adac(ProfileEditor* self, int animate, int design) {
#else
extern "C" ARM void func_ov012_0218adac(ProfileEditor* self, int animate, int design, int flag) {
#endif
    GameState* battle = GameState::GetInstance();
    func_ov023_021e6594(self);

    ProfileData preview;
    const ProfileData* profile;

    if (design == -1) {
        profile = &((SavedProfileState*)battle)->profile;
    } else {
        memcpy(&preview, &((SavedProfileState*)battle)->profile, sizeof(preview));
        preview.design = design;
        profile = &preview;
    }

#if defined(jpn)
    memset(self->text, 0, 0x800);
    func_02042428(self->text, 12);
    char* text = self->text;
    unsigned int length = strlen(text);
    func_0209b000(profile, self->playerName, self->messageScript, self->messageScriptSize, text + length, 0x800 - length, 0, self->titleText, self->accoladeText);
    memset(self->outputText, 0, 0xf2);
    const char* renderedText = self->text;
    memcpy(self->outputText, renderedText, strlen(renderedText));
    {
#else
    if (flag == 0) {
        self->secondPage = 0;
        self->pageVisible = 0;
    }

    int result = func_ov012_0218ae74(self, profile);

    if (result != 0 || flag == 0) {
#endif
        if (animate != 0) {
            DispatchEntryByIndex_021e7bc4((PMFObj021e7bc4*)self->controller, 2, 0);
        } else {
            DispatchEntryByIndex_021e7c58((PMFObj021e7c58*)self->controller, 2, 0);
        }
    }

    func_ov023_021e66ac(self);
}
