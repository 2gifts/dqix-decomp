#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" unsigned short* func_02012fe4(void);
extern "C" int _Z19IsIdInRange020981e4ii(int a, int id);
struct Foo0207df50;
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(struct Foo0207df50* p);
extern "C" void _Z17ResetTask020dbebcPv(void* a);
struct Struct020dbd9c;
extern "C" void _Z18InitStruct020dbd9cP14Struct020dbd9c(struct Struct020dbd9c* p);
struct BattleTask020dbf18;
extern "C" int _Z17BeginTask020dbf18P18BattleTask020dbf18iiii(struct BattleTask020dbf18* task, int name, int alloc, int tables, int count);

extern const char data_ov017_021d7383[];

struct BattleResources0218d510 {
    unsigned char pad0[0x2cc];
    unsigned char pairTables[0x4498 - 0x2cc];
    struct BattleTask020dbf18* task;
};

static inline struct Foo0207df50* SelectPairTable(unsigned char* pairTables, int inRange) {
    return (struct Foo0207df50*)(inRange ? pairTables + 0x930 : pairTables + 0xc40);
}

// USA: func_ov017_0218d510
extern "C" ARM int func_ov017_0218d510(struct BattleResources0218d510* self, SafeAllocator* alloc) {
    if (alloc == NULL) {
        return -1;
    }
    unsigned short* run = func_02012fe4();
    int inRange = _Z19IsIdInRange020981e4ii((int)(run + 0x420), *run);
    struct Foo0207df50* table = SelectPairTable(self->pairTables, inRange);
    _Z26CopyInternalFields0207df50P11Foo0207df50(table);
    if (self->task != NULL) {
        _Z17ResetTask020dbebcPv(self->task);
    }
    struct BattleTask020dbf18* task = self->task = (struct BattleTask020dbf18*)alloc->Allocate(0x18);
    _Z18InitStruct020dbd9cP14Struct020dbd9c((struct Struct020dbd9c*)task);
    _Z17BeginTask020dbf18P18BattleTask020dbf18iiii(task, (int)data_ov017_021d7383, (int)alloc, (int)table, 0x17);
    return 0;
}
