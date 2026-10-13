#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

#if defined(jpn)
#define AllocateNameBuffer02026b0c func_02026470
#define SetEntry02026b3c func_020264a0
#endif

struct Entry0201f8d0 { Script::Parameter key; Script::Parameter value; };
struct Obj02026b0c;
struct Obj02026b3c;
#if defined(jpn)
extern "C" void func_02026470(struct Obj02026b0c* p, int n);
extern "C" void func_020264a0(struct Obj02026b3c* obj, unsigned int index, unsigned short id, const char* name);
#endif

void ClearRecords02026644(char* obj);
void AllocateNameBuffer02026b0c(struct Obj02026b0c* p, int n);
#if !defined(jpn)
extern "C" void _Z16SetEntry02026b3cP11Obj02026b3cjsPKc(Obj02026b3c*, unsigned int, unsigned short, const char*);
#define SetEntry02026b3c _Z16SetEntry02026b3cP11Obj02026b3cjsPKc
#endif

// USA: func_0201f8d0  (semantic: PopulateEntriesFromVariantPairs0201f8d0)
extern "C" ARM int func_0201f8d0(struct Entry0201f8d0* list, int n) {
    int count = n / 2;
    void* obj = data_020fdc4c.currentObject;
    ClearRecords02026644((char*)obj);
    obj = data_020fdc4c.currentObject;
    AllocateNameBuffer02026b0c((struct Obj02026b0c*)obj, count & 0xff);
    struct Entry0201f8d0* p = list;
    for (int i = 0; i < count; i++) {
        int id = p->key.ToInt();
        const Script::Parameter* val = &p->value;
        p++;
        const char* name = val->ToString();
        obj = data_020fdc4c.currentObject;
        SetEntry02026b3c((struct Obj02026b3c*)obj, (unsigned char)i, id, name);
    }
    return 1;
}
