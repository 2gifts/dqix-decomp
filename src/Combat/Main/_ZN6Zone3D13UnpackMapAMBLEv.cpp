#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" {
    void func_020c9be0();
    void _ZN6Zone3D17QueueLoadATS_AMBLEv(void* obj);
}

void RunBufferedStream0205e104(char*, SafeAllocator*, const void*, unsigned int);
#if defined(jpn)
extern "C" void func_020148d0(void*);
#define data_020ef13e data_020ef07a
#define data_020ef145 data_020ef081
#define data_020ef14b data_020ef087
#define data_020ef150 data_020ef08c
#endif

extern char data_020ef13a;
extern char data_020ef13e;
extern char data_020ef145;
extern char data_020ef14b;
extern char data_020ef150;

// KEEP-NAME
// USA: func_02014108
ARM int Zone3D::UnpackMapAMBL() {
    if (mapAMBLLoadHandle_ < 0) {
        return 1;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(mapAMBLLoadHandle_)) {
        return 0;
    }

    if (loader->GetDetailedTaskStatus(mapAMBLLoadHandle_) != 2) {
        loader->RemoveTask(mapAMBLLoadHandle_);
        mapAMBLLoadHandle_ = -1;
        return 1;
    }

    void* archive;
    unsigned int archiveLength;
    loader->GetLoadedFileByID(mapAMBLLoadHandle_, &archive, &archiveLength);

    for (int pass = 0; pass < 2; pass++) {
        NarcHandle narc;
        if (narc.Initialize(&data_020ef13a, static_cast<const unsigned char*>(archive))) {
            NitroVM vm;
            unsigned int idx = 0;
            NitroVM_Initialize(&vm);
            while (PrepareReadFileInNARCByID(&vm, &narc, idx)) {
                char name[0x50];
                NitroVM_WriteOutFilePath(&vm, name, 0x50);
                char* dot = strrchr(name, '.');
                if (dot == 0) {
                    NitroVM_FinishRead(&vm);
                    idx++;
                    continue;
                }
                unsigned int size = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
                NitroVM_FinishRead(&vm);
                const void* src = narc.GetFileByIndex(idx);
                if (pass == 0) {
                    if (strcmp(&data_020ef13e, dot) == 0) {
                        ProcessNSBTXFile(src, size, name);
                    }
                } else if (pass == 1) {
                    if (strcmp(&data_020ef145, dot) == 0) {
                        ProcessBMBLFile(src, size);
                    } else if (strcmp(&data_020ef14b, dot) == 0) {
                        SafeAllocator* alloc = pAllocator_68_;
                        unsigned int decompSize;
                        void* data = DecompressLZ77FileIntoScratchSpace(*alloc, src, decompSize);
                        RunBufferedStream0205e104(reinterpret_cast<char*>(&substruct_c_), alloc, data, decompSize);
                    } else if (strcmp(&data_020ef150, dot) == 0) {
                        ProcessBPOSFile(src, size);
                    }
                }
                idx++;
            }
            narc.Destroy();
        }

        if (pass == 0) {
            unsigned int maxSize = pAllocator_4c_->GetMaxPossibleAllocation();
            void* mem = pAllocator_4c_->Allocate(maxSize);
            if (mem == 0) {
                func_020c9be0();
            }
            internalAllocator_.ResetAllocatorPointer();
            internalAllocator_.CreateTypeA(mem, maxSize);
            pAllocator_68_ = &internalAllocator_;
            internalAllocator_.Reset();
        }
    }

    loader->RemoveTask(mapAMBLLoadHandle_);
    mapAMBLLoadHandle_ = -1;
#if defined(jpn)
    func_020148d0(this);
#else
    _ZN6Zone3D17QueueLoadATS_AMBLEv(this);
#endif
    return 1;
}
