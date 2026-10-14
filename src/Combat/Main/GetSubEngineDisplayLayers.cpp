#include <globaldefs.h>

// USA: func_020dc008
ARM int GetSubEngineDisplayLayers_020dc008() {
    return (*(unsigned int*)0x4001000 & 0x1f00) >> 8;
}
