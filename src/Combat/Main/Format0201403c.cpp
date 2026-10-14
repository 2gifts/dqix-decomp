#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"

int IsInRange0201b5b0(int id);
int IsValueInRange0201b5d8(int x);

extern char data_020ef106;
extern char data_020ef116;
extern char data_020ef11f;
extern char data_020ef12f;

// USA: func_0201403c  (semantic: Format0201403c)
ARM void Zone3D::LoadMapAMBL() {
    Zone3D* zone = this;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char buf[0x14];

    if (IsInRange0201b5b0(zone->currentZoneID_)) {
        ActiveGrottoClass* grotto = &zone->grotto_;
        int env = grotto->GetActiveGrottoEnviron();
        if (env == 0) env = 1;
        if (env > 5) env = 5;
        sprintf(buf, &data_020ef106, &data_020ef116, env);
    } else if (IsValueInRange0201b5d8(zone->currentZoneID_)) {
        ActiveGrottoClass* grotto = &zone->grotto_;
        int env = grotto->GetActiveGrottoEnviron();
        sprintf(buf, &data_020ef11f, &data_020ef116, env);
    } else {
        sprintf(buf, &data_020ef12f, &data_020ef116, zone->pUnknownStruct_8_->mapShortName_);
    }

    zone->mapAMBLLoadHandle_ = loader->QueueLoadFile(buf, NULL);
}
