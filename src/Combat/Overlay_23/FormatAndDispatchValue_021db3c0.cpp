#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);
extern "C" long long func_0200c578(int x);
#if defined(jpn)
extern "C" int sprintf(void*, const void*, ...);
extern "C" float _fmul(int,int);
extern "C" int _ffix(float);
#else
extern "C" int sprintf(void* dst, void* fmt, int a, int b);
#endif
extern "C" int func_020420e8(void* builder, int obj);
extern "C" void func_0204f41c(int a, short b, short c, void* buf, int d, int e, void* f, void* g, int h);
extern char data_ov023_021fdb28;
#if defined(jpn)
extern const char data_ov023_021fcdec[];
extern "C" void func_02050678(int, int, short, void*, int, int, void*, void*);
#endif

// JPN: func_ov023_021dbc08
// USA: func_ov023_021db3c0
ARM void FormatAndDispatchValue_021db3c0(int param0, int param1, short param2, int param3, unsigned char param4) {
#if defined(jpn)
    int integer;
    int color = param4;
    int scaled = _ffix(_fmul(0x41200000, param3));
    integer = scaled;
    scaled %= 10;
    integer /= 10;
    char fraction[3];
    __clear(fraction, 3);
    sprintf(fraction, (void*)data_ov023_021fcdec, scaled);
    short outA;
    short outB;
    func_02050678(param0, param1, param2, fraction, 8, color, &outA, &outB);
    param1 = (short)(param1 - 2);
    fraction[0] = '.';
    func_02050678(param0, param1, param2, fraction, 8, color, &outA, &outB);
    param1 = (short)(param1 - 7);
    do {
        int digit = integer % 10;
        integer /= 10;
        char buf[2];
        __clear(buf, 2);
        sprintf(buf, (void*)data_ov023_021fcdec, digit);
        func_02050678(param0, param1, param2, buf, 8, color, &outA, &outB);
        param1 = (short)(param1 - 6);
    } while (integer != 0);

#else
    char buf[0x40];
    __clear(buf, 0x40);
    long long val = func_0200c578(param3);
    sprintf(buf, &data_ov023_021fdb28, (int)val, (int)(val >> 32));
    int r1val = func_020420e8(buf, 0);
    short sum = (short)(param1 - r1val);
    short outA;
    short outB;
    func_0204f41c(param0, sum, param2, buf, 8, param4, &outA, &outB, 0);

#endif
}
