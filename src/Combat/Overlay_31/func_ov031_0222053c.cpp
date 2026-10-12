#include <globaldefs.h>

struct Descriptor0222053c {
    unsigned short length;
    unsigned char name[7];
};
struct NetworkDebug0222053c {
    unsigned char field_0x0[0x50];
    int enabled;
};
extern unsigned char data_ov031_022460e0[7] __attribute__((aligned(4)));
extern unsigned char* data_ov031_0224b114;
extern NetworkDebug0222053c data_ov031_0224f670;
extern unsigned char data_ov031_0224fb18[6];
extern unsigned char data_ov031_0224fba4[];
extern "C" int func_ov031_02220390(int, int, const void*, int);
extern "C" int func_ov031_022202cc(int, int, const void*, int, int);

// USA: func_ov031_0222053c
extern "C" THUMB int func_ov031_0222053c(int request) {
    Descriptor0222053c descriptor;
    descriptor.length = 256;
    const unsigned char* source = data_ov031_022460e0;
    unsigned char* destination = descriptor.name;
    int remaining = 7;
    do {
        *destination++ = *source++;
    } while (--remaining);
    int cursor = func_ov031_02220390((int)data_ov031_0224b114, 1, &descriptor, 2);
    cursor = func_ov031_02220390(cursor, 2, &descriptor, 2);
    cursor = data_ov031_0224f670.enabled ? func_ov031_02220390(cursor, 5, &descriptor, 2) : cursor;
    cursor = func_ov031_02220390(cursor, 3, descriptor.name, 7);
    if (data_ov031_0224f670.enabled) cursor = func_ov031_02220390(cursor, 4, data_ov031_0224fb18, 6);
    return func_ov031_022202cc(request, 2, data_ov031_0224fba4, cursor - (int)data_ov031_0224b114 + 8, 0);
}
