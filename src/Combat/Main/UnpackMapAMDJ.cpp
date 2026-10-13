#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneFeatures.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/NitroVM.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileAccessor.h"
#include "std_library_functions.h"

struct BmdjScriptNode
{
    int unknown0;
    unsigned char scriptState[0x3c];
    int unknown40;
    int unknown44;
    Vector3i position;
    BmdjScriptNode* next;
};

extern "C"
{
    int _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE(Zone3D* zone, const void* src, unsigned int size, ZoneFeatures::Opcode64Entry* entry);
    int func_02014a24(Zone3D* zone, void* node);
}

extern char data_020ef13a[];
#if defined(jpn)
#define data_020ef199 data_020ef0d5
#endif
extern char data_020ef199[];

// KEEP-NAME
// USA: func_020146fc
// USA: _ZN6Zone3D13UnpackMapAMDJEv
// JPN: func_020144c8
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
                ZoneFeatures* features = reinterpret_cast<ZoneFeatures*>(substruct_6c_);
                int entryCount = features->arraySize64_;
                for (int i = 0; i < entryCount; i++)
                {
                    ZoneFeatures::Opcode64Entry* entry = features->GetOpcode64Entry(i);
                    if (strstr(innerFilePath, entry->string_10) != NULL)
                        _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE(this, innerFile, innerFileLength, entry);
                }
            }
            fileID++;
        }

        BmdjScriptNode* node = static_cast<BmdjScriptNode*>(firstBMDJStruct_41c_);
        while (node != NULL)
        {
            func_02014a24(this, node);
            if (unknown_42c_ == 2)
                break;
            node = node->next;
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
