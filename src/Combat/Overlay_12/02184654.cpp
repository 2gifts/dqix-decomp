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

extern "C" void* func_0202ae18(void* ctx);
extern "C" unsigned char* _Z15GetFieldAt0x150Ph(unsigned char* obj);
int CalculateAge(int year, int month, int day);
void* FindEntryByKey(struct TableA68* table, int key);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* texts, int key);
extern "C" void func_ov023_021e66ac(ProfileEditor02184654* self);

static inline Profile02184654* GetProfile02184654(GameState* gameState)
{
    return (Profile02184654*)((char*)gameState + 0x569c);
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
    func_0202ae18((char*)gameState + 0x29c);
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
