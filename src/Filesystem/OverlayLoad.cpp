#include "Filesystem/OverlayFSManagement.h"
#include "Filesystem/FSInnerDefs.h"
#include "System/Cache.h"
#include "System/Memory.h"
#include "System/BiosData.h"
#include <globaldefs.h>

#pragma optimize_for_size off

#if defined(jpn)
#define data_020f2e44 data_020f2e58
#define data_020f2290 data_020f23fc

#define func_020c0c3c func_020c2708
#endif

// might be some kind of overlay-like thing for download play
extern struct UnknownDownloadPlayStruct
{
    unsigned int unknown[5];
} data_020f2e44[];

#if defined(usa)
#define ADDR_FIRST_DOWNLOAD_PLAY_STRUCT 0x020f2e44
#elif defined(jpn)
#define ADDR_FIRST_DOWNLOAD_PLAY_STRUCT 0x020f2e58
#endif

extern struct {
    const void* pointer;
    unsigned int length;
} data_020f2290;

extern "C"
{
    int func_02000970(unsigned int);
    void func_020c9be0();
    void func_020c0c3c(UnknownDownloadPlayStruct*, unsigned, unsigned, unsigned char*, unsigned);
}

bool LoadCompressedOverlay(const OverlayMetadata &overlay, NitroVM *machine)
{
    NitroVM_Initialize(machine);
    NitroFileAccessor accessor;
    CreateFileAccessorForOverlay(&accessor, overlay);
    if (!NitroVM_PrepareReadFileByID(machine, accessor))
        return false;

    unsigned int cartridgeSize = GetOverlaySizeOnCartridge(overlay);
    InvalidateCacheAndZeroOverlay(overlay);
    if (NitroVM_ReadAsync(machine, (void*)overlay.loadAddress, cartridgeSize) != cartridgeSize)
    {
        NitroVM_FinishRead(machine);
        return false;
    }

    return true;
}

bool LoadCompressedOverlay(const OverlayMetadata& overlay)
{
    NitroVM machine;
    NitroVM_Initialize(&machine);
    NitroFileAccessor accessor;
    CreateFileAccessorForOverlay(&accessor, overlay);
    if (!NitroVM_PrepareReadFileByID(&machine, accessor))
        return false;

    unsigned int cartridgeSize = GetOverlaySizeOnCartridge(overlay);
    InvalidateCacheAndZeroOverlay(overlay);
    if (NitroVM_ReadSync(&machine, (void*)overlay.loadAddress, cartridgeSize) != cartridgeSize)
    {
        NitroVM_FinishRead(&machine);
        return false;
    }

    NitroVM_FinishRead(&machine);
    return true;
}

bool VerifyDownloadPlayStruct(const UnknownDownloadPlayStruct& data,
    unsigned int loadAddress, unsigned int size)
{
    UnknownDownloadPlayStruct clone;
    VectorizedMemset(&clone, 0, sizeof(UnknownDownloadPlayStruct));

    unsigned char buffer[64];
    VectorizedInvertedMemcpy(data_020f2290.pointer, buffer, data_020f2290.length);
    func_020c0c3c(&clone, loadAddress, size, buffer, data_020f2290.length);

    unsigned int offsetCounter = 0;
    unsigned int* cloneReader = &clone.unknown[0];
    do {
        if (*cloneReader != *(unsigned int*)((int)&data + offsetCounter))
            break;
        offsetCounter += 4;
        cloneReader++;
    } while (offsetCounter < sizeof(UnknownDownloadPlayStruct));

    return offsetCounter == sizeof(UnknownDownloadPlayStruct);
}

void DecompressAndStaticInitializeOverlay(const OverlayMetadata& overlay)
{
    unsigned int initialSize = GetOverlaySizeOnCartridge(overlay);

    // extremely weird code that never runs (only for DS Download Play?)
    if (IsDownloadPlay())
    {
        bool result = false;
        if (overlay.overlayFlags & (1 << OVERLAY_FLAG_DOWNLOAD_PLAY))
        {
            // Using two different formats for the same address (number and label)
            // forces the word to appear twice
            UnknownDownloadPlayStruct* start = (UnknownDownloadPlayStruct*)ADDR_FIRST_DOWNLOAD_PLAY_STRUCT;
            UnknownDownloadPlayStruct* end = data_020f2e44;
            if (overlay.overlayIndex < end - start)
            {
                result = VerifyDownloadPlayStruct(
                    *(UnknownDownloadPlayStruct*)((int)start + sizeof(UnknownDownloadPlayStruct) * overlay.overlayIndex),
                    overlay.loadAddress, initialSize);
            }
        }
        if (!result)
        {
            VectorizedMemset((void*)overlay.loadAddress, 0, initialSize);
            func_020c9be0();
            return;
        }
    }

    // Decompress the overlay in place
    if (overlay.overlayFlags & (1 << OVERLAY_FLAG_COMPRESSED))
        func_02000970(overlay.loadAddress + initialSize);

    CleanInvalidateCacheRange((void*)overlay.loadAddress, overlay.uncompressedSize);
    OverlayMetadata::StaticInitializer* pInitializer = overlay.staticInitStart;
    OverlayMetadata::StaticInitializer* initializerEnd = overlay.staticInitEnd;
    if (pInitializer < initializerEnd)
    {
        do {
            if (*pInitializer)
                (*pInitializer)();
            pInitializer++;
        } while (pInitializer < initializerEnd);
    }
}
