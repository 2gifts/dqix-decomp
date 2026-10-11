#include <globaldefs.h>

#include "Combat/WorkRecord.h"
#include "Combat/NodeLookup.h"

#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct TaggedValue02030b44;
extern "C" struct TaggedValue02030b44* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct TaggedValue02030b44* obj, int* outVec);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct S_020103b4;
extern "C" struct S_020103b4* _ZN9GameState11GetInstanceEv();
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(struct S_020103b4* obj);

struct Data02108cec0206c2c0 {
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
extern struct Data02108cec0206c2c0 data_02108cec;

// USA: func_0206c2c0
extern "C" ARM int func_0206c2c0(void* param0, int param1) {
    struct Rec0206bf2c* rec;
    struct TaggedValue02030b44* q;
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int v6;
    int v7;
    int v8;
    int key;
    int lo;
    int hi;

    data_02108cec.halfa = data_02108cec.halfa + 1;

    v0 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)param0);
    v1 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 8));
    v2 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x10));
    v3 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x18));
    v4 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x20));
    v5 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x28));

    hi = v3 * 1000 + v4 * 10 + v5;
    key = data_02108cec.byte0 + (data_02108cec.byte2 * 1000 + data_02108cec.byte1 * 10);
    lo = v0 * 1000 + v1 * 10 + v2;
    if (key < lo || hi < key) {
        return 1;
    }

    v6 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x30));

    {
        struct S_020103b4* gs = _ZN9GameState11GetInstanceEv();
        if (v6 == 1) {
            if (_ZNK9GameState21IsMorningDayOrEveningEv(gs)) return 1;
        } else if (v6 == 0) {
            if (!_ZNK9GameState21IsMorningDayOrEveningEv(gs)) return 1;
        }
    }

    v7 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x38));
    v8 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x40));

    if (v7 != data_02108cec.halfc) {
        UnlinkNodeByByteId0206dd68(data_02108cec.field10, v8);
        return 1;
    }

    rec = (struct Rec0206bf2c*)((SafeAllocator*)data_02108cec.field14)->Allocate(0x78);
    if (rec == 0) return 0;

    ClearWorkRecord0206bf2c(rec);

    rec->field4 = v0;
    rec->field5 = v1;
    rec->field6 = v2;
    rec->field7 = v3;
    rec->field8 = v4;
    rec->pad9 = v5;
    rec->flagsA_b0 = v6;
    rec->field2 = v7;
    rec->field0 = v8;

    if (param1 < 10) {
        UnlinkNodeByByteId0206dd68(data_02108cec.field10, v8);
        return 1;
    }

    q = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct TaggedValue02030b44*)((char*)param0 + 0x48), rec->vec);
    rec->field1c = (unsigned short)(int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(q));

    if (param1 > 13) {
        rec->field1e = (unsigned char)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)q + 8));
    }

    rec->field44 = data_02108cec.halfa;
    func_0206db48(data_02108cec.field10, rec);
    return 1;
}
