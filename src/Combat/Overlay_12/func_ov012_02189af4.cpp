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

extern "C" ARM void func_ov012_02189af4(char* editor, char* text, int hidden) {
    if (!text) return;
    int selection = *(int*)(editor + 0x1434) & 15;
    if (hidden)
        AppendFrameTag02041c08(text, selection, 8, 5, 5, 5);
    AppendCursorTag(text, selection);
    void* messages = GetGlobalField0x1c020421a0();
    int i;
    int end;
    int right;
    ProfileNavigation* navigation = ((ProfileWindowNavigation*)(editor + 0x90))->GetNavigation();
    int page = navigation->page;
    int pages = navigation->pages;
    int first, last;
    ComputeProductSums0205c508((UnkStruct0205c508*)navigation, &first, &last);
    end = first + (last + 1 - first) / 2;
    for (i = first; i < end; ++i) {
        if (i != first)
            AppendString02042058(text, *(const char**)(editor + 0x1348));
        AppendNameTag(text, i & 15, FindEntryByKey((TableA68*)(editor + 0x1314), (short)(i + 0x2774)));
        right = i + (last + 1 - first) / 2;
        if (right < 47) {
            AppendXTag(text, 0x56);
            AppendNameTag(text, right & 15, FindEntryByKey((TableA68*)(editor + 0x1314), (short)(right + 0x2774)));
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
    AppendString02042058(text, FindEntryByKey((TableA68*)(editor + 0x1314), 0x6a));
}

#else
#include <globaldefs.h>

struct UnkStruct0205c508;
struct TableA68;

struct Cursor02189af4
{
    int unk_0;
    int unk_4;
    int words_[6];
};

struct Window02189af4
{
    char unk_0[0x54];
    Cursor02189af4 cursor_;
    char unk_74[0x1290 - 0x74];

    Cursor02189af4* GetCursor() { return &cursor_; }
};

struct ProfileEditor02189af4
{
    char unk_0[0xac];
    Window02189af4 window_;
    char strings_[0x1378 - 0x133c];
    const char* unk_1378;
    char unk_137c[0x13d8 - 0x137c];
    int selections_[6];

    Window02189af4* GetWindow() { return &window_; }
};

void AppendFrameTag02041c08(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag(char* text, int a);
void* GetGlobalField0x1c020421a0();
void ComputeProductSums0205c508(UnkStruct0205c508* cursor, int* first, int* last);
void AppendString02042058(char* text, const char* append);
const char* FindEntryByKey(TableA68* texts, int id);
void AppendNameTag(char* text, int item, const char* itemText);
void AppendXTag(char* text, int x);
extern "C" void func_ov012_021842a0(ProfileEditor02189af4* self, int canvas, int color, int shadow);

// USA: func_ov012_02189af4
extern "C" ARM void func_ov012_02189af4(ProfileEditor02189af4* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->selections_[1] & 0xf;
    if (hidden)
        AppendFrameTag02041c08(text, selection, 8, 5, 5, 5);
    AppendCursorTag(text, selection);
    GetGlobalField0x1c020421a0();
    Cursor02189af4* cursor = self->GetWindow()->GetCursor();
    int shadow = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    ComputeProductSums0205c508((UnkStruct0205c508*)cursor, &first, &last);
    int end = first + (last + 1 - first) / 2;
    for (int i = first; i < end; i++)
    {
        if (i != first)
            AppendString02042058(text, self->unk_1378);
        AppendNameTag(text, i & 0xf, FindEntryByKey((TableA68*)self->strings_, (short)(i + 0x2846)));
        int right = i + (last + 1 - first) / 2;
        if (right < 0xc0)
        {
            AppendXTag(text, 0x56);
            AppendNameTag(text, right & 0xf, FindEntryByKey((TableA68*)self->strings_, (short)(right + 0x2846)));
        }
    }
    func_ov012_021842a0(self, 3, shadow, color);
}

#endif
