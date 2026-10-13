#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include "Filesystem/BackgroundLoader.h"

struct ClearTasksAndResetFlags02155508Struct {
    unsigned char pad0[LOW_REGION(0x34, 0x1b4)];
    unsigned int field1b4;
    unsigned int field1b8;
    unsigned char pad1[0x1c0 - 0x1bc];
    unsigned int field1c0;
    unsigned char pad2[0xad4 - 0x1c4];
    int taskA;
    int taskB;
    unsigned char pad3[0xade - 0xadc];
    unsigned char byteAde;
    unsigned char byteAdf;
    unsigned char pad4[0xae2 - 0xae0];
    unsigned short flags;
};

// USA: func_ov006_02155508
extern "C" ARM void func_ov006_02155508(ClearTasksAndResetFlags02155508Struct* s) {
    if (s->flags & 1)
        return;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (s->taskA >= 0) {
        loader->RemoveTask(s->taskA);
        s->taskA = -1;
    }
    s->taskA = -1;

    s->byteAde = 0;
    s->flags &= ~2;

    if (s->taskB >= 0) {
        loader->RemoveTask(s->taskB);
        s->taskB = -1;
    }
    s->taskB = -1;

    s->byteAdf = 0;
    s->field1b4 = 0;
    s->field1b8 = 0;
    s->field1c0 = 0;

    s->flags = (s->flags | 1) & ~4;
}
