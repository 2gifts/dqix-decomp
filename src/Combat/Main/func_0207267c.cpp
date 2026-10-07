#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct Elem02072a28 { short a; int b; };
struct List02072a28;
extern "C" void _Z27AppendShortWordPair02072a28P12List02072a28P12Elem02072a28(List02072a28* list, Elem02072a28* src);
int StringLength(const char* text);
struct ScriptStringState0207267c {
    unsigned char skipCount;
    unsigned char padding;
    unsigned short filterCount;
    char* destination;
    short* filterIds;
    SafeAllocator* allocator;
    List02072a28* list;
};
extern ScriptStringState0207267c data_02108db0;
extern char data_020f0cf0[];

// USA: func_0207267c
extern "C" ARM int func_0207267c(Script::Parameter* params) {
    Elem02072a28 entry;
    entry.b = 0;
    entry.a = (params++)->ToInt();
    int allowed = 1;
    if (data_02108db0.filterIds != NULL && data_02108db0.filterCount != 0) {
        allowed = 0;
        for (unsigned short i = 0; i < data_02108db0.filterCount; i++) {
            if (entry.a == data_02108db0.filterIds[i]) allowed = 1;
        }
    }
    if (!allowed) return 1;
    for (unsigned char i = 0; i < data_02108db0.skipCount; i++) {
        (params++)->ToString();
    }
    int length;
    const char* text = params->ToString();
    if (data_02108db0.destination != NULL) {
        if (text != NULL) strcpy(data_02108db0.destination, text);
        return 1;
    }
    length = 0;
    if (text != NULL) length = StringLength(text);
    entry.b = (int)data_02108db0.allocator->Allocate(length + 1);
    if (entry.b == 0) return 0;
    ((char*)entry.b)[length] = 0;
    if (entry.b != 0) sprintf((char*)entry.b, data_020f0cf0, text);
    _Z27AppendShortWordPair02072a28P12List02072a28P12Elem02072a28(data_02108db0.list, &entry);
    return 1;
}
