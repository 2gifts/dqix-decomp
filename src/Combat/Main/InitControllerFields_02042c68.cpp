#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void _Z21InitBigStruct0205c790Pc(char* obj);

struct State0204166c;
extern "C" void _Z18ResetState0204166cP13State0204166c(struct State0204166c* s);

struct Struct_020e2bd8;
extern "C" void _Z12Init020e2bd8P15Struct_020e2bd8ii(struct Struct_020e2bd8* obj, int arg1, int arg2);

struct Foo02042fcc;
extern "C" void _Z16ResetFoo02042fccP11Foo02042fcc(struct Foo02042fcc* p);

void InitEightSubStructs(char* obj);

struct Holder02042c24;
extern "C" void _Z22SetSubstructXY02042c24P14Holder02042c24ii(struct Holder02042c24* holder, int x, int y);

struct Holder02042c3c;
extern "C" void _Z24SetSubstructSize02042c3cP14Holder02042c3cii(struct Holder02042c3c* holder, int width, int height);

extern "C" void func_02043124(void* self);

struct RingBuffer02045824;
extern "C" void _Z25SetRingBufferSlot02045824P18RingBuffer02045824ii(struct RingBuffer02045824* rb, int value, int index);

struct Rect02042c54;
extern "C" void _Z15SetRect02042c54P12Rect02042c54iiii(struct Rect02042c54* rect, int left, int top, int right, int bottom);

extern "C" void _Z22ClearField0x0_020bc078Pi(int* field);

extern int data_02107820;

#if defined(jpn)
#define REGION_OFFSET(jpnOffset, usaOffset) jpnOffset
#else
#define REGION_OFFSET(jpnOffset, usaOffset) usaOffset
#endif

// USA: func_02042c68
extern "C" ARM void func_02042c68(char* self) {
    int i;

#if !defined(jpn)
    *(char*)(self + 0x30) = -1;
    *(char*)(self + 0x31) = -1;
#endif
    *(int*)(self + REGION_OFFSET(0x4, 0x38)) = 0;
    *(int*)(self + REGION_OFFSET(0x8, 0x3c)) = 9;
    *(int*)(self + REGION_OFFSET(0x4c, 0x8c)) = 0;
    _Z21InitBigStruct0205c790Pc(self + REGION_OFFSET(0x50, 0x90));

    *(int*)(self + REGION_OFFSET(0x218, 0x2c8)) = 0;
    memset(self + REGION_OFFSET(0x21c, 0x2cc), 0, 4);
    *(int*)(self + REGION_OFFSET(0x220, 0x2d0)) = -1;
    *(int*)(self + REGION_OFFSET(0x228, 0x2d8)) = 0;
    *(int*)(self + REGION_OFFSET(0x22c, 0x2dc)) = 0;
    *(int*)(self + REGION_OFFSET(0x230, 0x2e0)) = 0;
    *(short*)(self + REGION_OFFSET(0x234, 0x2e4)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x236, 0x2e6)) = 1;
    *(unsigned char*)(self + REGION_OFFSET(0x237, 0x2e7)) = 0;
    *(int*)(self + REGION_OFFSET(0x238, 0x2e8)) = 0;
    memset(self + REGION_OFFSET(0x37c, 0x4ac), 0, 0x400);
    *(int*)(self + REGION_OFFSET(0x77c, 0x8ac)) = 0;
    memset(self + REGION_OFFSET(0x780, 0x8b0), 0, 0x40);

    *(unsigned char*)(self + REGION_OFFSET(0x7e2, 0x912)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17e0, 0x19b0)) = 0;
    *(int*)(self + REGION_OFFSET(0x880, 0x9b0)) = 0;
    for (i = 0; i < 0x80; i++) {
        _Z18ResetState0204166cP13State0204166c((struct State0204166c*)(self + REGION_OFFSET(0x888, 0x9b8) + i * 0x1c));
        *(unsigned char*)(self + i + REGION_OFFSET(0x1688, 0x17b8)) = 0;
    }

    *(int*)(self + REGION_OFFSET(0x824, 0x954)) = 0;
    *(int*)(self + REGION_OFFSET(0x828, 0x958)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x1790, 0x1962)) = 0;
    _Z12Init020e2bd8P15Struct_020e2bd8ii((struct Struct_020e2bd8*)(self + REGION_OFFSET(0x1794, 0x1964)), 0, 0);

    _Z12Init020e2bd8P15Struct_020e2bd8ii((struct Struct_020e2bd8*)(self + REGION_OFFSET(0x17b8, 0x1988)), 0, 1);

    _Z16ResetFoo02042fccP11Foo02042fcc((struct Foo02042fcc*)(self + REGION_OFFSET(0x7e4, 0x914)));
    _Z16ResetFoo02042fccP11Foo02042fcc((struct Foo02042fcc*)(self + REGION_OFFSET(0x800, 0x930)));
    InitEightSubStructs(self + REGION_OFFSET(0x1804, 0x19e0));

    *(void**)(self + REGION_OFFSET(0x1c44, 0x1e20)) = (void*)(self + REGION_OFFSET(0x7e4, 0x914));
    _Z22SetSubstructXY02042c24P14Holder02042c24ii((struct Holder02042c24*)(self + REGION_OFFSET(0x1804, 0x19e0)), 0, 0x80);
    _Z24SetSubstructSize02042c3cP14Holder02042c3cii((struct Holder02042c3c*)(self + REGION_OFFSET(0x1804, 0x19e0)), 0x100, 0x40);
    *(unsigned char*)(self + REGION_OFFSET(0x17e1, 0x19b1)) = 1;
    *(int*)(self + REGION_OFFSET(0x1c4c, 0x1e28)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17fd, 0x19cc)) = 0;
    func_02043124(self);

    *(unsigned char*)(self + REGION_OFFSET(0x17eb, 0x19bb)) = 1;
    *(int*)(self + REGION_OFFSET(0x864, 0x994)) = -1;
    *(unsigned char*)(self + REGION_OFFSET(0x17ec, 0x19bc)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17e2, 0x19b2)) = 1;
    *(int*)(self + REGION_OFFSET(0x86c, 0x99c)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17e3, 0x19b3)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17e4, 0x19b4)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17e5, 0x19b5)) = 0;
    *(int*)(self + REGION_OFFSET(0x870, 0x9a0)) = 0;
    *(short*)(self + REGION_OFFSET(0x174c, 0x187c)) = 0x7fff;
    *(int*)(self + REGION_OFFSET(0x874, 0x9a4)) = 3;
    *(int*)(self + REGION_OFFSET(0x884, 0x9b4)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17dc, 0x19ac)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17dd, 0x19ad)) = 0;
#if defined(jpn)
    for (int slot = 0; slot < 4; slot++) {
        *(int*)(self + 0x1738) = 0;
    }
#else
    _Z25SetRingBufferSlot02045824P18RingBuffer02045824ii((struct RingBuffer02045824*)self, 0, -1);
#endif

    *(unsigned char*)(self + REGION_OFFSET(0x17e8, 0x19b8)) = 0;
    *(int*)(self + REGION_OFFSET(0x1718, 0x1848)) = 0;
    *(int*)(self + REGION_OFFSET(0x171c, 0x184c)) = 0;
    *(int*)(self + REGION_OFFSET(0x1720, 0x1850)) = 0x100;
    *(int*)(self + REGION_OFFSET(0x1724, 0x1854)) = 0xc0;
    _Z15SetRect02042c54P12Rect02042c54iiii((struct Rect02042c54*)(self + REGION_OFFSET(0x1718, 0x1848)), 0, 0x88, 0x100, 0xc0);

    *(unsigned char*)(self + REGION_OFFSET(0x17e9, 0x19b9)) = 1;
    *(int*)(self + REGION_OFFSET(0x1728, 0x1858)) = 0;
    *(int*)(self + REGION_OFFSET(0x172c, 0x185c)) = 0x88;
    *(int*)(self + REGION_OFFSET(0x1730, 0x1860)) = 0xc;
    *(int*)(self + REGION_OFFSET(0x1734, 0x1864)) = 0x10;
    *(unsigned char*)(self + REGION_OFFSET(0x17de, 0x19ae)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17df, 0x19af)) = 0;
    *(int*)(self + REGION_OFFSET(0x1738, 0x1868)) = 0;
    *(int*)(self + REGION_OFFSET(0x1708, 0x1838)) = -1;
    *(int*)(self + REGION_OFFSET(0x170c, 0x183c)) = 0;
#if defined(jpn)
    *(unsigned char*)(self + 0x17f2) = 0;
#endif
    *(int*)(self + REGION_OFFSET(0x860, 0x990)) = 0x80;
    memset(self + REGION_OFFSET(0x82c, 0x95c), 0, 0x20);

    memset(self + REGION_OFFSET(0x84c, 0x97c), 0, 0x10);

    *(unsigned char*)(self + REGION_OFFSET(0x17f3, 0x19c2)) = 1;
    memset(self + REGION_OFFSET(0x1752, 0x1882), 0xff01, REGION_OFFSET(0x20, 0x80));

#if !defined(jpn)
    memset(self + 0x1902, 0, 0x40);
#endif

    *(short*)(self + REGION_OFFSET(0x1772, 0x1942)) = 0;
#if !defined(jpn)
    *(short*)(self + 0x1944) = 0;
#endif
    *(unsigned char*)(self + REGION_OFFSET(0x17ee, 0x19be)) = 0;
    *(short*)(self + REGION_OFFSET(0x1776, 0x1948)) = -1;
    *(char*)(self + REGION_OFFSET(0x177b, 0x194d)) = 0x7f;
    *(char*)(self + REGION_OFFSET(0x177a, 0x194c)) = *(char*)(self + REGION_OFFSET(0x177b, 0x194d));
    *(char*)(self + REGION_OFFSET(0x1779, 0x194b)) = *(char*)(self + REGION_OFFSET(0x177a, 0x194c));
    *(char*)(self + REGION_OFFSET(0x1778, 0x194a)) = *(char*)(self + REGION_OFFSET(0x1779, 0x194b));
    *(unsigned char*)(self + REGION_OFFSET(0x1788, 0x195a)) = REGION_OFFSET(12, 8);
    *(unsigned char*)(self + REGION_OFFSET(0x1789, 0x195b)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17ef, 0x19bf)) = 0;
#if defined(jpn)
    *(unsigned char*)(self + 0x17ff) &= ~2;
#else
    *(unsigned char*)(self + 0x19cf) = 0;
#endif
    *(unsigned char*)(self + REGION_OFFSET(0x17fc, 0x19cb)) = 0;
    *(unsigned char*)(self + REGION_OFFSET(0x17fd, 0x19cc)) = 0;
#if defined(jpn)
    *(unsigned char*)(self + 0x17ff) &= ~1;
#else
    *(unsigned char*)(self + 0x19ce) = 0;
#endif
    _Z22ClearField0x0_020bc078Pi(&data_02107820);

#if defined(jpn)
    *(unsigned char*)(self + 0x17ff) &= ~4;
#else
    *(unsigned char*)(self + 0x19d0) = 0;
#endif
    *(short*)(self + REGION_OFFSET(0x1800, 0x19da)) = -1;
#if !defined(jpn)
    *(unsigned char*)(self + 0x19dc) = 1;
#endif
    *(unsigned char*)(self + REGION_OFFSET(0x17e1, 0x19b1)) = 0;
}
