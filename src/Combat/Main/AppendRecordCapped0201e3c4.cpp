#include <globaldefs.h>
#include "World/ZoneFeatures.h"
#include "std_library_functions.h"

// USA: func_0201e3c4
ARM void ZoneFeatures::CreateGrottoTileFeaturePlacementEntry_0201e3c4(const TileFeaturePlacementData& data) {
    int count = grottoTileFeatureEntryCount_;
    TileFeaturePlacementData* dst;
    if (count >= grottoTileFeatureEntryCapacity_) {
        return;
    }
    dst = &grottoTileFeatureEntries_[count];
    dst->tileID = data.tileID;
    COPY_ARRAY(dst->directionBitmasks, data.directionBitmasks);
    COPY_ARRAY(dst->tilename, data.tilename);
    grottoTileFeatureEntryCount_++;
}
