#include <globaldefs.h>
#include "World/ZoneFeatures.h"
#include "System/Memory.h"

// USA: func_0201e248
ARM void ZoneFeatures::Reset_0201e248() {
    VectorizedMemset(this, 0, sizeof(*this));
}
