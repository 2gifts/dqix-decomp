#include <globaldefs.h>

class GameState
{
public:
    static GameState* GetInstance();
};

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

extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" BattleResultMember_021d94e4* _Z13Find_021d994cPvi(void* self, int id);
extern "C" int _Z33AccumulateFlaggedSlotBits02085fb4Ph(unsigned char* data);
extern "C" int _Z33AccumulateFlaggedSlotBits02086020Ph(unsigned char* data);
extern "C" int _Z33AccumulateFlaggedSlotBits0208608cPh(unsigned char* data);
extern "C" int _Z33AccumulateFlaggedSlotBits020860f8Ph(unsigned char* data);
extern "C" int _Z33AccumulateFlaggedSlotBits02086164Ph(unsigned char* data);
extern "C" int _Z33AccumulateFlaggedSlotBits020861d0Ph(unsigned char* data);
extern "C" int _Z33AccumulateFlaggedSlotBits0208623cPh(unsigned char* data);
extern "C" int _Z35AccumulateSlotBitsFromTable020862a8Ph(unsigned char* data);
extern "C" int _Z35AccumulateSlotBitsFromTable02086314Ph(unsigned char* data);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int func_020420e8(const char* text, int large);
void AppendXYTag(char* text, int x, int y);
extern "C" void _Z23AppendFormatted02041facPcii(char* text, int line, int value);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_02046380(void* messages);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(struct Obj02046574* obj, int index, char* str);
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void SetByteAtIndex(unsigned char* base, int index, unsigned char value);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" void func_02046608(void* messages, int, const char* input, char* output, int, int, int);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);

#if defined(jpn)
extern "C" void func_020474a8(void*,int,const char*,char*);
#endif
// JPN: func_ov023_021d9d08
// USA: func_ov023_021d94e4
extern "C" ARM void func_ov023_021d94e4(BattleResultWindow_021d94e4* self, char* text, unsigned char lines)
{
    if (text == NULL || self->member_ == -1)
        return;
    GameState::GetInstance();
    void* messages = _Z26GetGlobalField0x1c020421a0v();
    if (self->members_ == NULL)
        return;
    BattleResultMember_021d94e4* member = _Z13Find_021d994cPvi(self, self->member_);
    if (member == NULL)
        return;
    BattleResultStatWord_021d94e4* bonuses = member->data_.bonuses_[member->vocation_];
    unsigned char* data = (unsigned char*)&member->data_;
    short stats[9][2];
    stats[0][0] = _Z33AccumulateFlaggedSlotBits02085fb4Ph(data) + self->before_.stats_[0].first_ + bonuses[0].first_;
    stats[1][0] = _Z33AccumulateFlaggedSlotBits02086020Ph(data) + self->before_.stats_[0].second_ + bonuses[0].second_;
    stats[2][0] = _Z33AccumulateFlaggedSlotBits0208608cPh(data) + self->before_.stats_[0].third_ + bonuses[0].third_;
    stats[3][0] = _Z33AccumulateFlaggedSlotBits020860f8Ph(data) + self->before_.stats_[1].first_ + bonuses[1].first_;
    stats[4][0] = _Z33AccumulateFlaggedSlotBits02086164Ph(data) + self->before_.stats_[1].second_ + bonuses[1].second_;
    stats[5][0] = _Z33AccumulateFlaggedSlotBits020861d0Ph(data) + self->before_.stats_[1].third_ + bonuses[1].third_;
    stats[6][0] = _Z33AccumulateFlaggedSlotBits0208623cPh(data) + self->before_.stats_[2].first_ + bonuses[2].first_;
    stats[7][0] = _Z35AccumulateSlotBitsFromTable020862a8Ph(data) + self->before_.stats_[2].second_ + bonuses[2].second_;
    stats[8][0] = _Z35AccumulateSlotBitsFromTable02086314Ph(data) + self->before_.stats_[2].third_ + bonuses[2].third_;
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
    const char* title = _Z21GetFieldByKey020e0434P17Container020e0310i(self->texts_, 0x7602);
    _Z20AppendString02042058PcPKc(text, title);
    for (int line = 0; line < 9; line++) {
        if (lines != 0) {
            AppendXYTag(text, 10, line * 15 + 0x15);
            char input[0x100] = {0};
    func_02046380(messages);
    _Z22SetIndexedName02046574P11Obj02046574iPc((Obj02046574*)messages, 0, (char*)_Z21GetFieldByKey020e0434P17Container020e0310i(self->texts_, (short)(line + 0x760c)));
    short before = stats[line][0];
    StoreInArray0x8b0((StoreStruct*)messages, 0, before);
    SetByteAtIndex((unsigned char*)messages, 0, 1);
    SetByteInRange((unsigned char*)messages, 0, 3);
    short after = stats[line][1];
    StoreInArray0x8b0((StoreStruct*)messages, 1, after);
    SetByteAtIndex((unsigned char*)messages, 1, 1);
    SetByteInRange((unsigned char*)messages, 1, 3);
    int color = 15;
    if (after > before)
        color = 5;
            StoreInArray0x8b0((StoreStruct*)messages, 2, color);
            SetByteAtIndex((unsigned char*)messages, 2, 1);
            SetByteInRange((unsigned char*)messages, 2, 0);
            func_020474a8(messages,12,_Z21GetFieldByKey020e0434P17Container020e0310i(self->texts_,0x7603),input);
            _Z20AppendString02042058PcPKc(text, input);
            lines--;
        }
    }

#else
    const char* title = _Z21GetFieldByKey020e0434P17Container020e0310i(self->texts_, 0x7602);
    AppendXYTag(text, (0xd0 - func_020420e8(title, 0)) >> 1, 1);
    _Z23AppendFormatted02041facPcii(text, (int)title, 0x10);
    int line;
    const char* format = _Z21GetFieldByKey020e0434P17Container020e0310i(self->texts_, 0x7603);
    line = lines - 1;
    if (line < 0)
        return;
    AppendXYTag(text, 10, line * 15 + 0x15);
    char output[0x100] = {0};
    char input[0x100] = {0};
    func_02046380(messages);
    _Z22SetIndexedName02046574P11Obj02046574iPc((Obj02046574*)messages, 0, (char*)_Z21GetFieldByKey020e0434P17Container020e0310i(self->texts_, (short)(line + 0x760c)));
    short before = stats[line][0];
    StoreInArray0x8b0((StoreStruct*)messages, 0, before);
    SetByteAtIndex((unsigned char*)messages, 0, 1);
    SetByteInRange((unsigned char*)messages, 0, 3);
    short after = stats[line][1];
    StoreInArray0x8b0((StoreStruct*)messages, 1, after);
    SetByteAtIndex((unsigned char*)messages, 1, 1);
    SetByteInRange((unsigned char*)messages, 1, 3);
    int color = 15;
    if (after > before)
        color = 5;
    sprintf(input, format, color);
    func_02046608(messages, 12, input, output, 0xe3, 0, 1);
    _Z20AppendString02042058PcPKc(text, output);

#endif
}
