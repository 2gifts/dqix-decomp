#include <globaldefs.h>
#include "System/LoadToVRAM.h"

// USA: func_020bba50
ARM void TransferBg2CharDataThunk020bba50(const void* data, unsigned int offset, unsigned int length) {
    LoadToMainBG2CharacterData(data, offset, length);
}
