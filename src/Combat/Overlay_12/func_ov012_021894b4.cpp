#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct TableA68;

struct Profile021894b4
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
    char unk_8[0x74];
};

struct Save021894b4
{
    char unk_0[0x569c];
    Profile021894b4 profile_;
};

struct ProfileEditor021894b4
{
    char unk_0[0x133c];
    char strings_[0x1370 - 0x133c];
    unsigned char step_;
    unsigned char state_;
    char unk_1372[0x1378 - 0x1372];
    const char* unk_1378;
    char unk_137c[0x13d0 - 0x137c];
    char* message_;
    unsigned int selection_;
    char unk_13d8[0x1400 - 0x13d8];
    char accoladeText_[0x40];
    char titleText_[0x40];
};

void AppendFrameTag02041c08(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag_02041ea4(char* text, int a);
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
extern "C" int func_020420e8(const char* text, int large);
void AppendXTag_02041a28(char* text, int x);
void AppendFormatted02041fac(char* text, int line, int a);
void AppendHeightTag_02041b00(char* text, int a);
void AppendNameTag_02041b70(char* text, int item, const char* itemText);
void AppendString02042058(char* text, const char* append);
void AppendWidthHeightTag_02041b34(char* text, int a, int b);
void AppendLineXTag02041cf4(char* text, int a, int b, int c, int d);
void AppendLineYTag02041d48(char* text, int a, int b, int c, int d);
void* GetGlobalField0x1c020421a0();
extern "C" void __clear(void* buffer, unsigned long size);
void AppendXYTag_02041a90(char* text, int x, int y);
int StringLength_020d2ff0(const char* text);
void CopyTextAndUppercaseIfFlagged0206819c(const char* text, char* output, int a);
void AppendPaletteTag_02041e70(char* text, int color);

extern "C" const short data_ov012_0218af92[];
extern "C" const char data_ov012_0218b305[];

static inline Profile021894b4* GetProfile021894b4(GameState* gameState)
{
    return &((Save021894b4*)gameState)->profile_;
}

// USA: func_ov012_021894b4
extern "C" ARM void func_ov012_021894b4(ProfileEditor021894b4* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->selection_;
    if (hidden)
        AppendFrameTag02041c08(text, selection, 8, 5, 5, 5);
    AppendCursorTag_02041ea4(text, selection);
    const char* title = FindEntryByKey_02072a68((TableA68*)self->strings_, 1);
    AppendXTag_02041a28(text, (0xe0 - func_020420e8(title, 0)) >> 1);
    AppendFormatted02041fac(text, (int)title, 0x10);
    AppendHeightTag_02041b00(text, 3);
    AppendNameTag_02041b70(text, 0, FindEntryByKey_02072a68((TableA68*)self->strings_, 2));
    int item;
    const short* texts = data_ov012_0218af92;
    for (item = 1;; item++, texts++)
    {
        short id = *texts;
        if (id < 0)
            break;
        AppendString02042058(text, self->unk_1378);
        if (item == 5)
            AppendWidthHeightTag_02041b34(text, 3, 3);
        AppendNameTag_02041b70(text, item, FindEntryByKey_02072a68((TableA68*)self->strings_, id));
    }
    AppendLineXTag02041cf4(text, 0x7fff, 2, 0xdd, 0x66);
    AppendLineYTag02041d48(text, 0x7fff, 0x58, 0x10, 0x66);

    GameState* gameState = GameState::GetInstance();
    Profile021894b4* profile = GetProfile021894b4(gameState);
    GetGlobalField0x1c020421a0();
    char unused[0x20];
    __clear(unused, sizeof(unused));
    AppendXYTag_02041a90(text, ((0x88 - func_020420e8(self->titleText_, 0)) >> 1) + 0x58, 0x16);
    AppendString02042058(text, self->titleText_);

    char birthday[0x100];
    __clear(birthday, sizeof(birthday));
    const char* month = FindEntryByKey_02072a68((TableA68*)self->strings_, (short)(GetProfile021894b4(gameState)->month_ + 0x13));
    int width;
    if (GetProfile021894b4(gameState)->showBirthday_)
    {
        sprintf(birthday, data_ov012_0218b305, profile->day_, month, GetProfile021894b4(gameState)->year_);
        width = func_020420e8(birthday, 0);
    }
    else
    {
        const char* hiddenBirthday = FindEntryByKey_02072a68((TableA68*)self->strings_, 0x78);
        int length = StringLength_020d2ff0(hiddenBirthday);
        char shown[0x40];
        __clear(shown, sizeof(shown));
        memcpy(shown, hiddenBirthday + 8, length - 0x11);
        width = func_020420e8(shown, 0);
        sprintf(birthday, hiddenBirthday);
    }
    AppendXYTag_02041a90(text, ((0x88 - width) >> 1) + 0x58, 0x26);
    AppendString02042058(text, birthday);

    char accolade[0x80];
    __clear(accolade, sizeof(accolade));
    CopyTextAndUppercaseIfFlagged0206819c(self->accoladeText_, accolade, 0);
    AppendXYTag_02041a90(text, ((0x88 - func_020420e8(accolade, 0)) >> 1) + 0x58, 0x36);
    AppendString02042058(text, accolade);

    short design = 0x6d;
    unsigned int chosen = profile->designChosen_;
    if (chosen)
        design = profile->unk_0_21 + 30000;
    const char* designText = FindEntryByKey_02072a68((TableA68*)self->strings_, design);
    AppendXYTag_02041a90(text, ((0x88 - func_020420e8(designText, 0)) >> 1) + 0x58, 0x46);
    AppendString02042058(text, designText);

    char* message = (char*)profile->unk_8;
    int empty = 0;
    if (self->state_ == 14 && self->step_ >= 1 && self->step_ <= 4)
        message = self->message_;
    const char* messageText;
    if (*message == 0)
    {
        messageText = FindEntryByKey_02072a68((TableA68*)self->strings_, 0x12);
        empty = 1;
    }
    else
    {
        messageText = FindEntryByKey_02072a68((TableA68*)self->strings_, 0x13);
    }
    AppendXYTag_02041a90(text, ((0x88 - func_020420e8(messageText, 0)) >> 1) + 0x58, 0x56);
    if (empty)
        AppendPaletteTag_02041e70(text, 3);
    AppendString02042058(text, messageText);
}
