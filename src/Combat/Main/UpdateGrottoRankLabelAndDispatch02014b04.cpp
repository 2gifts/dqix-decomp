#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "std_library_functions.h"
#include "World/Zone3D.h"

extern char data_020ef19f;
extern char data_020ef1a9;
extern char data_020ef1b3;
extern char data_020ef1bd;
extern char data_020ef1c7;
extern char data_020ef116;

// USA: func_02014b04
extern "C" ARM void _ZN6Zone3D17QueueLoadATS_AMBLEv(void* obj) {
    char* o = (char*)obj;

    if (*(unsigned char*)(o + 0x23b8) != 0) {
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)(o + 0x23ec);
        int env = grotto->GetActiveGrottoEnviron();
        if (env == 0) env = 1;

        signed char rank = *(signed char*)(o + 0x23ba);
        if (rank <= 0x4) {
            sprintf(o + 0xc, &data_020ef19f, env);
        } else if (rank <= 0x8) {
            sprintf(o + 0xc, &data_020ef1a9, env);
        } else if (rank <= 0xc) {
            sprintf(o + 0xc, &data_020ef1b3, env);
        } else if (rank <= 0x10) {
            sprintf(o + 0xc, &data_020ef1bd, env);
        }
    }

    if (strlen(o + 0xc) == 0) {
        ((Zone3D*)obj)->LoadMapAMDJ();
        return;
    }

    int handle = (int)BackgroundLoader::GetInstance();
    signed char b = *(signed char*)(o + 0xc);
    char buf[0x28];
    sprintf(buf, &data_020ef1c7, &data_020ef116, b);
    *(int*)(o + 0x440) = ((BackgroundLoader*)(handle))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
}
