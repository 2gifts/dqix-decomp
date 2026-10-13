#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct ProfileHeader02184654 {
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
    unsigned int age : 9;
    int title : 10;
    int accolade : 11;
    int edited : 1;
    unsigned int unknown31 : 1;
    signed char profileText[116];
};
struct AppearanceFlags02184654 {
    unsigned char female : 1;
    unsigned char eyeColor : 3;
    unsigned char skinColor : 4;
};
struct Appearance02184654 {
    short models[10];
    AppearanceFlags02184654 flags;
};
struct TableA68;
struct Container020e0310;
extern "C" void* func_0202ae18();
extern "C" unsigned char* _Z15GetFieldAt0x150Ph(unsigned char*);
int CalculateAge(int, int, int);
void* FindEntryByKey(TableA68*, int);
int GetFieldByKey020e0434(Container020e0310*, int);
extern "C" void func_ov023_021e66ac(void*);

static inline ProfileHeader02184654* GetProfile02184654(GameState* state) {
    return (ProfileHeader02184654*)((char*)state + 0x543c);
}

// USA: func_ov012_02184654
// JPN: func_ov012_02185724
extern "C" ARM void func_ov012_02184654(char* editor) {
    GameState* gameState = GameState::GetInstance();
    ProfileHeader02184654* profile = GetProfile02184654(gameState);
    signed char padding[3];
    memcpy(padding, FindEntryByKey((TableA68*)(editor + 0x1314), 113), 3);
    func_0202ae18();
    unsigned char* characterData = 0;
    GameObject* protagonist = gameState->GetProtagonist();
    if (protagonist)
        characterData = _Z15GetFieldAt0x150Ph((unsigned char*)protagonist);
    if (!characterData) return;
    *(void**)(editor + 0x1408) = characterData + 0x3c;

    if (!profile->initialized) {
        profile->year = 2000;
        profile->month = 1;
        profile->day = 1;
        profile->showBirthday = 1;
        Appearance02184654* appearance = (Appearance02184654*)(characterData + 0x488);
        profile->female = appearance->flags.female;
        profile->design = appearance->flags.female;
        profile->title = 300;
        char* partyData = *(char**)((char*)protagonist + 0x144);
        profile->accolade = *(int*)(partyData + 0x8b8) + 700;
        int i;
        signed char* text = profile->profileText;
        for (i = 0; i < 57; i++, text += 2) {
            memcpy(text, padding, 2);
        }
        profile->initialized = 1;
    }
    profile->age = CalculateAge(profile->year, profile->month, profile->day);
    signed char* text = profile->profileText;
    while (*(unsigned char*)(editor + 0x1375) < 114) {
        if (text[0] == padding[0] && text[1] == padding[1]) break;
        *(unsigned char*)(editor + 0x1375) += 2;
        text += 2;
    }
    const char* label = (const char*)FindEntryByKey((TableA68*)(editor + 0x1314), (short)(profile->title + 10000));
    memcpy(editor + 0x1498, label, strlen(label));
    if (profile->accolade < 700)
        label = (const char*)GetFieldByKey020e0434((Container020e0310*)(editor + 0x131c), (short)profile->accolade);
    else
        label = (const char*)FindEntryByKey((TableA68*)(editor + 0x1314), (short)(profile->accolade + 20000));
    memcpy(editor + 0x1458, label, strlen(label));
    func_ov023_021e66ac(editor);
}
#else
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Profile02184654
{
    unsigned int year_ : 12;
    unsigned int month_ : 4;
    unsigned int day_ : 5;
    unsigned int unk_0_21 : 4;
    unsigned int female_ : 1;
    unsigned int initialized_ : 1;
    unsigned int designChosen_ : 1;
    unsigned int birthdayChosen_ : 1;
    unsigned int accoladeChosen_ : 1;
    unsigned int vocationAccolade_ : 1;
    unsigned int showBirthday_ : 1;
    unsigned int unk_4_0 : 9;
    int title_ : 10;
    int accolade_ : 11;
    int edited_ : 1;
    unsigned int unk_4_31 : 1;
};

struct Save02184654
{
    char unk_0[0x5400];
    Profile02184654 profile_;
};

struct GameStateSave02184654
{
    char unk_0[0x29c];
    Save02184654 save_;
};

struct FieldFlags02184654
{
    char pad0[0x14];
    unsigned char female_ : 1;
    unsigned char eyeColor_ : 3;
    unsigned char skinColor_ : 4;
    char pad1[0x488 - 0x15];
};

struct Field02184654
{
    FieldFlags02184654 slots_[2];
};

struct Party02184654
{
    char unk_0[0x49c];
    unsigned char female_ : 1;
    char unk_49d[0x950 - 0x49d];
    int vocation_;
};

struct Member02184654
{
    char unk_0[0x150];
    Party02184654* partyData_;
};

struct TableA68;
struct Container020e0310;

struct ProfileEditor02184654
{
    char unk_0[0x133c];
    char strings_[8];
    char texts_[0x13b0 - 0x1344];
    void* unk_13b0;
    char unk_13b4[0x1400 - 0x13b4];
    char nameText_[0x40];
    char accoladeText_[0x40];
};

extern "C" void* func_0202ae18();
extern "C" unsigned char* _Z15GetFieldAt0x150Ph(unsigned char* obj);
int CalculateAge(int year, int month, int day);
void* FindEntryByKey(struct TableA68* table, int key);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* texts, int key);
extern "C" void func_ov023_021e66ac(ProfileEditor02184654* self);

static inline Profile02184654* GetProfile02184654(GameState* gameState)
{
    return &((GameStateSave02184654*)gameState)->save_.profile_;
}

static inline FieldFlags02184654* GetFieldFlags02184654(Field02184654* field, int i)
{
    return (FieldFlags02184654*)(void*)field->slots_ + i;
}

// USA: func_ov012_02184654
extern "C" ARM void func_ov012_02184654(ProfileEditor02184654* self)
{
    GameState* gameState = GameState::GetInstance();
    Profile02184654* profile = GetProfile02184654(gameState);
    func_0202ae18();
    Field02184654* field = 0;
    Member02184654* protagonist = (Member02184654*)gameState->GetProtagonist();
    if (protagonist != 0)
        field = (Field02184654*)_Z15GetFieldAt0x150Ph((unsigned char*)protagonist);
    if (field == 0)
        return;

    self->unk_13b0 = (char*)field + 0x3c;

    void* name2;
    if (!profile->initialized_)
    {
        profile->year_ = 2000;
        profile->month_ = 1;
        profile->day_ = 1;
        profile->showBirthday_ = 1;
        FieldFlags02184654* flags = GetFieldFlags02184654(field, 1);
        int accolade = 0x50dc;
        profile->female_ = flags->female_;
        profile->unk_0_21 = flags->female_;
        profile->title_ = 300;
        Party02184654* party = protagonist->partyData_;
        if (party->female_ == 1)
            accolade += 0x32;
        profile->accolade_ = accolade + party->vocation_ - 0x4e20;
        memset((char*)profile + 8, 0, 0x74);
        profile->initialized_ = 1;
    }

    profile->unk_4_0 = CalculateAge(profile->year_, profile->month_, profile->day_);

    name2 = FindEntryByKey((struct TableA68*)self->strings_, (short)(profile->title_ + 10000));
    memcpy(self->accoladeText_, name2, strlen((char*)name2));

    if (profile->accolade_ < 700)
        name2 = (void*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)self->texts_, (short)profile->accolade_);
    else
        name2 = FindEntryByKey((struct TableA68*)self->strings_, (short)(profile->accolade_ + 20000));
    memcpy(self->nameText_, name2, strlen((char*)name2));

    func_ov023_021e66ac(self);
}
#endif
