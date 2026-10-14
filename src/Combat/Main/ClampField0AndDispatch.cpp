#include <globaldefs.h>
#include "Graphics/NSBXX/NSBXX.h"
#include "Graphics/NSBXX/Animation.h"

void CalculateBoneMatrixRenderDataFromJAC(NSBXXAnimationJAC* jac, int arg, fix32_t time, BoneMatrixRenderData* bmrd);

// USA: func_020b78bc
ARM void JACAnimationProcessingCallback(void* a0, AnimationData* args, int a2) {
    NSBXXAnimationJAC* target = (NSBXXAnimationJAC*)args->pRawData_;
    fix32_t value = args->time_;
    int limit = target->numFrames_ << 12;
    if (value >= limit) {
        value = limit - 1;
    } else if (value < 0) {
        value = 0;
    }
    CalculateBoneMatrixRenderDataFromJAC(target, a2, value, (BoneMatrixRenderData*)a0);
}
