#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Data021b9e30 {
    unsigned char byte0, byte1, byte2, pad3;
    int field4, field8, fieldc, field10;
    void* field14;
    int field18, field1c, field20;
};
struct Selected021b9e30 { signed char selected; signed char pending; };
extern Data021b9e30 data_ov017_021d8438;
extern Selected021b9e30 data_ov017_021d7c54;
struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct PackedNibbleArray0206e2dc;
extern "C" PackedNibbleArray0206e120* func_0205ec34(GameState*);
int CheckFlagAndThreshold0206e31c(int, int);
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260*, int);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc*, int);
extern "C" int func_ov017_021b9bcc(int, const void*);
static inline int NibbleEquals021b9e30(PackedNibbleArray0206e120* fields, int index, int value) {
    return GetPackedNibbleField(fields, index) == value;
}

// USA: func_ov017_021b9e30
extern "C" ARM int func_ov017_021b9e30(Script::Parameter* params, int count) {
    if (data_ov017_021d8438.field10) return 1;
    if (data_ov017_021d8438.byte1) return 1;
    if (data_ov017_021d7c54.pending > -1) return 1;
    PackedNibbleArray0206e120* fields = func_0205ec34(GameState::GetInstance());
    int index = params->ToInt();
    if (!CheckFlagAndThreshold0206e31c((int)fields, index)) return 1;
    if (data_ov017_021d7c54.selected != index && data_ov017_021d7c54.selected > -1 && !NibbleEquals021b9e30(fields, index, 1) && !NibbleEquals021b9e30(fields, index, 2)) {
        if (!NibbleEquals021b9e30(fields, data_ov017_021d7c54.selected, 3) || !NibbleEquals021b9e30(fields, index, 3) || data_ov017_021d7c54.selected > index) return 1;
    }
    Script::Parameter* condition = params + 1;
    params += 2;
    switch (condition->ToInt()) {
    case -1:
        if (!NibbleEquals021b9e30(fields, index, 0)) return 1;
        break;
    case 0:
        if (!NibbleEquals021b9e30(fields, index, 2)) return 1;
        break;
    case 1:
        if (!GetPackedNibbleFlag0x4((PackedNibbleArray0206e260*)fields, index)) return 1;
        break;
    case 2:
        if (!NibbleEquals021b9e30(fields, index, 3)) return 1;
        break;
    case 3:
        if (!NibbleEquals021b9e30(fields, index, 1)) return 1;
        break;
    case 4:
        if (!GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)fields, index) || !NibbleEquals021b9e30(fields, index, 0)) return 1;
        break;
    }
    if (count >= 5) {
        int daytime = params->ToInt();
        params++;
        if (daytime) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.byte2 = 1;
        }
    } else if (data_ov017_021d8438.byte2) return 0;
    int value = params->ToInt();
    const char* name = params[1].ToString();
    if (!name) return 0;
    if (func_ov017_021b9bcc(value, name)) data_ov017_021d7c54.selected = index;
    return 1;
}
