#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// USA: func_0201e4b0
ARM void ZoneFeatures::CreateOpcode66Entry_0201e4b0(const Opcode66Entry& source) {
    int count = arraySize66_;
    Opcode66Entry* dst;
    if (count >= arrayCapacity66_) {
        return;
    }
    dst = &entries66_[count];
    COPY_ARRAY(dst->unk_0, source.unk_0);
    COPY_ARRAY(dst->unk_18, source.unk_18);
    dst->unk_20 = source.unk_20;
    arraySize66_++;
}
