#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov004_02156e68(void* a, int key);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int ScaleStatsIfType12_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
struct Obj021f6f08;
unsigned int GetShort6_021f6f08(struct Obj021f6f08* obj);
signed char GetFlagByte_021570f0(int idx);

struct Struct021707d8_02157128 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_02157128 data_ov004_021707d8;

// USA: func_ov004_02157128
extern "C" ARM signed char func_ov004_02157128(void* obj) {
    void* node = func_ov004_02156e68(obj, 0x5f);
    if (!node) {
        return (signed char)(*(short*)(data_ov004_021707d8.ptr + 0x3c));
    }

    if (ScaleStatsIfType12_021f6f10(node) != 8) {
        return 0;
    }

    int idx = 0;
    unsigned int v = GetShort6_021f6f08((struct Obj021f6f08*)node);
    switch (v) {
        case 0x322: idx = 0; break;
        case 0x323: idx = 1; break;
        case 0x324: idx = 2; break;
        case 0x325: idx = 3; break;
        case 0x326: idx = 4; break;
        case 0x327: return -1;
        default: break;
    }
    return GetFlagByte_021570f0(idx);
}
