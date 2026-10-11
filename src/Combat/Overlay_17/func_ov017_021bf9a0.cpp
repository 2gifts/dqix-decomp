#include <globaldefs.h>
#include "Resource/TextQueue.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "World/LootableContainer.h"

struct State0207dfc8 { unsigned int words[28]; };
struct StoreStruct;
struct Struct0218d618;
struct Obj0205eaa0;
struct Container020dedd0;
struct LootEventInfo { char pad0[0x30]; unsigned short containerId; };
struct LootEvent {
    char pad0[8]; unsigned short timer; short fieldA;
    LootEventInfo* info; Foo02048004* display; short taskId;
    char pad16[0x28 - 0x16]; Vector3fix position; SafeAllocator allocator;
    unsigned char special;
};
#if defined(jpn)
struct PersistentLootState { char pad0[0x2794]; char containerData[4]; };
#else
struct PersistentLootState { char pad0[0x2754]; char containerData[4]; };
#endif
struct LootTextContext {
    SafeAllocator allocator; char list[0x18]; Container020dedd0* containerData;
    int field30; int field34;
};
StoreStruct* GetGlobalField0x1c020421a0();
extern "C" PersistentLootState* func_02012fe4();
extern "C" unsigned char* func_0205ec34();
int IsField10Eq2_0218d618(Struct0218d618*);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
void MaybeInvoke0204719c(Foo02048004*);
void CopyState0207dfc8(State0207dfc8*, State0207dfc8*);
void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);
void Forward02047b30(void*, int, int, int);
int TestBitInByteArray(int, unsigned char*, int);
void SetOrClearBitInArray(void*, unsigned char*, int, int);
extern "C" void func_ov017_021cdb00(int, int, int, int);
extern "C" void __clear(void*, int);
void* ZeroInitReturn020de824(void*);
void InitStruct0207cbe8(char*);
extern "C" int func_0207d538(void*, int, int, char*, int);
void* GetGlobalResetObj020d7a50();
extern "C" void func_ov017_0218d644(GameResources*, Vector3fix*, int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
extern AllocatorUnion data_02114e20;
extern Obj0205eaa0 data_02108760;

static inline char& GetResourceStateBuffer(GameResources* resources, int offset) {
    return resources->unknown_2cc[offset];
}

// JPN: func_ov017_021bff4c
// USA: func_ov017_021bf9a0
extern "C" ARM int func_ov017_021bf9a0(LootEvent* self) {
    unsigned int delta = GameState::GetInstance()->GetEffectiveDeltaTime();
    if (delta < self->timer) { self->timer -= delta; return 3; }
    self->timer = 0;
    GetGlobalField0x1c020421a0();
    LootEventInfo* info = self->info;
    func_02012fe4();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    LootableContainerManager* manager = LootableContainerManager::GetMainInstance();
    unsigned char* flags = func_0205ec34();
    if (!manager || !flags) return 3;
    if (self->special) {
        if (!IsField10Eq2_0218d618((Struct0218d618*)func_ov017_0218b5b0())) return 5;
    } else if (self->taskId >= 0) {
        if (loader->GetTaskStatus(self->taskId)) {
            void* file = 0;
            unsigned int length = 0;
            loader->GetLoadedFileByID(self->taskId, &file, &length);
            void* buffer = AllocateAligned4(&data_02114e20, 256);
            if (file && buffer) {
                self->allocator.CreateTypeA(buffer, 256);
                MaybeInvoke0204719c(self->display);
                func_0204719c(self->display);
                State0207dfc8 saved;
                CopyState0207dfc8((State0207dfc8*)&GetResourceStateBuffer(func_ov017_0218b5b0(), 0x230), &saved);
                RestorePairTables0207df90((char*)&saved);
                Forward02047b30(self->display, (int)file, length, (int)&self->allocator);
                BackupPairTables0207dfac((char*)&saved);
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
        } else return 3;
    }
    self->timer = 300;
    unsigned short listPosition = 0;
    LootableContainerManager::Container* container = manager->GetContainerByID(info->containerId, &listPosition);
    if (container) {
        int id = container->uniqueID;
        int flagIndex = id + 0x79e;
        if (!TestBitInByteArray((int)flags, flags + 0x8c, flagIndex)) {
            SetOrClearBitInArray(flags, flags + 0x8c, flagIndex, 1);
            func_ov017_021cdb00(8, id, 1, -1);
            char text[128] = {};
            PersistentLootState* state = func_02012fe4();
            LootTextContext context;
            context.allocator.ResetAllocatorPointer();
            ZeroInitReturn020de824(context.list);
            InitStruct0207cbe8((char*)&context);
            InitStruct0207cbe8((char*)&context);
            context.containerData = (Container020dedd0*)state->containerData;
            if (func_0207d538(&context, container->lootType, container->itemIDOrRank, text, 1)) {
#if defined(jpn)
                func_020d7e10(GetGlobalResetObj020d7a50(), text, 0, 0, 1);
#else
                func_020d7e10(GetGlobalResetObj020d7a50(), text, 0, 0, 1, 0);
#endif
                GameResources* resources = func_ov017_0218b5b0();
                if (self->special) func_ov017_0218d644(resources, &self->position, 0);
                else DispatchWithShortB4_0205eaa0(&data_02108760, 14, 0);
                return 4;
            }
        }
    }
    return 5;
}
