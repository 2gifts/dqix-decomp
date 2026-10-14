#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct StrTable0201f308;
struct Struct02030b7c;

void AddString0201f308(StrTable0201f308*, char*, SafeAllocator*);

struct Container0201eff0 {
    int f0;
    SafeAllocator* alloc;
    StrTable0201f308* table;
};
extern Container0201eff0 data_020fdc40;

// USA: func_0201eff0
ARM int AddStringIfPresent0201eff0(Struct02030b7c* p) {
    char* str = (char*)(void*)((Script::Parameter*)p)->ToString();
    if (str != NULL) {
        AddString0201f308(data_020fdc40.table, str, data_020fdc40.alloc);
    }
    return 1;
}
