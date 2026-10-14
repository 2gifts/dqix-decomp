#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Obj02092b34 {
    SafeAllocator allocator;
    char pad14[0x2c - 0x14];
    int field2c;
    short field30;
    short field32;
    unsigned char field34;
    unsigned char field35;
    unsigned char field36;
    unsigned char field37;
    unsigned char field38;
    unsigned char field39;
    unsigned char field3a;
    unsigned char field3b;
};

int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);
struct Obj02092aa4;
void InitObj02092aa4(Obj02092aa4* obj, int param);

// USA: func_02092b34  (semantic: ShutdownAndReinitObj02092b34)
extern "C" ARM void func_02092b34(struct Obj02092b34* obj) {
    if (obj->field2c >= 0) {
        int v = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(v))->RemoveTask((int)(obj->field2c));
        obj->field2c = -1;
    }
    void* g = (void*)GetGlobalField0x1c020421a0();
    ReinitController02043204((char*)g);
    func_02043124((char*)g);
    if (!(obj->field37 & 8)) {
        FontBankLoader* g2 = GetGlobal02109400();
        func_02094ab0(g2);
        BlankFunction02094b34(g2, 0x6f, 0x1388, 1, 1);
    }
    if (obj->allocator.GetSignedAllocator() != 0) {
        obj->allocator.Destroy();
    }
    InitObj02092aa4((struct Obj02092aa4*)obj, 0);
}
