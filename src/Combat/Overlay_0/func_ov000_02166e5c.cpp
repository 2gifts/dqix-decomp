#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <GameState/GameState.h>
#include <Resource/IndexedResourceEntry.h>

extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
unsigned int FindFilesInNarcBySubstring(const void* narcBuffer, const char* substr, const void** pOutFilePtrs, unsigned int* pOutFileSizes, unsigned int maxOutputs);
struct T020545b8;
struct StreamHeader;
struct Struct_203dafc { int words[8]; };
union CombatantLoadInfo02166e5c { Struct_203dafc words; ObjectArchiveLoadInfo archive; };
struct InternalBlock02166e5c { char bytes[0x70]; };
struct Field0x19cData { unsigned char data[0x578]; };
struct CombatantModelState02166e5c { unsigned char data[0x70]; };
struct BattleWork02166e5c {
    char pad_0[0x2a0];
    unsigned char* roster;
    char pad_2a4[0x5734 - 0x2a4];
    Field0x19cData selection;
    CombatantModelState02166e5c model;
};
struct StatTriple02166e5c {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int rest : 2;
};
struct ClassEntry02166e5c {
    char name[0x10];
    unsigned char level : 3;
    unsigned char rest_10 : 5;
    unsigned char pad_11;
    unsigned char vocation;
    unsigned char emblem;
    StatTriple02166e5c stats[3];
};
struct ClassTable02166e5c { unsigned char data[0xb8]; };
struct Growth02166e5c {
    unsigned int experience : 32;
    unsigned short vocation : 7;
    unsigned short rank : 9;
    unsigned short pad_6;
    StatTriple02166e5c stats[3];
};
struct CombatantData02166e5c {
    char pad_0[0x3c];
    char name[0x16c - 0x3c];
    unsigned short vocationTable[0xd];
    unsigned char pad_186[0x56a - 0x186];
    unsigned char mode;
    unsigned char level : 4;
    unsigned char rest_56b : 4;
    unsigned char pad_56c[0x94c - 0x56c];
    int phase;
};
struct Combatant02166e5c {
    Object3D object;
    char pad_ac[0xc2 - 0xac];
    unsigned char flags;
    char pad_c3[0x130 - 0xc3];
    PrimaryCombatStats* stats;
    BaseCombatStats* baseStats;
    char* savedStats;
    char pad_13c[0x150 - 0x13c];
    CombatantData02166e5c* data;
};
struct PartyLog02166e5c {
    char pad_0[0xf78];
    unsigned char entries[4];
    unsigned char count;
};
struct RegionCode02166e5c { unsigned char bytes[4]; };

extern "C" GameResources* func_ov017_0218b5b0();
void DestroyAllocators020545b8(T020545b8*);
struct Foo0207df50;
void CopyInternalFields0207df50(Foo0207df50*);
void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);
void ClearEightWords(Struct_203dafc*);
struct Obj02054664;
void ResetSelectionState02054664(Obj02054664*);
void SetAndClearField0x19c(char*, Field0x19cData*);
extern "C" void func_02049c88(Combatant02166e5c*, CombatantModelState02166e5c*);
void RunOverlayScript0216d1c4(int, StreamHeader*, int, int*);
void SetPtrFieldIfNonNull0x13c(void*, int);
void RegisterCombatantSlot(GameState*, int, GameObject*);
void RegisterOrAllocateCombatant02053c74(char*, int);
CombatantData02166e5c* GetFieldAt0x150(unsigned char*);
void ResetStruct020d3c08(char*);
struct Obj020d3c28;
void InitAndMaybeStartStream020d3c28(Obj020d3c28*);
struct FindEntryByKindContainer020d3d90;
ClassEntry02166e5c* FindEntryByKind(FindEntryByKindContainer020d3d90*, int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void func_02083cbc(CombatantData02166e5c*, Growth02166e5c*, void*);
extern "C" void func_02083e28(CombatantData02166e5c*, int);
void SetBit0x954StoreIndex0x950(unsigned char*, int);
void ClearTwoRegions02083c18(char*);
void SetBitInArray0x910(unsigned char*, int);
void SetBitInField0x34(unsigned char*, int);
struct Bytes02033b88;
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
struct Obj020397cc;
void CancelPendingAction020397cc(Obj020397cc*, int);
void CopyCombatantStats0208936c(char*, char*, char*);
void CopyInRegion0x571d(char*, int, void*);
void SetCombatWorkFlags0x55f4(void*, int);
extern const char data_ov000_02183aa5[], data_ov000_021839e2[], data_ov000_02183abe[];
extern const char data_020ef078[];
extern const RegionCode02166e5c data_ov000_02183014;

// USA: func_ov000_02166e5c
extern "C" ARM void func_ov000_02166e5c(BattleWork02166e5c* self) {
    InternalBlock02166e5c* blocks;
    GameState* game = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    SafeAllocator* allocator = &resources->allocator_array_38[3];
    blocks = (InternalBlock02166e5c*)resources->unknown_2cc;
    DestroyAllocators020545b8((T020545b8*)GetIndexedEntry_021a11f4(resources, 2));
    allocator->Reset();
    CopyInternalFields0207df50((Foo0207df50*)&blocks[3]);
    RestorePairTables0207df90(blocks[3].bytes);
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    if (!LoadFileIntoMemory(data_ov000_02183aa5, data_0211e33c, &size)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    Combatant02166e5c* combatant = (Combatant02166e5c*)allocator->Allocate(0x2d4);
    if (!combatant) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    CombatantLoadInfo02166e5c loadInfo;
    ClearEightWords(&loadInfo.words);
    loadInfo.archive.fileData = data_0211e33c;
    loadInfo.archive.unk_8 = size;
    loadInfo.archive.allocator = allocator;
    loadInfo.archive.unk_10 = 1;
    ResetSelectionState02054664((Obj02054664*)combatant);
    if (!combatant->object.LoadFromCCHROrCMOTArchive(&loadInfo.archive, 0)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    combatant->object.SetScale(0x10a, 0x10a, 0x10a);
    SetAndClearField0x19c((char*)combatant, &self->selection);
    func_02049c88(combatant, &self->model);
    const void* script;
    unsigned int scriptSize;
    if (FindFilesInNarcBySubstring(data_0211e33c, data_ov000_021839e2, &script, &scriptSize, 1)) {
        int scriptState = 0;
        RunOverlayScript0216d1c4((int)allocator, (StreamHeader*)script, scriptSize, &scriptState);
        SetPtrFieldIfNonNull0x13c(combatant, scriptState);
    }
    if (!LoadFileIntoMemory(data_ov000_02183abe, data_0211e33c, &size)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    ClearEightWords(&loadInfo.words);
    loadInfo.archive.fileData = data_0211e33c;
    loadInfo.archive.unk_8 = size;
    loadInfo.archive.allocator = allocator;
    loadInfo.archive.unk_10 = 1;
    if (!combatant->object.LoadFromCCHROrCMOTArchive(&loadInfo.archive, 0)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    RegisterCombatantSlot(game, 1, (GameObject*)combatant);
    RegisterOrAllocateCombatant02053c74((char*)combatant, 1);
    CombatantData02166e5c* data = GetFieldAt0x150((unsigned char*)combatant);
    if (!data) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    ClassTable02166e5c table;
    ResetStruct020d3c08((char*)&table);
    InitAndMaybeStartStream020d3c28((Obj020d3c28*)&table);
    ClassEntry02166e5c* entry = FindEntryByKind((FindEntryByKindContainer020d3d90*)&table, 1);
    sprintf(data->name, data_020ef078, entry);
    Growth02166e5c growth;
    growth.experience = 0;
    growth.rank = 0;
    growth.vocation = entry->vocation;
    growth.stats[0].first = entry->stats[0].first;
    growth.stats[0].second = entry->stats[0].second;
    growth.stats[0].third = entry->stats[0].third;
    growth.stats[1].first = entry->stats[1].first;
    growth.stats[1].second = entry->stats[1].second;
    growth.stats[1].third = entry->stats[1].third;
    growth.stats[2].first = entry->stats[2].first;
    growth.stats[2].second = entry->stats[2].second;
    growth.stats[2].third = entry->stats[2].third;
    func_02083cbc(data, &growth, 0);
    func_02083e28(data, 0);
    combatant->stats->maxHP = combatant->baseStats->primaryStats.maxHP;
    combatant->stats->maxMP = combatant->baseStats->primaryStats.maxMP;
    SetBit0x954StoreIndex0x950((unsigned char*)data, 0);
    ClearTwoRegions02083c18((char*)data);
    SetBitInArray0x910((unsigned char*)data, entry->emblem);
    data->vocationTable[0] = entry->vocation;
    data->mode = 0xb;
    data->phase = 3;
    SetBitInField0x34(self->roster, 1);
    PartyLog02166e5c* log = (PartyLog02166e5c*)GetPtrField0x2a04(game);
    log->entries[log->count++] = 1;
    SetByte0xbeShiftPrev((Bytes02033b88*)combatant, 0);
    CancelPendingAction020397cc((Obj020397cc*)combatant, 1);
    CopyCombatantStats0208936c(combatant->savedStats, (char*)combatant->stats, (char*)combatant->baseStats);
    combatant->flags |= 0x20;
    BackupPairTables0207dfac(blocks[3].bytes);
    int level = entry->level;
    CombatantData02166e5c* levelData = combatant->data;
    if (levelData) levelData->level = (unsigned char)level;
    int codeLength = 2;
    RegionCode02166e5c code = data_ov000_02183014;
    CopyInRegion0x571d((char*)game, codeLength, &code);
    SetCombatWorkFlags0x55f4(self, 0x400000);
    BackgroundLoader::RemoveLockGlobal();
}
