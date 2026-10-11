#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" unsigned char _Z24NormalizeField5_0200fb08P14Struct0200fb08(void* obj);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" int _Z13GetFileInNarcPKvPKcPS0_Pjj(const void* narc, const char* name,
                                            const void** pPtr, const void** pSize,
                                            unsigned int firstIdx);
extern "C" void func_02047b40(void* dest, const void* data, void* flag);

extern const char data_ov000_02184184[];
extern const char data_ov000_02184186[];
extern const char data_ov000_02184188[];
extern const char data_ov000_0218418a[];
extern const char data_ov000_02184190[];
extern const char data_ov000_02184193[];
extern const char data_ov000_02184197[];
extern const char data_ov000_0218419b[];
extern const char data_ov000_021841a0[];
extern const char data_ov000_021841a5[];
extern const char data_ov000_021841a8[];
extern const char data_ov000_021841ae[];
extern const char data_ov000_021841b3[];
extern const char data_ov000_021841b8[];
extern const char data_ov000_021841c1[];
extern const char data_ov000_021841c6[];
extern const char data_ov000_021841cb[];
extern const char data_ov000_021841d4[];
extern const char data_ov000_021841d9[];
extern const char data_ov000_021841de[];
extern const char data_ov000_021841e7[];
extern const char data_ov000_021841ec[];
extern const char data_ov000_021841f1[];
extern const char data_ov000_021841fa[];
extern const char data_ov000_021841ff[];
extern const char data_ov000_02184204[];
extern const char data_ov000_02184209[];
extern const char data_ov000_0218420e[];

struct ComboSlot0218214c {
    const char* name;
    Foo02048004* obj;
};

// USA: func_ov000_0218214c
extern "C" ARM void func_ov000_0218214c(Foo02048004* base, void* extra, const void* narc) {
    char buf[0x28];
    struct ComboSlot0218214c tab[13];
    int i;
    int j;
    int skip;
    unsigned char mode = _Z24NormalizeField5_0200fb08P14Struct0200fb08(_ZN9GameState11GetInstanceEv());
    int count;

    skip = 2;
    tab[0].name = data_ov000_02184184;
    tab[1].name = data_ov000_02184186;
    tab[2].name = data_ov000_02184188;
    tab[3].name = data_ov000_0218418a;
    tab[4].name = data_ov000_02184190;
    if (mode == 1) {
        tab[5].name = data_ov000_02184193;
        tab[6].name = data_ov000_02184197;
    } else {
        tab[5].name = data_ov000_0218419b;
        tab[6].name = data_ov000_021841a0;
    }
    tab[7].name = data_ov000_021841a5;

    if (mode == 1) {
        tab[8].name = data_ov000_021841a8;
        tab[9].name = data_ov000_021841ae;
        tab[10].name = data_ov000_021841b3;
    } else if (mode == 2) {
        tab[8].name = data_ov000_021841b8;
        tab[9].name = data_ov000_021841c1;
        tab[10].name = data_ov000_021841c6;
    } else if (mode == 3) {
        tab[8].name = data_ov000_021841cb;
        tab[9].name = data_ov000_021841d4;
        tab[10].name = data_ov000_021841d9;
    } else if (mode == 4) {
        tab[8].name = data_ov000_021841de;
        tab[9].name = data_ov000_021841e7;
        tab[10].name = data_ov000_021841ec;
    } else if (mode == 5) {
        tab[8].name = data_ov000_021841f1;
        tab[9].name = data_ov000_021841fa;
        tab[10].name = data_ov000_021841ff;
        tab[11].name = data_ov000_02184204;
        tab[12].name = data_ov000_02184209;
        skip = 0;
    }
    count = 13 - skip;

    for (i = 0; i < count; i++) {
        tab[i].obj = (Foo02048004*)((char*)base + i * 0x88);
    }

    for (j = 0; j < count; j++) {
        sprintf(buf, data_ov000_0218420e, tab[j].name);
        const void* fileSize = 0;
        const void* fileData = 0;
        _Z13GetFileInNarcPKvPKcPS0_Pjj(narc, buf, &fileData, &fileSize, 0);
        func_02047b40(tab[j].obj, fileData, extra);
    }

    tab[0].obj->word0 = 0x3e;
    tab[1].obj->word0 = 0x3e;
    tab[2].obj->word0 = 0x3e;
}
