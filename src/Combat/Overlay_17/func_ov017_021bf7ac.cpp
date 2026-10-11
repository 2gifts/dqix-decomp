#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "World/LootableContainer.h"
#include "std_library_functions.h"

struct StructDE234_020de234 {
    int a, b, c, d;
    unsigned int field10Low : 10;
    unsigned int field10Mid : 10;
    unsigned int field10High : 8;
    unsigned int field10Unused : 4;
    short e, f, g, h, i;
};

struct Base02019508;
struct Container020dedd0;
struct Foo02048004;

extern "C" void* func_02012fe4(void);
void ClearAndFlagEntry0201ba1c(struct Base02019508* base, int key1, int key2);
void EnqueueEventTag166_021cfe40(unsigned short a, unsigned short b, unsigned short c);
extern "C" unsigned char* func_0205ec34(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
int GetField0x3acValue(GameState* battleStruct);
void MaybeInvoke0204719c(struct Foo02048004* obj);
StructDE234_020de234* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_ov017_0218d510(int a, void* b);
unsigned short GetPreferredPackedField020de234(struct StructDE234_020de234* p, int preferMid);

struct FileName_021bf7ac {
    char path[0x20];
};

extern AllocatorUnion data_02114e20;
extern const FileName_021bf7ac data_ov017_021d6ca4;
extern const char data_ov017_021d7ee8[];

struct Info_021bf7ac {
    char pad0[0x2c];
    unsigned short key1;
    unsigned short key2;
    unsigned short containerId;
};

struct Obj021bf7ac {
    char pad0[8];
    short timer;
    char padA[2];
    struct Info_021bf7ac* info;
    struct Foo02048004* entry;
    short taskId;
    char pad16[0x48 - 0x16];
    unsigned char field48;
    char pad49[3];
    SafeAllocator allocator;
};

// JPN: func_ov017_021bfd58
// USA: func_ov017_021bf7ac
extern "C" ARM int func_ov017_021bf7ac(struct Obj021bf7ac* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x394, regionalOffset1=0x620};
#else
 enum {regionalOffset0=0x354, regionalOffset1=0x600};
#endif
    GameState* gs = GameState::GetInstance();
    gs->GetUnknownGameObject();
    unsigned short* events = (unsigned short*)func_02012fe4();
    struct Info_021bf7ac* info = obj->info;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned short key1 = info->key1;
    unsigned short key2 = info->key2;
    ClearAndFlagEntry0201ba1c((struct Base02019508*)events, key1, key2);
    EnqueueEventTag166_021cfe40(*events, key1, key2);

    LootableContainerManager* mgr = LootableContainerManager::GetMainInstance();
    unsigned char* flags = func_0205ec34();
    if (mgr == 0 || flags == 0) {
        return 3;
    }

    unsigned short listPos = 0;
    LootableContainerManager::Container* container = mgr->GetContainerByID(info->containerId, &listPos);
    if (container != 0 && !TestBitInByteArray((int)flags, flags + 0x8c, container->uniqueID + 0x79e)) {
        char* base = (char*)func_02012fe4();
        char* sub = base + regionalOffset0;
        obj->entry = (struct Foo02048004*)(base + regionalOffset1 + GetField0x3acValue(gs) * 0x88);
        MaybeInvoke0204719c(obj->entry);
        if (container->lootType == 1) {
            FileName_021bf7ac name = data_ov017_021d6ca4;
            obj->taskId = loader->QueueLoadFile(name.path, 0);
        } else {
            StructDE234_020de234* elem = FindElementByKey020dedd0((struct Container020dedd0*)(sub + 0x2400), (short)container->itemIDOrRank);
            if (elem != 0) {
                if (elem->g == 0x5617) {
                    obj->field48 = 1;
                    obj->allocator.ResetAllocatorPointer();
                    obj->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0x4000), 0x4000);
                    obj->allocator.Reset();
                    func_ov017_0218d510((int)func_ov017_0218b5b0(), &obj->allocator);
                } else {
                    char path[0x80];
                    sprintf(path, data_ov017_021d7ee8, (signed char)elem->field10High, GetPreferredPackedField020de234(elem, 0));
                    obj->taskId = loader->QueueLoadFile(path, 0);
                }
            }
        }
    }
    obj->timer = 0x12c;
    return 3;
}
