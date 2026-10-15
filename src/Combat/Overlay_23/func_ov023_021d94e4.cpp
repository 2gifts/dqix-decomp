#include <globaldefs.h>
#include "GameState/GameState.h"

struct BattleResultStatWord_021d94e4
{
    unsigned int first_ : 10;
    unsigned int second_ : 10;
    unsigned int third_ : 10;
};

struct BattleResultStats_021d94e4
{
    int unk_0;
    unsigned short level_ : 7;
    unsigned short skillPoints_ : 9;
    short unk_6;
    BattleResultStatWord_021d94e4 stats_[3];
};

struct PartyMemberData_021d94e4
{
#if defined(jpn)
    char pad0[0x7b8];
#else
    char pad0[0x850];
#endif

    BattleResultStatWord_021d94e4 bonuses_[13][3];
};

struct BattleResultMember_021d94e4
{
    unsigned char id_;
    unsigned char vocation_;
    unsigned char level_;
    unsigned char dead_;
    int experience_;
#if defined(jpn)
    char name_[0xc];
#else
    char name_[0x30];
#endif

    PartyMemberData_021d94e4 data_;
};

struct Container020e0310;

struct BattleResultWindow_021d94e4
{
    struct Container020e0310* texts_;
    char pad4[0xec - 4];
    int member_;
    BattleResultStats_021d94e4 before_;
    BattleResultStats_021d94e4 after_;
    unsigned char lines_;
    unsigned char count_;
    unsigned char state_;
    unsigned char loadStep_;
    unsigned char step_;
    signed char timer_;
    unsigned char memberCount_;
    BattleResultMember_021d94e4* members_;
};

struct Obj02046574;
struct StoreStruct;

void* GetGlobalField0x1c020421a0();
BattleResultMember_021d94e4* Find_021d994c(void* self, int id);
int AccumulateFlaggedSlotBits02085fb4(unsigned char* data);
int AccumulateFlaggedSlotBits02086020(unsigned char* data);
int AccumulateFlaggedSlotBits0208608c(unsigned char* data);
int AccumulateFlaggedSlotBits020860f8(unsigned char* data);
int AccumulateFlaggedSlotBits02086164(unsigned char* data);
int AccumulateFlaggedSlotBits020861d0(unsigned char* data);
int AccumulateFlaggedSlotBits0208623c(unsigned char* data);
int AccumulateSlotBitsFromTable020862a8(unsigned char* data);
int AccumulateSlotBitsFromTable02086314(unsigned char* data);
const char* GetFieldByKey020e0434(struct Container020e0310* c, int key);
extern "C" int func_020420e8(const char* text, int large);
void AppendXYTag_02041a90(char* text, int x, int y);
void AppendFormatted02041fac(char* text, int line, int value);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_02046380(void* messages);
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" void func_02046608(void* messages, int, const char* input, char* output, int, int, int);
void AppendString02042058(char* text, const char* append);

#if defined(jpn)
extern "C" void func_020474a8(void*,int,const char*,char*);
#endif
// USA: func_ov023_021d94e4
extern "C" ARM void func_ov023_021d94e4(BattleResultWindow_021d94e4* self, char* text, unsigned char lines)
{
    if (text == NULL || self->member_ == -1)
        return;
    GameState::GetInstance();
    void* messages = GetGlobalField0x1c020421a0();
    if (self->members_ == NULL)
        return;
    BattleResultMember_021d94e4* member = Find_021d994c(self, self->member_);
    if (member == NULL)
        return;
    BattleResultStatWord_021d94e4* bonuses = member->data_.bonuses_[member->vocation_];
    unsigned char* data = (unsigned char*)&member->data_;
    short stats[9][2];
    stats[0][0] = AccumulateFlaggedSlotBits02085fb4(data) + self->before_.stats_[0].first_ + bonuses[0].first_;
    stats[1][0] = AccumulateFlaggedSlotBits02086020(data) + self->before_.stats_[0].second_ + bonuses[0].second_;
    stats[2][0] = AccumulateFlaggedSlotBits0208608c(data) + self->before_.stats_[0].third_ + bonuses[0].third_;
    stats[3][0] = AccumulateFlaggedSlotBits020860f8(data) + self->before_.stats_[1].first_ + bonuses[1].first_;
    stats[4][0] = AccumulateFlaggedSlotBits02086164(data) + self->before_.stats_[1].second_ + bonuses[1].second_;
    stats[5][0] = AccumulateFlaggedSlotBits020861d0(data) + self->before_.stats_[1].third_ + bonuses[1].third_;
    stats[6][0] = AccumulateFlaggedSlotBits0208623c(data) + self->before_.stats_[2].first_ + bonuses[2].first_;
    stats[7][0] = AccumulateSlotBitsFromTable020862a8(data) + self->before_.stats_[2].second_ + bonuses[2].second_;
    stats[8][0] = AccumulateSlotBitsFromTable02086314(data) + self->before_.stats_[2].third_ + bonuses[2].third_;
    stats[0][1] = stats[0][0] + self->after_.stats_[0].first_;
    stats[1][1] = stats[1][0] + self->after_.stats_[0].second_;
    stats[2][1] = stats[2][0] + self->after_.stats_[0].third_;
    stats[3][1] = stats[3][0] + self->after_.stats_[1].first_;
    stats[4][1] = stats[4][0] + self->after_.stats_[1].second_;
    stats[5][1] = stats[5][0] + self->after_.stats_[1].third_;
    stats[6][1] = stats[6][0] + self->after_.stats_[2].first_;
    stats[7][1] = stats[7][0] + self->after_.stats_[2].second_;
    stats[8][1] = stats[8][0] + self->after_.stats_[2].third_;
    for (int i = 0; i < 9; i++)
    {
        if (i == 7)
        {
            if (stats[i][0] <= 0)
                stats[i][0] = 1;
            if (stats[i][1] <= 0)
                stats[i][1] = 1;
        }
        else
        {
            if (stats[i][0] < 0)
                stats[i][0] = 0;
            if (stats[i][1] < 0)
                stats[i][1] = 0;
        }
        if (stats[i][0] > 999)
            stats[i][0] = 999;
        if (stats[i][1] > 999)
            stats[i][1] = 999;
    }
#if defined(jpn)
    const char* title = GetFieldByKey020e0434(self->texts_, 0x7602);
    AppendString02042058(text, title);
    for (int line = 0; line < 9; line++) {
        if (lines != 0) {
            AppendXYTag_02041a90(text, 10, line * 15 + 0x15);
            char input[0x100] = {0};
    func_02046380(messages);
    SetIndexedName02046574((Obj02046574*)messages, 0, (char*)GetFieldByKey020e0434(self->texts_, (short)(line + 0x760c)));
    short before = stats[line][0];
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, before);
    SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
    SetByteInRange_020465f0((unsigned char*)messages, 0, 3);
    short after = stats[line][1];
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 1, after);
    SetByteAtIndex_020465d8((unsigned char*)messages, 1, 1);
    SetByteInRange_020465f0((unsigned char*)messages, 1, 3);
    int color = 15;
    if (after > before)
        color = 5;
            StoreInArray0x8b0_020465c0((StoreStruct*)messages, 2, color);
            SetByteAtIndex_020465d8((unsigned char*)messages, 2, 1);
            SetByteInRange_020465f0((unsigned char*)messages, 2, 0);
            func_020474a8(messages,12,GetFieldByKey020e0434(self->texts_,0x7603),input);
            AppendString02042058(text, input);
            lines--;
        }
    }

#else
    const char* title = GetFieldByKey020e0434(self->texts_, 0x7602);
    AppendXYTag_02041a90(text, (0xd0 - func_020420e8(title, 0)) >> 1, 1);
    AppendFormatted02041fac(text, (int)title, 0x10);
    int line;
    const char* format = GetFieldByKey020e0434(self->texts_, 0x7603);
    line = lines - 1;
    if (line < 0)
        return;
    AppendXYTag_02041a90(text, 10, line * 15 + 0x15);
    char output[0x100] = {0};
    char input[0x100] = {0};
    func_02046380(messages);
    SetIndexedName02046574((Obj02046574*)messages, 0, (char*)GetFieldByKey020e0434(self->texts_, (short)(line + 0x760c)));
    short before = stats[line][0];
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, before);
    SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
    SetByteInRange_020465f0((unsigned char*)messages, 0, 3);
    short after = stats[line][1];
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 1, after);
    SetByteAtIndex_020465d8((unsigned char*)messages, 1, 1);
    SetByteInRange_020465f0((unsigned char*)messages, 1, 3);
    int color = 15;
    if (after > before)
        color = 5;
    sprintf(input, format, color);
    func_02046608(messages, 12, input, output, 0xe3, 0, 1);
    AppendString02042058(text, output);

#endif
}
