#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

#if defined(jpn)
#define data_020ef1d6 data_020ef112
#endif
extern char data_020ef1d6[];

// KEEP-NAME
// USA: func_02014c04
ARM int Zone3D::UnpackATS_AMBL_02014c04() {
    if (atsAMBLLoadHandle_ < 0) return 1;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(atsAMBLLoadHandle_)) return 0;
    if (loader->GetDetailedTaskStatus(atsAMBLLoadHandle_) != 2) {
        loader->RemoveTask(atsAMBLLoadHandle_);
        atsAMBLLoadHandle_ = -1;
        LoadMapAMDJ_020145a8();
        return 1;
    }
    void* archive;
    unsigned int archiveSize;
    const void* script;
    unsigned int scriptSize;
    char filename[0x28];
    loader->GetLoadedFileByID(atsAMBLLoadHandle_, &archive, &archiveSize);
    sprintf(filename, data_020ef1d6, substruct_c_.buffer1);
    if (!GetFileInNarc(archive, filename, &script, &scriptSize, 0)) {
        loader->RemoveTask(atsAMBLLoadHandle_);
        atsAMBLLoadHandle_ = -1;
        LoadMapAMDJ_020145a8();
        return 1;
    }
    ProcessBATSFile_02014414(script, scriptSize);
    loader->RemoveTask(atsAMBLLoadHandle_);
    atsAMBLLoadHandle_ = -1;
    LoadMapAMDJ_020145a8();
    return 1;
}
