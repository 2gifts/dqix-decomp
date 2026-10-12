#include <globaldefs.h>

extern "C" void* func_02012fe4(void);

struct Zone02161f64 {
    unsigned char unk0[0x2261];
    unsigned char flag;
};

// USA: func_ov001_02161f64
ARM int SetFlagAtOffset_02161f64_02161f64(void) {
    Zone02161f64* zone = (Zone02161f64*)((unsigned char*)func_02012fe4() + 0x3ec);
    zone->flag = 1;
    return 1;
}
