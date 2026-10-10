#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"
#include "World/ZoneFeatures.h"
#include "Graphics/AtmosphericEffect.h"
#include "std_library_functions.h"

extern "C" void _ZN6Zone3D11LoadMapAMDJEv(void* obj);
extern "C" void _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE(void* obj, const void* src, unsigned int length, ZoneFeatures::Opcode64Entry* entry);
extern "C" int func_02014a24(void* zone, void* data);

extern char data_020ef13a;
extern char data_020ef199;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020146fc
extern "C" ARM int _ZN6Zone3D13UnpackMapAMDJEv(void* objp) {
    char* obj = (char*)objp;
    if (*(int*)(obj + 0x43c) < 0) {
        return 1;
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(*(int*)(obj + 0x43c))) {
        return 0;
    }
    if (loader->GetDetailedTaskStatus(*(int*)(obj + 0x43c)) != 2) {
        loader->RemoveTask(*(int*)(obj + 0x43c));
        *(int*)(obj + 0x43c) = -1;
        return 1;
    }
    void* fileData;
    unsigned int fileLength;
    loader->GetLoadedFileByID(*(int*)(obj + 0x43c), &fileData, &fileLength);
    NarcHandle narc;
    NitroVM machine;
    char filename[0x50];
    if (narc.Initialize(&data_020ef13a, (const unsigned char*)fileData)) {
        unsigned int fileID = 0;
        NitroVM_Initialize(&machine);
        for (; PrepareReadFileInNARCByID(&machine, &narc, fileID); ) {
            NitroVM_WriteOutFilePath(&machine, filename, sizeof(filename));
            char* ext = strrchr(filename, '.');
            if (ext == NULL) {
                NitroVM_FinishRead(&machine);
                fileID++;
                continue;
            }
            unsigned int length = machine.fileInfo.endOffset - machine.fileInfo.startOffset;
            NitroVM_FinishRead(&machine);
            const void* data = narc.GetFileByIndex(fileID);
            if (strcmp(&data_020ef199, ext) == 0) {
                int count = ((ZoneFeatures*)(obj + 0x6c))->arraySize64_;
                for (int i = 0; i < count; i++) {
                    ZoneFeatures::Opcode64Entry* entry = ((ZoneFeatures*)(obj + 0x6c))->GetOpcode64Entry(i);
                    if (strstr(filename, entry->string_10)) {
                        _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE(obj, data, length, entry);
                    }
                }
            }
            fileID++;
        }
        int node = *(int*)(obj + 0x41c);
        while (node != 0) {
            func_02014a24(obj, (void*)node);
            if (*(unsigned char*)(obj + 0x42c) == 2) {
                break;
            }
            node = *(int*)(node + 0x54);
        }
        narc.Destroy();
    }
    loader->RemoveTask(*(int*)(obj + 0x43c));
    *(int*)(obj + 0x43c) = -1;
    if (*(unsigned char*)(obj + 0x42c) == 1) {
        _ZN6Zone3D11LoadMapAMDJEv(obj);
        return 0;
    }
    if (*(signed char*)(obj + 0x16) != 0) {
        ((AtmosphericEffectSet*)(obj + 0xf4))->LoadArchive((const char*)(obj + 0x16));
    }
    return 1;
}
