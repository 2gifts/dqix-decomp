#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

struct PlayTime {
    unsigned short hours_;
    unsigned char minutes_;
    unsigned char seconds_;
};

struct ClearRecords {
    PlayTime times_[2];
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

struct _Z27ClearShortByteByte_02184598P27ClearShortByteByte_02184598;
struct Container020e0310;

extern "C" void _Z27ClearShortByteByte_02184598P27ClearShortByteByte_02184598(struct _Z27ClearShortByteByte_02184598P27ClearShortByteByte_02184598* time);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
void AppendPaletteTag(char* text, int color);
void AppendYTag(char* text, int y);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);

extern "C" {
void __clear(void* buffer, unsigned long size);
int sprintf(char* buffer, const char* format, ...);
}

// USA: func_ov008_02187278
extern "C" ARM void func_ov008_02187278(BattleRecords* self, char* text, int index, ClearRecords* records)
{
    if (text == NULL)
        return;
    PlayTime* time = NULL;
    PlayTime guestTime;
    _Z27ClearShortByteByte_02184598P27ClearShortByteByte_02184598((struct _Z27ClearShortByteByte_02184598P27ClearShortByteByte_02184598*)&guestTime);
    if (index == 0)
    {
        GuestRecords* guest = self->guestRecords_;
        time = &self->times_[0];
        if (guest != NULL)
        {
            time = &guestTime;
            guestTime.hours_ = guest->hours1_;
            guestTime.minutes_ = self->guestRecords_->minutes1_;
        }
        else if (records != NULL)
        {
            time = &records->times_[0];
        }
    }
    else if (index == 1)
    {
        GuestRecords* guest = self->guestRecords_;
        time = &self->times_[1];
        if (guest != NULL)
        {
            time = &guestTime;
            guestTime.hours_ = guest->hours2_;
            guestTime.minutes_ = self->guestRecords_->minutes2_;
        }
        else if (records != NULL)
        {
            time = &records->times_[1];
        }
    }
    if (time == NULL)
        return;
    GameState::GetInstance();
    _Z26GetGlobalField0x1c020421a0v();
    AppendPaletteTag(text, 0xe);
    AppendYTag(text, 2);
    char buffer[0x40];
    __clear(buffer, sizeof(buffer));
    const char* format = _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&self->texts_, 0x6e);
    if (format != NULL)
        sprintf(buffer, format, time->hours_, time->minutes_);
    _Z20AppendString02042058PcPKc(text, buffer);
}
