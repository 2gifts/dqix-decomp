#include <globaldefs.h>
#include "GameState/GameState.h"

struct UnkStruct0205c508;
struct TableA68;

struct Cursor0218a5f0
{
    int unk_0;
    int unk_4;
    int words_[6];
};

struct Party0218a5f0
{
    char unk_0[0x49c];
    unsigned char female_ : 1;
};

struct Protagonist0218a5f0
{
    char unk_0[0x150];
    Party0218a5f0* partyData_;
};

struct ProfileEditor0218a5f0
{
    char unk_0[0xac];
    char window_[0x133c - 0xac];
    char strings_[0x1378 - 0x133c];
    const char* unk_1378;
    char unk_137c[0x13d8 - 0x137c];
    int selections_[6];
};

extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag(char* text, int a);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(UnkStruct0205c508* cursor, int* first, int* last);
extern "C" void func_0202ae18();
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);
const char* FindEntryByKey(TableA68* texts, int id);
void AppendNameTag(char* text, int item, const char* itemText);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char* text, char* output, int a);
extern "C" void func_ov012_021842a0(ProfileEditor0218a5f0* self, int canvas, int color, int shadow);

static inline Cursor0218a5f0* GetCursor0218a5f0(char* window)
{
    return (Cursor0218a5f0*)(window + 0x54);
}

// USA: func_ov012_0218a5f0
extern "C" ARM void func_ov012_0218a5f0(ProfileEditor0218a5f0* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->selections_[5] % 10;
    if (hidden)
        _Z22AppendFrameTag02041c08Pciiiii(text, selection, 8, 5, 5, 5);
    AppendCursorTag(text, selection);
    _Z26GetGlobalField0x1c020421a0v();
    Protagonist0218a5f0* protagonist;
    int i;
    Cursor0218a5f0* cursor = GetCursor0218a5f0(self->window_);
    int shadow = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((UnkStruct0205c508*)cursor, &first, &last);
    func_0202ae18();
    protagonist = (Protagonist0218a5f0*)GameState::GetInstance()->GetProtagonist();
    int base = 0x50dc;
    for (i = first; i < last; i++)
    {
        if (i != first)
            _Z20AppendString02042058PcPKc(text, self->unk_1378);
        if (i == 0)
        {
            int id = base;
            if (protagonist->partyData_->female_ == 1)
                id = 0x510e;
            const char* name = FindEntryByKey((TableA68*)self->strings_, (short)id);
            AppendNameTag(text, i % 10, name);
        }
        else
        {
            int id = 0x5140;
            if (protagonist->partyData_->female_ == 1)
                id = 0x51a4;
            const char* name = FindEntryByKey((TableA68*)self->strings_, (short)(id + i - 1));
            char converted[0x80];
            __clear(converted, sizeof(converted));
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(name, converted, 0);
            AppendNameTag(text, i % 10, converted);
        }
    }
    func_ov012_021842a0(self, 11, shadow, color);
}
