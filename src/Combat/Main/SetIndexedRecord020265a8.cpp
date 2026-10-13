#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define data_020ef6d0 data_020ef5c0
#define data_020ef6d3 data_020ef5c3
#endif

extern char data_020ef6d0;
extern char data_020ef6ca;
extern char data_020ef6d3;

struct TreasureDropDisplay {
    char unknown0[0x5fc];
#if defined(jpn)
    char names[3][0x24];
#else
    char names[3][0x48];
#endif
    char rates[3][8];
};

ARM void SetIndexedRecord020265a8(char* owner, int index, const char* name, int dropRate) {
    TreasureDropDisplay* display = reinterpret_cast<TreasureDropDisplay*>(owner);
    if (static_cast<unsigned int>(index) >= 3) return;
    if (name != NULL && *name != 0) {
        strcpy(display->names[index], name);
        sprintf(display->rates[index], &data_020ef6d0, dropRate);
    } else {
        strcpy(display->names[index], &data_020ef6ca);
        strcpy(display->rates[index], &data_020ef6d3);
    }
}
