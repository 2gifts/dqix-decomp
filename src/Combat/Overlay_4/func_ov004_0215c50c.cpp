#include <globaldefs.h>
#include "GameState/GameState.h"

int DispatchNodeIfType7_02156e2c(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);
extern "C" int func_ov004_02156fd4(void* a, int key);
extern "C" int func_ov004_0215799c(void* a, int e, unsigned int kind, int d);
void CallVTableFnAt240_021f66bc(void* a, int key, void* arg3);
int NotifyCountedEvents_02159384(void* self);

struct Container020dedd0;
struct Element020de650;
Element020de650* FindElementByKey020dedd0(Container020dedd0* c, int key);

struct Struct021707d8_0215c50c { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215c50c data_ov004_021707d8;

struct ResultEntry0215c50c { short field0; short pad2; int field4; };

// USA: func_ov004_0215c50c  (semantic: RecalcCounterAndNotify_0215c50c)
extern "C" ARM int func_ov004_0215c50c(void* a) {
    int b = DispatchNodeIfType7_02156e2c(a, 0x5b);
    if (b < 0) return 0;

    ResultEntry0215c50c* entry = (ResultEntry0215c50c*)GetEntryFor_021570a4(a, (unsigned char)b);
    if (!entry) return 0;

    unsigned char orig11 = data_ov004_021707d8.ptr[0x11];
    data_ov004_021707d8.ptr[0x11] = (unsigned char)((unsigned int)(entry->field4 << 25) >> 25);

    void* ptr2a04 = GetPtrField0x2a04_02010828(GameState::GetInstance());
    unsigned int hi = (unsigned int)entry->field4 >> 7;
    unsigned int product = data_ov004_021707d8.ptr[0x11] * hi;
    int f6c = *(int*)((char*)ptr2a04 + 0xf6c);
    if ((unsigned int)f6c < product) {
        unsigned int q = (unsigned int)f6c / hi;
        data_ov004_021707d8.ptr[0x11] = (unsigned char)q;
        if (data_ov004_021707d8.ptr[0x11] < 1) data_ov004_021707d8.ptr[0x11] = 1;
    }

    int contPtr = func_ov004_02156fd4(a, 5);
    if (!contPtr) return 0;

    short shortE = *(short*)(data_ov004_021707d8.ptr + 0xe);
    Element020de650* elem = FindElementByKey020dedd0((Container020dedd0*)contPtr, shortE);
    if (!elem) return 0;

    int elemField8 = *(int*)((char*)elem + 8);
    int qret = func_ov004_0215799c(ptr2a04, entry->field0, (unsigned int)(elemField8 << 28) >> 28, *(short*)(data_ov004_021707d8.ptr + 0x3a));

    if (data_ov004_021707d8.ptr[0x11] >= (unsigned int)qret) {
        data_ov004_021707d8.ptr[0x11] = (unsigned char)qret;
        if (data_ov004_021707d8.ptr[0x11] < 1) data_ov004_021707d8.ptr[0x11] = 1;
    }

    if (data_ov004_021707d8.ptr[0x11] == 0) data_ov004_021707d8.ptr[0x11] = 1;

    if (orig11 < data_ov004_021707d8.ptr[0x11]) {
        CallVTableFnAt240_021f66bc(a, 0x25b, (void*)1);
    }

    NotifyCountedEvents_02159384(a);
    return 0;
}
