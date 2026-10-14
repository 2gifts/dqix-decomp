#include <globaldefs.h>
#include "Filesystem/OverlayFSManagement.h"

struct FourWords;
struct Mutex;
void ZeroInitializeMutex(Mutex*);
void Fill6BytesWithFF_020a18d4(char* p);

extern struct FourWords data_01ffd34c;
extern unsigned char data_01ffd344;
extern unsigned char data_01ffd340;
extern char data_01ffd364[8][6];
extern struct OverlayMetadata data_01ffd394[35];
extern int data_01ffd348;

// USA: func_020a1838
ARM void InitOverlaySystem_020a1838(void) {
    unsigned int i;
    unsigned int j;

    ZeroInitializeMutex((Mutex*)&data_01ffd34c);
    data_01ffd344 = 1;
    data_01ffd340 = 0;

    for (i = 0; i < 8; i++) {
        Fill6BytesWithFF_020a18d4(data_01ffd364[i]);
    }

    for (j = 0; j < 0x23; j++) {
        LoadOverlayMetadata(&data_01ffd394[j], false, j);
    }

    data_01ffd348 = 0;
}
