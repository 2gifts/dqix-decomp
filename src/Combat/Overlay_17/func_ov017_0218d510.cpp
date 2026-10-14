#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" unsigned short* func_02012fe4(void);
int IsIdInRange020981e4(int a, int id);
struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void ResetTask020dbebc(void* a);
struct Struct020dbd9c;
void InitStruct020dbd9c(struct Struct020dbd9c* p);
struct BattleTask020dbf18;
int BeginTask020dbf18(struct BattleTask020dbf18* task, int name, int alloc, int tables, int count);

extern const char data_ov017_021d7383[];

struct BattleResources0218d510 {
#if defined(jpn)
    unsigned char pad0[0x27c];
#else
    unsigned char pad0[0x2cc];
#endif
#if defined(jpn)
    unsigned char pairTables[0x41e8 - 0x27c];
#else
    unsigned char pairTables[0x4498 - 0x2cc];
#endif
    struct BattleTask020dbf18* task;
};

static inline struct Foo0207df50* SelectPairTable(unsigned char* pairTables, int inRange) {
    return (struct Foo0207df50*)(inRange ? pairTables + 0x930 : pairTables + 0xc40);
}

// USA: func_ov017_0218d510
extern "C" ARM int func_ov017_0218d510(struct BattleResources0218d510* self, SafeAllocator* alloc) {
#if defined(jpn)
 enum {regionalOffset0=0x430};
#else
 enum {regionalOffset0=0x420};
#endif
    if (alloc == NULL) {
        return -1;
    }
    unsigned short* run = func_02012fe4();
    int inRange = IsIdInRange020981e4((int)(run + regionalOffset0), *run);
    struct Foo0207df50* table = SelectPairTable(self->pairTables, inRange);
    CopyInternalFields0207df50(table);
    if (self->task != NULL) {
        ResetTask020dbebc(self->task);
    }
    struct BattleTask020dbf18* task = self->task = (struct BattleTask020dbf18*)alloc->Allocate(0x18);
    InitStruct020dbd9c((struct Struct020dbd9c*)task);
    BeginTask020dbf18(task, (int)data_ov017_021d7383, (int)alloc, (int)table, 0x17);
    return 0;
}
