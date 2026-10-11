#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"

extern "C" {
    int _Z17IsInRange0201b5b0i(int id);
    int _Z22IsValueInRange0201b5d8i(int id);
}

extern char data_020ef116[];
extern char data_020ef156[];
extern char data_020ef166[];
extern char data_020ef176[];
extern char data_020ef182[];
extern char data_020ef18e[];

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020145a8
void Zone3D::LoadMapAMDJ() {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char buf[0x14];

    if (_Z17IsInRange0201b5b0i(currentZoneID_)) {
        int env = grotto_.GetActiveGrottoEnviron();
        if (env == 0) env = 1;
        if (env > 5) env = 5;
        sprintf(buf, data_020ef156, data_020ef116, env);
    } else if (_Z22IsValueInRange0201b5d8i(currentZoneID_)) {
        int env = grotto_.GetActiveGrottoEnviron();
        sprintf(buf, data_020ef166, data_020ef116, env);
    } else if (currentZoneID_ == 10000 || currentZoneID_ == 10100) {
        if (unknown_42c_ == 0) {
            sprintf(buf, data_020ef176, data_020ef116, *(int*)((char*)this + 8) + 5);
            unknown_42c_++;
        } else if (unknown_42c_ == 1) {
            sprintf(buf, data_020ef182, data_020ef116, *(int*)((char*)this + 8) + 5);
            unknown_42c_++;
        }
    } else {
        sprintf(buf, data_020ef18e, data_020ef116, *(int*)((char*)this + 8) + 5);
    }

    mapAMDJLoadHandle_ = loader->QueueLoadFile(buf, NULL);
}
