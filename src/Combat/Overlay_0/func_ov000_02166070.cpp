#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/MonsterDefinition.h"

extern char data_ov000_02183a47[];
extern char data_ov000_02183a4e[];
extern char data_ov000_02183a54[];
extern char data_ov000_021839e2[];
extern char data_020ef078[];

struct StreamHeader;
struct Container02070e60 { unsigned char data[0xc]; };
struct Struct_203dafc {
    int field0;
    int fieldTable;
    int fieldLength;
    SafeAllocator* allocator;
    int field10;
    int field14;
    int field18;
    int field1c;
};
struct Foo0207df50;

struct ModelEntry { int id; const char* name; };
struct ModelNames {
    unsigned char pad_00[0x14]; unsigned int words; unsigned char pad_18[0x14]; char name[1]; };
struct Input020484f8 { ModelEntry* entry; ModelNames* names; int script; };

struct CombatantRoster02166070 {
    unsigned char pad_00[0x678];
    List0206f170 search;
    Container02070e60 names;
};
struct Scene02166070 {
    unsigned char pad_00[0x44];
    SafeAllocator allocator;
    unsigned char pad_pre[0x14c - 0x44 - sizeof(SafeAllocator)];
    char tables14c[0x70];
    char tables1bc[0x2a0 - 0x1bc];
    CombatantRoster02166070* roster;
    unsigned char pad_2a4[0xeb8 - 0x2a4];
    Object3D* models[4];
};

ModelEntry* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
void SetFlag0x400Reset020484d0(void*);
void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);
void ClearEightWords_0203dafc(struct Struct_203dafc*);
ModelNames* SearchWithLow15Comparator02070fd0(struct Container02070e60*, int);
void RunOverlayScript0216d1c4(int, struct StreamHeader*, int, int*);
void InitObjectFields020484f8(unsigned char*, Input020484f8*);
void CopyInternalFields0207df50(struct Foo0207df50*);
extern "C" void _ZN8Object3D10SetField78Et(Object3D*, unsigned int);
extern "C" void _ZN8Object3D10SetField7aEt(Object3D*, unsigned int);
extern "C" void func_0207de48(char*, int, int);

// USA: func_ov000_02166070
extern "C" ARM void func_ov000_02166070(Scene02166070* self, GPCReadPair* pair, int slot, int id, int flag, unsigned int offset) {
    CombatantRoster02166070* roster = self->roster;
    BinarySearchByComparatorStruct* search = &roster->search.table;
    SafeAllocator* alloc = &self->allocator;
    Container02070e60* names = &roster->names;
    char path[0x10];
    struct Struct_203dafc params;
    Input020484f8 input;
    unsigned int length;
    const void* filePtr;
    unsigned int fileSize;
    unsigned int modelLength;
    unsigned int animLength;
    const void* scriptPtr;
    unsigned int scriptSize;
    ModelEntry* entry = SearchWithComparator0206f4f0(search, (short)id);
    if (entry == 0) return;
    sprintf(path, data_ov000_02183a47, entry->name);
    if (!DecompressFileFromGPCByName(pair->pGPCFile, pair->machine, data_0211e33c + offset, length, 0x30000 - offset, path)) {
        pair->Reset();
        if (flag) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    if (!FindFilesInNarcBySubstring(data_0211e33c + offset, data_ov000_02183a4e, &filePtr, &fileSize, 1)) {
        pair->Reset();
        if (flag) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* model = DecompressLZ77FileIntoAllocatedSpace(*alloc, filePtr, modelLength);
    if (!FindFilesInNarcBySubstring(data_0211e33c + offset, data_ov000_02183a54, &filePtr, &fileSize, 1)) {
        pair->Reset();
        if (flag) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* anim = DecompressLZ77FileIntoAllocatedSpace(*alloc, filePtr, animLength);
    if (!FindFilesInNarcBySubstring(data_0211e33c + offset, data_ov000_021839e2, &scriptPtr, &scriptSize, 1)) {
        scriptPtr = 0;
        scriptSize = 0;
    }
    Object3D* obj = (Object3D*)alloc->Allocate(0xb8);
    if (obj == 0) {
        pair->Reset();
        if (flag) BackgroundLoader::RemoveLockGlobal();
        return;
    }
    SetFlag0x400Reset020484d0(obj);
    obj->unknown_2_ = id;
    RestorePairTables0207df90(self->tables1bc);
    ClearEightWords_0203dafc(&params);
    params.fieldTable = (int)model;
    params.fieldLength = modelLength;
    params.allocator = alloc;
    obj->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
    BackupPairTables0207dfac(self->tables1bc);
    ClearEightWords_0203dafc(&params);
    params.fieldTable = (int)anim;
    params.fieldLength = animLength;
    params.allocator = alloc;
    obj->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
    input.names = SearchWithLow15Comparator02070fd0(names, id);
    input.entry = SearchWithComparator0206f4f0(search, id << 16 >> 16);
    sprintf(input.names->name, data_020ef078, input.entry->id);
    if (scriptPtr == 0) {
        input.script = 0;
    } else {
        RunOverlayScript0216d1c4((int)alloc, (StreamHeader*)scriptPtr, scriptSize, &input.script);
    }
    InitObjectFields020484f8((unsigned char*)obj, &input);
    unsigned int low = (unsigned short)input.names->words;
    unsigned int high;
    _ZN8Object3D10SetField78Et(obj, (high = input.names->words >> 16, low));
    _ZN8Object3D10SetField7aEt(obj, high);
    self->models[slot] = obj;
    if (id == 0x13f || id == 0x13d || id == 0x321) {
        CopyInternalFields0207df50((struct Foo0207df50*)self->tables14c);
        RestorePairTables0207df90(self->tables14c);
        func_0207de48(self->tables14c, 0x800, 0);
        func_0207de48(self->tables14c, 0xb800, 0x400);
    }
}
