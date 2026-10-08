#include <globaldefs.h>
#include <std_library_functions.h>

struct GameState;
struct MessageSystem;
struct TableA68;
struct StoreStruct;
struct SearchStruct0202c1a4;

struct ProfileData_021e868c {
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

struct PartyMemberData_021e868c {
    char unk_0[0x3c];
    char name_[1];
};

struct ProfileCard_021e868c {
    char unk_0[0x5d8];
    char* text_;
    char unk_5dc[0x5f4 - 0x5dc];
    TableA68* strings_;
};

struct GameState {
    static GameState* GetInstance();
};

static inline ProfileData_021e868c* GetProfile(GameState* gameState)
{
    return (ProfileData_021e868c*)((char*)gameState + 0x569c);
}

extern "C" MessageSystem* _Z26GetGlobalField0x1c020421a0v();
int CheckField0NonZero(int* unknown);
void* GetCombatantWithFlag0x100(GameState* gameState, int member);
PartyMemberData_021e868c* GetFieldAt0x150(unsigned char* member);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* unknown);
void AppendXTag(char* text, int x);
void AppendYTag(char* text, int y);
void AppendXYTag(char* text, int x, int y);
void AppendNameTag(char* text, int item, const char* itemText);
extern "C" void _Z23AppendFormatted02041facPcii(char* text, int line, int size);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);
const char* FindEntryByKey(TableA68* texts, int id);
void StoreInArray0x8b0(StoreStruct* messages, int index, int value);
void SetByteAtIndex(unsigned char* messages, int index, unsigned char value);
void SetByteInRange(unsigned char* messages, int index, unsigned char digits);

extern "C" {
void* func_0202ae18();
int func_020420e8(const char* text, int large);
void func_02046608(MessageSystem* messages, int a, const char* format, char* output, int size, int b, int c);
}

// USA: func_ov023_021e868c
extern "C" ARM void func_ov023_021e868c(ProfileCard_021e868c* self)
{
    GameState* gameState = GameState::GetInstance();
    MessageSystem* messages = _Z26GetGlobalField0x1c020421a0v();
    void* unknown = func_0202ae18();
    PartyMemberData_021e868c* data = NULL;
    if (CheckField0NonZero((int*)unknown) == 0)
    {
        void* member = GetCombatantWithFlag0x100(gameState, 0);
        if (member != NULL)
            data = GetFieldAt0x150((unsigned char*)member);
    }
    else
    {
        void* member = GetCombatantWithFlag0x100(gameState, GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)unknown));
        if (member != NULL)
            data = GetFieldAt0x150((unsigned char*)member);
    }
    if (data == NULL)
        return;
    ProfileData_021e868c* profile = GetProfile(gameState);
    char* text = self->text_;
    char buffer[0x20] = {};
    AppendXTag(text, (0xd0 - func_020420e8(data->name_, 0)) >> 1);
    _Z23AppendFormatted02041facPcii(text, (int)data->name_, 0x10);
    const char* title = FindEntryByKey(self->strings_, (short)(profile->title_ + 10000));
    AppendNameTag(text, 0, FindEntryByKey(self->strings_, 2));
    _Z20AppendString02042058PcPKc(text, FindEntryByKey(self->strings_, 0x6c));
    AppendXTag(text, ((0x6e - func_020420e8(title, 0)) >> 1) + 0x56);
    _Z20AppendString02042058PcPKc(text, title);
    _Z20AppendString02042058PcPKc(text, FindEntryByKey(self->strings_, 0));
    AppendNameTag(text, 1, FindEntryByKey(self->strings_, 3));
    AppendXTag(text, 0x4c);
    _Z20AppendString02042058PcPKc(text, FindEntryByKey(self->strings_, 0x6c));
    if (profile->showBirthday_)
    {
        AppendXTag(text, 0x5a);
    }
    else
    {
        AppendXYTag(text, 0x6e, 0x34);
        func_02046608(messages, 10, FindEntryByKey(self->strings_, 0x78), buffer, 0x100, 0, 0);
        _Z20AppendString02042058PcPKc(text, buffer);
        AppendXYTag(text, 0x5a, 0x28);
    }
    if (profile->birthdayChosen_)
    {
        StoreInArray0x8b0((StoreStruct*)messages, 0, profile->year_);
        SetByteAtIndex((unsigned char*)messages, 0, 1);
        SetByteInRange((unsigned char*)messages, 0, 4);
        func_02046608(messages, 10, FindEntryByKey(self->strings_, 0x64), buffer, 0x100, 0, 0);
        _Z20AppendString02042058PcPKc(text, buffer);
        memset(buffer, 0, sizeof(buffer));
        StoreInArray0x8b0((StoreStruct*)messages, 0, profile->month_);
        SetByteAtIndex((unsigned char*)messages, 0, 1);
        SetByteInRange((unsigned char*)messages, 0, 2);
        func_02046608(messages, 10, FindEntryByKey(self->strings_, 0x65), buffer, 0x100, 0, 0);
        _Z20AppendString02042058PcPKc(text, buffer);
        memset(buffer, 0, sizeof(buffer));
        StoreInArray0x8b0((StoreStruct*)messages, 0, profile->day_);
        SetByteAtIndex((unsigned char*)messages, 0, 1);
        SetByteInRange((unsigned char*)messages, 0, 2);
        func_02046608(messages, 10, FindEntryByKey(self->strings_, 0x66), buffer, 0x100, 0, 0);
        _Z20AppendString02042058PcPKc(text, buffer);
        _Z20AppendString02042058PcPKc(text, FindEntryByKey(self->strings_, 0));
    }
    else
    {
        func_02046608(messages, 10, FindEntryByKey(self->strings_, 0x6e), buffer, 0x100, 0, 0);
        _Z20AppendString02042058PcPKc(text, buffer);
        memset(buffer, 0, sizeof(buffer));
        func_02046608(messages, 10, FindEntryByKey(self->strings_, 0x6f), buffer, 0x100, 0, 0);
        _Z20AppendString02042058PcPKc(text, buffer);
        memset(buffer, 0, sizeof(buffer));
        func_02046608(messages, 10, FindEntryByKey(self->strings_, 0x70), buffer, 0x100, 0, 0);
        _Z20AppendString02042058PcPKc(text, buffer);
        _Z20AppendString02042058PcPKc(text, FindEntryByKey(self->strings_, 0));
    }
    int accolade = profile->accolade_;
    short accoladeId = accolade + 20000;
    if (accolade < 700)
        accoladeId = accolade;
    const char* accoladeText = FindEntryByKey(self->strings_, accoladeId);
    AppendYTag(text, 0x42);
    AppendNameTag(text, 2, FindEntryByKey(self->strings_, 4));
    AppendXTag(text, 0x4c);
    _Z20AppendString02042058PcPKc(text, FindEntryByKey(self->strings_, 0x6c));
    AppendXTag(text, ((0x6e - func_020420e8(accoladeText, 0)) >> 1) + 0x56);
    _Z20AppendString02042058PcPKc(text, accoladeText);
    _Z20AppendString02042058PcPKc(text, FindEntryByKey(self->strings_, 0));
    short id = 0x6d;
    if (profile->designChosen_)
        id = profile->unk_0_21 + 30000;
    const char* vocation = FindEntryByKey(self->strings_, id);
    AppendNameTag(text, 3, FindEntryByKey(self->strings_, 5));
    AppendXTag(text, 0x4c);
    _Z20AppendString02042058PcPKc(text, FindEntryByKey(self->strings_, 0x6c));
    AppendXTag(text, ((0x6e - func_020420e8(vocation, 0)) >> 1) + 0x56);
    _Z20AppendString02042058PcPKc(text, vocation);
}
