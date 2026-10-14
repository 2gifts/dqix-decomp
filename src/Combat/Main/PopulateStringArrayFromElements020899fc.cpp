#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct02030b7c {
    int field0;
    void* field4;
};

int StringLength_020d2ff0(const char* s);

struct Target020899fc {
    char pad0[0xc];
    char** array;
    short count;
};

struct Data02108efc {
    struct Target020899fc* target;
    char pad1[0xc - 4];
    SafeAllocator* allocator;
};
extern struct Data02108efc data_02108efc;

// USA: func_020899fc  (semantic: PopulateStringArrayFromElements020899fc)
extern "C" ARM int func_020899fc(struct Struct02030b7c* elements) {
    struct Target020899fc* target = data_02108efc.target;
    char** arr;
    short count = target->count;
    short i;
    arr = (char**)data_02108efc.allocator->Allocate(count * 4);

    for (i = 0; i < count; i++) {
        char* str = (char*)(void*)((Script::Parameter*)elements)->ToString();
        elements++;

        int len = StringLength_020d2ff0(str);
        char* buf = (char*)data_02108efc.allocator->Allocate(len + 1);
        arr[i] = buf;
        memset(arr[i], 0, len + 1);
        memcpy(arr[i], str, len);
    }

    data_02108efc.target->array = arr;
    return 1;
}
