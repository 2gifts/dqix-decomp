#include <globaldefs.h>

extern "C" int func_ov031_0223d414(void* data);
extern "C" int func_ov031_0223d69c(void* out);
extern "C" void func_ov031_022368e0(void);
extern "C" void func_ov031_02235488(int level);
void ForwardWithOffsetThenTag_02235744(int a);

extern int data_ov031_022493b8;
extern unsigned char data_ov031_022491f4[];

struct State022353b8 {
    char pad0[0x10];
    unsigned short field10;
    char pad14[0x16 - 0x12];
    unsigned short field16;
    unsigned char field18;
    unsigned char field19;
    char pad1a;
    unsigned char field1b;
    unsigned char field1c;
    unsigned char field1d;
};

extern State022353b8* data_ov031_02290cf4;

#pragma optimize_for_size off
// USA: func_ov031_022353b8  (semantic: CheckAndApplyFade_022353b8)
extern "C" ARM void func_ov031_022353b8(void) {
    unsigned short buf[2];

    if (!func_ov031_0223d414(&data_ov031_022493b8)) {
        goto fail;
    }

    func_ov031_0223d69c(buf);

    {
        State022353b8* p = data_ov031_02290cf4;
        if (buf[0] < p->field10 - 0x1e) {
            goto fail;
        }

        int diff = buf[1] - p->field16;
        int level = p->field18 + diff;
        if (level < 0) {
            level = 0;
        } else {
            unsigned char tableVal = data_ov031_022491f4[p->field1b];
            int maxVal = p->field19 - tableVal;
            if (level >= maxVal) level = maxVal;
        }

        func_ov031_02235488(level);
        ForwardWithOffsetThenTag_02235744(level);
        data_ov031_02290cf4->field1d = 2;
        return;
    }

fail:
    func_ov031_022368e0();
    data_ov031_02290cf4->field1c = 0;
    data_ov031_02290cf4->field1d = 3;
}
