#include <globaldefs.h>

#include "Combat/WorkRecord.h"
#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct TaggedValue02030b44;
extern "C" struct TaggedValue02030b44* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct TaggedValue02030b44* obj, int* outVec);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct S_020103b4;
extern "C" struct S_020103b4* _ZN9GameState11GetInstanceEv();
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(struct S_020103b4* obj);



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

    v0 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)param0);
    if (v0 != data_02108cec.byte2) return 1;
    v1 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 8));
    if (v1 != data_02108cec.byte1) return 1;
    v2 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x10));
    if (v2 != data_02108cec.byte0) return 1;
    v3 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x18));

    {
        struct S_020103b4* gs = _ZN9GameState11GetInstanceEv();
        if (v3 == 1) {
            if (_ZNK9GameState21IsMorningDayOrEveningEv(gs)) return 1;
        } else if (v3 == 0) {
            if (!_ZNK9GameState21IsMorningDayOrEveningEv(gs)) return 1;
        }
    }

    v4 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x20));
    v5 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x28));

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

    q = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct TaggedValue02030b44*)((char*)param0 + 0x30), rec->vec);
    rec->field1c = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(q));

    if (param1 > 10) {
        rec->field1e = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)q + 8));
    }

    rec->field44 = data_02108cec.halfa;
    func_0206db48(data_02108cec.field10, rec);
    return 1;
}
