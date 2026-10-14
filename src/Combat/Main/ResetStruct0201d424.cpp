#include <globaldefs.h>
#include "System/Memory.h"
#include "World/ZoneFeatures.h"

// USA: func_0201d424
ARM void ZoneFeatures::Opcode6aEntry::Reset_0201d424() {
    char* obj = (char*)this;
    VectorizedMemset(obj, 0, 0x74);
    *(short*)(obj + 0x0) = 0;
    *(int*)(obj + 0x4) = 0;
    *(short*)(obj + 0x20) = 0;
    *(short*)(obj + 0x22) = 0;
    *(int*)(obj + 0x24) = 0;
    *(int*)(obj + 0x8) = 0;
    *(int*)(obj + 0xc) = 0;
    *(int*)(obj + 0x10) = 0;
    *(int*)(obj + 0x14) = 0;
    *(int*)(obj + 0x18) = 0;
    *(int*)(obj + 0x1c) = 0;
    *(int*)(obj + 0x28) = 0;
    *(int*)(obj + 0x70) = 0;
}
