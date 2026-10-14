#include <globaldefs.h>
#include "World/ZoneFeatures.h"
#include "std_library_functions.h"

// USA: func_0201e304
ARM void ZoneFeatures::CreateOpcode64Entry_0201e304(const Opcode64Entry& source) {
    if (arraySize64_ >= arrayCapacity64_) return;
    Opcode64Entry& dest = entries64_[arraySize64_];
    dest.unk_0 = source.unk_0;
    dest.vector_4 = source.vector_4;
    COPY_ARRAY(dest.string_10, source.string_10);
    COPY_ARRAY(dest.string_20, source.string_20);
    COPY_ARRAY(dest.string_30, source.string_30);
    COPY_ARRAY(dest.unknown_40, source.unknown_40);
    arraySize64_++;
}
