#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/NarcHandle.h"
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"
#include "std_library_functions.h"


extern "C" char* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(char* obj);
extern "C" void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" void _Z24BackupPairTables0207dfacPc(char* obj);
extern "C" void _Z29CallFunc0202f310AtField0x19e0Pci(char* base, SafeAllocator* alloc, void* data);

extern char data_ov017_021d7504[];
extern char data_ov017_021d7510[];
extern char data_ov017_021d751b[];
extern char data_ov017_021d7577[];
extern char data_ov017_021d7584[];
extern char data_ov017_021d758d[];
extern char data_ov017_021d75a2[];

// JPN: func_ov017_0219c4fc
// USA: func_ov017_0219ba0c
extern "C" ARM void func_ov017_0219ba0c(GameResources* res, int skipModels) {
    const void* file;
    unsigned int fileSize;
    unsigned int length;
    unsigned int size;
    char* controller = _Z26GetGlobalField0x1c020421a0v();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    SafeAllocator* alloc = &res->allocator_array_38[6];
    char* tables = res->unknown_2cc + 0x2a0;
    loader->AddLockGlobal();
    alloc->Reset();
    _Z26CopyInternalFields0207df50P11Foo0207df50(tables);
    _Z25RestorePairTables0207df90Pc(tables);

    char path[0x50];
    sprintf(path, data_ov017_021d7504, data_ov017_021d7510);
    if (!LoadFileIntoMemory(path, data_0211e33c, &length)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }

    NarcHandle narc;
    if (!narc.Initialize(data_ov017_021d751b, data_0211e33c)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    _Z29CallFunc0202f310AtField0x19e0Pci(controller, alloc, data_0211e33c);
    if (skipModels) {
        narc.Destroy();
        _Z24BackupPairTables0207dfacPc(tables);
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    narc.Destroy();

    ((Model3D*)res->unknown_ptr_36c8)->Clear();
    if (GetFileInNarc(data_0211e33c, data_ov017_021d7577, &file, &fileSize, 0)) {
        ((Model3D*)res->unknown_ptr_36c8)->CopyAndProcessRawFile(&alloc->allocUnion, file, fileSize, Model3D::TextureStagingMode_Normal);
    }
    ((Object3D*)res->unknown_ptr_36cc)->Initialize();
    if (GetFileInNarc(data_0211e33c, data_ov017_021d7584, &file, &fileSize, 0)) {
        ObjectArchiveLoadInfo info;
        info.fileData = file;
        info.unk_8 = fileSize;
        info.allocator = alloc;
        info.unk_10 = 1;
        ((Object3D*)res->unknown_ptr_36cc)->LoadFromCHRArchive(&info);
    }
    _Z24BackupPairTables0207dfacPc(tables);

    if (!LoadFileIntoMemory(data_ov017_021d758d, data_0211e33c, &size)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* buf = alloc->Allocate(size);
    if (buf == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    memcpy(buf, data_0211e33c, size);
    *(void**)((char*)res + 0x30) = buf;
    *(unsigned int*)((char*)res + 0x34) = size;
    if (!LoadFileIntoMemory(data_ov017_021d75a2, data_0211e33c, &size)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    buf = alloc->Allocate(size);
    if (buf == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    memcpy(buf, data_0211e33c, size);
    *(void**)((char*)res + 0x2c) = buf;
    BackgroundLoader::RemoveLockGlobal();
}
