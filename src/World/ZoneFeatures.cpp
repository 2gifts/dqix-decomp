#include "World/ZoneWarpScript.h"
#include "World/ZoneFeatures.h"
#include "World/Zone3D.h"
#include "Resource/Script.h"
#include "GameState/GameState.h"
#include "System/Memory.h"

extern Script::OpcodeLookupEntry data_020ef388[];

extern "C"
{
    extern "C" void* _Z25GetPtrField0x468_02011584Pv(GameState*);
    void _ZN12ZoneFeatures13Opcode68Entry14Reset_0201ce10Ev(void*);

    Matrix4x3 _Z15RotationMatrixYi(fix32_t);

    fix32_t _Z22fix32ReduceAngle0To2Pii(fix32_t);

    extern "C" unsigned short* _Z25FindElementByName0209998cP12List0209998cPKc(void*, const char*);

}

int WarpScript_Opcode_64_0201c79c(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateOpcode64Entries_0201e25c(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

int WarpScript_Opcode_65_0201c7c4(Script::Parameter* params, int numParams)
{
    const char* string2;
    const char* string3;
    int arg0 = params[0].ToInt();
    Vector3fix argVector;
    Script::Parameter* post = params[1].ToVec3fix(&argVector);
    params = post + 1;
    const char* string1 = post->ToString();
    string2 = NULL;
    string3 = NULL;

    if (numParams >= 6)
    {
        string2 = params->ToString();
        params++;
    }
    if (numParams >= 7)
    {
        string3 = params->ToString();
        params++;
    }

    if (string1 == NULL)
        return 0;

    ZoneFeatures::Opcode64Entry entry;
    entry.unk_0 = arg0;
    entry.vector_4.vec = argVector;
    strcpy(entry.string_10, string1);
    if (string2 == NULL)
        entry.string_20[0] = '\0';
    else
        strcpy(entry.string_20, string2);
    if (string3 == NULL)
        entry.string_30[0] = '\0';
    else
        strcpy(entry.string_30, string3);

    data_020fdc20.warp->CreateOpcode64Entry_0201e304(entry);
    return 1;
}

int WarpScript_Opcode_7d_0201c8a8(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateGrottoTileFeaturePlacementEntries_0201e288(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

int WarpScript_Opcode_7e_0201c8d0(Script::Parameter* params, int numParams)
{
    TileFeaturePlacementData placement;
    placement.tileID = (params++)->ToInt();
    strcpy(placement.tilename, (params++)->ToString());

    for (int i = 0; i < 9; i++)
        placement.directionBitmasks[i] = (params++)->ToInt();

    data_020fdc20.warp->CreateGrottoTileFeaturePlacementEntry_0201e3c4(placement);
    return 1;
}

int WarpScript_Opcode_66_0201c944(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateOpcode66Entries_0201e480(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

int WarpScript_Opcode_68_0201cb38(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateOpcode68Entries_0201e518(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

void ZoneFeatures::Opcode68Entry::Reset_0201ce10()
{
    unk_0 = 0;
    unk_1c = -1;
    unk_50 = 0;
    unk_52 = 0;
    unk_54 = 0;
    unk_64[0] = 0;
    unk_64[1] = 0;
    unk_58[0] = 0;
    unk_58[1] = 0;
    unk_58[2] = 0;
    unk_20[0].x = 0;
    unk_20[0].y = 0;
    unk_20[0].z = 0;
    unk_20[1].x = 0;
    unk_20[1].y = 0;
    unk_20[1].z = 0;
    unk_20[2].x = 0;
    unk_20[2].y = 0;
    unk_20[2].z = 0;
    unk_20[3].x = 0;
    unk_20[3].y = 0;
    unk_20[3].z = 0;
    unk_6c = -1;
}

int WarpScript_Opcode_6a_0201d01c(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateOpcode6aEntries_0201e634(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

int WarpScript_Opcode_6b_0201d044(Script::Parameter* params, int numParams)
{
    Script::Parameter* paramsStart = params;
    ZoneFeatures::Opcode6aEntry entry;
    entry.Reset_0201d424();
    int hash = (params++)->ToInt();
    entry.maybeType = hash;
    bool didSubtraction = false;
    if (entry.maybeType >= 10)
    {
        entry.maybeType -= 10;
        didSubtraction = true;
    }

    Vector3fix tempVector;
    params = params->ToVec3fix(&tempVector);
    entry.unk_8.vec = tempVector;
    params = params->ToVec3fix(&tempVector);
    entry.unk_14.vec = tempVector;

    if (didSubtraction)
    {
        fix32_t angle = 4096.0f * (params++)->ToFloat();
        entry.unk_22 = _Z22fix32ReduceAngle0To2Pii(angle);
    }
    entry.unk_20 = 4096.0f * (params++)->ToFloat();

    fix32_t halfx = entry.unk_14.vec.x / 2;
    fix32_t halfz = entry.unk_14.vec.z / 2;
    fix32_t xsqu = FIX32_MULTIPLY(halfx, halfx);
    fix32_t zsqu = FIX32_MULTIPLY(halfz, halfz);
    entry.unk_24 = zsqu;
    entry.unk_24 = xsqu + zsqu;

    if (entry.maybeType == 2)
    {
        entry.unk_2c.type2.unk_0 = (params++)->ToInt();
        entry.unk_2c.type2.unk_1 = (params++)->ToInt();
        entry.unk_2c.type2.unk_2_high = (params++)->ToInt();
    }
    else if (entry.maybeType == 3)
    {
        entry.unk_2c.type3.unk_0 = (params++)->ToInt();
    }
    else if (entry.maybeType == 4)
    {
        int arg = (params++)->ToInt();
        entry.unk_2c.type4.unk_1 = -1;
        entry.unk_2c.type4.unk_0 = arg;
        entry.unk_2c.type4.unk_0_high = 0;
        switch (entry.unk_2c.type4.unk_0)
        {
        case 0:
            entry.unk_2c.type4.vector_4.vec3.vec.y = 4096.0f * (params++)->ToFloat();
            entry.unk_2c.type4.vector_4.vec3.vec.z = 4096.0f * (params++)->ToFloat();
            break;
        case 1:
            params = params->ToVec3fix(&tempVector);
            entry.unk_2c.type4.vector_4.vec3.vec = tempVector;
            break;
        case 2:
        case 3:
            params = params->ToVec3fix(&tempVector);
            entry.unk_2c.type4.vector_4.vec3.vec = tempVector;
            break;
        case 4:
        case 5:
        {
            Vector3fix vecB;
            Vector3fix vecA;
            params = params->ToVec3fix(&vecB);
            params = params->ToVec3fix(&vecA);
            MaybeVector4fix difference;
            Vector3fix_Subtract(&vecA, &vecB, &difference.vec3.vec);
            fix32_t distance = Vector3fix_Length(&difference.vec3.vec);
            Vector3fix_Normalize(&difference.vec3.vec, &difference.vec3.vec);
            difference.w = Vector3fix_InnerProduct(&difference.vec3.vec, &vecB);
            Vector3fix vecC  = { 0, 0, 0 };
            if (entry.unk_2c.type4.unk_0 == 4)
            {
                vecC.x = 4096.0f * (params++)->ToFloat();
            }
            vecC.y = 4096.0f * (params++)->ToFloat();
            vecC.z = 4096.0f * (params++)->ToFloat();
            Vector3fix vecD;
            params = params->ToVec3fix(&vecD);
            entry.unk_2c.type4.vector_4.CopyFrom_0201d474(difference);
            entry.unk_2c.type4.distance_14 = distance;
            entry.unk_2c.type4.vector_18 = vecC;
            entry.unk_2c.type4.vector_24 = vecD;
            break;
        }
        }
        entry.unk_2c.type4.vector_30.x = 0;
        entry.unk_2c.type4.vector_30.y = 0;
        entry.unk_2c.type4.vector_30.z = 0;
        if (numParams > 12)
        {
            params = params->ToVec3fix(&tempVector);
            entry.unk_2c.type4.vector_30 = tempVector;
        }
    }
    else if (entry.maybeType == 5)
    {
        entry.unk_2c.type5.unk_0 = (params++)->ToInt();
        entry.unk_2c.type5.unk_2 = (params++)->ToInt();
        entry.unk_2c.type5.unk_4 = 0;
    }

    ZoneFeatures* instance = data_020fdc20.warp;
    entry.pNext = NULL;
    instance->CreateOpcode6aEntry_0201e710(entry);
    return 1;
}

void ZoneFeatures::Opcode6aEntry::Reset_0201d424()
{
    VectorizedMemset(this, 0, sizeof(Opcode6aEntry));
    unk_0 = 0;
    maybeType = 0;
    unk_20 = 0;
    unk_22 = 0;
    unk_24 = 0;
    unk_8.vec.x = 0;
    unk_8.vec.y = 0;
    unk_8.vec.z = 0;
    unk_14.vec.x = 0;
    unk_14.vec.y = 0;
    unk_14.vec.z = 0;
    unk_28 = 0;
    pNext = NULL;
}

MaybeVector4fix &MaybeVector4fix::CopyFrom_0201d474(const MaybeVector4fix &other)
{
    vec3 = other.vec3;
    fix32_t sourceW = other.w;
    w = sourceW;
    return *this;
}

int WarpScript_Opcode_6e_0201d494(Script::Parameter* params, int numParams)
{
    Vector3fix tempVector;
    params = params->ToVec3fix(&tempVector);
    fix32_t angle = _Z22fix32ReduceAngle0To2Pii(4096.0f * (params++)->ToFloat());

    ZoneFeatures* warp = data_020fdc20.warp;
    warp->vector_70_ = tempVector;
    warp->angle_7c_ = angle;
    return 1;
}

int WarpScript_Opcode_70_0201d4ec(Script::Parameter* params, int numParams)
{
    int red = (params++)->ToInt();
    int green = (params++)->ToInt();
    int blue = (params++)->ToInt();
    data_020fdc20.warp->color_7e_ = red | (green << 5) | (blue << 10);
    return 1;
}

int WarpScript_Opcode_73_0201d530(Script::Parameter* params, int numParams)
{
    ZoneFeatures::Opcode6aEntry entry;
    entry.Reset_0201d424();
    entry.maybeType = (params++)->ToInt();
    Vector3fix tempVector;
    params = params->ToVec3fix(&tempVector);
    entry.unk_8.vec = tempVector;
    params = params->ToVec3fix(&tempVector);
    entry.unk_14.vec = tempVector;

    entry.unk_22 = _Z22fix32ReduceAngle0To2Pii(4096.0f * (params++)->ToFloat());
    entry.unk_20 = 4096.0f * (params++)->ToFloat();

    fix32_t halfx = entry.unk_14.vec.x / 2;
    fix32_t halfz = entry.unk_14.vec.z / 2;
    fix32_t xsqu = FIX32_MULTIPLY(halfx, halfx);
    fix32_t zsqu = FIX32_MULTIPLY(halfz, halfz);
    entry.unk_24 = zsqu;
    entry.unk_24 = xsqu + zsqu;

    data_020fdc20.currentEntry = data_020fdc20.warp->CreateOpcode6aEntry_0201e710(entry);
    return 1;
}

int WarpScript_Opcode_74_0201d638(Script::Parameter* params, int numParams)
{
    if (data_020fdc20.currentEntry == NULL)
        return 0;
    void* worldData = _Z25GetPtrField0x468_02011584Pv(GameState::GetInstance());
    switch (data_020fdc20.currentEntry->maybeType)
    {
    case 0:
        data_020fdc20.currentEntry->unk_2c.type0.unk_0 = 0;
        if (numParams != 0)
            data_020fdc20.currentEntry->unk_0 = params->ToInt();
        break;
    case 6:
        data_020fdc20.currentEntry->maybeType = 0;
        data_020fdc20.currentEntry->unk_2c.type0.unk_0 = 1;
        if (numParams != 0)
            data_020fdc20.currentEntry->unk_0 = params->ToInt();
        break;
    case 1:
        if (numParams != 0)
            data_020fdc20.currentEntry->unk_0 = params->ToInt();
        break;
    case 2:
        if (numParams == 3)
        {
            data_020fdc20.currentEntry->unk_2c.type2.unk_0 = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type2.unk_1 = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type2.unk_2_high = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type2.unk_2_low = 0;
        }
        else
        {
            int numArgsConsumed = 0;
            data_020fdc20.currentEntry->unk_2c.type2.unk_0 = (params++)->ToInt();
            numArgsConsumed++;
            data_020fdc20.currentEntry->unk_2c.type2.unk_1 = (params++)->ToInt();
            numArgsConsumed++;
            data_020fdc20.currentEntry->unk_2c.type2.unk_2_high = (params++)->ToInt();
            numArgsConsumed++;
            data_020fdc20.currentEntry->unk_2c.type2.unk_2_low = (params++)->ToInt();
            numArgsConsumed++;

            if (data_020fdc20.currentEntry->unk_2c.type2.unk_2_high & 8)
            {
                if (params->type == 0)
                {
                    const char* zoneName = (params++)->ToString();
                    numArgsConsumed++;
                    unsigned short* maybeZoneData = _Z25FindElementByName0209998cP12List0209998cPKc(worldData, zoneName);

                    if (maybeZoneData == NULL)
                        return 0;
                    data_020fdc20.currentEntry->unk_2c.type2.maybeZone = *maybeZoneData;
                }
                else
                {
                    data_020fdc20.currentEntry->unk_2c.type2.maybeZone = (params++)->ToInt();
                    numArgsConsumed++;
                }
                data_020fdc20.currentEntry->unk_2c.type2.unk_6 = (params++)->ToInt();
                numArgsConsumed++;
                data_020fdc20.currentEntry->unk_2c.type2.unk_8 = (params++)->ToInt();
                numArgsConsumed++;
                Vector3fix tempVector;
                params = params->ToVec3fix(&tempVector);
                numArgsConsumed += 3;
                data_020fdc20.currentEntry->unk_2c.type2.vectors_c[0] = tempVector;
                data_020fdc20.currentEntry->unk_2c.type2.unk_3c = 4096.0f * (params++)->ToFloat();
                numArgsConsumed++;
                data_020fdc20.currentEntry->unk_2c.type2.unk_3e = 4096.0f * (params++)->ToFloat();
                numArgsConsumed++;

                for (int i = 1; i < 4; i++)
                {
                    params = params->ToVec3fix(&tempVector);
                    numArgsConsumed += 3;
                    data_020fdc20.currentEntry->unk_2c.type2.vectors_c[i] = tempVector;
                }
            }
            if (numArgsConsumed < numParams)
            {
                (void)((params++)->ToFloat());
                numArgsConsumed++;
            }
            if (numArgsConsumed < numParams)
            {
                (void)((params++)->ToInt());
                numArgsConsumed++;
            }
            if (data_020fdc20.currentEntry->unk_2c.type2.unk_2_high & 0x20)
            {
                data_020fdc20.currentEntry->unk_2c.type2.unk_40 = 4096.0f * (params++)->ToFloat();
            }
        }
        break;
    case 3:
        data_020fdc20.currentEntry->unk_2c.type3.unk_0 = (params++)->ToInt();
        break;
    case 4:
    {
        data_020fdc20.currentEntry->unk_2c.type4.unk_0 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type4.unk_1 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type4.unk_0_high = (params++)->ToInt();
        Vector3fix vecA;
        Vector3fix vecB;
        params = params->ToVec3fix(&vecA);
        params = params->ToVec3fix(&vecB);
        MaybeVector4fix vector4;
        Vector3fix_Subtract(&vecB, &vecA, &vector4.vec3.vec);
        fix32_t distance = Vector3fix_Length(&vector4.vec3.vec);
        Vector3fix_Normalize(&vector4.vec3.vec, &vector4.vec3.vec);
        vector4.w = Vector3fix_InnerProduct(&vector4.vec3.vec, &vecA);
        Vector3fix vecC = { 0, 0, 0 };
        if (data_020fdc20.currentEntry->unk_2c.type4.unk_0 == 4)
        {
            params = params->ToVec3fix(&vecC);
        }
        else
        {
            vecC.y = 4096.0f * (params++)->ToFloat();
            vecC.z = 4096.0f * (params++)->ToFloat();
        }
        Vector3fix vecD;
        params = params->ToVec3fix(&vecD);
        data_020fdc20.currentEntry->unk_2c.type4.vector_4.CopyFrom_0201d474(vector4);
        data_020fdc20.currentEntry->unk_2c.type4.distance_14 = distance;
        data_020fdc20.currentEntry->unk_2c.type4.vector_18 = vecC;
        data_020fdc20.currentEntry->unk_2c.type4.vector_24 = vecD;
        break;
    }
    case 5:
        data_020fdc20.currentEntry->unk_2c.type5.unk_0 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type5.unk_2 = (params++)->ToInt();
        if (numParams > 2)
            data_020fdc20.currentEntry->unk_0 = (params++)->ToInt();
        break;
    case 8:
        if (numParams != 0)
            data_020fdc20.currentEntry->unk_0 = (params++)->ToInt();
        break;
    case 9:
        data_020fdc20.currentEntry->unk_2c.type9.unk_0 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type9.unk_2 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type9.unk_4 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type9.unk_5 = (params++)->ToInt();
        if (data_020fdc20.currentEntry->unk_2c.type9.unk_5 & 2)
        {
            if (params->type == 0)
            {
                const char* zoneName = (params++)->ToString();
                unsigned short* maybeZoneData = _Z25FindElementByName0209998cP12List0209998cPKc(worldData, zoneName);

                if (maybeZoneData == NULL)
                    return 0;
                data_020fdc20.currentEntry->unk_2c.type9.maybeZone = *maybeZoneData;
            }
            else
            {
                data_020fdc20.currentEntry->unk_2c.type9.maybeZone = (params++)->ToInt();
            }
            data_020fdc20.currentEntry->unk_2c.type9.unk_8 = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type9.unk_a = (params++)->ToInt();
            params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type9.vector_c);
            data_020fdc20.currentEntry->unk_2c.type9.unk_3c = 4096.0f * (params++)->ToFloat();
            data_020fdc20.currentEntry->unk_2c.type9.unk_3e = 4096.0f * (params++)->ToFloat();
            params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type9.vector_18);
            params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type9.vector_24);
            params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type9.vector_30);
            data_020fdc20.currentEntry->unk_2c.type9.unk_40 = 4096.0f * (params++)->ToFloat();
            data_020fdc20.currentEntry->unk_2c.type9.unk_42 = (params++)->ToInt();
        }
        break;
    case 10:
        data_020fdc20.currentEntry->unk_2c.type10.unk_0 = (params++)->ToInt();
        params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type10.vector_4);
        data_020fdc20.currentEntry->unk_2c.type10.unk_2 = 4096.0f * (params++)->ToFloat();
        data_020fdc20.currentEntry->unk_2c.type10.unk_10 = 4096.0f * (params++)->ToFloat();
        if (numParams > 6)
        {
            params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type10.vector_14);
            data_020fdc20.currentEntry->unk_2c.type10.unk_20 = 4096.0f * (params++)->ToFloat();
        }
        break;
    case 12:
    {
        VectorizedMemset(&data_020fdc20.currentEntry->unk_2c.type12,
            0, sizeof(data_020fdc20.currentEntry->unk_2c.type12));
        data_020fdc20.currentEntry->unk_2c.type12.subtype = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type12.unk_1 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type12.unk_2 = (params++)->ToInt();

        ZoneFeatures::Opcode6aEntry* entry = data_020fdc20.currentEntry;
        switch (entry->unk_2c.type12.subtype)
        {
        case 1:
            entry->unk_2c.type12.subtype1.unk_0 = 0;
            entry->unk_2c.type12.subtype1.unk_1 = 0;
            entry->unk_2c.type12.subtype1.unk_3 = 0;
            entry->unk_2c.type12.subtype1.unk_4 = (params++)->ToInt();
            entry->unk_2c.type12.subtype1.unk_5 = (params++)->ToInt();
            entry->unk_2c.type12.subtype1.unk_2 = (params++)->ToInt();
            break;
        case 2:
            entry->unk_2c.type12.subtype2.unk_0 = 0;
            entry->unk_2c.type12.subtype2.unk_4 = 0;
            entry->unk_2c.type12.subtype2.unk_8 = 4096.0f * (params++)->ToFloat();
            entry->unk_2c.type12.subtype2.unk_c = 4096.0f * (params++)->ToFloat();
            entry->unk_2c.type12.subtype2.unk_10 = 25;
            break;
        case 3:
            entry->unk_2c.type12.subtype3.unk_0 = 0;
            entry->unk_2c.type12.subtype3.unk_1 = 0;
            entry->unk_2c.type12.subtype3.unk_4 = 4096 * 9 / 20;
            entry->unk_2c.type12.subtype3.unk_8 = 4096.0f * (params++)->ToFloat();
            entry->unk_2c.type12.subtype3.unk_c = 4096.0f * (params++)->ToFloat();
            entry->unk_2c.type12.subtype3.unk_10 = 4096.0f * (params++)->ToFloat();
            entry->unk_2c.type12.subtype3.unk_8 = 4096 * 9 / 20;
            entry->unk_2c.type12.subtype3.unk_10 = -4096 / 10;
            break;
        }
        break;
    }
    }
    return 1;
}

int WarpScript_Opcode_7b_0201dfcc(Script::Parameter* params, int numParams)
{
    int count = params[0].ToInt();
    ZoneFeatures::Opcode7bEntry* alloc =
        (ZoneFeatures::Opcode7bEntry*)data_020fdc20.allocator->Allocate(count * sizeof(ZoneFeatures::Opcode7bEntry));
    if (alloc == NULL)
        return 0;
    data_020fdc20.warp->SetOpcode7bAllocation_0201e878(alloc, count);
    return 1;
}

int WarpScript_Opcode_7c_0201e018(Script::Parameter* params, int numParams)
{
    ZoneFeatures::Opcode7bEntry entry;
    params = params->ToVec3fix(&entry.vector_0.vec);
    params = params->ToVec3fix(&entry.vector_c.vec);
    entry.unk_18 = 4096.0f * (params++)->ToFloat();

    fix32_t mhalfx = -entry.vector_c.vec.x / 2;
    fix32_t mhalfz = -entry.vector_c.vec.z / 2;
    fix32_t phalfx = entry.vector_c.vec.x / 2;
    fix32_t phalfz = entry.vector_c.vec.z / 2;

    Vector3fix vertices[4] = { 0 };

    vertices[0].x = mhalfx;
    vertices[0].z = mhalfz;
    vertices[1].x = mhalfx;
    vertices[1].z = phalfz;
    vertices[2].x = phalfx;
    vertices[2].z = mhalfz;
    vertices[3].x = phalfx;
    vertices[3].z = phalfz;

    Matrix4x3 matrix;
    matrix = _Z15RotationMatrixYi(entry.unk_18);

    for (int i = 0; i < 4; i++)
        Mat4x3_ApplyToVector(&vertices[i], &matrix, &vertices[i]);

    entry.minX = vertices[0].x;
    entry.minZ = vertices[0].z;
    entry.maxX = vertices[0].x;
    entry.maxZ = vertices[0].z;

    for (int i = 1; i < 4; i++)
    {
        if (entry.minX > vertices[i].x)
            entry.minX = vertices[i].x;
        if (entry.minZ > vertices[i].z)
            entry.minZ = vertices[i].z;
        if (entry.maxX < vertices[i].x)
            entry.maxX = vertices[i].x;
        if (entry.maxZ < vertices[i].z)
            entry.maxZ = vertices[i].z;
    }

    fix32_t minX = entry.minX;
    fix32_t maxX = entry.maxX;
    fix32_t minZ = entry.minZ;
    fix32_t maxZ = entry.maxZ;

    fix32_t baseX = entry.vector_0.vec.x;
    fix32_t baseZ = entry.vector_0.vec.z;

    minX = baseX + minX;
    minZ = baseZ + minZ;
    maxX = baseX + maxX;
    maxZ = baseZ + maxZ;

    entry.minX = minX;
    entry.minZ = minZ;
    entry.maxX = maxX;
    entry.maxZ = maxZ;
    data_020fdc20.warp->CreateOpcode7bEntry_0201e88c(entry);
    return 1;
}

void ExecuteZoneWarpScript_0201e1d0(const void* data, unsigned int length, ZoneFeatures* warp, SafeAllocator* alloc)
{
    if (length == 0)
        return;
    data_020fdc20.warp = warp;
    data_020fdc20.allocator = alloc;
    data_020fdc20.currentEntry = NULL;

    Script script;
    script.Initialize();
    script.SetOpcodeLookup(data_020ef388);
    script.Load(data, length);
    script.Execute();

    data_020fdc20.warp = NULL;
    data_020fdc20.allocator = NULL;
    data_020fdc20.currentEntry = NULL;
}

void ZoneFeatures::Reset_0201e248()
{
    VectorizedMemset(this, 0, sizeof(ZoneFeatures));
}

void ZoneFeatures::AllocateOpcode64Entries_0201e25c(int count, SafeAllocator *alloc)
{
    entries64_ = (Opcode64Entry*)alloc->Allocate(count * sizeof(Opcode64Entry));
    arraySize64_ = 0;
    arrayCapacity64_ = count;
}

void ZoneFeatures::AllocateGrottoTileFeaturePlacementEntries_0201e288(int count, SafeAllocator* alloc)
{
    grottoTileFeatureEntries_ = (TileFeaturePlacementData*)alloc->Allocate(count * sizeof(TileFeaturePlacementData));
    grottoTileFeatureEntryCount_ = 0;
    grottoTileFeatureEntryCapacity_ = count;
}

void ZoneFeatures::LoadFromScript_0201e2b4(SafeAllocator* alloc, const void* script, unsigned int length)
{
    ExecuteZoneWarpScript_0201e1d0(script, length, this, alloc);
}

ZoneFeatures::Opcode64Entry* ZoneFeatures::GetOpcode64Entry_0201e2d8(int index)
{
    if (index < 0 || arraySize64_ <= index)
        return NULL;
    return &entries64_[index];
}

void ZoneFeatures::CreateOpcode64Entry_0201e304(const Opcode64Entry& source)
{
    if (arraySize64_ >= arrayCapacity64_)
        return;
    Opcode64Entry& dest = entries64_[arraySize64_];

    dest.unk_0 = source.unk_0;
    dest.vector_4 = source.vector_4;
    COPY_ARRAY(dest.string_10, source.string_10);
    COPY_ARRAY(dest.string_20, source.string_20);
    COPY_ARRAY(dest.string_30, source.string_30);
    COPY_ARRAY(dest.unknown_40, source.unknown_40);
    arraySize64_++;
}

void ZoneFeatures::CreateGrottoTileFeaturePlacementEntry_0201e3c4(const TileFeaturePlacementData& source)
{
    if (grottoTileFeatureEntryCount_ >= grottoTileFeatureEntryCapacity_)
        return;

    TileFeaturePlacementData& dest = grottoTileFeatureEntries_[grottoTileFeatureEntryCount_];
    dest.tileID = source.tileID;
    COPY_ARRAY(dest.directionBitmasks, source.directionBitmasks);
    COPY_ARRAY(dest.tilename, source.tilename);

    grottoTileFeatureEntryCount_++;
}

void ZoneFeatures::AllocateOpcode66Entries_0201e480(int count, SafeAllocator *alloc)
{
    entries66_ = (Opcode66Entry*)alloc->Allocate(count * sizeof(Opcode66Entry));
    arraySize66_ = 0;
    arrayCapacity66_ = count;
}

void ZoneFeatures::CreateOpcode66Entry_0201e4b0(const Opcode66Entry& source)
{
    if (arraySize66_ >= arrayCapacity66_)
        return;
    Opcode66Entry& dest = entries66_[arraySize66_];

    COPY_ARRAY(dest.unk_0, source.unk_0);
    COPY_ARRAY(dest.unk_18, source.unk_18);
    dest.unk_20 = source.unk_20;

    arraySize66_++;
}

void ZoneFeatures::AllocateOpcode68Entries_0201e518(int count, SafeAllocator* alloc)
{
    entries68_ = (Opcode68Entry*)alloc->Allocate(count * sizeof(Opcode68Entry));
    arraySize68_ = 0;
    arrayCapacity68_ = count;
}

void ZoneFeatures::CreateOpcode68Entry_0201e574(const Opcode68Entry& source)
{
    if (arraySize68_ >= arrayCapacity68_)
        return;
    Opcode68Entry& dest = entries68_[arraySize68_];

    dest.unk_0 = source.unk_0;
    COPY_ARRAY(dest.unk_4, source.unk_4);
    dest.unk_1c = source.unk_1c;
    COPY_ARRAY(dest.unk_20, source.unk_20);
    dest.unk_50 = source.unk_50;
    dest.unk_52 = source.unk_52;
    dest.unk_54 = source.unk_54;
    COPY_ARRAY(dest.unk_58, source.unk_58);
    COPY_ARRAY(dest.unk_64, source.unk_64);
    dest.unk_6c = source.unk_6c;

    arraySize68_++;
}

void ZoneFeatures::AllocateOpcode6aEntries_0201e634(int count, SafeAllocator *alloc)
{
    entries6a_ = (Opcode6aEntry*)alloc->Allocate(count * sizeof(Opcode6aEntry));
    arraySize6a_ = 0;
    arrayCapacity6a_ = count;
}

void ZoneFeatures::SetOpcode7bAllocation_0201e878(Opcode7bEntry* array, unsigned short capacity)
{
    entries7b_ = array;
    arrayCapacity7b_ = capacity;
    arraySize7b_ = 0;
}

void ZoneFeatures::CreateOpcode7bEntry_0201e88c(const Opcode7bEntry& source)
{
    if (entries7b_ == NULL)
        return;

    Opcode7bEntry& dest = entries7b_[arraySize7b_++];
    dest.vector_0 = source.vector_0;
    dest.vector_c = source.vector_c;
    dest.unk_18 = source.unk_18;
    dest.minX = source.minX;
    dest.minZ = source.minZ;
    dest.maxX = source.maxX;
    dest.maxZ = source.maxZ;
}
