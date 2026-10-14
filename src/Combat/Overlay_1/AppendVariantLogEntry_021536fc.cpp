#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" int _ZNK6Script9Parameter5ToIntEv(void* variant);
extern "C" void* _ZNK6Script9Parameter8ToStringEv(void* s);

struct LogEntry021536fc { int val; char* str; };
struct LogHeader021536fc { int count; void* allocator; LogEntry021536fc** entries; };
extern LogHeader021536fc data_ov001_02165800;

// USA: func_ov001_021536fc  (semantic: AppendVariantLogEntry_021536fc)
extern "C" ARM int func_ov001_021536fc(void* variant) {
    int val = _ZNK6Script9Parameter5ToIntEv(variant);
    LogEntry021536fc* entries = *data_ov001_02165800.entries;
    entries[data_ov001_02165800.count].val = val;

    char* s = (char*)_ZNK6Script9Parameter8ToStringEv((char*)variant + 8);
    if (!s) {
        return 0;
    }

    unsigned int len = strlen(s);
    void* buf = ((SafeAllocator*)data_ov001_02165800.allocator)->Allocate(len + 1);
    (*data_ov001_02165800.entries)[data_ov001_02165800.count].str = (char*)buf;
    if ((*data_ov001_02165800.entries)[data_ov001_02165800.count].str == 0) {
        return 0;
    }

    strcpy((*data_ov001_02165800.entries)[data_ov001_02165800.count].str, s);
    data_ov001_02165800.count += 1;
    return 1;
}
