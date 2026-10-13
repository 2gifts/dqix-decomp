#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "World/Zone3D.h"

struct Obj02013fb4;
struct StreamHeader;

#if defined(jpn)
#define _ZN6Zone3D11LoadMapAMBLEv func_02013e08
#define ApplyAndClearPendingEntry02013fb4 func_02013d80
extern "C" ARM int func_02013d80(Obj02013fb4* object);
#endif

extern "C" void func_0201c724(int zoneId, void* mapList, StreamHeader* data, int size);
extern "C" void _ZN6Zone3D11LoadMapAMBLEv(Zone3D* zone);

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
    _ZN6Zone3D11LoadMapAMBLEv(zone);
    return 1;
}
