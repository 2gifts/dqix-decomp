#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x7e8
#define REGION_OFFSET_1 0x7bc
#define REGION_OFFSET_2 0x768
#define REGION_OFFSET_3 0x76c
#define REGION_OFFSET_4 0x778
#define REGION_OFFSET_5 0x7e4
#define REGION_OFFSET_6 0x31c
#define REGION_OFFSET_7 0x3400
#else
#define REGION_OFFSET_0 0x5f8
#define REGION_OFFSET_1 0x5cc
#define REGION_OFFSET_2 0x574
#define REGION_OFFSET_3 0x578
#define REGION_OFFSET_4 0x588
#define REGION_OFFSET_5 0x5f4
#define REGION_OFFSET_6 0x760
#define REGION_OFFSET_7 0x3000
#endif


void ApplyFieldGroups021742c8(void* obj);
void HandleFieldFlagsAndState021870c0(void* obj);
struct Obj021d8c94;
void CallIfFieldNot0Or3_021d8c94(struct Obj021d8c94* obj);
void CallDispatchIfFlagSet_021eb4f4(char* obj);
extern "C" void func_ov013_02184aec(void* obj);

// USA: func_ov000_02160ad0  (semantic: HandleFieldStateOnLoad02160ad0)
extern "C" ARM void func_ov000_02160ad0(char* obj) {
    if (*(int*)(obj + 0x5000 + REGION_OFFSET_0) == 0) return;
    if (*(void**)(obj + 0x5000 + REGION_OFFSET_1) != 0) {
        CallDispatchIfFlagSet_021eb4f4(*(char**)(obj + 0x5000 + REGION_OFFSET_1));
    }
    if (*(void**)(obj + 0x5000 + REGION_OFFSET_2) != 0) {
        func_ov013_02184aec(*(void**)(obj + 0x5000 + REGION_OFFSET_2));
        if (*(void**)(obj + 0x5000 + REGION_OFFSET_3) == 0) return;
        HandleFieldFlagsAndState021870c0(*(void**)(obj + 0x5000 + REGION_OFFSET_3));
        return;
    }
    if (*(struct Obj021d8c94**)(obj + 0x5000 + REGION_OFFSET_4) != 0) {
        CallIfFieldNot0Or3_021d8c94(*(struct Obj021d8c94**)(obj + 0x5000 + REGION_OFFSET_4));
        return;
    }
    if (*(int*)(obj + 0x5000 + REGION_OFFSET_5) & 0x40000) return;
    ApplyFieldGroups021742c8(obj + REGION_OFFSET_6 + REGION_OFFSET_7);
}
