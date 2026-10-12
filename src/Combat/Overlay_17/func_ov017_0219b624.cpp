#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Memory/SafeAllocator.h"

struct Foo0207df50 { unsigned char fields[0x70]; };
struct Struct0200fb08;
struct SpriteResource0219b624 { unsigned char fields[0x88]; };
struct ResourceState0219b624 {
    unsigned char padding_0[0x9c];
    SafeAllocator allocator;
    unsigned char padding_b0[0x4fc - 0xb0];
    Foo0207df50 pairs;
    unsigned char padding_56c[0x2b90 - 0x56c];
    SpriteResource0219b624 sprites[20];
    unsigned char padding_3630[0x4328 - 0x3630];
    char* named;
};
struct ResourceGlobals0219b624 {
    unsigned char padding_0[0x480];
    SpriteResource0219b624* sprites[6];
};
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
ResourceGlobals0219b624* func_02012fe4();
void func_02018d28(ResourceGlobals0219b624*, SafeAllocator*, void*, unsigned int);
void func_0204719c(void*);
void func_02047b40(SpriteResource0219b624*, const void*, SafeAllocator*);
void func_02057924();
void func_0208f36c(void*, Object3D*);
void func_02013d24(ResourceGlobals0219b624*);
int sprintf(char*, const char*, ...);
}

// USA: func_ov017_0219b624
extern "C" ARM void func_ov017_0219b624(ResourceState0219b624* self) {
    SpriteResource0219b624* sprites;
    ResourceGlobals0219b624* globals;
    SafeAllocator* allocator;
    GameState* game = GameState::GetInstance();
    globals = func_02012fe4();
    BackgroundLoader::GetInstance();
    allocator = &self->allocator;
    Foo0207df50* pairs = &self->pairs;
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
        sprites = self->sprites;
        int index = data_ov017_021d656c[i].index;
        sprintf(name, data_ov017_021d751f, data_ov017_021d656c[i].name);
        func_0204719c(&sprites[index]);
        const void* file = GetFileFromNARCInMemory(name);
        if (file != 0) func_02047b40(&sprites[index], file, allocator);
    }
    sprintf(name, data_ov017_021d751f, data_ov017_021d7526);
    switch (_Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)game)) {
    case 3: sprintf(name, data_ov017_021d751f, data_ov017_021d7530); break;
    case 5: sprintf(name, data_ov017_021d751f, data_ov017_021d753a); break;
    }
    func_0204719c(&self->sprites[0]);
    {
        const void* file = GetFileFromNARCInMemory(name);
        if (file != 0) func_02047b40(&self->sprites[0], file, allocator);
    }
    const void* file;
    file = GetFileFromNARCInMemory(data_ov017_021d7544);
    if (file != 0) {
        func_0204719c(&self->sprites[18]);
        func_02047b40(&self->sprites[18], file, allocator);
    }
    file = GetFileFromNARCInMemory(data_ov017_021d7555);
    if (file != 0) {
        func_0204719c(&self->sprites[19]);
        func_02047b40(&self->sprites[19], file, allocator);
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
    InitFourNamedSubStructs(self->named, (int)allocator);
    _Z24BackupPairTables0207dfacPc((char*)pairs);
    globals->sprites[0] = &self->sprites[5];
    globals->sprites[1] = &self->sprites[6];
    globals->sprites[2] = &self->sprites[7];
    globals->sprites[3] = &self->sprites[8];
    globals->sprites[4] = &self->sprites[9];
    globals->sprites[5] = &self->sprites[10];
    func_02013d24(globals);
}
