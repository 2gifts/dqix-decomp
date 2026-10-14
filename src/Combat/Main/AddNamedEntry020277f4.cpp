#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Entry020277f4 {
    int value;
    char* str;
    char pad[0x1c];
};

struct Table020277f4 {
    char pad0[0x20];
    Entry020277f4* list;
    int count;
    int capacity;
};

// USA: func_020277f4  (semantic: AddNamedEntry020277f4)
extern "C" ARM void func_020277f4(Table020277f4* obj, int value, const char* key, void* allocator) {
    if (obj->capacity <= obj->count) return;
    obj->list[obj->count].value = value;
    char* buf = (char*)((SafeAllocator*)allocator)->Allocate(strlen(key) + 1);
    obj->list[obj->count].str = buf;
    strcpy(obj->list[obj->count].str, key);
    obj->count = obj->count + 1;
}
