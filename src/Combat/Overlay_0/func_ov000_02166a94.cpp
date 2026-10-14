#include <globaldefs.h>
#include <Filesystem/FileIO.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/GameResources.h>
#include <World/Object3D.h>

struct BattleEffectResource02166a94 { int state; char pad_4[0x84]; };
struct BattleWork02166a94 {
    char pad_0[4];
    SafeAllocator* allocator;
    char pad_8[0xea4 - 8];
    void* entryManager;
    char pad_ea8[0x5600 - 0xea8];
    BattleEffectResource02166a94 effects[2];
    char pad_5710[0x5ab0 - 0x5710];
    Object3D models[2];
    char pad_5c08[0x6ffc - 0x5c08];
    char battleResources[4];
};
struct BattlePairTables02166a94 {
    char pad_0[0x230];
    char tables[4];
};
struct NodeList02057de0;
struct Struct_203dafc { int words[8]; };
union BattleModelLoadInfo02166a94 { Struct_203dafc words; ObjectArchiveLoadInfo archive; };
struct Container020d6d18;
struct Obj020d6d90;
struct MergeLowNibbleField020d76fc;
struct Container020d6f44;
extern "C" GameResources* func_ov017_0218b5b0();
extern "C" NodeList02057de0* func_02057924();
extern "C" void func_020c9be0();
void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);
void CreateAndRegisterNode02057de0(NodeList02057de0*, int, SafeAllocator*, int, int);
void ClearEightWords_0203dafc(Struct_203dafc*);
void Forward02047b30(void*, int, int, int);
void ResetArrayAndEntry02182114(char*);
extern "C" void func_ov000_0218214c(void*, SafeAllocator*, const void*);
char* GetData02104b6c_02039e70();
void ResetBattleArrays02039e7c(void*);
void LoadObjectResourceFiles02039f04(char*, int, const void*);
void ConstructEntryManager020d6d18(Container020d6d18*);
void LoadFilesAndBuildNodeList020d6d90(Obj020d6d90*, const void*, SafeAllocator*, char*);
void MergeLowNibbleField(MergeLowNibbleField020d76fc*);
void OrMaskedField24IntoField26_020d771c(unsigned char*);
void InitEntryManagerAllocator020d6ec8(Container020d6f44*, SafeAllocator*);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void*, int);
extern const char data_ov000_02183a5a[], data_ov000_02183a6f[], data_ov000_02183a7a[], data_ov000_02183a85[], data_ov000_02183a93[];
extern const char data_ov000_02183910[][16];
struct BattleModelIDList02166a94 {
    int entries[3];
    int Get(int i) const { return entries[i]; }
};
extern int data_ov000_021838fc[];
extern BattleModelIDList02166a94 data_ov000_02183028;

// USA: func_ov000_02166a94
extern "C" ARM void func_ov000_02166a94(BattleWork02166a94* self) {
    SafeAllocator* sourceAllocator;
    BattlePairTables02166a94* pairTables;
    NodeList02057de0* nodes;
    SafeAllocator* destinationAllocator;
    GameResources* resources = func_ov017_0218b5b0();
    nodes = func_02057924();
    sourceAllocator = &resources->allocator_array_38[0];
    destinationAllocator = &resources->allocator_array_38[5];
    pairTables = (BattlePairTables02166a94*)resources->unknown_2cc;
    unsigned int size;
    const void* data;
    BackgroundLoader::AddLockGlobal();
    if (!LoadFileIntoMemory(data_ov000_02183a5a, data_0211e33c, &size)) func_020c9be0();
    RestorePairTables0207df90(pairTables->tables);
    if (GetFileInNarc(data_0211e33c, data_ov000_02183a6f, &data, &size, 0)) {
        void* buffer = sourceAllocator->Allocate(size);
        if (buffer) {
            memcpy(buffer, data, size);
            CreateAndRegisterNode02057de0(nodes, 2, sourceAllocator, (int)buffer, size);
        }
    }
    SafeAllocator* sourceAllocators[4] = {sourceAllocator, self->allocator, self->allocator, self->allocator};
    SafeAllocator* destinationAllocators[4] = {destinationAllocator, destinationAllocator, self->allocator, self->allocator};
    long resourceIndex;
    SafeAllocator** sourceSlot;
    SafeAllocator** destinationSlot;
    resourceIndex = 0;
    sourceSlot = sourceAllocators;
    destinationSlot = destinationAllocators;
    for (; data_ov000_021838fc[resourceIndex] >= 0; ++resourceIndex, ++sourceSlot, ++destinationSlot) {
        if (GetFileInNarc(data_0211e33c, data_ov000_02183910[resourceIndex], &data, &size, 0)) {
            void* buffer = (*sourceSlot)->Allocate(size);
            if (buffer) {
                memcpy(buffer, data, size);
                CreateAndRegisterNode02057de0(nodes, data_ov000_021838fc[resourceIndex], *destinationSlot, (int)buffer, size);
            }
        }
    }
    Object3D* models[3] = {};
    models[0] = &self->models[0];
    models[1] = &self->models[1];
    char path[80];
    BattleModelLoadInfo02166a94 loadInfo;
    Object3D* const* modelSlots;
    BattleModelIDList02166a94* modelIDs;
    long modelIndex;
    Object3D* model;
    for (modelIndex = 0; data_ov000_02183028.entries[modelIndex] > 0; ++modelIndex) {
        modelIDs = &data_ov000_02183028;
        sprintf(path, data_ov000_02183a7a, modelIDs->Get(modelIndex));
        GetFileInNarc(data_0211e33c, path, &data, &size, 0);
        if (data) {
            modelSlots = models;
            model = modelSlots[modelIndex];
            ClearEightWords_0203dafc(&loadInfo.words);
            const void* modelData;
            int modelSize;
            modelSize = size;
            modelData = data;
            loadInfo.archive.unk_10 = 1;
            loadInfo.archive.fileData = modelData;
            loadInfo.archive.allocator = destinationAllocator;
            loadInfo.archive.unk_8 = modelSize;
            model->Initialize();
            model->LoadFromCHRArchive(&loadInfo.archive);
            model->SetScale(0x10a, 0x10a, 0x10a);
        }
    }
    if (GetFileInNarc(data_0211e33c, data_ov000_02183a85, &data, &size, 0)) {
        Forward02047b30(&self->effects[0], (int)data, size, (int)destinationAllocator);
        self->effects[0].state = 0x3e;
    }
    if (GetFileInNarc(data_0211e33c, data_ov000_02183a93, &data, &size, 0)) {
        Forward02047b30(&self->effects[1], (int)data, size, (int)destinationAllocator);
        self->effects[1].state = 0x3e;
    }
    char* battleResources = self->battleResources;
    ResetArrayAndEntry02182114(battleResources);
    func_ov000_0218214c(battleResources, destinationAllocator, data_0211e33c);
    char* objectResources = GetData02104b6c_02039e70();
    ResetBattleArrays02039e7c(objectResources);
    LoadObjectResourceFiles02039f04(objectResources, (int)destinationAllocator, data_0211e33c);
    BackupPairTables0207dfac(pairTables->tables);
    self->entryManager = destinationAllocator->Allocate(0xa48);
    ConstructEntryManager020d6d18((Container020d6d18*)self->entryManager);
    LoadFilesAndBuildNodeList020d6d90((Obj020d6d90*)self->entryManager, data_0211e33c, destinationAllocator, pairTables->tables);
    MergeLowNibbleField((MergeLowNibbleField020d76fc*)self->entryManager);
    OrMaskedField24IntoField26_020d771c((unsigned char*)self->entryManager);
    InitEntryManagerAllocator020d6ec8((Container020d6f44*)self->entryManager, self->allocator);
    RestorePairTables0207df90(pairTables->tables);
    BackupPairTables0207dfac(pairTables->tables);
    SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x40);
    BackgroundLoader::RemoveLockGlobal();
}
