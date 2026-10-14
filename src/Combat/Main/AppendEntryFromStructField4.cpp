#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct02030b7c { int field0; void* field4; };

struct Name0201c470 { unsigned char v[31]; };
struct Elem0201c470 { struct Name0201c470 name; unsigned char flag; };
struct Obj0201c470 { struct Elem0201c470* base; int cap; int count; };
void AppendElem0201c470(struct Obj0201c470* obj, struct Elem0201c470* src);

struct Global020fdc14View8 {
    char pad[8];
    struct Obj0201c470* obj;
};
extern struct Global020fdc14View8 data_020fdc14;

// USA: func_0201c3a4
ARM int AppendEntryFromStructField4(struct Struct02030b7c* arg) {
    struct Elem0201c470 buf;
    void* name = (void*)((Script::Parameter*)arg)->ToString();
    memset(&buf, 0, 0x1f);
    strcpy((char*)&buf, (char*)name);
    AppendElem0201c470(data_020fdc14.obj, &buf);
    return 1;
}
