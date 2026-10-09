#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0207df50;
extern "C" ARM void _Z26CopyInternalFields0207df50P11Foo0207df50(struct Foo0207df50* p);
extern "C" ARM void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" ARM void _Z24BackupPairTables0207dfacPc(char* obj);
extern "C" void func_0207de48(void* p, int a, int b);

struct PairEntry02054464 { int a; int b; };
extern unsigned int data_020e7c18[];
extern struct PairEntry02054464 data_020e7d30[];
extern struct PairEntry02054464 data_020e7d34[];

// USA: func_02054464
extern "C" ARM int func_02054464(char* obj, SafeAllocator* alloc, char* p) {
    int i;
    unsigned int size;
    void* buf;

    alloc->Reset();
    _Z26CopyInternalFields0207df50P11Foo0207df50((struct Foo0207df50*)p);
    _Z25RestorePairTables0207df90Pc(p);

    for (i = 0; i < 10; i++) {
        size = data_020e7c18[i];
        if (size != 0) {
            buf = alloc->Allocate(size);
            ((SafeAllocator*)(obj + 4 + i * 0x14))->CreateTypeA(buf, size);
            func_0207de48(obj + 0xcc + i * 0x70, data_020e7d30[i].a, data_020e7d34[i].a);
        } else {
            ((SafeAllocator*)(obj + 4 + i * 0x14))->ResetAllocatorPointer();
        }
    }

    func_0207de48(obj + 0x168 + 0x400, 0x240, 0x20);
    _Z24BackupPairTables0207dfacPc(p);

    buf = alloc->Allocate(0x2000);
    ((SafeAllocator*)(obj + 0x12c + 0x400))->CreateTypeA(buf, 0x2000);

    buf = alloc->Allocate(0x5400);
    ((SafeAllocator*)(obj + 0x540))->CreateTypeA(buf, 0x5400);

    buf = alloc->Allocate(0x1000);
    ((SafeAllocator*)(obj + 0x154 + 0x400))->CreateTypeA(buf, 0x1000);

    buf = alloc->Allocate(0xc00);
    ((SafeAllocator*)(obj + 0x1d8 + 0x400))->CreateTypeA(buf, 0xc00);
}