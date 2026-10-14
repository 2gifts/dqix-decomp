#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct020A2CF0;
void ResetState020a2cf0(struct Struct020A2CF0* obj);
void SetBitsInField0_0202e08c(unsigned int* obj, unsigned int mask);
void Clear0x28Bytes_020a0d58(void* p);
void ResetFields0x2c4SetByte0x2c5_020a2ca0(unsigned char* obj);
void ApplyVecFromField0x246_020a2718(char* actor);

// USA: func_020a2010
ARM void InitCombatController020a2010(void* objIn) {
    char* obj = (char*)objIn;

    ResetState020a2cf0((struct Struct020A2CF0*)objIn);
    SetBitsInField0_0202e08c((unsigned int*)objIn, 4);

    *(int*)(obj + 0x220) = 0;
    *(int*)(obj + 0x224) = 0x6000;
    *(int*)(obj + 0x228) = 0xb000;
    *(short*)(obj + 0x21c) = -1;
    *(int*)(obj + 0x22c) = 0;
    *(int*)(obj + 0x230) = 0;
    *(int*)(obj + 0x234) = 0;
    *(int*)(obj + 0x238) = 1;
    *(int*)(obj + 0x23c) = 1;
    *(int*)(obj + 0x240) = 1;
    obj[0x244] = 0;
    obj[0x245] = 0;
    *(short*)(obj + 0x246) = 0;

    Clear0x28Bytes_020a0d58(obj + 0x248);

    obj[0x270] = (char)0xff;
    *(int*)(obj + 0x274) = 0;
    *(int*)(obj + 0x278) = 0;
    *(int*)(obj + 0x27c) = 0;
    *(int*)(obj + 0x280) = 0;
    *(int*)(obj + 0x284) = 0;
    *(int*)(obj + 0x288) = 0;
    *(int*)(obj + 0x28c) = 0;
    *(int*)(obj + 0x290) = 0;
    *(int*)(obj + 0x294) = 0;

    memset(obj + 0x298, 0, 0x2c);

    *(short*)(obj + 0x21e) = 0;

    ResetFields0x2c4SetByte0x2c5_020a2ca0((unsigned char*)obj);
    ApplyVecFromField0x246_020a2718(obj);
}
