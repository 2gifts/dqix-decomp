#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0216d2d0 {
    char pad[0x21c];
    int field21c;
    unsigned char field220;
    unsigned char field221;
    char pad2[2];
    int field224;
    int field228;
    int field22c;
    int field230;
    int field234;
    int field238;
    int field23c;
    int field240;
    int field244;
    int field248;
    int field24c;
    int field250;
    int field254;
    int field258;
    int field25c;
    unsigned char field260[4];
    unsigned char field264[0x14];
    char pad3[0x278 - 0x278];
    unsigned char field278;
    char pad4[3];
    int field27c;
};

struct Struct020A2CF0;
void ResetState020a2cf0(Struct020A2CF0*);
void SetBitsInField0_0202e08c(unsigned int*, unsigned int);

// USA: func_ov000_0216d2d0  (semantic: ResetSlotState_0216d2d0)
extern "C" ARM void func_ov000_0216d2d0(struct Struct0216d2d0* obj) {
    ResetState020a2cf0((Struct020A2CF0*)obj);
    SetBitsInField0_0202e08c((unsigned int*)obj, 8);
    obj->field21c = 0;
    obj->field220 = 0;
    obj->field221 = 0;
    obj->field224 = -1;
    obj->field228 = 0x1000;
    obj->field22c = 0x1000;
    obj->field230 = 0x1000;
    obj->field234 = 0x1000;
    obj->field238 = 0;
    obj->field23c = 0;
    obj->field240 = 0;
    obj->field244 = 0;
    obj->field248 = 0;
    obj->field24c = 0;
    obj->field250 = 0;
    obj->field254 = 0;
    obj->field25c = 0;
    obj->field258 = 0;
    memset(obj->field260, 0, 4);
    memset(obj->field264, 0, 0x14);
    obj->field278 = 0;
    obj->field27c = 0;
}
