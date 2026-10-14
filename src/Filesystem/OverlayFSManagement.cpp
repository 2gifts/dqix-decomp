#include "Filesystem/OverlayFSManagement.h"
#include "Filesystem/FSInnerDefs.h"
#include "System/Cache.h"
#include "System/Memory.h"
#include "System/BiosData.h"
#include <globaldefs.h>

unsigned int GetOverlaySizeOnCartridge(const OverlayMetadata& overlay)
{
    bool isCompressed = overlay.overlayFlags & (1 << OVERLAY_FLAG_COMPRESSED);
    if (!isCompressed)
        return overlay.uncompressedSize;
    return overlay.compressedSize;
}

void InvalidateCacheAndZeroOverlay(const OverlayMetadata &overlay)
{
    unsigned char* startAddr = (unsigned char*)overlay.loadAddress;
    unsigned int copySize = overlay.uncompressedSize;
    unsigned int totalSize = copySize + overlay.bssSectionSize;

    InvalidateInstructionCacheRange(startAddr, totalSize);
    InvalidateDataCacheRange(startAddr, totalSize);
    VectorizedMemset(startAddr + copySize, 0, totalSize - copySize);
}

void CreateFileAccessorForOverlay(NitroFileAccessor *outAccessor, const OverlayMetadata &overlay)
{
    NitroFileAccessor temp;
    temp.handle = &data_02111754;
    temp.fileID = overlay.nitroFileID;

    // this cast forces the temporary struct to be created on the stack
    // (writing *&temp, or *(&temp), isn't enough)
    *outAccessor = *(NitroFileAccessor*)&temp;
}
