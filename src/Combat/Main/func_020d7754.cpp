#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct CallbackCache0214e33c {
    short field0;
    short pad2;
    short* field4;
    void* field8;
    void** fieldC;
};
extern struct CallbackCache0214e33c data_0214e33c;

struct Elem020d7754 { short a; short b; char* c; };

int StringLength(const char* text);
extern "C" void _Z22AppendListNode020d78e0PPvS_(void** headSlot, void* srcData);
extern char data_020f2330[];

// USA: func_020d7754
extern "C" ARM int func_020d7754(Script::Parameter* params) {
    Elem020d7754 entry;
    entry.c = NULL;
    entry.a = params[0].ToInt();
    entry.b = params[1].ToInt();
    int allowed = 1;
    if (data_0214e33c.field4 != NULL && data_0214e33c.field0 != 0) {
        allowed = 0;
        for (unsigned short i = 0; i < data_0214e33c.field0; i++) {
            if (entry.a == data_0214e33c.field4[i]) allowed = 1;
        }
    }
    if (!allowed) return 1;
    const char* text = params[2].ToString();
    int length = StringLength(text);
    entry.c = (char*)((SafeAllocator*)data_0214e33c.field8)->Allocate(length + 1);
    if (entry.c == NULL) return 0;
    entry.c[length] = 0;
    sprintf(entry.c, data_020f2330, text);
    _Z22AppendListNode020d78e0PPvS_(data_0214e33c.fieldC, (void*)&entry);
    return 1;
}