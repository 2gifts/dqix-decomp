#include "Graphics/OBJImage.h"
#include "System/Graphics.h"
#include "std_library_functions.h"
#include <globaldefs.h>

// USA: func_02076738
extern "C" ARM int func_02076738(InitStruct02075cdcStruct *resource, const unsigned char *stream, int) {
    unsigned int alignmentMask;
    int alignmentShift;
    unsigned int alignedTotal;
    unsigned short groupIndex;
    unsigned int entryIndex;
    int mappingMode;
    if (resource->f5e == 0) {
        mappingMode = (int) (DISPCNT & 0x300010);
    } else {
        mappingMode = (int) (DISPCNTSUB & 0x300010);
    }

    switch (mappingMode) {
        case 0: return 0;
        case 0x10: alignmentShift = 5; break;
        case 0x100010: alignmentShift = 6; break;
        case 0x200010: alignmentShift = 7; break;
        case 0x300010: alignmentShift = 8; break;
        default: return 0;
    }

    unsigned short groupCount = 0;
    unsigned int format       = 0;
    memcpy(&groupCount, stream, 2);
    memcpy(&format, stream + 2, 2);
    stream += 4;

    alignedTotal = 0;
    groupIndex   = 0;
    while (groupIndex < groupCount) {
        unsigned short groupField0;
        unsigned short groupField2;
        unsigned int entryCount;
        memcpy(&groupField0, stream, 2);
        memcpy(&groupField2, stream + 2, 2);
        memcpy(&entryCount, stream + 4, 4);
        stream += 8;

        entryIndex    = 0;
        alignmentMask = (1u << alignmentShift) - 1;

        while (entryIndex < entryCount) {
            unsigned short entryField0, entryField2, widthShift, heightShift;
            memcpy(&entryField0, stream, 2);
            memcpy(&entryField2, stream + 2, 2);
            memcpy(&widthShift, stream + 4, 2);
            memcpy(&heightShift, stream + 6, 2);

            stream += 8;
            unsigned int payloadSize = (8 << widthShift) * (8 << heightShift);
            if (format == 3) payloadSize = payloadSize >> 1;
            stream += payloadSize;
            alignedTotal += (payloadSize + alignmentMask) & ~alignmentMask;
            entryIndex++;
        }
        groupIndex++;
    }
    return alignedTotal;
}
