#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Container020e0310;
struct MessageSystem;
struct StoreStruct;

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* size);
extern "C" const char* func_020e046c(char* output, void* file, unsigned int size, short id);
extern "C" int func_020420e8(const char* text, int large);
extern "C" char* func_0205ec34();
extern "C" void func_02046380(MessageSystem* messages);

MessageSystem* GetGlobalField0x1c020421a0();
void AppendXYTag(char* text, int x, int y);
void AppendYTag(char* text, int y);
void AppendString02042058(char* text, const char* append);
void AppendFormatted0204201c(char* text, int append, int);
int TestBitInByteArray(int, unsigned char*, int);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
int GetFieldPercentOver307(BattleRecordSnapshot* records);
int GetFieldPercentOver944(BattleRecordSnapshot* records);
int GetFieldPercentOver232(BattleRecordSnapshot* records);
int GetFieldPercentOver448(BattleRecordSnapshot* records);
void StoreInArray0x8b0(StoreStruct* messages, int index, int value);

extern char data_ov008_0218b465[];
extern char data_ov008_0218b47c[];

struct ClearRecords
{
    char unk_0[0x10];
    unsigned int unk_10_0 : 9;
    unsigned int unk_10_9 : 14;
    unsigned int title_ : 9;
};

struct GuestRecords
{
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
};

struct Appearance
{
    unsigned char female_ : 1;
};

struct PartyData
{
    char unk_0[0x49c];
    Appearance appearance_;
};

struct Hero
{
    char unk_0[0x150];
    PartyData* partyData_;
};

struct BattleRecords
{
    char unk_0[0xa0];
    char texts_[0x18];
    char* text_;
    char unk_bc[0xb34 - 0xbc];
    GuestRecords* guestRecords_;
};

// USA: func_ov008_02188408
extern "C" ARM void func_ov008_02188408(BattleRecords* self, char* text, int kind, ClearRecords* records)
{
    if (text == NULL)
        return;
    MessageSystem* messages = GetGlobalField0x1c020421a0();
    if (records != NULL)
    {
        Hero* hero = (Hero*)GameState::GetInstance()->GetProtagonist();
        char* name = self->text_ + 0x8e0;
        BackgroundLoader::AddLockGlobal();
        unsigned int size = 0;
        char gp2[0x40];
        char inner[0x20];
        __clear(gp2, sizeof(gp2));
        __clear(inner, sizeof(inner));
        sprintf(gp2, data_ov008_0218b465, hero->partyData_->appearance_.female_);
        sprintf(inner, data_ov008_0218b47c, hero->partyData_->appearance_.female_);
        void* file = ExtractFileFromGP2(gp2, inner, &size);
        if (file != NULL)
            func_020e046c(name, file, size, (short)records->title_);
        BackgroundLoader::RemoveLockGlobal();
        int x = (0xa0 - func_020420e8(name, 1)) / 2;
        if (x < 0)
            x = 0;
        AppendXYTag(text, x, 6);
        if (name != NULL)
            AppendString02042058(text, name);
        return;
    }
    int count = 3;
    char* store = func_0205ec34();
    if (TestBitInByteArray((int)store, (unsigned char*)store + 0x8c, 0x1198))
        count = 4;
    if (kind == 0)
    {
        for (int i = 0; i < count; i++)
        {
            AppendXYTag(text, 4, i * 15 + 4);
            AppendString02042058(text, GetFieldByKey020e0434((Container020e0310*)&self->texts_, (short)(i + 0x82)));
        }
    }
    else if (kind == 1)
    {
        unsigned int count1;
        unsigned int count2;
        unsigned int count3;
        unsigned int count4;
        GuestRecords* guest = self->guestRecords_;
        if (guest != NULL)
        {
            count1 = guest->unk_8_14;
            count2 = guest->unk_c_24;
            count3 = guest->unk_8_21;
            count4 = guest->unk_10_23;
        }
        else
        {
            BattleRecordSnapshot playRecords;
            LoadBattleBlock020ac4c0(&playRecords);
            int max1 = playRecords.unknown14_0;
            int max2 = playRecords.unknown14_18;
            int max3 = playRecords.unknown14_9;
            int max4 = playRecords.unknown10_23;
            count1 = GetFieldPercentOver307(&playRecords);
            count2 = GetFieldPercentOver944(&playRecords);
            count3 = GetFieldPercentOver232(&playRecords);
            count4 = GetFieldPercentOver448(&playRecords);
            if (count1 == 0 && max1 > 0)
                count1 = 1;
            if (count2 == 0 && max2 > 0)
                count2 = 1;
            if (count3 == 0 && max3 > 0)
                count3 = 1;
            if (count4 == 0 && max4 > 0)
                count4 = 1;
        }
        func_02046380(messages);
        StoreInArray0x8b0((StoreStruct*)messages, 0, count1);
        StoreInArray0x8b0((StoreStruct*)messages, 1, count2);
        StoreInArray0x8b0((StoreStruct*)messages, 2, count3);
        StoreInArray0x8b0((StoreStruct*)messages, 3, count4);
        for (int i = 0; i < count; i++)
        {
            AppendYTag(text, i * 15 + 4);
            AppendFormatted0204201c(text, (int)GetFieldByKey020e0434((Container020e0310*)&self->texts_, (short)(i + 0x8c)), 0x18);
        }
    }
}
