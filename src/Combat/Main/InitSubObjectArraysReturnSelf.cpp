#include <globaldefs.h>

struct Container0203a54c;

void ProcessAllSubObjects0203a54c(struct Container0203a54c* c);
void* NotifyThenResetNameTable_0201c108(void* obj);
extern "C" void func_0200ef44(void* base, int count, int size, void* (*ctor)(void*));

// USA: func_0203a8d4
ARM struct Container0203a54c* InitSubObjectArraysReturnSelf_0203a8d4(struct Container0203a54c* obj) {
    ProcessAllSubObjects0203a54c(obj);
    func_0200ef44((char*)obj + 0x2a8, 5, 0x88, NotifyThenResetNameTable_0201c108);
    func_0200ef44(obj, 5, 0x88, NotifyThenResetNameTable_0201c108);
    return obj;
}
