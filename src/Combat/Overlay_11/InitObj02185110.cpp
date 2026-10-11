#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct NameTable02048080;
void ClearNameTable(NameTable02048080* table);
extern "C" void func_0204719c(void* obj);

extern int data_ov023_021fe3e4;

struct Obj_02185110 {
    void* vtable;
    char pad[0x34 - 4];
};

// USA: func_ov011_02185110
ARM Obj_02185110* InitObj02185110(Obj_02185110* obj) {
    obj->vtable = &data_ov023_021fe3e4;
    ClearNameTable((NameTable02048080*)((char*)obj + 0x34));
    func_0204719c((char*)obj + 0x20);
    return obj;
}
