#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);
struct Obj02053f7c;
extern "C" void _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7cti(struct Obj02053f7c* obj, unsigned short a, int b);
#define SetField0x1b2IfMatchOrFlag02053f7c _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7cti
void ResetStopwatchesUnlessCurrent_021c6034(signed char* arr);

struct Source021c60a4 {
    unsigned short field0;
    unsigned short field2;
    unsigned char flags[4];
    unsigned char field8;
    unsigned char field9;
    short fieldA;
};

struct Msg021c60a4 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4;
    unsigned short field6;
    unsigned char arr[4];
    unsigned char field0xc;
    unsigned char field0xd;
    short field0xe;
    unsigned char pad2[2];
};

// USA: func_ov017_021c60a4  (semantic: BroadcastAndFlagCombatants_021c60a4)
extern "C" ARM void func_ov017_021c60a4(struct Source021c60a4* obj) {
    void* data = GetData02100044();

    struct Msg021c60a4 msg;
    msg.tag = 0x65;
    msg.field4 = obj->field0;
    int n = 4;
    unsigned char* dst = msg.arr;
    unsigned char* src = obj->flags;
    msg.field6 = obj->field2;
    do {
        *dst = *src;
        dst++;
        src++;
    } while (--n);
    msg.field0xc = obj->field8;
    msg.field0xd = obj->field9;
    msg.field0xe = obj->fieldA;
    func_0205e330(data, &msg, 0);

    GameState* bs = GameState::GetInstance();
    for (unsigned int i = 0; i < 4; i++) {
        if ((signed char)obj->flags[i] == 0) continue;
        GameObject* c = GetCombatantWithFlag0x100(bs, i);
        if (c == NULL) continue;
        SetField0x1b2IfMatchOrFlag02053f7c((struct Obj02053f7c*)c, obj->field0, 1);
    }

    ResetStopwatchesUnlessCurrent_021c6034((signed char*)msg.arr);
}
