#include "World/ZoneFeatures.h"
#include <globaldefs.h>

// USA: func_0201e710
ARM ZoneFeatures::Opcode6aEntry *ZoneFeatures::CreateOpcode6aEntry(const Opcode6aEntry &source) {
    if (arraySize6a_ < arrayCapacity6a_) {
        Opcode6aEntry &dest            = entries6a_[arraySize6a_];
        entries6a_[arraySize6a_].unk_0 = source.unk_0;
        dest.maybeType                 = source.maybeType;
        dest.unk_8                     = source.unk_8;
        dest.unk_14                    = source.unk_14;
        dest.unk_20                    = source.unk_20;
        dest.unk_22                    = source.unk_22;
        dest.unk_24                    = source.unk_24;
        dest.unk_28                    = source.unk_28;
        dest.unk_2c                    = source.unk_2c;
        dest.pNext                     = source.pNext;

        int cacheIdx = entries6a_[arraySize6a_].maybeType;
        if (entries6aByType_[cacheIdx] == NULL)
            entries6aByType_[cacheIdx] = &entries6a_[arraySize6a_];
        else {
            entries6a_[arraySize6a_].pNext = entries6aByType_[cacheIdx];
            entries6aByType_[cacheIdx]     = &entries6a_[arraySize6a_];
        }

        arraySize6a_++;
        return &dest;
    }
    return NULL;
}
