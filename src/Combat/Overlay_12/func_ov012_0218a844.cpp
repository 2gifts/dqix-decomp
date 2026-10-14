#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

struct UnkStruct0205c508;
struct Container020e0310;

struct Cursor0218a844
{
    int unk_0;
    int unk_4;
    int words_[6];
};

struct Window0218a844
{
    char unk_0[0x54];
    Cursor0218a844 cursor_;
    char unk_74[LOW_REGION(0x128c, 0x1298) - 0x74];

    Cursor0218a844* GetCursor() { return &cursor_; }
};

struct ProfileEditor0218a844
{
    char unk_0[LOW_REGION(0x90, 0xac)];
    Window0218a844 window_;
    char texts_[LOW_REGION(0x1348, 0x1378) - LOW_REGION(0x131c, 0x1344)];
    const char* unk_1378;
    char unk_137c[LOW_REGION(0x1420, 0x13c8) - LOW_REGION(0x134c, 0x137c)];
    short* unk_13c8;
    char unk_13cc[LOW_REGION(0x1448, 0x13f0) - LOW_REGION(0x1424, 0x13cc)];
    int unk_13f0;

    Window0218a844* GetWindow() { return &window_; }
};

void AppendFrameTag02041c08(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag_02041ea4(char* text, int a);
void* GetGlobalField0x1c020421a0();
void ComputeProductSums0205c508(UnkStruct0205c508* cursor, int* first, int* last);
void AppendString02042058(char* text, const char* append);
void AppendXTag_02041a28(char* text, int x);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
void AppendNameTag_02041b70(char* text, int item, const char* itemText);
void AppendXYTag_02041a90(char* text, int x, int y);
#if !defined(jpn)
extern "C" void func_ov012_021842a0(ProfileEditor0218a844* self, int canvas, int color, int shadow);

extern "C" const char data_ov012_0218b310[];
#endif

#if defined(jpn)
struct StoreStruct;
struct TableA68;
extern "C" void func_02046380(void*);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
void SetByteAtIndex_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_02042428(char*, int);
const char* FindEntryByKey_02072a68(TableA68*, int);
#endif

// USA: func_ov012_0218a844
extern "C" ARM void func_ov012_0218a844(ProfileEditor0218a844* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->unk_13f0 & 0xf;
    if (hidden)
        AppendFrameTag02041c08(text, selection, 8, 5, 5, 5);
    AppendCursorTag_02041ea4(text, selection);
#if defined(jpn)
    void* messages = GetGlobalField0x1c020421a0();
#else
    GetGlobalField0x1c020421a0();
#endif
    int i;
    Cursor0218a844* cursor = self->GetWindow()->GetCursor();
    int shadow = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    ComputeProductSums0205c508((UnkStruct0205c508*)cursor, &first, &last);
    for (i = first; i < last; i++)
    {
        if (i % 2 == 0)
        {
            if (i != first)
                AppendString02042058(text, self->unk_1378);
        }
        else
        {
            AppendXTag_02041a28(text, LOW_REGION(0x7c, 0x88));
        }
        AppendNameTag_02041b70(text, i & 0xf, GetFieldByKey020e0434((Container020e0310*)self->texts_, self->unk_13c8[i]));
    }
    if (color > 1)
    {
#if defined(jpn)
        func_02046380(messages);
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, shadow + 1);
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 1, color);
        SetByteInRange_020465f0((unsigned char*)messages, 0, 2);
        SetByteInRange_020465f0((unsigned char*)messages, 1, 2);
        SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
        SetByteAtIndex_020465d8((unsigned char*)messages, 1, 0);
        func_02042428(text, 8);
        AppendString02042058(text, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x1314), 0x7a));
#else
        func_ov012_021842a0(self, 12, shadow, color);
        AppendXYTag_02041a90(text, 0x56, 0x94);
        AppendString02042058(text, data_ov012_0218b310);
#endif
    }
}
