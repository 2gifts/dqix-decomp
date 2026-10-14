#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };

struct BattleStruct021ba124;

struct SearchStruct0202c1a4 { char pad[0x1038]; signed char arr[16]; };
extern "C" int* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct S_020103b4;

struct Struct02030b7c { int field0; void* field4; };

extern "C" int func_ov017_021b9bcc(int a, void* b);

struct Data021ba124_8438 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int field4;
    unsigned char pad8[8];
    int field10;
};
extern struct Data021ba124_8438 data_ov017_021d8438;

struct Data021ba124_7c54 { signed char byte0; signed char byte1; };
extern struct Data021ba124_7c54 data_ov017_021d7c54;

// USA: func_ov017_021ba124  (semantic: CheckVariantRangeAndFlags_021ba124)
extern "C" ARM int func_ov017_021ba124(struct Variant02030b0c* v, int idx) {
    if (data_ov017_021d8438.field10 != 0) return 1;
    if (data_ov017_021d7c54.byte0 > -1) return 1;
    if (data_ov017_021d8438.byte1 != 0) return 1;
    if (data_ov017_021d7c54.byte1 > -1) return 1;

    GameState::GetInstance();
    struct SearchStruct0202c1a4* search = (struct SearchStruct0202c1a4*)func_0202ae18();
    if (!CheckField0NonZero_0202b7d8((int*)search)) return 1;
    if (GetSearchStructCurrentArrEntry(search) != 0) return 1;

    int a = ((Script::Parameter*)v)->ToInt();
    struct Variant02030b0c* vn = (struct Variant02030b0c*)((char*)v + 8);
    v = (struct Variant02030b0c*)((char*)v + 16);
    int b = ((Script::Parameter*)vn)->ToInt();
    if (a >= 0 && (data_ov017_021d8438.field4 < a || b < data_ov017_021d8438.field4)) return 1;

    if (idx >= 5) {
        int c = ((Script::Parameter*)v)->ToInt();
        v = (struct Variant02030b0c*)((char*)v + 8);
        if (c != 0) {
            if (((GameState*)((struct S_020103b4*)GameState::GetInstance()))->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.byte2 = 1;
        }
    } else {
        if (data_ov017_021d8438.byte2 != 0) return 1;
    }

    int d = ((Script::Parameter*)v)->ToInt();
    void* e = (void*)((Script::Parameter*)((struct Struct02030b7c*)((char*)v + 8)))->ToString();
    if (e == 0) return 0;
    if (func_ov017_021b9bcc(d, e) != 0) data_ov017_021d8438.byte0 = 1;
    return 1;
}
