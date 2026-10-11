#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Combat/Overlay15ViewerContext.h"

extern "C" void* __clear(void* dst, int count);
extern "C" void _Z24ResetObjectState02079a3cPv(void* obj);

struct Struct_203dafc;
void ClearEightWords(struct Struct_203dafc* obj);

extern char data_ov015_02194020[27] __attribute__((aligned(4)));
extern char data_ov015_0219403b[7];
extern char data_ov015_02194042[8];
extern char data_ov015_0219404a[8];
extern char data_ov015_02194052[17];
extern char data_ov015_02194064[20];
extern char data_ov015_02194078[22];
extern char data_ov015_0219408e[6];

// USA: func_ov015_0218c538
extern "C" ARM void func_ov015_0218c538(Obj0218c274* self, char* arg) {
    self->objects_[0].RemoveAllAnimationPackages();
    self->objects_[1].RemoveAllAnimationPackages();

    SafeAllocator allocator;
    allocator.ResetAllocatorPointer();
    allocator.CreateTypeA(self->buffer_, self->bufferSize_);
    allocator.Reset();

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    char status[0x80];
    char name[0x80];
    __clear(status, 0x80);
    __clear(name, 0x80);

    unsigned int size = 0;
    char* buffer = reinterpret_cast<char*>(data_0211e33c);
    unsigned int room = 0x30000;
    GPCReadPair pair;
    _Z24ResetObjectState02079a3cPv(&pair);

    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine,
            data_ov015_02194020, buffer, size, room, false, 0)) {
        buffer += size;
        room -= size;

        func_ov015_0218c274(self, status, 0);
        sprintf(name, data_ov015_0219403b, status);
        if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, name)) {
            ObjectArchiveLoadInfo info1;
            ClearEightWords((Struct_203dafc*)&info1);
            info1.allocator = &allocator;
            info1.unk_8 = size;
            info1.fileData = buffer;
            info1.unk_10 = 1;
            self->objects_[0].LoadFromCCHROrCMOTArchive(&info1, 0);
            buffer += size;
            room -= size;
        }

        if (self->field48_ == 1) {
            sprintf(name, data_ov015_02194042, status);
            if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, name)) {
                ObjectArchiveLoadInfo info2;
                ClearEightWords((Struct_203dafc*)&info2);
info2.allocator = &allocator;
            info2.unk_8 = size;
            info2.fileData = buffer;
            info2.unk_10 = 1;
                self->objects_[0].LoadFromCCHROrCMOTArchive(&info2, 0);
                buffer += size;
                room -= size;
            }
            sprintf(name, data_ov015_0219404a, status);
            if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, name)) {
                ObjectArchiveLoadInfo info3;
                ClearEightWords((Struct_203dafc*)&info3);
info3.allocator = &allocator;
            info3.unk_8 = size;
            info3.fileData = buffer;
            info3.unk_10 = 1;
                self->objects_[0].LoadFromCCHROrCMOTArchive(&info3, 0);
                buffer += size;
                room -= size;
            }
        }

        func_ov015_0218c274(self, status, 1);
        if (self->field48_ == 0) {
            sprintf(name, data_ov015_02194042, status);
        } else {
            sprintf(name, data_ov015_0219403b, status);
        }
        if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, name)) {
            ObjectArchiveLoadInfo info4;
            ClearEightWords((Struct_203dafc*)&info4);
            info4.allocator = &allocator;
            info4.unk_8 = size;
            info4.fileData = buffer;
            info4.unk_10 = 1;
            self->objects_[0].LoadFromCCHROrCMOTArchive(&info4, 0);
        }

        pair.Reset();
    }

    if (arg != 0) {
        char code = 'w';
        if (self->flag3b_ == 0)
            code = 'm';
        if (*(int*)((char*)self->viewer_ + 0x1a4) == 0x1f) {
            sprintf(name, data_ov015_02194052, arg);
        } else if (*(int*)((char*)self->viewer_ + 0x1a4) == 0x20) {
            sprintf(name, data_ov015_02194064, arg, code);
        } else {
            sprintf(name, data_ov015_02194078, arg);
        }
        if (LoadFileIntoMemory(name, data_0211e33c, &size)) {
            ObjectArchiveLoadInfo info5;
            ClearEightWords((Struct_203dafc*)&info5);
            info5.allocator = &allocator;
            info5.fileData = data_0211e33c;
            info5.unk_8 = size;
            info5.unk_10 = 1;
            info5.packageID = 4;
            self->objects_[0].LoadFromCCHROrCMOTArchive(&info5, 0);
        }
    }

    allocator.Destroy();
    BackgroundLoader::RemoveLockGlobal();
    self->objects_[0].StopCurrentAnimation();
    self->objects_[0].MaybeSetRegularAnimation(data_ov015_0219408e, 0);
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}