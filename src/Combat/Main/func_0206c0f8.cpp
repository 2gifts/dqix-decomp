#include <globaldefs.h>

#include "Combat/WorkRecord.h"
#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct TaggedValue02030b44;
struct Vector3i;

struct S_020103b4;

struct Data02108cec0206c0f8 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    unsigned short half4;
    unsigned short half6;
    unsigned short half8;
    unsigned short halfa;
    unsigned short halfc;
    unsigned short pade;
    void* field10;
    void* field14;
};
extern struct Data02108cec0206c0f8 data_02108cec;

// USA: func_0206c0f8
extern "C" ARM int func_0206c0f8(void* param0, int param1) {
    struct Rec0206bf2c* rec;
    struct TaggedValue02030b44* q;
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;

    data_02108cec.halfa = data_02108cec.halfa + 1;

    v0 = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    if (v0 != data_02108cec.byte2) return 1;
    v1 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    if (v1 != data_02108cec.byte1) return 1;
    v2 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x10)))->ToInt();
    if (v2 != data_02108cec.byte0) return 1;
    v3 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x18)))->ToInt();

    {
        struct S_020103b4* gs = (S_020103b4*)GameState::GetInstance();
        if (v3 == 1) {
            if (((GameState*)gs)->IsMorningDayOrEvening()) return 1;
        } else if (v3 == 0) {
            if (!((GameState*)gs)->IsMorningDayOrEvening()) return 1;
        }
    }

    v4 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x20)))->ToInt();
    v5 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x28)))->ToInt();

    if (v4 != data_02108cec.halfc) {
        UnlinkNodeByByteId0206dd68(data_02108cec.field10, v5);
        return 1;
    }

    rec = (struct Rec0206bf2c*)((SafeAllocator*)data_02108cec.field14)->Allocate(0x78);
    if (rec == 0) return 0;

    ClearWorkRecord0206bf2c(rec);

    rec->field4 = v0;
    rec->field5 = v1;
    rec->field6 = v2;
    rec->flagsA_b0 = (unsigned char)v3;
    rec->field2 = v4;
    rec->field0 = v5;

    if (param1 < 7) {
        UnlinkNodeByByteId0206dd68(data_02108cec.field10, v5);
        return 1;
    }

    q = (TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)((char*)param0 + 0x30)))->ToVec3fix((Vector3i*)rec->vec);
    rec->field1c = (int)(4096.0f * ((Script::Parameter*)q)->ToFloat());

    if (param1 > 10) {
        rec->field1e = ((Script::Parameter*)((struct Variant02030b0c*)((char*)q + 8)))->ToInt();
    }

    rec->field44 = data_02108cec.halfa;
    func_0206db48(data_02108cec.field10, rec);
    return 1;
}
