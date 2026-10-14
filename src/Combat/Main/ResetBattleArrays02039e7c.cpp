#include <globaldefs.h>

struct ResetStruct_39ee8;
void ResetFields39ee8_02039ee8(struct ResetStruct_39ee8* s);
extern "C" void func_0204719c(void* p);

// USA: func_02039e7c
ARM void ResetBattleArrays02039e7c(void* objPtr) {
    char* obj = (char*)objPtr;
    int i;
    for (i = 0; i < 0x10; i++) {
        ResetFields39ee8_02039ee8((struct ResetStruct_39ee8*)(obj + 0x550 + i * 0x18));
    }
    for (i = 0; i < 5; i++) {
        func_0204719c(obj + i * 0x88);
        func_0204719c(obj + 0x2a8 + i * 0x88);
    }
    *(int*)(obj + 0x6d0) = 0;
    *(int*)(obj + 0x6d4) = 0;
}
