#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "Combat/Overlay15ViewerContext.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

void* ResetObjectState02079a3c(void* obj);
extern "C" void* __clear(void* dst, int bytes);
extern char data_ov015_02194094[27] __attribute__((aligned(4)));
extern char data_ov015_021940af[9];
extern char data_ov015_021940b8[8];
extern char data_ov015_0219408e[6];

// USA: func_ov015_0218c920
extern "C" ARM void func_ov015_0218c920(void* context, int unused) {
    Obj0218c274* self = static_cast<Obj0218c274*>(context);
    SafeAllocator allocator;
    allocator.ResetAllocatorPointer();
    allocator.CreateTypeA(self->buffer_, self->bufferSize_);
    allocator.Reset();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    unsigned int size = 0;
    char* buffer = reinterpret_cast<char*>(data_0211e33c);
    unsigned int room = 0x30000;
    GPCReadPair pair;
    ResetObjectState02079a3c(&pair);
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine,
            data_ov015_02194094, buffer, size, room, false, 0)) {
        buffer += size;
        room -= size;
        self->objects_[0].RemoveAllAnimationPackages();
        self->objects_[2].RemoveAllAnimationPackages();
        self->objects_[3].RemoveAllAnimationPackages();
        self->objects_[7].RemoveAllAnimationPackages();
        self->objects_[8].RemoveAllAnimationPackages();
        self->objects_[9].RemoveAllAnimationPackages();
        self->objects_[6].RemoveAllAnimationPackages();
        self->objects_[5].RemoveAllAnimationPackages();
        self->objects_[1].RemoveAllAnimationPackages();
        char status[0x80];
        char name[0x80];
        __clear(status, 0x80);
        __clear(name, 0x80);
        func_ov015_0218c274(self, status, 0);
        sprintf(name, data_ov015_021940af, status);
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, name);
        self->objects_[0].LoadType0AnimationFromFileInMemory(0, &allocator, buffer, size);
        unsigned int firstSize = size;
        room -= firstSize;
        sprintf(name, data_ov015_021940b8, status);
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer + firstSize, size, room, name);
        self->objects_[0].LoadType0AnimationPackageFromBCFGScript(&allocator, buffer + firstSize, size);
        allocator.Destroy();
        self->objects_[0].StopCurrentAnimation();
        self->objects_[0].MaybeSetRegularAnimation(data_ov015_0219408e, 0);
    }
    BackgroundLoader::RemoveLockGlobal();
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
