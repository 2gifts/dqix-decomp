#if defined(jpn)
enum { RegionalOffset = 0x72be };
#else
enum { RegionalOffset = 0x74fe };
#endif

#include <globaldefs.h>
#include "Util/Random.h"

int RegisterSlotB020cf1a8(int a);
void CopyFrom027ffcf4(void* dst);
unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _u32_div_f(unsigned int a, unsigned int b);
extern char data_020ef0ca;

// USA: func_020120f0  (semantic: GenerateDeviceRandomBytes_020120f0)
// JPN: func_020120f0  (semantic: GenerateDeviceRandomBytes_020120f0)
extern "C" ARM void func_020120f0(unsigned char* self) {
    struct Random rng;
    CreateRandom(&rng, &data_020ef0ca, 0);

    int slotBuf[3];
    RegisterSlotB020cf1a8((int)slotBuf);

    unsigned char raw[6];
    CopyFrom027ffcf4(raw);

    unsigned long long seeds[6];
    seeds[0] = (unsigned int)slotBuf[0];
    seeds[1] = (unsigned int)slotBuf[1];
    seeds[2] = (unsigned int)slotBuf[2];

    seeds[3] = (unsigned int)_u32_div_f((unsigned int)GetCurrentTimestamp() << 6, 0x82ea);
    seeds[4] = (unsigned int)_u32_div_f((unsigned int)GetCurrentTimestamp() * 0xfa00, 0x82ea);

    int packed = (raw[5] << 24) | (raw[4] << 16) | (raw[3] << 8) | raw[2];
    seeds[5] = (long long)packed;

    int i;
    for (i = 0; i < 6; i++) {
        SeedRandom(&rng, seeds[i]);
        *(self + i + RegionalOffset) = (unsigned char)NextRandom(&rng);
    }
}
