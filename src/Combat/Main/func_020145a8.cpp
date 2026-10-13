#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"

int IsInRange0201b5b0(int id);
int IsValueInRange0201b5d8(int id);

#if defined(jpn)
#define data_020ef156 data_020ef092
#define data_020ef166 data_020ef0a2
#define data_020ef176 data_020ef0b2
#define data_020ef182 data_020ef0be
#endif

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

    if (IsInRange0201b5b0(currentZoneID_)) {
        int env = grotto_.GetActiveGrottoEnviron();
        if (env == 0) env = 1;
        if (env > 5) env = 5;
        sprintf(buf, data_020ef156, data_020ef116, env);
    } else if (IsValueInRange0201b5d8(currentZoneID_)) {
        int env = grotto_.GetActiveGrottoEnviron();
        sprintf(buf, data_020ef166, data_020ef116, env);
    } else if (currentZoneID_ == 10000 || currentZoneID_ == 10100) {
        if (unknown_42c_ == 0) {
            sprintf(buf, data_020ef176, data_020ef116, pUnknownStruct_8_->mapShortName_);
            unknown_42c_++;
        } else if (unknown_42c_ == 1) {
            sprintf(buf, data_020ef182, data_020ef116, pUnknownStruct_8_->mapShortName_);
            unknown_42c_++;
        }
    } else {
        sprintf(buf, data_020ef18e, data_020ef116, pUnknownStruct_8_->mapShortName_);
    }

    mapAMDJLoadHandle_ = loader->QueueLoadFile(buf, NULL);
}
