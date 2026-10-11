#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"


struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);

void InitBoxLayout_021d921c(void* obj, int unused, int w, int h);

extern "C" void func_ov023_021d9290(void* obj, void* buf, unsigned char step);

struct StructA0205d5d0;
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d);
#else
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif


// JPN: func_ov023_021d97ec
// USA: func_ov023_021d8f2c  (semantic: AdvanceScaleBoxState_021d8f2c)
extern "C" ARM int func_ov023_021d8f2c(char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x800};
#else
 enum {regionalOffset0=0x960};
#endif
    int count = GameState::GetInstance()->GetTickCount();
    if (count == 0) count = 1;
    unsigned char step = *(unsigned char*)(obj + 0x11c);

    if (step == 0) {
        ResetEntryList0205d6a0((struct Entry_0205d6a0*)(obj + 0x20), 1);
        int next = *(unsigned char*)(obj + 0x11c) + 1;
        *(unsigned char*)(obj + 0x11c) = (unsigned char)next;
        return next;
    }
    if (step == 1) {
        *(unsigned char*)(obj + 0x118) = 1;
        *(unsigned char*)(obj + 0x11d) = 5;
        *(unsigned char*)(obj + 0x119) = 0;
        unsigned char* counter = (unsigned char*)(obj + 0x119);
        int i;
        for (i = 0; i < 4; i++) {
            if (*(int*)(obj + i * 4 + 0xdc) != 0) {
                *counter = *counter + 1;
            }
        }
        int mode = 0xc;
        switch (*(unsigned char*)(obj + 0x119)) {
            case 1:
                mode = 5;
                break;
            case 2:
                mode = 7;
                break;
            case 3:
                mode = 0xa;
                break;
            case 4:
                mode = 0xc;
                break;
            case 0:
                *(unsigned char*)(obj + 0x118) = 4;
                mode = 5;
                break;
        }
        memset(*(void**)(obj + 4), 0, regionalOffset0);
        func_ov023_021d9290(obj, *(void**)(obj + 4), *(unsigned char*)(obj + 0x118));
        InitBoxLayout_021d921c(obj, *(int*)(obj + 4), 0x18, mode);
        int next = *(unsigned char*)(obj + 0x11c) + 1;
        *(unsigned char*)(obj + 0x11c) = (unsigned char)next;
        return next;
    }
    if (step != 2) return count;

    signed char v = *(signed char*)(obj + 0x11d);
    if (v > 0) {
        int result = v - (signed char)count;
        *(unsigned char*)(obj + 0x11d) = (unsigned char)result;
        return result;
    }

    *(unsigned char*)(obj + 0x11d) = 5;
    *(unsigned char*)(obj + 0x118) = *(unsigned char*)(obj + 0x118) + 1;
    memset(*(void**)(obj + 4), 0, regionalOffset0);
    func_ov023_021d9290(obj, *(void**)(obj + 4), *(unsigned char*)(obj + 0x118));
#if defined(jpn)
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)(obj + 0x20), 0, *(int*)(obj + 4), 1);
#else
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)(obj + 0x20), 0, *(int*)(obj + 4), 1, 0);
#endif


    if (*(unsigned char*)(obj + 0x118) == 4) {
        int next = *(unsigned char*)(obj + 0x11c) + 1;
        *(unsigned char*)(obj + 0x11c) = (unsigned char)next;
        return next;
    }
    return *(unsigned char*)(obj + 0x118);
}
