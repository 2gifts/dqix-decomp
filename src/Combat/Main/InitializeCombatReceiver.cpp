#include <globaldefs.h>

#include "Combat/ActionState.h"
#include "Combat/MapDisplay.h"
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
void ClearRecords02026644(char *receiver);

extern State_1f9b8 data_020fdcb0[4];
#if defined(jpn)
extern unsigned char data_020fda36;
#define data_020fdcce data_020fda36
#else
extern unsigned char data_020fdcce;
#endif

// USA: func_02020554
extern "C" ARM void func_02020554(MapDisplay *obj) {
#if defined(jpn)
    VectorizedMemset(obj, 0, 0xad8);
#else
    VectorizedMemset(obj, 0, 0xc30);
#endif
    obj->field9c1 = 0;
    obj->loadStage = 0;
    obj->field9c3 = 0;
    obj->field9c4 = 0;
    obj->field9c6 = 0;
    obj->fielda96 = 0;
    func_02020720(obj);

    for (int i = 0; i < 4; i++) {
        InitStruct_0201f9b8(&data_020fdcb0[i]);
        (&data_020fdcce)[i * 0x20] = 0;
        InitStopwatch0201f9e8((Stopwatch0201f9e8 *) &data_020fdc60[i]);
    }

    obj->flags |= 1;
    obj->field765 = 1;
    obj->field5a8 = 0;
    obj->field12  = 0;
    obj->failed = 0;
    obj->field778 = 0;
    obj->field9c5 = 0;
    obj->field76c = 0;
    obj->field770 = 0;
    obj->field774 = 0;
    obj->refreshRecords = 0;
    obj->field9ba = 0;
    obj->field77c = 0;
    obj->field780 = 0;
    ClearRecords02026644((char *) obj);

    obj->field9b8  = 0;
    obj->field9b9  = 0;
    obj->field9c8  = 0;
    obj->mask55d   = 0xf;
    obj->field55e  = 0;
    obj->fileTask920 = -1;
#if !defined(jpn)
    obj->scriptTask = -1;
#endif
    obj->namesTask = -1;
    obj->fileTask928 = -1;
    obj->task9fc = -1;
    obj->taska00 = -1;
    obj->taska04 = -1;
    obj->taska08 = -1;
    obj->taska0c = -1;
    obj->taska10 = -1;
    obj->taska14 = -1;
    obj->taska18 = -1;
    obj->taska1c = -1;
    obj->taska20 = -1;
    obj->taska24 = -1;
    obj->taska28 = -1;
    obj->taska2c = -1;
    obj->fileTask984 = -1;
    for (int i = 0; i < 8; i++) {
        obj->nameTasks[i] = -1;
    }
    obj->fielda34 = 0xff;
    VectorizedMemset(obj->bytesa35, 0, 0x10);
    VectorizedMemset(obj->bytesa45, 0, 0x10);
    VectorizedMemset(obj->bytesa55, 0, 0x20);
    obj->fielda95 = 0;
    obj->fielda97 = 0;
#if !defined(jpn)
    VectorizedMemset(obj->scriptName, 0, 0x40);
    obj->scriptNameWidth = 0;
    obj->fieldb3c = 0;
    obj->fieldb40 = 0;
    obj->fieldb42 = 0;
#endif
}
