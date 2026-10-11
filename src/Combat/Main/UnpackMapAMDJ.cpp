#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneFeatures.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/NitroVM.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileAccessor.h"
#include "std_library_functions.h"

struct Zone3D_BMDJNode
{
    char unknown_0_[0x54];
    Zone3D_BMDJNode* pNext_;
};

extern "C"
{
    ZoneFeatures::Opcode64Entry* _ZN12ZoneFeatures16GetOpcode64EntryEi(void* features, int index);
    int _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE(Zone3D* zone, const void* src, unsigned int size, ZoneFeatures::Opcode64Entry* entry);
    int func_02014a24(Zone3D* zone, void* node);
}

extern char data_020ef13a[];
extern char data_020ef199[];

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020146fc
// USA: _ZN6Zone3D13UnpackMapAMDJEv
ARM int Zone3D::UnpackMapAMDJ()
{
    if (mapAMDJLoadHandle_ < 0)
        return 1;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (loader->GetTaskStatus(mapAMDJLoadHandle_) == 0)
        return 0;

    if (loader->GetDetailedTaskStatus(mapAMDJLoadHandle_) != BackgroundLoader::TaskStatus_Complete)
    {
        loader->RemoveTask(mapAMDJLoadHandle_);
        mapAMDJLoadHandle_ = -1;
        return 1;
    }

    void* archiveData;
    unsigned int archiveLength;
    loader->GetLoadedFileByID(mapAMDJLoadHandle_, &archiveData, &archiveLength);

    NarcHandle narc;
    if (narc.Initialize(data_020ef13a, (const unsigned char*)archiveData))
    {
        NitroVM vm;
        unsigned int fileID = 0;
        NitroVM_Initialize(&vm);

        while (PrepareReadFileInNARCByID(&vm, &narc, fileID))
        {
            char innerFilePath[0x50];
            NitroVM_WriteOutFilePath(&vm, innerFilePath, sizeof(innerFilePath));
            const char* extension = strrchr(innerFilePath, '.');
            if (extension == NULL)
            {
                NitroVM_FinishRead(&vm);
                fileID++;
                continue;
            }

            unsigned int innerFileLength = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
            NitroVM_FinishRead(&vm);
            const void* innerFile = narc.GetFileByIndex(fileID);

            if (strcmp(data_020ef199, extension) == 0)
            {
                int entryCount = *(int*)(substruct_6c_ + 4);
                int i = 0;
                while (i < entryCount)
                {
                    ZoneFeatures::Opcode64Entry* entry = _ZN12ZoneFeatures16GetOpcode64EntryEi(substruct_6c_, i);
                    if (strstr(innerFilePath, entry->string_10) != NULL)
                        _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE(this, innerFile, innerFileLength, entry);
                    i++;
                }
            }
            fileID++;
        }

        Zone3D_BMDJNode* node = (Zone3D_BMDJNode*)firstBMDJStruct_41c_;
        while (node != NULL)
        {
            func_02014a24(this, node);
            if (unknown_42c_ == 2)
                break;
            node = node->pNext_;
        }

        narc.Destroy();
    }

    loader->RemoveTask(mapAMDJLoadHandle_);
    mapAMDJLoadHandle_ = -1;

    if (unknown_42c_ == 1)
    {
        LoadMapAMDJ();
        return 0;
    }

    if (this->substruct_c_.buffer2[0] != 0)
        atmosphericEffects_.LoadArchive(this->substruct_c_.buffer2);

    return 1;
}
