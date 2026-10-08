#include <globaldefs.h>

#include "Combat/ActionState.h"
#include "System/Memory.h"

struct State_1f9b8 {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    unsigned char field14;
    char pad15[0x3];
    int field18;
    unsigned char field1C;
    unsigned char field1D;
};

struct Stopwatch0201f9e8 {
    unsigned char state;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};

void InitStruct_0201f9b8(State_1f9b8 *state);
extern "C" void InitStopwatch0201f9e8(Stopwatch0201f9e8 *timer);
extern "C" void func_02020720(char *receiver);
void ClearRecords02026644(char *receiver);

extern State_1f9b8 data_020fdcb0[4];
extern unsigned char data_020fdcce;
struct CombatReceiverInitializationView {
    unsigned char unknown0[0x12];
    unsigned char field12;
    unsigned char unknown13[0x54a];
    unsigned char mask55d;
    unsigned char field55e;
    unsigned char unknown55f[0x45];
    int flags5a4;
    unsigned char field5a8;
    unsigned char unknown5a9[0x1bc];
    unsigned char field765;
    unsigned char unknown766[0x6];
    int field76c;
    int field770;
    int field774;
    unsigned char field778;
    unsigned char field779;
    unsigned char unknown77a[0x2];
    int field77c;
    unsigned char field780;
    unsigned char unknown781[0x237];
    unsigned char field9b8;
    unsigned char field9b9;
    unsigned char field9ba;
    unsigned char unknown9bb[0x6];
    unsigned char field9c1;
    unsigned char field9c2;
    unsigned char field9c3;
    unsigned char field9c4;
    unsigned char field9c5;
    unsigned char field9c6;
    unsigned char field9c7;
    unsigned char field9c8;
    unsigned char unknown9c9[0x3];
    int handle9cc;
    int handle9d0;
    int handle9d4;
    int handles9d8[0x8];
    int handle9f8;
    int handle9fc;
    int handlea00;
    int handlea04;
    int handlea08;
    int handlea0c;
    int handlea10;
    int handlea14;
    int handlea18;
    int handlea1c;
    int handlea20;
    int handlea24;
    int handlea28;
    int handlea2c;
    int handlea30;
    unsigned char fielda34;
    unsigned char bytesa35[0x10];
    unsigned char bytesa45[0x10];
    unsigned char bytesa55[0x20];
    unsigned char unknowna75[0x20];
    unsigned char fielda95;
    unsigned char fielda96;
    unsigned char fielda97;
    unsigned char unknowna98[0x10a];
    unsigned char bytesba2[0x40];
    unsigned char unknownbe2[0x2];
    int fieldbe4;
    int fieldbe8;
    short fieldbec;
    short fieldbee;
};

// USA: func_02020554
extern "C" ARM void func_02020554(void *receiver) {
    CombatReceiverInitializationView *obj = (CombatReceiverInitializationView *) receiver;
    VectorizedMemset(obj, 0, 0xc30);
    obj->field9c1 = 0;
    obj->field9c2 = 0;
    obj->field9c3 = 0;
    obj->field9c4 = 0;
    obj->field9c6 = 0;
    obj->fielda96 = 0;
    func_02020720((char *) obj);

    for (int i = 0; i < 4; i++) {
        InitStruct_0201f9b8(&data_020fdcb0[i]);
        (&data_020fdcce)[i * 0x20] = 0;
        InitStopwatch0201f9e8((Stopwatch0201f9e8 *) &data_020fdc60[i]);
    }

    obj->flags5a4 |= 1;
    obj->field765 = 1;
    obj->field5a8 = 0;
    obj->field12  = 0;
    obj->field9c7 = 0;
    obj->field778 = 0;
    obj->field9c5 = 0;
    obj->field76c = 0;
    obj->field770 = 0;
    obj->field774 = 0;
    obj->field779 = 0;
    obj->field9ba = 0;
    obj->field77c = 0;
    obj->field780 = 0;
    ClearRecords02026644((char *) obj);

    obj->field9b8  = 0;
    obj->field9b9  = 0;
    obj->field9c8  = 0;
    obj->mask55d   = 0xf;
    obj->field55e  = 0;
    obj->handle9cc = -1;
    obj->handle9f8 = -1;
    obj->handle9d0 = -1;
    obj->handle9d4 = -1;
    obj->handle9fc = -1;
    obj->handlea00 = -1;
    obj->handlea04 = -1;
    obj->handlea08 = -1;
    obj->handlea0c = -1;
    obj->handlea10 = -1;
    obj->handlea14 = -1;
    obj->handlea18 = -1;
    obj->handlea1c = -1;
    obj->handlea20 = -1;
    obj->handlea24 = -1;
    obj->handlea28 = -1;
    obj->handlea2c = -1;
    obj->handlea30 = -1;
    for (int i = 0; i < 8; i++) {
        obj->handles9d8[i] = -1;
    }
    obj->fielda34 = 0xff;
    VectorizedMemset(obj->bytesa35, 0, 0x10);
    VectorizedMemset(obj->bytesa45, 0, 0x10);
    VectorizedMemset(obj->bytesa55, 0, 0x20);
    obj->fielda95 = 0;
    obj->fielda97 = 0;
    VectorizedMemset(obj->bytesba2, 0, 0x40);
    obj->fieldbe4 = 0;
    obj->fieldbe8 = 0;
    obj->fieldbec = 0;
    obj->fieldbee = 0;
}
