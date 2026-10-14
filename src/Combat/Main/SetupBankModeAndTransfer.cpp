#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int LoadToSubBG0CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern int data_021065d8;
extern int data_02105fd8;

// USA: func_0203b678
ARM void SetupBankModeAndTransfer_0203b678(int* arr, int index, int mode) {
    char buf[0x20];
    arr[index] = 0x20;
    *(int*)((char*)&arr[index] + 0x20) = 1;
    memset(buf, 0, sizeof(buf));
    if (index == 1) {
        switch (mode) {
        case 0:
            memset(&data_021065d8, 0, 0x1000);
            LoadToSubBG0CharacterData((int)buf, 0, 0x20);
            break;
        case 1:
            memset(&data_02105fd8, 0, 0x600);
            LoadToSubBG1CharacterData((int)buf, 0, 0x20);
            break;
        }
    }
}
