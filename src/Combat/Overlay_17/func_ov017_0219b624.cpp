#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"

struct Foo0207df50;
struct Struct0200fb08;
#if defined(jpn)
enum { PairTablesOffset = 0x4ac };
#define func_02018d28 func_02018ac8
#define data_ov017_021d656c data_ov017_021d69bc
#define data_ov017_021d751f data_ov017_021d797b
#define data_ov017_021d7544 data_ov017_021d7982
#define data_ov017_021d7555 data_ov017_021d7993
#define data_ov017_021d7567 data_ov017_021d79a5
#else
enum { PairTablesOffset = 0x4fc };
#endif
struct ResourceFile0219b624 { int index; const char* name; };
extern const ResourceFile0219b624 data_ov017_021d656c[];
extern int data_0211e33c __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
bool GetFileInNarc(const void*, const char*, const void**, unsigned int*, unsigned int);
extern const char data_ov017_021d7504[], data_ov017_021d7510[], data_ov017_021d751b[];
extern const char data_ov017_021d751f[], data_ov017_021d7526[], data_ov017_021d7530[], data_ov017_021d753a[];
extern const char data_ov017_021d7544[], data_ov017_021d7555[], data_ov017_021d7567[];
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50*);
extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08*);
void* GetData02109020();
void InitFourNamedSubStructs(char*, int);
extern "C" {
Zone3D* func_02012fe4();
void func_02018d28(Zone3D*, SafeAllocator*, void*, unsigned int);
void func_0204719c(void*);
void func_02047b40(Foo02048004*, const void*, SafeAllocator*);
void func_02057924();
void func_0208f36c(void*, Object3D*);
void func_02013d24(Zone3D*);
int sprintf(char*, const char*, ...);
}

// USA: func_ov017_0219b624
extern "C" ARM void func_ov017_0219b624(GameResources* self) {
    Foo02048004* sprites;
    Zone3D* globals;
    SafeAllocator* allocator;
#if !defined(jpn)
    GameState* game = GameState::GetInstance();
#endif
    globals = func_02012fe4();
    BackgroundLoader::GetInstance();
    allocator = &self->allocator_array_38[5];
    Foo0207df50* pairs = reinterpret_cast<Foo0207df50*>(reinterpret_cast<char*>(self) + PairTablesOffset);
    allocator->Reset();
    _Z26CopyInternalFields0207df50P11Foo0207df50(pairs);
    BackgroundLoader::AddLockGlobal();
    char path[0x50];
    unsigned int length;
    sprintf(path, data_ov017_021d7504, data_ov017_021d7510);
    if (!LoadFileIntoMemory(path, &data_0211e33c, &length)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    _Z25RestorePairTables0207df90Pc((char*)pairs);
    NarcHandle archive;
    if (!archive.Initialize(data_ov017_021d751b, (const unsigned char*)&data_0211e33c)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    func_02018d28(globals, allocator, &data_0211e33c, length);
    char name[0x50];
    int i = 0;
    for (; data_ov017_021d656c[i].index >= 0; i++) {
        sprites = self->substruct_array_2b90;
        int index = data_ov017_021d656c[i].index;
        sprintf(name, data_ov017_021d751f, data_ov017_021d656c[i].name);
        func_0204719c(&sprites[index]);
        const void* file = GetFileFromNARCInMemory(name);
        if (file != 0) func_02047b40(&sprites[index], file, allocator);
    }
#if !defined(jpn)
    sprintf(name, data_ov017_021d751f, data_ov017_021d7526);
    switch (_Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)game)) {
    case 3: sprintf(name, data_ov017_021d751f, data_ov017_021d7530); break;
    case 5: sprintf(name, data_ov017_021d751f, data_ov017_021d753a); break;
    }
    func_0204719c(&self->substruct_array_2b90[0]);
    {
        const void* file = GetFileFromNARCInMemory(name);
        if (file != 0) func_02047b40(&self->substruct_array_2b90[0], file, allocator);
    }
#endif
    const void* file;
    file = GetFileFromNARCInMemory(data_ov017_021d7544);
    if (file != 0) {
        func_0204719c(&(*reinterpret_cast<Foo02048004*>(self->unknown_3520)));
        func_02047b40(&(*reinterpret_cast<Foo02048004*>(self->unknown_3520)), file, allocator);
    }
    file = GetFileFromNARCInMemory(data_ov017_021d7555);
    if (file != 0) {
        func_0204719c(&(*reinterpret_cast<Foo02048004*>(self->unknown_35a8)));
        func_02047b40(&(*reinterpret_cast<Foo02048004*>(self->unknown_35a8)), file, allocator);
    }
    archive.Destroy();
    func_02057924();
    unsigned int size;
    if (GetFileInNarc(&data_0211e33c, data_ov017_021d7567, &file, &size, 0)) {
        Object3D* object = (Object3D*)allocator->Allocate(0xac);
        if (object != 0) {
            object->Initialize();
            ObjectArchiveLoadInfo info;
            info.fileData = file;
            info.unk_8 = size;
            info.allocator = allocator;
            info.unk_10 = 1;
            object->LoadFromCHRArchive(&info);
            func_0208f36c(GetData02109020(), object);
        }
    }
    BackgroundLoader::RemoveLockGlobal();
    InitFourNamedSubStructs(static_cast<char*>(self->unknown_ptr_4328), (int)allocator);
    _Z24BackupPairTables0207dfacPc((char*)pairs);
    globals->lootableTemplates_[0] = &self->substruct_array_2b90[5];
    globals->lootableTemplates_[1] = &self->substruct_array_2b90[6];
    globals->lootableTemplates_[2] = &self->substruct_array_2b90[7];
    globals->lootableTemplates_[3] = &self->substruct_array_2b90[8];
    globals->lootableTemplates_[4] = &self->substruct_array_2b90[9];
    globals->lootableTemplates_[5] = &self->substruct_array_2b90[10];
    func_02013d24(globals);
}
