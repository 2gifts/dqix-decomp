#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x3b0Value(GameState* battleStruct);
extern "C" void _Z20AdvanceActor020a20d8Pv(void* actor);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

struct Struct021931b4;
extern "C" void _Z22PushArrayValue021931b4P14Struct021931b4i(struct Struct021931b4* s, int v);
struct Owner_021931cc;
extern "C" int _Z11Pop021931ccP14Owner_021931cc(struct Owner_021931cc* o);
extern "C" void func_ov015_02192700(void* obj, int a1);
struct S0218f1c4;
extern "C" ARM void func_ov015_0218f1c4(struct S0218f1c4* obj);

struct ListNode02190d7c {
    int value;
    struct ListNode02190d7c* next;
};

struct S02190d7c {
    char pad0[0x2c];
    struct ListNode02190d7c* list;
    char pad1[0x38 - 0x2c - 4];
    signed char field38;
    char pad2[0x194 - 0x38 - 1];
    int field194;
    int field198;
    char pad3[0x1a4 - 0x198 - 4];
    int field1a4;
};

// USA: func_ov015_02190d7c
extern "C" ARM void func_ov015_02190d7c(struct S02190d7c* obj) {
    GameState* bs = GameState::GetInstance();
    if (bs == 0) {
        return;
    }
    int f3b0 = GetField0x3b0Value(bs);
    if (f3b0 != 0) {
        _Z20AdvanceActor020a20d8Pv((void*)f3b0);
    }

    struct ListNode02190d7c* node = obj->list;
    while (node != 0) {
        func_ov015_0218f1c4((struct S0218f1c4*)node->value);
        node = node->next;
    }

    if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 4)) {
        return;
    }

    int tmp = obj->field194;
    obj->field194 = obj->field198;
    obj->field198 = tmp;

    int v;
    if (obj->field194 == 2) {
        _Z22PushArrayValue021931b4P14Struct021931b4i((struct Struct021931b4*)obj, obj->field1a4);
        obj->field1a4 = 0x23;
        goto cleanup;
    }

    do {
        v = _Z11Pop021931ccP14Owner_021931cc((struct Owner_021931cc*)obj);
    } while (v >= 0x23);

    signed char state = obj->field38;
    if (state >= 0) {
        switch (state) {
        case 0:
        case 1:
            while (v >= 0xf) {
                v = _Z11Pop021931ccP14Owner_021931cc((struct Owner_021931cc*)obj);
            }
            goto reset;
        case 2:
            while (v >= 0x21) {
                v = _Z11Pop021931ccP14Owner_021931cc((struct Owner_021931cc*)obj);
            }
            goto reset;
        default:
        reset:
            obj->field38 = -1;
            if (obj->field194 == 1) {
                obj->field194 = 0;
            }
            break;
        }
    }

    obj->field1a4 = v;
cleanup:
    func_ov015_02192700(obj, 0);
}
