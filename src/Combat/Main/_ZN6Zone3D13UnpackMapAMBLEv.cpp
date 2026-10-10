#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" {
    void func_020c9be0();
    void _ZN6Zone3D17QueueLoadATS_AMBLEv(char* obj);
    void _ZN6Zone3D16ProcessNSBTXFileEPKvjPKc(char* obj, const void* src, unsigned int size, const char* name);
    void _ZN6Zone3D15ProcessBMBLFileEPKvj(char* obj, const void* src, unsigned int size);
    void _ZN6Zone3D15ProcessBPOSFileEPKvj(char* obj, const void* src, unsigned int size);
}

struct StreamHeader;
extern "C" void _Z25RunBufferedStream0205e104iiP12StreamHeaderi(int, int, StreamHeader*, int);

extern char data_020ef13a;
extern char data_020ef13e;
extern char data_020ef145;
extern char data_020ef14b;
extern char data_020ef150;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02014108
extern "C" ARM int _ZN6Zone3D13UnpackMapAMBLEv(char* obj) {
    if (*(int*)(obj + 0x438) < 0) {
        return 1;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(*(int*)(obj + 0x438))) {
        return 0;
    }

    if (loader->GetDetailedTaskStatus(*(int*)(obj + 0x438)) != 2) {
        loader->RemoveTask(*(int*)(obj + 0x438));
        *(int*)(obj + 0x438) = -1;
        return 1;
    }

    void* out1;
    unsigned int out2;
    loader->GetLoadedFileByID(*(int*)(obj + 0x438), &out1, &out2);

    for (int pass = 0; pass < 2; pass++) {
        NarcHandle narc;
        if (narc.Initialize(&data_020ef13a, (const unsigned char*)out1)) {
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
                        _ZN6Zone3D16ProcessNSBTXFileEPKvjPKc(obj, src, size, name);
                    }
                } else if (pass == 1) {
                    if (strcmp(&data_020ef145, dot) == 0) {
                        _ZN6Zone3D15ProcessBMBLFileEPKvj(obj, src, size);
                    } else if (strcmp(&data_020ef14b, dot) == 0) {
                        SafeAllocator* alloc = *(SafeAllocator**)(obj + 0x68);
                        unsigned int decompSize;
                        void* data = DecompressLZ77FileIntoScratchSpace(*alloc, src, decompSize);
                        _Z25RunBufferedStream0205e104iiP12StreamHeaderi((int)(obj + 0xc), (int)alloc, (StreamHeader*)data, decompSize);
                    } else if (strcmp(&data_020ef150, dot) == 0) {
                        _ZN6Zone3D15ProcessBPOSFileEPKvj(obj, src, size);
                    }
                }
                idx++;
            }
            narc.Destroy();
        }

        if (pass == 0) {
            unsigned int maxSize = (*(SafeAllocator**)(obj + 0x4c))->GetMaxPossibleAllocation();
            void* mem = (*(SafeAllocator**)(obj + 0x4c))->Allocate(maxSize);
            if (mem == 0) {
                func_020c9be0();
            }
            ((SafeAllocator*)(obj + 0x54))->ResetAllocatorPointer();
            ((SafeAllocator*)(obj + 0x54))->CreateTypeA(mem, maxSize);
            *(SafeAllocator**)(obj + 0x68) = (SafeAllocator*)(obj + 0x54);
            ((SafeAllocator*)(obj + 0x54))->Reset();
        }
    }

    loader->RemoveTask(*(int*)(obj + 0x438));
    *(int*)(obj + 0x438) = -1;
    _ZN6Zone3D17QueueLoadATS_AMBLEv(obj);
    return 1;
}
