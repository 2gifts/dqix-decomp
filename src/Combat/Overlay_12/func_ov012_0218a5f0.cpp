#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct TableA68;
struct UnkStruct0205c508;
struct StoreStruct;
struct ProfileNavigation {
    int count;
    int pages;
    int columns;
    int rows;
    int mode;
    int page;
};

struct ProfileWindowNavigation {
    unsigned char unknown[0x54];
    ProfileNavigation navigation;
    ProfileNavigation* GetNavigation() { return &navigation; }
};

void AppendFrameTag02041c08(char*, int, int, int, int, int);
int AppendCursorTag(char*, int);
void* GetGlobalField0x1c020421a0();
void ComputeProductSums0205c508(UnkStruct0205c508*, int*, int*);
int AppendString02042058(char*, const char*);
const char* FindEntryByKey(TableA68*, int);
int AppendNameTag(char*, int, const char*);
int AppendXTag(char*, int);
extern "C" void func_02046380(void*);
void StoreInArray0x8b0(StoreStruct*, int, int);
void SetByteInRange(unsigned char*, int, unsigned char);
void SetByteAtIndex(unsigned char*, int, unsigned char);
extern "C" void func_02042428(char*, int);
extern "C" void func_0202ae18();

extern "C" ARM void func_ov012_0218a5f0(char* editor, char* text, int hidden) {
    if (!text) return;
    int selection = *(int*)(editor + 0x1444) % 10;
    if (hidden)
        AppendFrameTag02041c08(text, selection, 8, 5, 5, 5);
    AppendCursorTag(text, selection);
    void* messages = GetGlobalField0x1c020421a0();
    int i;
    ProfileNavigation* navigation = ((ProfileWindowNavigation*)(editor + 0x90))->GetNavigation();
    int page = navigation->page;
    int pages = navigation->pages;
    int first, last;
    ComputeProductSums0205c508((UnkStruct0205c508*)navigation, &first, &last);
    func_0202ae18();
    GameState::GetInstance();
    for (i = first; i < last; ++i) {
        if (i != first)
            AppendString02042058(text, *(const char**)(editor + 0x1348));
        if (i == 0) {
            const char* name = FindEntryByKey((TableA68*)(editor + 0x1314), 0x50dc);
            AppendNameTag(text, i % 10, name);
        } else {
            const char* name = FindEntryByKey((TableA68*)(editor + 0x1314), (short)(0x5140 + i - 1));
            AppendNameTag(text, i % 10, name);
        }
    }
    func_02046380(messages);
    StoreInArray0x8b0((StoreStruct*)messages, 0, page + 1);
    StoreInArray0x8b0((StoreStruct*)messages, 1, pages);
    SetByteInRange((unsigned char*)messages, 0, 2);
    SetByteInRange((unsigned char*)messages, 1, 2);
    SetByteAtIndex((unsigned char*)messages, 0, 1);
    SetByteAtIndex((unsigned char*)messages, 1, 0);
    func_02042428(text, 8);
    AppendString02042058(text, FindEntryByKey((TableA68*)(editor + 0x1314), 0x6b));
}

#else
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

struct Window0218a5f0
{
    char unk_0[0x54];
    Cursor0218a5f0 cursor_;
    char unk_74[0x1290 - 0x74];

    Cursor0218a5f0* GetCursor() { return &cursor_; }
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
    Window0218a5f0 window_;
    char strings_[0x1378 - 0x133c];
    const char* unk_1378;
    char unk_137c[0x13d8 - 0x137c];
    int selections_[6];

    Window0218a5f0* GetWindow() { return &window_; }
};

void AppendFrameTag02041c08(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag(char* text, int a);
void* GetGlobalField0x1c020421a0();
void ComputeProductSums0205c508(UnkStruct0205c508* cursor, int* first, int* last);
extern "C" void func_0202ae18();
void AppendString02042058(char* text, const char* append);
const char* FindEntryByKey(TableA68* texts, int id);
void AppendNameTag(char* text, int item, const char* itemText);
extern "C" void __clear(void* buffer, unsigned long size);
void CopyTextAndUppercaseIfFlagged0206819c(const char* text, char* output, int a);
extern "C" void func_ov012_021842a0(ProfileEditor0218a5f0* self, int canvas, int color, int shadow);

// USA: func_ov012_0218a5f0
extern "C" ARM void func_ov012_0218a5f0(ProfileEditor0218a5f0* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->selections_[5] % 10;
    if (hidden)
        AppendFrameTag02041c08(text, selection, 8, 5, 5, 5);
    AppendCursorTag(text, selection);
    GetGlobalField0x1c020421a0();
    Protagonist0218a5f0* protagonist;
    int i;
    Cursor0218a5f0* cursor = self->GetWindow()->GetCursor();
    int shadow = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    ComputeProductSums0205c508((UnkStruct0205c508*)cursor, &first, &last);
    func_0202ae18();
    protagonist = (Protagonist0218a5f0*)GameState::GetInstance()->GetProtagonist();
    int base = 0x50dc;
    for (i = first; i < last; i++)
    {
        if (i != first)
            AppendString02042058(text, self->unk_1378);
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
            CopyTextAndUppercaseIfFlagged0206819c(name, converted, 0);
            AppendNameTag(text, i % 10, converted);
        }
    }
    func_ov012_021842a0(self, 11, shadow, color);
}

#endif
