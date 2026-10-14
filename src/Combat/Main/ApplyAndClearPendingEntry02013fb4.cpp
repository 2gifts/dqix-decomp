#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "World/Zone3D.h"

struct Obj02013fb4;
struct StreamHeader;

extern "C" void func_0201c724(int zoneId, void* mapList, StreamHeader* data, int size);

// USA: func_02013fb4
ARM int ApplyAndClearPendingEntry02013fb4(Obj02013fb4* object) {
    Zone3D* zone = reinterpret_cast<Zone3D*>(object);
    if (zone->mapListLoadHandle_ < 0)
        return 1;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(zone->mapListLoadHandle_))
        return 0;

    void* fileData;
    unsigned int fileSize;
    loader->GetLoadedFileByID(zone->mapListLoadHandle_, &fileData, &fileSize);
    func_0201c724(zone->currentZoneID_, &zone->substruct_c_,
                 static_cast<StreamHeader*>(fileData), fileSize);
    loader->RemoveTask(zone->mapListLoadHandle_);
    zone->mapListLoadHandle_ = -1;
    zone->LoadMapAMBL_0201403c();
    return 1;
}
