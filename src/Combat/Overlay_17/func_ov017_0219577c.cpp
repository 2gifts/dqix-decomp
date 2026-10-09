#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
extern "C" void func_ov017_021acd7c(void* obj);
extern "C" void _Z37InitCombatPairAndResetGlobal_021adb50Pc(char* obj);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);
struct Field3f8Struct;
Field3f8Struct* GetField0x3f8Address(GameState* bs);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);
extern "C" void func_02046a8c(void* list, void* node);
extern "C" int _Z24UpdatePlayClocks020ac4f8i(int commit);
extern "C" void func_ov017_021d1118(int a, int b, int c, int d);

struct Field3f8Struct0219577c {
    unsigned short field_0;
    unsigned char field_2;
    unsigned char pad3;
    unsigned char field_4;
    unsigned char pad5[2];
    unsigned char active;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char pada;
    signed char field_b;
    unsigned char field_c;
    unsigned char padd[3];
    Vector3i pos;
    short angle;
    short field_1e;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    unsigned char pad30[0x35];
    unsigned char field_65;
    unsigned char field_66;
    unsigned char pad67[5];
    short field_6c;
};

struct Node0219577c {
    unsigned char pad0[2];
    unsigned char busy;
    unsigned char pad3[0x27c];
    unsigned char field_27f;
    unsigned char field_280;
    unsigned char field_281;
    unsigned char field_282;
};

// USA: func_ov017_0219577c
extern "C" ARM void func_ov017_0219577c(unsigned char mode, int resetField, int append) {
    GameState* gs = GameState::GetInstance();
    char* ctx = (char*)func_ov017_0218b5b0();
    void* list = *(void**)(ctx + 0x3000 + 0x6fc);
    func_02012fe4();
    Node0219577c* node = *(Node0219577c**)(ctx + 0x3000 + 0xb20);
    if (node->busy) return;

    func_ov017_021acd7c(node);
    node->field_280 = 1;
    node->field_27f = mode;
    node->field_281 = resetField == 0;
    node->field_282 = append == 0;
    if (mode == 0 && append != 0) {
        _Z37InitCombatPairAndResetGlobal_021adb50Pc((char*)node);
    }
    AppendNodeToTail((struct TailList020469b4*)list, (struct TailNode020469b4*)node);

    if (resetField) {
        Field3f8Struct0219577c* field = (Field3f8Struct0219577c*)GetField0x3f8Address(gs);
        VectorizedMemset(field, 0, 0x70);
        field->field_4 = 1;
        field->field_8 = 1;
        field->field_9 = 1;
        field->field_b = -1;
        field->field_20 = -1;
        field->field_24 = -1;
        field->field_28 = -1;
        field->field_2c = -1;
        field->field_1e = -1;
        field->field_c = 0;
        field->field_6c = -1;
        field->field_2 = 1;
        field->field_0 = 0xc3b5;
        field->active = 1;
        field->angle = 0;
        field->pos.x = 0x48cc;
        field->pos.y = 0x199;
        field->pos.z = -0x733;
        field->field_66 = 1;
        field->field_65 = 1;

        if (ListContainsId((struct ListHead02046b60*)list, 0x4e)) {
            func_02046a8c(list, *(void**)(ctx + 0x3000 + 0xca4));
        }
        if (ListContainsId((struct ListHead02046b60*)list, 3)) {
            func_02046a8c(list, *(void**)(ctx + 0x3000 + 0x70c));
        }
    }
    if (ListContainsId((struct ListHead02046b60*)list, 0x40)) {
        func_02046a8c(list, *(void**)(ctx + 0x3000 + 0xb98));
    }
    _Z24UpdatePlayClocks020ac4f8i(1);
    if (mode) {
        func_ov017_021d1118(-1, 1, 1, 2);
    }
}
