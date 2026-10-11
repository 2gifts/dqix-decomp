#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { countOffset = 0x9f4, flagOffset = 0x9fd, flagBase = 0x1900, recordStride = 0x1e4 };
#else
enum { countOffset = 0x8f4, flagOffset = 0x8fd, flagBase = 0x1800, recordStride = 0x1c4 };
#endif

int GetWord0x0(int* obj);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(int* obj);
extern char* data_ov004_02171010;
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" unsigned int func_ov023_021f6f10(void* self);
#define NODE_KIND_CALL func_ov023_021f6f10
#else
int ScaleStatsIfType12_021f6f10(void* self);
#define NODE_KIND_CALL ScaleStatsIfType12_021f6f10
#endif
struct Obj021f9bb0;
unsigned int GetShort28_021f9bb0(struct Obj021f9bb0* obj);
extern "C" void func_ov004_021636b0(void* a1, void* a2);

// USA: func_ov004_0216556c
ARM int CheckAndDispatchByShort28_0216556c(void* a1) {
    if (*(unsigned char*)(data_ov004_02171010 + 0x1000 + countOffset) == 0) return 0;
    if (_Z28IsBrightnessTransitionActiveP13GameResources((int*)GetWord0x0((int*)GameState::GetInstance())) != 0) return 0;

    {
        char* base = data_ov004_02171010;
        unsigned char b = *(unsigned char*)(base + 0x1000 + flagOffset);
        unsigned char* target = (unsigned char*)(base + 0xfd + flagBase);
        if (b != 0) {
            *target = 0;
            return 0;
        }
    }

    void* obj = func_ov023_021f6880(func_ov011_021849c8(a1), 0xa);
    if (obj == NULL) return 0;
    if (NODE_KIND_CALL(obj) != 7) return 0;

    unsigned int idx = GetShort28_021f9bb0((struct Obj021f9bb0*)obj);
    void* ptr = (void*)(idx * recordStride + (data_ov004_02171010 + 1 + 0xb00));
    func_ov004_021636b0(a1, ptr);
    return 0;
}
