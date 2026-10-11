#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct Struct021707d8_0215e148 { char pad[8]; char* ptr; };
extern Struct021707d8_0215e148 data_ov004_021707d8;

int DispatchNodeIfType7_02156e2c(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);

struct Container020dedd0;
struct Element020de650 { char pad[8]; unsigned int field8 : 4; };
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

void* ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
void InitStruct0207cc0c(char* obj);
extern "C" void func_0207d134(void* buf, int a, int b);
extern "C" void func_0207cf30(void* buf, int a, int b, int c);

#if defined(jpn)
#define MESSAGE_FLAG_OFFSET 0xa9
#else
#define MESSAGE_FLAG_OFFSET 0x9d
#endif

// USA: func_ov004_0215e148  (semantic: SetupDamageMessageOrDefault_0215e148)
extern "C" ARM int func_ov004_0215e148(void* obj) {
    if (data_ov004_021707d8.ptr != NULL && *(unsigned char*)(data_ov004_021707d8.ptr + MESSAGE_FLAG_OFFSET) != 0) {
        GameState::GetInstance();
        int key = DispatchNodeIfType7_02156e2c(obj, 0x5b);
        if (key < 0) return 0;
        void* entry = GetEntryFor_021570a4(obj, key & 0xff);
        if (!entry) return 0;
        struct Container020dedd0* node = func_ov004_02156fd4(obj, 5);
        if (!node) return 0;
        struct Element020de650* elem = FindElementByKey020dedd0(node, *(short*)entry);
        if (!elem) return 0;

        char buf[0x38];
        ((SafeAllocator*)buf)->ResetAllocatorPointer();
        ZeroInitReturn020de824(buf + 0x14);
        InitStruct0207cbe8(buf);
        InitStruct0207cbe8(buf);
        *(void**)(buf + 0x2c) = node;
        int ok = elem->field8 <= 7;
        if (ok) {
            func_0207d134(buf, *(short*)(data_ov004_021707d8.ptr + 0xe), *(signed char*)(data_ov004_021707d8.ptr + 0x11));
        } else {
            func_0207cf30(buf, *(short*)(data_ov004_021707d8.ptr + 0xe), *(unsigned char*)(data_ov004_021707d8.ptr + 0x11), 1);
        }
        InitStruct0207cc0c(buf);
    }
    return 0;
}
