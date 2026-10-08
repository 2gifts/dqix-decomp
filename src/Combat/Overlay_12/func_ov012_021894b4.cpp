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

extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag(char* text, int a);
const char* FindEntryByKey(TableA68* texts, int id);
extern "C" int func_020420e8(const char* text, int large);
void AppendXTag(char* text, int x);
extern "C" void _Z23AppendFormatted02041facPcii(char* text, int line, int a);
void AppendHeightTag(char* text, int a);
void AppendNameTag(char* text, int item, const char* itemText);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);
void AppendWidthHeightTag(char* text, int a, int b);
extern "C" void _Z22AppendLineXTag02041cf4Pciiii(char* text, int a, int b, int c, int d);
extern "C" void _Z22AppendLineYTag02041d48Pciiii(char* text, int a, int b, int c, int d);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void __clear(void* buffer, unsigned long size);
void AppendXYTag(char* text, int x, int y);
int StringLength(const char* text);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char* text, char* output, int a);
void AppendPaletteTag(char* text, int color);

extern "C" const short data_ov012_0218af92[];
extern "C" const char data_ov012_0218b305[];

static inline Profile021894b4* GetProfile021894b4(GameState* gameState)
{
    return (Profile021894b4*)((char*)gameState + 0x569c);
}

// USA: func_ov012_021894b4
extern "C" ARM void func_ov012_021894b4(ProfileEditor021894b4* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->selection_;
    if (hidden)
        _Z22AppendFrameTag02041c08Pciiiii(text, selection, 8, 5, 5, 5);
    AppendCursorTag(text, selection);
    const char* title = FindEntryByKey((TableA68*)self->strings_, 1);
    AppendXTag(text, (0xe0 - func_020420e8(title, 0)) >> 1);
    _Z23AppendFormatted02041facPcii(text, (int)title, 0x10);
    AppendHeightTag(text, 3);
    AppendNameTag(text, 0, FindEntryByKey((TableA68*)self->strings_, 2));
    int item;
    const short* texts = data_ov012_0218af92;
    for (item = 1;; item++, texts++)
    {
        short id = *texts;
        if (id < 0)
            break;
        _Z20AppendString02042058PcPKc(text, self->unk_1378);
        if (item == 5)
            AppendWidthHeightTag(text, 3, 3);
        AppendNameTag(text, item, FindEntryByKey((TableA68*)self->strings_, id));
    }
    _Z22AppendLineXTag02041cf4Pciiii(text, 0x7fff, 2, 0xdd, 0x66);
    _Z22AppendLineYTag02041d48Pciiii(text, 0x7fff, 0x58, 0x10, 0x66);

    GameState* gameState = GameState::GetInstance();
    Profile021894b4* profile = GetProfile021894b4(gameState);
    _Z26GetGlobalField0x1c020421a0v();
    char unused[0x20];
    __clear(unused, sizeof(unused));
    AppendXYTag(text, ((0x88 - func_020420e8(self->titleText_, 0)) >> 1) + 0x58, 0x16);
    _Z20AppendString02042058PcPKc(text, self->titleText_);

    char birthday[0x100];
    __clear(birthday, sizeof(birthday));
    const char* month = FindEntryByKey((TableA68*)self->strings_, (short)(GetProfile021894b4(gameState)->month_ + 0x13));
    int width;
    if (GetProfile021894b4(gameState)->showBirthday_)
    {
        sprintf(birthday, data_ov012_0218b305, profile->day_, month, GetProfile021894b4(gameState)->year_);
        width = func_020420e8(birthday, 0);
    }
    else
    {
        const char* hiddenBirthday = FindEntryByKey((TableA68*)self->strings_, 0x78);
        int length = StringLength(hiddenBirthday);
        char shown[0x40];
        __clear(shown, sizeof(shown));
        memcpy(shown, hiddenBirthday + 8, length - 0x11);
        width = func_020420e8(shown, 0);
        sprintf(birthday, hiddenBirthday);
    }
    AppendXYTag(text, ((0x88 - width) >> 1) + 0x58, 0x26);
    _Z20AppendString02042058PcPKc(text, birthday);

    char accolade[0x80];
    __clear(accolade, sizeof(accolade));
    _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(self->accoladeText_, accolade, 0);
    AppendXYTag(text, ((0x88 - func_020420e8(accolade, 0)) >> 1) + 0x58, 0x36);
    _Z20AppendString02042058PcPKc(text, accolade);

    short design = 0x6d;
    unsigned int chosen = profile->designChosen_;
    if (chosen)
        design = profile->unk_0_21 + 30000;
    const char* designText = FindEntryByKey((TableA68*)self->strings_, design);
    AppendXYTag(text, ((0x88 - func_020420e8(designText, 0)) >> 1) + 0x58, 0x46);
    _Z20AppendString02042058PcPKc(text, designText);

    char* message = (char*)profile->unk_8;
    int empty = 0;
    if (self->state_ == 14 && self->step_ >= 1 && self->step_ <= 4)
        message = self->message_;
    const char* messageText;
    if (*message == 0)
    {
        messageText = FindEntryByKey((TableA68*)self->strings_, 0x12);
        empty = 1;
    }
    else
    {
        messageText = FindEntryByKey((TableA68*)self->strings_, 0x13);
    }
    AppendXYTag(text, ((0x88 - func_020420e8(messageText, 0)) >> 1) + 0x58, 0x56);
    if (empty)
        AppendPaletteTag(text, 3);
    _Z20AppendString02042058PcPKc(text, messageText);
}
