#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

struct PlayTime {
    unsigned short hours_;
    unsigned char minutes_;
    unsigned char seconds_;
};

struct ClearRecords {
    PlayTime times_[2];
    unsigned int unk_8_0 : 17;
    unsigned int unk_8_17 : 7;
    unsigned int unk_8_24 : 7;
    unsigned int unk_8_31 : 1;
    unsigned int unk_c_0 : 17;
    unsigned int unk_c_17 : 7;
    unsigned int unk_c_24 : 7;
    unsigned int unk_c_31 : 1;
    unsigned int unk_10_0 : 9;
    unsigned int unk_10_9 : 14;
    unsigned int title_ : 9;
    unsigned int unk_14_0 : 8;
    unsigned int unk_14_8 : 14;
    unsigned int unk_14_22 : 10;
};

struct PlayRecords {
    PlayTime playTime_;
    PlayTime unk_4;
    unsigned int unk_8_0 : 24;
    unsigned int unk_8_24 : 8;
    unsigned int unk_c_0 : 7;
    unsigned int unk_c_7 : 7;
    unsigned int unk_c_14 : 14;
    unsigned int unk_c_28 : 4;
    unsigned int unk_10_0 : 9;
    unsigned int unk_10_9 : 14;
    unsigned int unk_10_23 : 9;
};

struct GameFlags {
    unsigned int flags_[15];
};

struct SavedRecords {
    GameFlags flags_;
    PlayRecords records_;
};

struct GuestRecords {
    unsigned int hours1_ : 14;
    unsigned int unk_0_14 : 17;
    unsigned int unk_0_31 : 1;
    unsigned int hours2_ : 14;
    unsigned int unk_4_14 : 17;
    unsigned int unk_4_31 : 1;
    unsigned int minutes1_ : 7;
    unsigned int minutes2_ : 7;
    unsigned int unk_8_14 : 7;
    unsigned int unk_8_21 : 7;
    unsigned int unk_8_28 : 4;
    unsigned int unk_c_0 : 10;
    unsigned int unk_c_10 : 14;
    unsigned int unk_c_24 : 7;
    unsigned int unk_c_31 : 1;
    unsigned int unk_10_0 : 9;
    unsigned int unk_10_9 : 14;
    unsigned int unk_10_23 : 7;
    unsigned int unk_10_30 : 2;
    short title_;
    unsigned char female_ : 1;
    unsigned char unk_16_1 : 4;
    unsigned char unk_16_5 : 3;
    unsigned char unk_17;
};

struct TextTable {
    int pad_0[0x18 / 4];
};

struct BackgroundGraphics {
    int pad_0[0x20 / 4];
};

struct TextWindow {
    int pad_0[0xbc / 4];
};

struct Canvas {
    int pad_0[0xe0 / 4];
};

struct WindowCursor {
    int pad_0[0x40 / 4];
};

struct Object3D {
    int pad_0[0xac / 4];
};

struct BattleRecords {
    SafeAllocator allocator_;
    SafeAllocator backgroundAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator guideAllocator_;
    TextTable texts_;
    char* text_;
    char titleTable_[0x14];
    BackgroundGraphics backgrounds_[3];
    TextWindow window_;
    Canvas canvases_[6];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char itemCount_;
    WindowCursor cursor_;
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    void* guide_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char loadStep_;
    unsigned char exit_;
    short title_;
    short comment_;
    int flags_;
    int unk_b1c;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char top_;
    unsigned char closed_;
    int titleX_;
    const void* guest_;
    GuestRecords* guestRecords_;
    void* guestTexts_;
    void* guestTitles_;
    PlayTime times_[2];
};

struct GameState {
    static GameState* GetInstance();
};

struct StoreStruct;
struct Container020e0310;

extern char data_ov008_0218b4c3[];

extern "C" unsigned char* _Z26GetGlobalField0x1c020421a0v();
void CopyOutBattleField0x7ac0(void* count);
void StoreInArray0x8b0(StoreStruct* messages, int index, int value);
void SetByteInRange(unsigned char* messages, int index, unsigned char digits);
void SetByteAtIndex(unsigned char* messages, int index, unsigned char value);
void AppendPaletteTag(char* text, int color);
int TestBitInByteArray(int store, unsigned char* bits, int flag);
void AppendXYTag(char* text, int x, int y);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);

extern "C" {
void __clear(void* buffer, unsigned long size);
void func_02046380(unsigned char* messages);
char* func_0205ec34();
unsigned long strlen(const char* text);
void* memcpy(void* destination, const void* source, unsigned long size);
char* strstr(const char* text, const char* search);
}

// USA: func_ov008_02187b20
extern "C" ARM void func_ov008_02187b20(BattleRecords* self, char* text, ClearRecords* records)
{
    SavedRecords* saved;
    int y;
    if (text == NULL)
        return;
    unsigned char* messages = _Z26GetGlobalField0x1c020421a0v();
    int count1;
    unsigned int count2;
    unsigned char shown;
    count2 = 0;
    saved = (SavedRecords*)((char*)GameState::GetInstance() + 0x104 + 0x7400);
    int count3;
    GuestRecords* guest = self->guestRecords_;
    int count4;
    int count5;
    int count6;
    if (guest != NULL)
    {
        count1 = guest->unk_4_14;
        count2 = guest->unk_0_14;
        count3 = self->guestRecords_->unk_c_0;
        count4 = self->guestRecords_->unk_10_0;
        count5 = self->guestRecords_->unk_c_10;
        count6 = self->guestRecords_->unk_10_9;
    }
    else if (records != NULL)
    {
        count1 = records->unk_8_0;
        count2 = records->unk_c_0;
        count3 = records->unk_10_0;
        count4 = records->unk_14_0;
        count5 = records->unk_10_9;
        count6 = records->unk_14_8;
    }
    else
    {
        count1 = saved->records_.unk_8_0;
        CopyOutBattleField0x7ac0(&count2);
        count3 = saved->records_.unk_10_0;
        count4 = saved->records_.unk_8_24;
        count5 = saved->records_.unk_c_14;
        count6 = saved->records_.unk_10_9;
    }
    if (self->page_ != NULL)
        count3--;
    if (count1 > 99999)
        count1 = 99999;
    if ((int)count2 > 99999)
        count2 = 99999;
    if (count3 > 999)
        count3 = 999;
    if (count4 > 999)
        count4 = 999;
    if (count5 > 9999)
        count5 = 9999;
    if (count6 > 9999)
        count6 = 9999;
    func_02046380(messages);
    StoreInArray0x8b0((StoreStruct*)messages, 0, count1);
    SetByteInRange(messages, 0, 5);
    SetByteAtIndex(messages, 0, 1);
    StoreInArray0x8b0((StoreStruct*)messages, 1, count2);
    SetByteInRange(messages, 1, 5);
    SetByteAtIndex(messages, 1, 1);
    StoreInArray0x8b0((StoreStruct*)messages, 2, count3);
    SetByteInRange(messages, 2, 5);
    char* store;
    SetByteAtIndex(messages, 2, 1);
    StoreInArray0x8b0((StoreStruct*)messages, 3, count4);
    SetByteInRange(messages, 3, 5);
    SetByteAtIndex(messages, 3, 1);
    StoreInArray0x8b0((StoreStruct*)messages, 4, count5);
    SetByteInRange(messages, 4, 5);
    SetByteAtIndex(messages, 4, 1);
    StoreInArray0x8b0((StoreStruct*)messages, 5, count6);
    SetByteInRange(messages, 5, 5);
    SetByteAtIndex(messages, 5, 1);
    AppendPaletteTag(text, 0xe);
    store = func_0205ec34();
    shown = 0;
    if (records != NULL)
    {
        for (int i = 0; i < 6; i++)
            shown += 1 << i;
    }
    else
    {
        shown += 1;
        if (TestBitInByteArray((int)store, (unsigned char*)(store + 0x8c), 0x1198))
            shown += 2;
        shown += 4;
        if (saved->records_.unk_8_24 != 0)
            shown += 8;
        if (saved->records_.unk_c_14 != 0)
            shown += 0x10;
        if (TestBitInByteArray((int)store, (unsigned char*)(store + 0x8c), 0x1199))
            shown += 0x20;
    }
    int line = 0;
    for (int i = 0; i < 6; i++)
    {
        if (shown & (1 << i))
        {
            char label[0x40];
            y = line * 14;
            AppendXYTag(text, 2, y + 7);
            __clear(label, sizeof(label));
            const char* name = _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&self->texts_, (short)(i + 0x78));
            memcpy(label, name, strlen(name));
            char* value = strstr(label, data_ov008_0218b4c3);
            if (value != NULL)
                *value = 0;
            _Z20AppendString02042058PcPKc(text, label);
            AppendXYTag(text, 0x62, y + 7);
            _Z20AppendString02042058PcPKc(text, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&self->texts_, (short)(i + 500)));
            line++;
        }
    }
}
