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
ARM int InitObjWithMisc_021f6f20(void* obj, int p1, int p3, int p4, int arg5, unsigned int arg6);
ARM void* AddOffset20_021f7318(void* p);
ARM void SetField1cTo2_021f7320(void* p);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
extern "C" void func_0204719c(void* obj);
void Forward02047b30(void* a, int b, int c, int d);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

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

    if (InitObjWithMisc_021f6f20(block, (int)ctx, 0x6a4, 6, 0, 0) == 0) {
        int result = 0;
        func_ov004_0215c474(&local);
        return result;
    }

    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* file = LoadFileIntoMemory(data_ov004_021703ff, data_0211e33c, &size);
    char* pairs = GetPairTable(func_ov017_0218b5b0(), 0);
    void* model = AddOffset20_021f7318(block);
    CopyInternalFields0207df50((struct Foo0207df50*)pairs);
    RestorePairTables0207df90(pairs);
    func_0204719c(model);
    if (file != 0) {
        Forward02047b30(model, (int)file, size, (int)((char*)node + 4));
    }
    BackupPairTables0207dfac(pairs);
    BackgroundLoader::RemoveLockGlobal();
    SetField1cTo2_021f7320(block);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(ctx), (struct ListNode_021f67ac*)block);

    int result = 0;
    func_ov004_0215c474(&local);
    return result;
}
