#include <globaldefs.h>
#include "Resource/Script.h"

struct DataBlock02291e04 {
    unsigned char count;
#if defined(jpn)
    unsigned char pad0[3];
#else
    unsigned char pad0[4];
#endif
    unsigned char field5;
#if defined(jpn)
    unsigned char pad1[0x22];
#else
    unsigned char pad1[0x22];
#endif
    int* values;
    void* entries;
};
extern DataBlock02291e04 data_ov031_02291e04;

// USA: func_ov031_02243300
extern "C" ARM int func_ov031_02243300(Script::Parameter* parameters) {
    int index = parameters[0].ToInt();
    if (index < 0 || index >= 14) return 1;
    int value;
    *(volatile int*)&value = parameters[1].ToInt();
    data_ov031_02291e04.values[index] = value;
    return 1;
}
