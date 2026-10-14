#include <globaldefs.h>

struct DispatchTarget020b78bc {
    char pad0[4];
    unsigned short field4;
};

struct DispatchArgs020b78bc {
    int field0;
    int pad4;
    struct DispatchTarget020b78bc* field8;
};

struct BoneMatrixRenderData;
struct NSBXXAnimationJAC;
void CalculateBoneMatrixRenderDataFromJAC(NSBXXAnimationJAC*, int, int, BoneMatrixRenderData*);

// USA: func_020b78bc
extern "C" ARM void _Z30JACAnimationProcessingCallbackPvP13AnimationDatai(int a0, struct DispatchArgs020b78bc* args, int a2) {
    struct DispatchTarget020b78bc* target = args->field8;
    int value = args->field0;
    int limit = target->field4 << 12;
    if (value >= limit) {
        value = limit - 1;
    } else if (value < 0) {
        value = 0;
    }
    CalculateBoneMatrixRenderDataFromJAC((NSBXXAnimationJAC*)target, a2, value, (BoneMatrixRenderData*)a0);
}
