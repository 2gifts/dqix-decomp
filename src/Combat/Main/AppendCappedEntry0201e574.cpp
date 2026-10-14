#include <globaldefs.h>
#include "World/ZoneFeatures.h"
#include "std_library_functions.h"

// USA: func_0201e574
ARM void ZoneFeatures::CreateOpcode68Entry_0201e574(const Opcode68Entry& src) {
    Opcode68Entry* dst;
    if (arraySize68_ >= arrayCapacity68_) return;
    dst = &entries68_[arraySize68_];
    dst->unk_0 = src.unk_0;
    COPY_ARRAY(dst->unk_4, src.unk_4);
    dst->unk_1c = src.unk_1c;
    COPY_ARRAY(dst->unk_20, src.unk_20);
    dst->unk_50 = src.unk_50;
    dst->unk_52 = src.unk_52;
    dst->unk_54 = src.unk_54;
    COPY_ARRAY(dst->unk_58, src.unk_58);
    COPY_ARRAY(dst->unk_64, src.unk_64);
    dst->unk_6c = src.unk_6c;
    arraySize68_++;
}
