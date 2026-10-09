#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
extern char data_ov004_021703ff[];

extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov004_0215c448(void* obj);
extern "C" void* func_ov004_0215c474(void* obj);
extern "C" ARM int _Z24InitObjWithMisc_021f6f20Pviiiij(void* obj, int p1, int p3, int p4, int arg5, unsigned int arg6);
extern "C" ARM void* _Z20AddOffset20_021f7318Pv(void* p);
extern "C" ARM void _Z22SetField1cTo2_021f7320Pv(void* p);

struct Foo0207df50;
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(struct Foo0207df50* p);
extern "C" void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" void _Z24BackupPairTables0207dfacPc(char* obj);
extern "C" void func_0204719c(void* obj);
extern "C" void _Z15Forward02047b30Pviii(void* a, int b, int c, int d);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
extern "C" void _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

static inline char* GetPairTable(GameResources* res, int index) { return res->unknown_2cc + index * 0x70; }

struct LocalNodeBuf_0215c30c {
    int words[0xac / 4];
};

// USA: func_ov004_0215c30c
extern "C" ARM int func_ov004_0215c30c(void* ctx) {
    void* node = func_ov011_021845f8(ctx, 6);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0xac);
    if (block == 0) return 0;

    LocalNodeBuf_0215c30c local;
    func_ov004_0215c448(&local);
    memcpy(block, &local, sizeof(local));

    if (_Z24InitObjWithMisc_021f6f20Pviiiij(block, (int)ctx, 0x6a4, 6, 0, 0) == 0) {
        int result = 0;
        func_ov004_0215c474(&local);
        return result;
    }

    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* file = LoadFileIntoMemory(data_ov004_021703ff, data_0211e33c, &size);
    char* pairs = GetPairTable(func_ov017_0218b5b0(), 0);
    void* model = _Z20AddOffset20_021f7318Pv(block);
    _Z26CopyInternalFields0207df50P11Foo0207df50((struct Foo0207df50*)pairs);
    _Z25RestorePairTables0207df90Pc(pairs);
    func_0204719c(model);
    if (file != 0) {
        _Z15Forward02047b30Pviii(model, (int)file, size, (int)((char*)node + 4));
    }
    _Z24BackupPairTables0207dfacPc(pairs);
    BackgroundLoader::RemoveLockGlobal();
    _Z22SetField1cTo2_021f7320Pv(block);
    _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(ctx), (struct ListNode_021f67ac*)block);

    int result = 0;
    func_ov004_0215c474(&local);
    return result;
}
