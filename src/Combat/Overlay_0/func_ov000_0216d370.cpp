#include <globaldefs.h>
#include "std_library_functions.h"

struct Flags0202ecfc;
void ClearFlag0x1At0x168(struct Flags0202ecfc* p);
void SetField0x7cClearFields0x1ec0x1ee_0202e874(unsigned char* obj, unsigned short val);
struct AngleTrig0202e9a4;
void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4* obj, int angle);
void ClearFields0x20e0x210_0202e948(unsigned char* obj);
struct HalfwordTriple0202e98c;
void ClearThreeHalfwords(struct HalfwordTriple0202e98c* p);
void* CallFunc020a0d58AtField0x16c_0202ee84(char* obj);
void* CallFunc020a0d58AtField0x194_0202ee94(void* obj);
void* CallFunc020a0d58AtField0x1bc_0202eea4(void* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Vec3_0216d370 { int x, y, z; };

// USA: func_ov000_0216d370  (semantic: ResetCombatFields_0216d370)
extern "C" ARM void func_ov000_0216d370(char* obj, int flagA, int flagB, int flagC) {
    *(unsigned char*)(obj + 0x220) = 0;
    if (*(int*)(obj + 0x224) >= 0) {
        struct Vec3_0216d370 tmp1 = *(struct Vec3_0216d370*)(obj + 0x12c);
        struct Vec3_0216d370 tmp2 = *(struct Vec3_0216d370*)(obj + 0x120);
        _ZN8Vector3iaSERKS_((int*)(obj + 0x10), (int*)&tmp1);
        _ZN8Vector3iaSERKS_((int*)(obj + 0x4), (int*)&tmp2);
    }

    *(int*)(obj + 0x224) = -1;
    *(int*)(obj + 0x238) = 0;
    *(int*)(obj + 0x23c) = 0;
    ClearFlag0x1At0x168((struct Flags0202ecfc*)obj);
    *(unsigned char*)(obj + 0x260) = 0;

    if (flagA) {
        SetField0x7cClearFields0x1ec0x1ee_0202e874((unsigned char*)obj, 0);
    }

    if (flagB) {
        SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)obj, 0xf000);
    }

    if (flagC) {
        ClearFields0x20e0x210_0202e948((unsigned char*)obj);
        ClearThreeHalfwords((struct HalfwordTriple0202e98c*)obj);
    }

    memset(obj + 0x264, 0, 0x14);
    CallFunc020a0d58AtField0x16c_0202ee84(obj);
    CallFunc020a0d58AtField0x194_0202ee94(obj);
    CallFunc020a0d58AtField0x1bc_0202eea4(obj);
}
