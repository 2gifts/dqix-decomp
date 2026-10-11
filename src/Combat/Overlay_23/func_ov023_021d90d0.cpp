#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"


struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);

void InitBoxLayout_021d921c(void* obj, int unused, int w, int h);

extern "C" void func_ov023_021d94e4(void* obj, void* buf, unsigned char step);

struct Struct_0205d81c;
struct Elem_0205d81c;
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);

struct StructA0205d5d0;
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d);
#else
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif


// JPN: func_ov023_021d998c
// USA: func_ov023_021d90d0  (semantic: AdvanceBoxLayoutState_021d90d0)
extern "C" ARM int func_ov023_021d90d0(char* obj) {
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
        *(unsigned char*)(obj + 0x118) = 0;
        *(unsigned char*)(obj + 0x11d) = 5;
        memset(*(void**)(obj + 0x4), 0, regionalOffset0);
        func_ov023_021d94e4(obj, *(void**)(obj + 4), *(unsigned char*)(obj + 0x118));
        InitBoxLayout_021d921c(obj, *(int*)(obj + 4), 0x1a, 0x14);
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
    memset(*(void**)(obj + 0x4), 0, regionalOffset0);
    func_ov023_021d94e4(obj, *(void**)(obj + 4), *(unsigned char*)(obj + 0x118));

#if defined(jpn)
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)(obj + 0x20), 0, *(int*)(obj + 4), 1);


#else
    unsigned char* elem = (unsigned char*)FindElementByC40205d81c((struct Struct_0205d81c*)(obj + 0x20), 0);
    if (elem != NULL) {
        elem[0xd8] |= 4;
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)(obj + 0x20), 0, *(int*)(obj + 4), 1, 0);
        elem[0xd8] &= ~4;
    }


#endif
    if (*(unsigned char*)(obj + 0x118) == 9) {
        int next = *(unsigned char*)(obj + 0x11c) + 1;
        *(unsigned char*)(obj + 0x11c) = (unsigned char)next;
        return next;
    }
    return *(unsigned char*)(obj + 0x118);
}
