#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"

#include <Memory/SafeAllocator.h>

struct ClearRecords {
    BattleRecordPlayClock times_[2];
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
#if !defined(jpn)
    int titleX_;
#endif
    const void* guest_;
    GuestRecords* guestRecords_;
    void* guestTexts_;
    void* guestTitles_;
    BattleRecordPlayClock times_[2];
};

struct Container020e0310;

void* GetGlobalField0x1c020421a0();
void AppendPaletteTag_02041e70(char* text, int color);
void AppendYTag_02041a5c(char* text, int y);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
void AppendString02042058(char* text, const char* append);

extern "C" {
void __clear(void* buffer, unsigned long size);
int sprintf(char* buffer, const char* format, ...);
}

#if defined(jpn)
struct StoreStruct;
extern "C" void func_02046380(void*);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
void SetByteAtIndex_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_020474a8(void*, int, const char*, char*);
#endif

// USA: func_ov008_02187278
extern "C" ARM void func_ov008_02187278(BattleRecords* self, char* text, int index, ClearRecords* records)
{
    if (text == NULL)
        return;
    BattleRecordPlayClock* time = NULL;
    BattleRecordPlayClock guestTime;
    ClearShortByteByte_02184598(&guestTime);
    if (index == 0)
    {
        GuestRecords* guest = self->guestRecords_;
        time = &self->times_[0];
        if (guest != NULL)
        {
            time = &guestTime;
            guestTime.hours = guest->hours1_;
            guestTime.minutes = self->guestRecords_->minutes1_;
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
            guestTime.hours = guest->hours2_;
            guestTime.minutes = self->guestRecords_->minutes2_;
        }
        else if (records != NULL)
        {
            time = &records->times_[1];
        }
    }
    if (time == NULL)
        return;
    GameState::GetInstance();
#if defined(jpn)
    void* messages = GetGlobalField0x1c020421a0();
    char buffer[0x40];
    __clear(buffer, sizeof(buffer));
    func_02046380(messages);
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, time->hours);
    SetByteInRange_020465f0((unsigned char*)messages, 0, 4);
    SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 1, time->minutes);
    SetByteInRange_020465f0((unsigned char*)messages, 1, 2);
    SetByteAtIndex_020465d8((unsigned char*)messages, 1, 1);
    func_020474a8(messages, 10, GetFieldByKey020e0434((Container020e0310*)&self->texts_, 0x6e), buffer);
    AppendPaletteTag_02041e70(text, 0xe);
    AppendString02042058(text, buffer);
#else
    GetGlobalField0x1c020421a0();
    AppendPaletteTag_02041e70(text, 0xe);
    AppendYTag_02041a5c(text, 2);
    char buffer[0x40];
    __clear(buffer, sizeof(buffer));
    const char* format = GetFieldByKey020e0434((Container020e0310*)&self->texts_, 0x6e);
    if (format != NULL)
        sprintf(buffer, format, time->hours, time->minutes);
    AppendString02042058(text, buffer);
#endif
}
