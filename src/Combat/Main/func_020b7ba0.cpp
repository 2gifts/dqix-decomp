#include "Graphics/NSBXX/NSBXX.h"
#include "Graphics/NSBXX/Animation.h"
#include "Graphics/NSBXX/RenderCommands_Common.h"

void ApplyBindPoseTranslation(BoneMatrixRenderData* bmrd);
void ApplyBindPoseScaling(BoneMatrixRenderData* bmrd);
void ApplyBindPoseRotation(BoneMatrixRenderData* bmrd);

void CalculateTranslationAmountFrameAligned(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);
void CalculateTranslationAmountSmooth(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);

void CalculateScalingAmountFrameAligned(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);
void CalculateScalingAmountSmooth(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);

void CalculateRotationFrameAligned(Matrix3x3* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);
void CalculateRotationSmooth(Matrix3x3* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);
bool GetMatrixFromIndex(Matrix3x3* out, intptr_t pivotList, intptr_t basisList, int index);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020b7ba0
void CalculateBoneMatrixRenderDataFromJAC(NSBXXAnimationJAC* jac, int arg, fix32_t time, BoneMatrixRenderData* bmrd)
{
    NSBXXAnimationJAC::Track* track = (NSBXXAnimationJAC::Track*)((intptr_t)jac + jac->trackOffsets_[arg]);

    NSBXXBoneMatrix::Scaling scaleData;

    unsigned int trackFlags = track->flagsAndTargetBoneMatrix_;

    if (trackFlags & 1) // track has no channels at all
        bmrd->flags_ = 7;
    else
    {
        intptr_t channelAddr = (intptr_t)(track + 1);
        bool smooth;
        if ((time & 0xfff) != 0 && (jac->unk_8 & 1))
            smooth = true;
        else
            smooth = false;

        bmrd->flags_ = 0;

        if (!(trackFlags & 6)) // has translation channels (check both bits)
        {
            if (!(trackFlags & 0x08)) // x translation non-const
            {
                if (smooth)
                    CalculateTranslationAmountSmooth(&bmrd->translate_.x, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                else
                    CalculateTranslationAmountFrameAligned(&bmrd->translate_.x, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                channelAddr += sizeof(NSBXXAnimationJAC::Track::ChannelNonConst);
            }
            else // x-translation constant
            {
                bmrd->translate_.x = *(fix32_t*)(channelAddr);
                channelAddr += sizeof(fix32_t);
            }

            if (!(trackFlags & 0x10)) // y-translation non-const
            {
                if (smooth)
                    CalculateTranslationAmountSmooth(&bmrd->translate_.y, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                else
                    CalculateTranslationAmountFrameAligned(&bmrd->translate_.y, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                channelAddr += sizeof(NSBXXAnimationJAC::Track::ChannelNonConst);
            }
            else // y-translation constant
            {
                bmrd->translate_.y = *(fix32_t*)(channelAddr);
                channelAddr += sizeof(fix32_t);
            }

            if (!(trackFlags & 0x20)) // z-translation non-const
            {
                if (smooth)
                    CalculateTranslationAmountSmooth(&bmrd->translate_.z, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                else
                    CalculateTranslationAmountFrameAligned(&bmrd->translate_.z, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                channelAddr += sizeof(NSBXXAnimationJAC::Track::ChannelNonConst);
            }
            else // z-translation constant
            {
                bmrd->translate_.z = *(fix32_t*)(channelAddr);
                channelAddr += sizeof(fix32_t);
            }
        }
        else if (trackFlags & 2)
        {
            bmrd->flags_ |= 4;
        }
        else
        {
            ApplyBindPoseTranslation(bmrd);
        }

        if (!(trackFlags & 0xc0))
        {
            if (!(trackFlags & 0x100))
            {
                if (smooth)
                    CalculateRotationSmooth(&bmrd->rotationMatrix_, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                else
                    CalculateRotationFrameAligned(&bmrd->rotationMatrix_, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                channelAddr += sizeof(NSBXXAnimationJAC::Track::ChannelNonConst);
            }
            else // rotation channel constant
            {
                if (GetMatrixFromIndex(&bmrd->rotationMatrix_, (intptr_t)jac->GetPivotMatrices(), (intptr_t)jac->GetBasisMatrices(), *(uint32_t*)(channelAddr)))
                {
                    fix32_t m23 = bmrd->rotationMatrix_.entries[5]; // yes, this order is actually important
                    fix32_t m11 = bmrd->rotationMatrix_.entries[0];
                    fix32_t m21 = bmrd->rotationMatrix_.entries[3];
                    fix32_t m13 = bmrd->rotationMatrix_.entries[2];
                    fix32_t m12 = bmrd->rotationMatrix_.entries[1];
                    fix32_t m22 = bmrd->rotationMatrix_.entries[4];

                    fix32_t m31 = (m12 * m23 - m13 * m22) >> 12;
                    fix32_t m32 = (m13 * m21 - m11 * m23) >> 12;
                    fix32_t m33 = (m11 * m22 - m12 * m21) >> 12;
                    bmrd->rotationMatrix_.entries[6] = m31;
                    bmrd->rotationMatrix_.entries[7] = m32;
                    bmrd->rotationMatrix_.entries[8] = m33;
                }
                channelAddr += sizeof(uint32_t);
            }
        }
        else if (trackFlags & 0x40)
        {
            bmrd->flags_ |= 2;
        }
        else
        {
            ApplyBindPoseRotation(bmrd);
        }

        if (!(trackFlags & 0x600)) // has scaling channels (check both bits)
        {
            // Note scale channels are 8 bytes whether constant or not
            if (!(trackFlags & 0x800)) // x-scaling non-const
            {
                fix32_t xscales[2];
                if (smooth)
                    CalculateScalingAmountSmooth(xscales, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                else
                    CalculateScalingAmountFrameAligned(xscales, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                scaleData.x = xscales[0];
                scaleData.x_v2 = xscales[1];
            }
            else
            {
                scaleData.x = *(fix32_t*)channelAddr;
                scaleData.x_v2 = *(fix32_t*)(channelAddr + 4);
            }
            channelAddr += 8;

            if (!(trackFlags & 0x1000)) // y-scaling non-const
            {
                fix32_t yscales[2];
                if (smooth)
                    CalculateScalingAmountSmooth(yscales, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                else
                    CalculateScalingAmountFrameAligned(yscales, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                scaleData.y = yscales[0];
                scaleData.y_v2 = yscales[1];
            }
            else
            {
                scaleData.y = *(fix32_t*)(channelAddr);
                scaleData.y_v2 = *(fix32_t*)(channelAddr + 4);
            }
            channelAddr += 8;

            if (!(trackFlags & 0x2000)) // z-scaling non-const
            {
                fix32_t zscales[2];
                if (smooth)
                    CalculateScalingAmountSmooth(zscales, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                else
                    CalculateScalingAmountFrameAligned(zscales, time, (NSBXXAnimationJAC::Track::ChannelNonConst*)channelAddr, jac);
                scaleData.z = zscales[0];
                scaleData.z_v2 = zscales[1];
            }
            else
            {
                scaleData.z = *(fix32_t*)(channelAddr);
                scaleData.z_v2 = *(fix32_t*)(channelAddr + 4);
            }
        }
        else if (trackFlags & 0x200)
        {
            bmrd->flags_ |= 1;
        }
        else
        {
            ApplyBindPoseScaling(bmrd);
            return;
        }
    }

    int boneMatrixFlags = (bmrd->flags_ & 1) ? 4 : 0;
    data_0210a274->boneMatrixRenderDataScalePopulateProc_(bmrd, &scaleData, data_0210a274->instructionPointer_, boneMatrixFlags);
}
