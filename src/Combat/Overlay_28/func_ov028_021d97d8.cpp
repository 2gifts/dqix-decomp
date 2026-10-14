#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Entry_021d999c { short a; short b; int c; int d; };
struct EntryListStruct_021d999c;
void AppendEntry_021d999c(EntryListStruct_021d999c* obj, Entry_021d999c* item);

extern "C" void func_ov028_021d987c(void*);
struct Variant02030b0c;
struct Struct02030b7c;
int StringLength(const char* s);

struct Ctx9bc4_97d8 {
    void* field0;
    SafeAllocator* field4;
};
extern Ctx9bc4_97d8 data_ov028_021d9bc4;

// USA: func_ov028_021d97d8
extern "C" ARM int func_ov028_021d97d8(void* obj) {
    Entry_021d999c local;
    func_ov028_021d987c(&local);
    local.a = (short)((Script::Parameter*)((struct Variant02030b0c*)obj))->ToInt();
    local.c = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    local.b = (short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x10)))->ToInt();
    const char* text = (const char*)(void*)((Script::Parameter*)((struct Struct02030b7c*)((char*)obj + 0x18)))->ToString();
    if (text != 0) {
        int len = StringLength(text);
        char* buf = (char*)data_ov028_021d9bc4.field4->Allocate(len + 1);
        if (buf != 0) {
            memset(buf, 0, len);
            sprintf(buf, text);
            local.d = (int)buf;
        }
    }
    AppendEntry_021d999c((EntryListStruct_021d999c*)data_ov028_021d9bc4.field0, &local);
    return 1;
}
