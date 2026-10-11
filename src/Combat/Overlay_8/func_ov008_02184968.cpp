#include <globaldefs.h>

#if defined(jpn)
#define func_ov008_02184968 func_ov008_02185a64
#endif
#include "std_library_functions.h"

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
extern "C" void func_ov008_02187278(void* obj, char* dst, int mode, void* extra);
extern "C" void func_0204b088(void* p, int flag);
void CallDispatchIfFlagSet_021eb4f4(char* obj);
struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);
struct Obj021873ac;
void UpdateElementBuffer_021873ac(struct Obj021873ac* obj, int modeArg);

struct Obj02184968 {
    char pad0[0xb8];
    char* bufPtr;
    char pad1[0xb08 - 0xbc];
    char* b08;
    char pad2[0xb10 - 0xb0c];
    signed char b10;
    char pad3[0xb18 - 0xb11];
    int b18;
    char pad4[0xb24 - 0xb1c];
    int b24;
};

// USA: func_ov008_02184968
extern "C" ARM void func_ov008_02184968(struct Obj02184968* obj) {
    if (obj->b10 == 0 || obj->b10 == 1 || obj->b10 == 0xe) return;

    if (obj->b24 == 0) {
        func_0204b088((char*)obj + 0xd0, 0);
    }
    if (obj->b08 != 0) {
        CallDispatchIfFlagSet_021eb4f4(obj->b08);
        return;
    }

    if (obj->b18 & 0x800) {
        memset(obj->bufPtr, 0, 0x960);
        func_ov008_02187278(obj, obj->bufPtr, 0, 0);
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x130), 1, (int)obj->bufPtr, 1, 0);
        obj->b18 &= ~0x800;
    }

    UpdateElementBuffer_021873ac((struct Obj021873ac*)obj, 1);
    InitEntries0205d2bc((struct Obj0205d2bc*)((char*)obj + 0x130));
}
