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
extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);
extern "C" void _Z29CreateAndRegisterNode02057de0P16NodeList02057de0iP13SafeAllocatorii(NodeList02057de0*, int, SafeAllocator*, int, int);
void ClearEightWords(Struct_203dafc*);
extern "C" void _Z15Forward02047b30Pviii(void*, int, int, int);
extern "C" void _Z26ResetArrayAndEntry02182114Pc(char*);
extern "C" void func_ov000_0218214c(void*, SafeAllocator*, const void*);
char* GetData02104b6c();
extern "C" void _Z25ResetBattleArrays02039e7cPv(void*);
extern "C" void _Z31LoadObjectResourceFiles02039f04PciPKv(char*, int, const void*);
extern "C" void _Z29ConstructEntryManager020d6d18P17Container020d6d18(Container020d6d18*);
extern "C" void _Z33LoadFilesAndBuildNodeList020d6d90P11Obj020d6d90PKvP13SafeAllocatorPc(Obj020d6d90*, const void*, SafeAllocator*, char*);
void MergeLowNibbleField(MergeLowNibbleField020d76fc*);
void OrMaskedField24IntoField26(unsigned char*);
extern "C" void _Z33InitEntryManagerAllocator020d6ec8P17Container020d6f44P13SafeAllocator(Container020d6f44*, SafeAllocator*);
void SetCombatWorkFlags0x55f4(void*, int);
extern const char data_ov000_02183a5a[], data_ov000_02183a6f[], data_ov000_02183a7a[], data_ov000_02183a85[], data_ov000_02183a93[];
extern const char data_ov000_02183910[][16];
extern int data_ov000_021838fc[], data_ov000_02183028[];

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
    _Z25RestorePairTables0207df90Pc(pairTables->tables);
    if (GetFileInNarc(data_0211e33c, data_ov000_02183a6f, &data, &size, 0)) {
        void* buffer = sourceAllocator->Allocate(size);
        if (buffer) {
            memcpy(buffer, data, size);
            _Z29CreateAndRegisterNode02057de0P16NodeList02057de0iP13SafeAllocatorii(nodes, 2, sourceAllocator, (int)buffer, size);
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
                _Z29CreateAndRegisterNode02057de0P16NodeList02057de0iP13SafeAllocatorii(nodes, data_ov000_021838fc[resourceIndex], *destinationSlot, (int)buffer, size);
            }
        }
    }
    Object3D* models[3] = {};
    models[0] = &self->models[0];
    models[1] = &self->models[1];
    char path[80];
    BattleModelLoadInfo02166a94 loadInfo;
    Object3D* const* modelSlots;
    int* modelIDs;
    long modelIndex;
    Object3D* model;
    for (modelIndex = 0; data_ov000_02183028[modelIndex] > 0; ++modelIndex) {
        modelIDs = data_ov000_02183028;
        sprintf(path, data_ov000_02183a7a, modelIDs[(unsigned int)modelIndex]);
        GetFileInNarc(data_0211e33c, path, &data, &size, 0);
        if (data) {
            modelSlots = models;
            model = modelSlots[modelIndex];
            ClearEightWords(&loadInfo.words);
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
        _Z15Forward02047b30Pviii(&self->effects[0], (int)data, size, (int)destinationAllocator);
        self->effects[0].state = 0x3e;
    }
    if (GetFileInNarc(data_0211e33c, data_ov000_02183a93, &data, &size, 0)) {
        _Z15Forward02047b30Pviii(&self->effects[1], (int)data, size, (int)destinationAllocator);
        self->effects[1].state = 0x3e;
    }
    char* battleResources = self->battleResources;
    _Z26ResetArrayAndEntry02182114Pc(battleResources);
    func_ov000_0218214c(battleResources, destinationAllocator, data_0211e33c);
    char* objectResources = GetData02104b6c();
    _Z25ResetBattleArrays02039e7cPv(objectResources);
    _Z31LoadObjectResourceFiles02039f04PciPKv(objectResources, (int)destinationAllocator, data_0211e33c);
    _Z24BackupPairTables0207dfacPc(pairTables->tables);
    self->entryManager = destinationAllocator->Allocate(0xa48);
    _Z29ConstructEntryManager020d6d18P17Container020d6d18((Container020d6d18*)self->entryManager);
    _Z33LoadFilesAndBuildNodeList020d6d90P11Obj020d6d90PKvP13SafeAllocatorPc((Obj020d6d90*)self->entryManager, data_0211e33c, destinationAllocator, pairTables->tables);
    MergeLowNibbleField((MergeLowNibbleField020d76fc*)self->entryManager);
    OrMaskedField24IntoField26((unsigned char*)self->entryManager);
    _Z33InitEntryManagerAllocator020d6ec8P17Container020d6f44P13SafeAllocator((Container020d6f44*)self->entryManager, self->allocator);
    _Z25RestorePairTables0207df90Pc(pairTables->tables);
    _Z24BackupPairTables0207dfacPc(pairTables->tables);
    SetCombatWorkFlags0x55f4(self, 0x40);
    BackgroundLoader::RemoveLockGlobal();
}
