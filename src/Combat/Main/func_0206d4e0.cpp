#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/Script.h"
#include "Combat/WorkRecord.h"

struct Variant02030b0c;
struct TaggedValue02030b44;
struct Vector3i;

struct GameState;

extern "C" char* func_0205ec34();
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
int TestBitWithBias0206eb98(unsigned char*, int);
void UnlinkNodeByByteId0206dd68(void*, int);

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned short field0xc;
    void* field0x10;
    void* field0x14;
};
extern struct Data02108cec data_02108cec;

// USA: func_0206d4e0
extern "C" ARM int func_0206d4e0(void* param0, int param1) {
    if (param1 < 9) {
        return 0;
    }
    data_02108cec.field0xa++;
    bool even = false;
    if (param1 % 2 == 0) {
        even = true;
    }
    int n;
    int second;
    int half = (even ? param1 - 8 : param1 - 7) / 2;
    char* ctx = func_0205ec34();
    struct Variant02030b0c* arg = (struct Variant02030b0c*)param0;
    for (n = half; n > 0; n--) {
        int packed = ((Script::Parameter*)arg)->ToInt();
        struct Variant02030b0c* next = (struct Variant02030b0c*)((char*)arg + 8);
        arg = (struct Variant02030b0c*)((char*)arg + 0x10);
        second = ((Script::Parameter*)next)->ToInt();
        int mode = packed >> 16;
        if (mode == 1) {
            int hit = TestBitInByteArray_0206dfb0((int)ctx, (unsigned char*)(ctx + 0x8c), (unsigned short)packed);
            if ((second != 0 && hit == 0) || (second == 0 && hit != 0)) {
                return 1;
            }
        } else if (mode == 2) {
            int hit = TestBitWithBias0206eb98((unsigned char*)ctx, (unsigned short)packed);
            if ((second != 0 && hit == 0) || (second == 0 && hit != 0)) {
                return 1;
            }
        } else {
            return 1;
        }
    }

    int kind = ((Script::Parameter*)arg)->ToInt();
    struct GameState* gs = GameState::GetInstance();
    if (kind == 1) {
        if (gs->IsMorningDayOrEvening()) {
            return 1;
        }
    } else if (kind == 0) {
        if (!gs->IsMorningDayOrEvening()) {
            return 1;
        }
    }

    int a = ((Script::Parameter*)((struct Variant02030b0c*)((char*)arg + 8)))->ToInt();
    int b = ((Script::Parameter*)((struct Variant02030b0c*)((char*)arg + 0x10)))->ToInt();
    if (a != data_02108cec.field0xc) {
        UnlinkNodeByByteId0206dd68(data_02108cec.field0x10, b);
        return 1;
    }

    struct Rec0206bf2c* rec = (struct Rec0206bf2c*)((SafeAllocator*)data_02108cec.field0x14)->Allocate(0x78);
    if (rec == 0) {
        return 0;
    }
    ClearWorkRecord0206bf2c(rec);
    rec->field2 = (unsigned short)a;
    int rem = param1 - half * 2 - even;
    rec->field0 = (unsigned char)b;
    if (rem < 4) {
        UnlinkNodeByByteId0206dd68(data_02108cec.field0x10, rec->field0);
        return 1;
    }

    struct TaggedValue02030b44* v = (TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)((char*)arg + 0x18)))->ToVec3fix((Vector3i*)rec->vec);
    rec->field1c = (short)(4096.0f * ((Script::Parameter*)v)->ToFloat());
    if (even) {
        rec->field1e = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 8)))->ToInt();
    }
    rec->field44 = data_02108cec.field0xa;
    rec->flagsA_b1 = 1;
    func_0206db48(data_02108cec.field0x10, rec);
    return 1;
}
