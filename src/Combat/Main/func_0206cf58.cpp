#include <globaldefs.h>
#include "Resource/Script.h"
#include "GameState/GameState.h"
#include "Combat/WorkRecord.h"
#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"

struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct PackedNibbleArray0206e2dc;
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260*, int);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc*, int);
extern "C" PackedNibbleArray0206e120* func_0205ec34();
static inline int NibbleIs0206cf58(PackedNibbleArray0206e120* table, int slot, int value)
{
    return GetPackedNibbleField(table, slot) == value;
}
struct WorkGlobals0206cf58
{
    unsigned char day;
    unsigned char month;
    unsigned char year;
    char pad3;
    short slot;
    short id;
    short state;
    unsigned short sequence;
    unsigned short expected;
    char pade[2];
    void* receiver;
    SafeAllocator* allocator;
};
extern WorkGlobals0206cf58 data_02108cec;

// USA: func_0206cf58
extern "C" ARM int func_0206cf58(Script::Parameter* params, int count)
{
    PackedNibbleArray0206e120* table;
    Rec0206bf2c* record;
    data_02108cec.sequence++;
    int slot = params[0].ToInt();
    int mode = params[1].ToInt();
    int startYear = params[2].ToInt();
    int startMonth = params[3].ToInt();
    int startDay = params[4].ToInt();
    int endYear = params[5].ToInt();
    int endMonth = params[6].ToInt();
    int endDay = params[7].ToInt();
    int daytime = params[8].ToInt();
    int expected = params[9].ToInt();
    int id = params[10].ToInt();
    if (data_02108cec.id != id)
    {
        data_02108cec.id = id;
        data_02108cec.state = -1;
        data_02108cec.slot = -1;
    }
    table = func_0205ec34();
    if (data_02108cec.slot != slot && data_02108cec.slot > -1)
    {
        if (NibbleIs0206cf58(table, slot, 1) || NibbleIs0206cf58(table, slot, 2))
        {
        }
        else if (NibbleIs0206cf58(table, data_02108cec.slot, 3) && NibbleIs0206cf58(table, slot, 3))
        {
            if (data_02108cec.slot > slot)
                return 1;
        }
    }
    switch (mode)
    {
    case -1:
        if (!NibbleIs0206cf58(table, slot, 0)) return 1;
        break;
    case 3:
        if (!NibbleIs0206cf58(table, slot, 1)) return 1;
        break;
    case 0:
        if (!NibbleIs0206cf58(table, slot, 2)) return 1;
        break;
    case 1:
        if (!GetPackedNibbleFlag0x4((PackedNibbleArray0206e260*)table, slot)) return 1;
        break;
    case 2:
        if (!NibbleIs0206cf58(table, slot, 3)) return 1;
        break;
    case 4:
        if (GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)table, slot) && NibbleIs0206cf58(table, slot, 0))
        {
        }
        else return 1;
        break;
    }
    int lastDate = endDay + (endYear * 1000 + endMonth * 10);
    int date = data_02108cec.day + (data_02108cec.year * 1000 + (short)data_02108cec.month * (short)10);
    int firstDate = startDay + (startYear * 1000 + startMonth * 10);
    if (date < firstDate || lastDate < date)
        return 1;
    GameState* game = GameState::GetInstance();
    if (daytime == 1)
    {
        if (game->IsMorningDayOrEvening())
            return 1;
    }
    else if (daytime == 0)
    {
        if (!game->IsMorningDayOrEvening())
            return 1;
    }
    if (expected != data_02108cec.expected)
    {
        UnlinkNodeByByteId0206dd68(data_02108cec.receiver, id);
        return 1;
    }
    record = (Rec0206bf2c*)data_02108cec.allocator->Allocate(0x78);
    if (record == NULL)
        return 0;
    ClearWorkRecord0206bf2c(record);
    record->field46 = slot;
    record->field4 = startYear;
    record->field5 = startMonth;
    record->field6 = startDay;
    record->field7 = endYear;
    record->field8 = endMonth;
    record->pad9 = endDay;
    record->flagsA_b0 = (unsigned char)daytime;
    record->field2 = expected;
    record->field0 = id;
    if (data_02108cec.id != id)
        data_02108cec.id = id;
    if (count < 12)
    {
        UnlinkNodeByByteId0206dd68(data_02108cec.receiver, id);
        data_02108cec.slot = slot;
        return 1;
    }
    Script::Parameter* next = params[11].ToVec3fix((Vector3fix*)record->vec);
    record->field1c = (int)(4096.0f * next->ToFloat());
    if (count > 15)
        record->field1e = next[1].ToInt();
    record->field44 = data_02108cec.sequence;
    record->flagsA_b3 = 1;
    func_0206db48(data_02108cec.receiver, record);
    data_02108cec.slot = slot;
    return 1;
}
