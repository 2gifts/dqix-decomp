#include <globaldefs.h>
#include "GameState/GameState.h"

int DispatchNodeIfType7_02156e2c(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);
void CallVTableFnAt240_021f66bc(void* a, int key, void* arg3);
int NotifyCountedEvents_02159384(void* self);

struct Struct021707d8_02159888 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_02159888 data_ov004_021707d8;

struct EntryStruct02159888 { short field0; short pad2; unsigned int field4 : 7; };

void* GetPtrField0x2a04_02010828(GameState* battleStruct);

struct Container020dedd0;
struct Element020de650 { char pad[8]; unsigned int field8 : 4; };
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

extern "C" unsigned int func_ov004_0215799c(void* a, int b, int c, int d);

// USA: func_ov004_02159888  (semantic: TryConsumeEntryAndDispatch_02159888)
extern "C" ARM int func_ov004_02159888(void* obj) {
    int key = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (key < 0) return 0;

    EntryStruct02159888* entry = (EntryStruct02159888*)GetEntryFor_021570a4(obj, (unsigned char)key);
    if (!entry) return 0;

    if (data_ov004_021707d8.ptr[0x11] >= entry->field4) return 0;

    void* ptr2a04 = GetPtrField0x2a04_02010828(GameState::GetInstance());
    unsigned int cap = *(unsigned int*)((char*)entry + 4) >> 7;
    if (*(unsigned int*)((char*)ptr2a04 + 0xf6c) < (data_ov004_021707d8.ptr[0x11] + 1) * cap) return 0;

    struct Container020dedd0* node = func_ov004_02156fd4(obj, 5);
    if (!node) return 0;

    struct Element020de650* elem = FindElementByKey020dedd0(node, *(short*)(data_ov004_021707d8.ptr + 0xe));
    if (!elem) return 0;

    unsigned int r = func_ov004_0215799c(ptr2a04, entry->field0, elem->field8, *(short*)(data_ov004_021707d8.ptr + 0x3a));
    if (data_ov004_021707d8.ptr[0x11] >= r) return 0;

    data_ov004_021707d8.ptr[0x11] = data_ov004_021707d8.ptr[0x11] + 1;
    CallVTableFnAt240_021f66bc(obj, 0x25b, (void*)1);
    NotifyCountedEvents_02159384(obj);
    return 0;
}
