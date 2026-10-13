#include <globaldefs.h>
#include "std_library_functions.h"

struct StringPair18a38 { char* name; char* value; };
struct PairList18a38 { StringPair18a38* entries; int capacity; int count; };
typedef char* (*Allocate18a38)(const char*, unsigned int);
typedef void (*Release18a38)(const char*, char*, int);
#if defined(jpn)
#define data_ov031_02249f40 data_ov031_0224ab40
#define data_ov031_02249f60 data_ov031_0224ab60
#define data_ov031_02249f80 data_ov031_0224ab80
#define data_ov031_02249f9c data_ov031_0224ab9c
#endif
extern char data_ov031_02249f40[];
extern char data_ov031_02249f60[];
extern char data_ov031_02249f80[];
extern char data_ov031_02249f9c[];

// USA: func_ov031_02218a38
extern "C" ARM int func_ov031_02218a38(void* allocator, PairList18a38* list, const char* name, const char* value) {
    Allocate18a38 allocate = *(Allocate18a38*)((char*)allocator + 0x1010);
    Release18a38 release = *(Release18a38*)((char*)allocator + 0x1014);
    if (list->count > list->capacity) return 0;
    list->entries[list->count].name = allocate(data_ov031_02249f40, strlen(name) + 1);
    if (list->entries[list->count].name != NULL) {
        list->entries[list->count].value = allocate(data_ov031_02249f60, strlen(value) + 1);
        if (list->entries[list->count].value != NULL) {
            strcpy(list->entries[list->count].name, name);
            strcpy(list->entries[list->count].value, value);
            list->count++;
            return 1;
        }
    }
    if (list->entries[list->count].name != NULL) {
        release(data_ov031_02249f80, list->entries[list->count].name, 0);
        list->entries[list->count].name = NULL;
    }
    StringPair18a38* entries = list->entries;
    int count = list->count;
    if (entries[count].value != NULL) {
        release(data_ov031_02249f9c, entries[count].value, 0);
        list->entries[list->count].value = NULL;
    }
    return 0;
}
