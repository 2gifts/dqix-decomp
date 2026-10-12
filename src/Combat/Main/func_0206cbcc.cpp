#include <globaldefs.h>
#include "Resource/Script.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Combat/WorkRecord.h"

struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct PackedNibbleArray0206e2dc;
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260*, int);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc*, int);
extern "C" PackedNibbleArray0206e120* func_0205ec34();
void UnlinkNodeByByteId0206dd68(void*, int);
struct Data02108cec {
    int field0;
    short wait;
    short group;
    short previous;
    unsigned short serial;
    unsigned short level;
    unsigned short field_e;
    void* list;
    SafeAllocator* allocator;
};
extern Data02108cec data_02108cec;
static inline int IsNibble0206cbcc(PackedNibbleArray0206e120* table, int index, int value) {
    return GetPackedNibbleField(table, index) == value;
}

// USA: func_0206cbcc
extern "C" ARM int func_0206cbcc(Script::Parameter* params, int count) {
    data_02108cec.serial++;
    PackedNibbleArray0206e120* table;
    int index = params[0].ToInt();
    int condition = params[1].ToInt();
    int day = params[2].ToInt();
    int level = params[3].ToInt();
    int group = params[4].ToInt();
    if (data_02108cec.group != group) {
        data_02108cec.group = group;
        data_02108cec.previous = -1;
        data_02108cec.wait = -1;
    }
    if (data_02108cec.wait > 0) return 1;
    table = func_0205ec34();
    if (data_02108cec.previous != index && data_02108cec.previous > -1 &&
        !IsNibble0206cbcc(table, index, 1) && !IsNibble0206cbcc(table, index, 2) &&
        IsNibble0206cbcc(table, data_02108cec.previous, 3) && IsNibble0206cbcc(table, index, 3)) {
        if (data_02108cec.previous > index) return 1;
    }
    switch (condition) {
    case -1: if (!IsNibble0206cbcc(table, index, 0)) return 1; break;
    case 3: if (!IsNibble0206cbcc(table, index, 1)) return 1; break;
    case 0: if (!IsNibble0206cbcc(table, index, 2)) return 1; break;
    case 1: if (!GetPackedNibbleFlag0x4((PackedNibbleArray0206e260*)table, index)) return 1; break;
    case 2: if (!IsNibble0206cbcc(table, index, 3)) return 1; break;
    case 4: if (!GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)table, index) || !IsNibble0206cbcc(table, index, 0)) return 1; break;
    }
    GameState* state = GameState::GetInstance();
    if (day == 1) { if (state->IsMorningDayOrEvening()) return 1; }
    else if (day == 0) { if (!state->IsMorningDayOrEvening()) return 1; }
    if (level != data_02108cec.level) {
        UnlinkNodeByByteId0206dd68(data_02108cec.list, group);
        return 1;
    }
    Rec0206bf2c* record = (Rec0206bf2c*)data_02108cec.allocator->Allocate(0x78);
    if (!record) return 0;
    ClearWorkRecord0206bf2c(record);
    record->field46 = index;
    record->flagsA_b0 = (unsigned char)day;
    record->field2 = level;
    record->field0 = group;
    if (count < 6) {
        UnlinkNodeByByteId0206dd68(data_02108cec.list, group);
        data_02108cec.previous = index;
        return 1;
    }
    Script::Parameter* value = params[5].ToVec3fix((Vector3fix*)record->vec);
    record->field1c = (int)(4096.0f * value->ToFloat());
    if (count > 9) record->field1e = value[1].ToInt();
    record->field44 = data_02108cec.serial;
    func_0206db48(data_02108cec.list, record);
    data_02108cec.previous = index;
    return 1;
}
