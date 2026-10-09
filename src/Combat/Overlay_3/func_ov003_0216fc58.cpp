#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205ba68;
struct Node0205bacc;
struct Struct_0205d81c;
struct ShortArrays0204c610;
struct Container020e0310;

struct Elem0216fc58 {
    char unk_0[0xac];
    short baseX;
    short baseY;
};

extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void _Z23SetChannelAFlag0205cef8Pv(void* obj);
extern "C" void* __clear(void* dst, int count);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" short func_ov003_0216df38(char* dst, struct Container020e0310* c, int flag);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(struct Struct_0205ba68* s, int a, int b, int mode);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(struct Node0205bacc* s, int val);
extern "C" struct Elem0216fc58* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
void GetFourShortsAtIndex(struct ShortArrays0204c610* base, int index, short* out0, short* out1, short* out2, short* out3);
extern "C" void* _Z29CreateAndSetFields46_021e2ca8PvS_ii(void* a, void* b, int c, int d);
extern "C" void* _Z29CreateAndSetFields8A_021e2cc8PvS_ii(void* a, void* b, int c, int d);

// USA: func_ov003_0216fc58
extern "C" ARM void func_ov003_0216fc58(char* self, int flag, int tag) {
    char* window = *(char**)(self + 0x3c);
    if (window == 0) {
        return;
    }
    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24*)window, 0, 1);

    (*(char**)(self + 0x3c))[0xb1] = 0;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa0) = 0x11;
    *(short*)(window + 0xa2) = 9;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa4) = 6;
    *(short*)(window + 0xa6) = 6;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa8) = 0xc;
    *(short*)(window + 0xaa) = 0xe;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xac) = 0xa;
    *(short*)(window + 0xae) = 0x10;

    (*(char**)(self + 0x3c))[0xb5] = 1;

    _Z23SetChannelAFlag0205cef8Pv(*(char**)(self + 0x3c));

    char buf[0x200];
    __clear(buf, 0x200);
    _Z22AppendFrameTag02041c08Pciiiii(buf, tag, 8, 5, 5, 5);

    short w = func_ov003_0216df38(buf, (struct Container020e0310*)(self + 0xdc), flag);

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa4) = (short)((0x20 - w) >> 1);
    *(short*)(window + 0xa6) = 6;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa0) = w;
    *(short*)(window + 0xa2) = 9;

    func_0205d304(*(char**)(self + 0x3c), buf, 0, 0, 0, 1, 0, 0);

    window = *(char**)(self + 0x3c);
    *(int*)(window + 0x8) = 1;
    *(int*)(window + 0x58) = 1;
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)(window + 0x4), 1, 3, 0);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)(window + 0x54), 1, 3, 0);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)(window + 0x4), 3);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)(window + 0x54), 3);

    struct Elem0216fc58* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci(*(struct Struct_0205d81c**)(self + 0x3c), 0);
    if (elem == 0) {
        return;
    }

    short baseX = elem->baseX * 8;
    short baseY = elem->baseY * 8;
    short id = 0x16;
    for (int i = 0; i < 3; i++, id++) {
        short x0, y0, x1, y1;
        GetFourShortsAtIndex((struct ShortArrays0204c610*)elem, (short)i, &x0, &y0, &x1, &y1);
        _Z29CreateAndSetFields46_021e2ca8PvS_ii(*(void**)(self + 0xd4), (void*)id, (short)(x0 + baseX), (short)(y0 + baseY));
        _Z29CreateAndSetFields8A_021e2cc8PvS_ii(*(void**)(self + 0xd4), (void*)id, x1, y1);
    }
}
