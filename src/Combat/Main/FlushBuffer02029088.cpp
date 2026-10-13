#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"
#include "std_library_functions.h"
#include "System/Cache.h"

#if defined(jpn)
int GetData02107800Word0(void);

typedef unsigned char TileRow4bpp[4];
typedef TileRow4bpp Tile4bpp[8];
typedef TileRow4bpp Scanline4bpp[32];
typedef Scanline4bpp ScanlineBand4bpp[8];
#endif

// USA: func_02029088
ARM void FlushBuffer02029088() {
    if (glyphBitmapContext.buffer == NULL) return;
#if defined(jpn)
    unsigned char* tiledBand = reinterpret_cast<unsigned char*>(GetData02107800Word0());
    unsigned char* image = static_cast<unsigned char*>(glyphBitmapContext.buffer);
    unsigned char* destination;
    const unsigned char* source;
    unsigned int tileColumnOffset;
    unsigned int band;
    unsigned int tile;
    unsigned int row;
    unsigned int bandOffset;
    for (band = 0; band < 24; ++band) {
        tileColumnOffset = band * sizeof(ScanlineBand4bpp);
        destination = tiledBand;
        bandOffset = tileColumnOffset;
        for (tile = 0; tile < 32; ++tile) {
            source = image + tileColumnOffset;
            for (row = 0; row < 8; ++row) {
                memcpy(destination, source, sizeof(TileRow4bpp));
                destination += sizeof(TileRow4bpp);
                source += sizeof(Scanline4bpp);
            }
            tileColumnOffset += sizeof(TileRow4bpp);
        }
        memcpy(image + bandOffset, tiledBand, sizeof(ScanlineBand4bpp));
    }
#endif
    CleanInvalidateCacheRange(glyphBitmapContext.buffer, 256 * 192 / 2);
}
