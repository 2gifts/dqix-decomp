#include <globaldefs.h>
#include "Graphics/NSBXX/NSBXX.h"
#include "Graphics/NSBXX/Animation.h"
#include "Graphics/NSBXX/RenderCommands_Common.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020b8404
ARM void CalculateScalingAmountSmooth(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac)
{
    NSBXXAnimationJAC::ScaleSample32* samples = (NSBXXAnimationJAC::ScaleSample32*)((intptr_t)jac + channel->samplesOffset_);
    NSBXXAnimationJAC::ScaleSample16* samples16 = (NSBXXAnimationJAC::ScaleSample16*)samples;
    unsigned int flags = channel->metadata_;
    unsigned int frameIdx = time >> 12;
    unsigned int lerpEndIdx;

    int preMultiply;
    int rightShift;

    if (jac->numFrames_ - 1 == frameIdx)
    {
        if (flags & 0xc0000000)
        {
            if (flags & 0x40000000)
            {
                frameIdx = (frameIdx & 1) + (frameIdx >> 1);
            }
            else
            {
                frameIdx = (frameIdx & 3) + (frameIdx >> 2);
            }
        }

        if (jac->unk_8 & 2)
        {
            lerpEndIdx = 0;
        }
        else
        {
            if (flags & 0x20000000)
            {
                out[0] = samples16[frameIdx].primary_;
                out[1] = samples16[frameIdx].secondary_;
            }
            else
            {
                out[0] = samples[frameIdx].primary_;
                out[1] = samples[frameIdx].secondary_;
            }
            return;
        }
    }
    else if ((flags & 0xc0000000) != 0)
    {
        unsigned int endFrame = (flags & 0x1fff0000) >> 0x10;
        if (flags & 0x40000000)
        {
            if (frameIdx >= endFrame)
            {
                frameIdx = endFrame / 2;
                lerpEndIdx = frameIdx + 1;
            }
            else
            {
                frameIdx = frameIdx / 2;
                lerpEndIdx = frameIdx + 1;
                time &= 0x1fff;
                preMultiply = 2;
                rightShift = 1;
                goto skip_default_values;
            }
        }
        else
        {
            if (frameIdx >= endFrame)
            {
                frameIdx = (frameIdx & 3) + (frameIdx / 4);
                lerpEndIdx = frameIdx + 1;
            }
            else
            {
                frameIdx = frameIdx / 4;
                lerpEndIdx = frameIdx + 1;
                time &= 0x3fff;
                preMultiply = 4;
                rightShift = 2;
                goto skip_default_values;
            }
        }
    }
    else
        lerpEndIdx = frameIdx + 1;

    time &= 0xfff;
    preMultiply = 1;
    rightShift = 0;
skip_default_values:
    fix32_t primaryLerp0;
    fix32_t primaryLerp1;
    fix32_t secondaryLerp0;
    fix32_t secondaryLerp1;
    if (flags & 0x20000000)
    {
        primaryLerp0 = samples16[frameIdx].primary_;
        secondaryLerp0 = samples16[frameIdx].secondary_;
        primaryLerp1 = samples16[lerpEndIdx].primary_;
        secondaryLerp1 = samples16[lerpEndIdx].secondary_;
    }
    else
    {
        primaryLerp0 = samples[frameIdx].primary_;
        secondaryLerp0 = samples[frameIdx].secondary_;
        primaryLerp1 = samples[lerpEndIdx].primary_;
        secondaryLerp1 = samples[lerpEndIdx].secondary_;
    }

    out[0] = (primaryLerp0 * preMultiply + ((time * (primaryLerp1 - primaryLerp0)) >> 12)) >> rightShift;
    out[1] = (secondaryLerp0 * preMultiply + ((time * (secondaryLerp1 - secondaryLerp0)) >> 12)) >> rightShift;
}
