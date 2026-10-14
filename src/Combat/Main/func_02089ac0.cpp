#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct02030b7c {
    int field0;
    void* field4;
};
int StringLength(const char* s);

struct Pool02089ac0 {
    char pad[0x14];
    char** strings;
    short count;
};

struct Ctx02108efc02089ac0 {
    struct Pool02089ac0* pool;
    int unk4;
    int unk8;
    SafeAllocator* alloc;
};
extern struct Ctx02108efc02089ac0 data_02108efc;

// USA: func_02089ac0
extern "C" ARM int func_02089ac0(struct Struct02030b7c* items) {
    char** strings;
    short count = data_02108efc.pool->count;
    strings = (char**)data_02108efc.alloc->Allocate(count * 4);
    for (short i = 0; i < count; i++) {
        char* text = (char*)(void*)((Script::Parameter*)items)->ToString();
        items = (struct Struct02030b7c*)((char*)items + 8);
        int len = StringLength(text);
        strings[i] = (char*)data_02108efc.alloc->Allocate(len + 1);
        memset(strings[i], 0, len + 1);
        memcpy(strings[i], text, len);
    }
    data_02108efc.pool->strings = strings;
    return 1;
}
