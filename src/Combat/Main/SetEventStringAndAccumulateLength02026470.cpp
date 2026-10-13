#include <globaldefs.h>
#include "std_library_functions.h"

int CallFunc020e0434With02153694(int value);
extern "C" int func_020420e8(char*, int);

#if defined(jpn)
#define data_020ef6c5 data_020ef5b0
#endif
extern char data_020ef6b5;
extern char data_020ef6c5;

// KEEP-NAME
// USA: func_02026470
ARM void SetEventStringAndAccumulateLength02026470(void* obj, int number) {
    if (number == 0) {
        strcpy((char*)obj + 0x5f4, &data_020ef6b5);
    } else {
#if defined(jpn)
        sprintf((char*)obj + 0x5f4, &data_020ef6c5, number);
#else
        const char* prefix = (const char*)CallFunc020e0434With02153694(0x3f3);
        sprintf((char*)obj + 0x5f4, &data_020ef6c5, prefix, number);
#endif
    }
#if !defined(jpn)
    int len = func_020420e8((char*)obj + 0x5f4, 0);
    *(int*)((char*)obj + 0xbe4) += len + 4;
#endif
}
