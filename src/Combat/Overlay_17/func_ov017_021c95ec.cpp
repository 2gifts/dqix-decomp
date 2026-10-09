#include <globaldefs.h>

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Vec3i021c95ec {
    int x;
    int y;
    int z;
};

struct Evt021c95ec {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short id;
    unsigned char kind : 6;
    unsigned char flag6 : 1;
    unsigned char flag7 : 1;
    unsigned char lowNibble : 4;
    signed char highNibble : 4;
    short field8;
    short field_a;
    int field_c;
    int field_10;
};

// USA: func_ov017_021c95ec
extern "C" ARM void func_ov017_021c95ec(int id, int lowNibble, int unused, int kind, int highNibble,
                                        struct Vec3i021c95ec v, int field8, unsigned char flag6, unsigned char flag7) {
    void* data = GetData02100044();
    struct Evt021c95ec evt;
    evt.lowNibble = lowNibble;
    evt.highNibble = highNibble;
    evt.field_c = v.x;
    evt.kind = kind;
    evt.flag6 = flag6;
    evt.flag7 = flag7;
    evt.id = id;
    evt.tag = 0x87;
    evt.field_a = v.y >> 4;
    evt.field_10 = v.z;
    evt.field8 = field8;
    func_0205e330(data, &evt, 0);
}
