#include <globaldefs.h>
#include "Graphics/NSBXX/NSBXX.h"
#include "Graphics/NSBXX/Animation.h"
#include "Graphics/NSBXX/RenderCommands_Common.h"

bool GetMatrixFromIndex(Matrix3x3*, intptr_t, intptr_t, int);

static inline void CalculateThirdRowByCrossProduct(Matrix3x3* mat)
{
    fix32_t m23 = mat->entries[5];
    fix32_t m11 = mat->entries[0];
    fix32_t m21 = mat->entries[3];
    fix32_t m13 = mat->entries[2];
    fix32_t m12 = mat->entries[1];
    fix32_t m22 = mat->entries[4];

    mat->entries[6] = (m12 * m23 - m13 * m22) >> 12;
    mat->entries[7] = (m13 * m21 - m11 * m23) >> 12;
    mat->entries[8] = (m11 * m22 - m12 * m21) >> 12;
}

// USA: func_020b8598
ARM void CalculateRotationFrameAligned(Matrix3x3* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac)
{
    unsigned int flags = channel->metadata_;
    unsigned int frameIdx = time >> 12;
    unsigned int averageIdx;

    unsigned int basisOffset;
    unsigned int pivotOffset = jac->pivotDataOffset_;
    basisOffset = jac->basisMatricesOffset_;
    uint16_t* samples = (uint16_t*)((intptr_t)jac + channel->samplesOffset_);

    if ((flags & 0xc0000000) == 0)
        goto calculate_exact_frame;

{
    unsigned int endFrame = (flags & 0x1fff0000) >> 16;
    if (flags & 0x40000000)
    {
        if (frameIdx & 1)
        {
            if (frameIdx > endFrame)
            {
                frameIdx = (endFrame / 2) + 1;
                goto calculate_exact_frame;
            }
            else
            {
                averageIdx = (frameIdx / 2);
                goto calculate_by_average;
            }
        }
        else
        {
            frameIdx = frameIdx / 2;
            goto calculate_exact_frame;
        }
    }
    else
    {
        unsigned int mod4 = frameIdx & 3;
        if (mod4 != 0)
        {
            if (frameIdx > endFrame)
            {
                frameIdx = mod4 + (endFrame / 4);
                goto calculate_exact_frame;
            }
            else if (frameIdx & 1)
            {
                unsigned int lowWeightFrame;
                unsigned int highWeightFrame;
                int anyBasisMatrix = 0;
                if (frameIdx & 2)
                {
                    lowWeightFrame = frameIdx / 4;
                    highWeightFrame = lowWeightFrame + 1;
                }
                else
                {
                    highWeightFrame = frameIdx / 4;
                    lowWeightFrame = highWeightFrame + 1;
                }

                anyBasisMatrix |= GetMatrixFromIndex(out, (intptr_t)jac + pivotOffset,
                    (intptr_t)jac + basisOffset, samples[highWeightFrame]);
                Matrix3x3 tempMatrix;
                anyBasisMatrix |= GetMatrixFromIndex(&tempMatrix, (intptr_t)jac + pivotOffset,
                    (intptr_t)jac + basisOffset, samples[lowWeightFrame]);

                out->entries[0] = tempMatrix.entries[0] + out->entries[0] * 3;
                out->entries[1] = tempMatrix.entries[1] + out->entries[1] * 3;
                out->entries[2] = tempMatrix.entries[2] + out->entries[2] * 3;
                out->entries[3] = tempMatrix.entries[3] + out->entries[3] * 3;
                out->entries[4] = tempMatrix.entries[4] + out->entries[4] * 3;
                out->entries[5] = tempMatrix.entries[5] + out->entries[5] * 3;
                Vector3fix_Normalize(&out->rows[0], &out->rows[0]);
                Vector3fix_Normalize(&out->rows[1], &out->rows[1]);
                if (!anyBasisMatrix)
                {
                    out->entries[6] = tempMatrix.entries[6] + out->entries[6] * 3;
                    out->entries[7] = tempMatrix.entries[7] + out->entries[7] * 3;
                    out->entries[8] = tempMatrix.entries[8] + out->entries[8] * 3;
                    Vector3fix_Normalize(&out->rows[2], &out->rows[2]);
                }
                else
                    CalculateThirdRowByCrossProduct(out);
                return;
            }
            else
            {
                averageIdx = frameIdx / 4;
                goto calculate_by_average;
            }
        }
        else
        {
            frameIdx = frameIdx / 4;
            goto calculate_exact_frame;
        }
    }
}

calculate_by_average:
{
    Matrix3x3 tempMatrix;
    int anyBasisMatrix = 0;
    anyBasisMatrix |= GetMatrixFromIndex(out, (intptr_t)jac + pivotOffset,
        (intptr_t)jac + basisOffset, (samples + averageIdx)[0]);
    anyBasisMatrix |= GetMatrixFromIndex(&tempMatrix, (intptr_t)jac + pivotOffset,
        (intptr_t)jac + basisOffset, (samples + averageIdx)[1]);

    out->entries[0] += tempMatrix.entries[0];
    out->entries[1] += tempMatrix.entries[1];
    out->entries[2] += tempMatrix.entries[2];
    out->entries[3] += tempMatrix.entries[3];
    out->entries[4] += tempMatrix.entries[4];
    out->entries[5] += tempMatrix.entries[5];
    Vector3fix_Normalize(&out->rows[0], &out->rows[0]);
    Vector3fix_Normalize(&out->rows[1], &out->rows[1]);

    if (!anyBasisMatrix)
    {
        out->entries[6] += tempMatrix.entries[6];
        out->entries[7] += tempMatrix.entries[7];
        out->entries[8] += tempMatrix.entries[8];
        Vector3fix_Normalize(&out->rows[2], &out->rows[2]);
    }
    else
        CalculateThirdRowByCrossProduct(out);

    return;
}
calculate_exact_frame:
{
    bool isBasis = GetMatrixFromIndex(out, (intptr_t)jac + pivotOffset,
        (intptr_t)jac + basisOffset, samples[frameIdx]);
    if (isBasis)
        CalculateThirdRowByCrossProduct(out);
    else
        Vector3fix_Normalize(&out->rows[2], &out->rows[2]);
}
}
