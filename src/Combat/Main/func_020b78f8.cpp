#include "Graphics/NSBXX/NSBXX.h"
#include "Graphics/NSBXX/Animation.h"
#include "Graphics/NSBXX/RenderCommands_Common.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020b78f8
void ApplyBindPoseTranslation(BoneMatrixRenderData* bmrd)
{
    RenderCommandHandler* handler = data_0210a274;
    NSBXXBoneMatrix* boneMatrix = handler->boneList_->GetEntryFromu32Offset_v2<NSBXXBoneMatrix>(handler->instructionPointer_[1]);
    if (boneMatrix->flags_ & 1)
    {
        bmrd->flags_ |= 4;
    }
    else
    {
        NSBXXBoneMatrix::Translation* tdata = (NSBXXBoneMatrix::Translation*)((intptr_t)boneMatrix + 4);
        bmrd->translate_.x = tdata->x;
        bmrd->translate_.y = tdata->y;
        bmrd->translate_.z = tdata->z;
    }
}
