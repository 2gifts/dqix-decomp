// JPN: func_ov017_021ba8d8
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
extern "C" int func_ov017_021b9bcc(int a, const char* b);

struct Struct0130_021ba3dc {
    char pad0[4];
    unsigned short half4;
};

struct Data_ov017_021d8438 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int field4;
    unsigned char pad8[8];
    int field10;
};
extern struct Data_ov017_021d8438 data_ov017_021d8438;

struct Data_ov017_021d7c54 {
    signed char byte0;
    signed char byte1;
};
extern struct Data_ov017_021d7c54 data_ov017_021d7c54;

// USA: func_ov017_021ba3dc
extern "C" ARM int func_ov017_021ba3dc(Script::Parameter* params, int count) {
    if (data_ov017_021d8438.field10 != 0) return 1;
    if (data_ov017_021d7c54.byte1 > -1) return 1;

    GameState* battle = GameState::GetInstance();
    if (func_0202c540(func_0202ae18()) != 0) return 1;

    GameObject* leader = battle->GetGameObjectByIndex(0);
    struct Struct0130_021ba3dc* p = *(struct Struct0130_021ba3dc**)((char*)leader + 0x130);
    int pending = p->half4;
    if (pending > 0) return 1;

    int a = params[0].ToInt();
    Script::Parameter* pb = &params[1];
    params = &params[2];
    int b = pb->ToInt();
    if (a >= 0 && (data_ov017_021d8438.field4 < a || b < data_ov017_021d8438.field4)) return 1;

    if (count >= 5) {
        int c = params->ToInt();
        params++;
        if (c != 0) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.byte2 = 1;
        }
    } else {
        if (data_ov017_021d8438.byte2 != 0) return 1;
    }

    int d = params[0].ToInt();
    const char* e = params[1].ToString();
    if (e == 0) return 0;
    if (func_ov017_021b9bcc(d, e) != 0) data_ov017_021d8438.byte1 = 1;
    return 1;
}
