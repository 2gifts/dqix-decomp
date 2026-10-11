#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Variant02030b0c* p);
extern "C" int _Z12StringLengthPKc(char* s);
extern "C" char* strcpy(char* dst, const char* src);

struct List0208df94;
struct Copy0208e000;
extern "C" void _Z31AppendNodeToCountedList0208df94P12List0208df94P13SafeAllocatorP12Copy0208e000(struct List0208df94* list, SafeAllocator* alloc, struct Copy0208e000* src);

struct Data02108fd4 {
    unsigned short* field0;
    unsigned short* field4;
    void* field8;
    void* fieldC;
};
extern struct Data02108fd4 data_02108fd4;

struct Bits0208dc84 {
    unsigned short b0 : 2;
    unsigned short b2 : 7;
#if defined(jpn)
    unsigned short b9 : 7;
#else
    unsigned short b9 : 6;
    unsigned short b15 : 1;
#endif
};

struct Copy0208dc84 {
    short field0;
    struct Bits0208dc84 field2;
    int field4;
    int field8;
#if defined(jpn)
    int fieldC;
#endif
};

// USA: func_0208dc84
// JPN: func_0208dc84
extern "C" ARM int func_0208dc84(char* p
#if defined(jpn)
    , int parameterCount
#endif
) {
    struct Copy0208dc84 c;
#if defined(jpn)
    char* extra;
#endif
    char* s;
    void* dst;

    c.field0 = -1;
    c.field2.b0 = 0;
    c.field2.b2 = 0;
    c.field2.b9 = 0;
#if !defined(jpn)
    c.field2.b15 = 0;
#endif
    c.field4 = 0;
    c.field8 = 0;
#if defined(jpn)
    c.fieldC = 0;
#endif

    if (data_02108fd4.field4 != 0) {
        unsigned short i;
        c.field0 = (short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)p);
        s = (char*)_ZNK6Script9Parameter8ToStringEv((struct Variant02030b0c*)(p + 8));
        c.field2.b0 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x10));
        c.field2.b9 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x18));
        c.field2.b2 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x20));
#if defined(jpn)
        extra = 0;
        if (parameterCount - 5) {
            extra = (char*)_ZNK6Script9Parameter8ToStringEv((struct Variant02030b0c*)(p + 0x28));
        }
#else
        c.field2.b15 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x28));
#endif
        for (i = 0; i < *data_02108fd4.field0; i++) {
            if (data_02108fd4.field4[i] == c.field2.b9) {
                if (s != 0) {
                    dst = ((SafeAllocator*)data_02108fd4.fieldC)->Allocate((unsigned int)(_Z12StringLengthPKc(s) + 1));
                    c.field4 = (int)dst;
                    if (dst != 0) {
                        strcpy((char*)dst, s);
                    }
                }
#if defined(jpn)
                if (extra != 0) {
                    dst = ((SafeAllocator*)data_02108fd4.fieldC)->Allocate((unsigned int)(_Z12StringLengthPKc(extra) + 1));
                    c.field8 = (int)dst;
                    if (dst != 0) {
                        strcpy((char*)dst, extra);
                    }
                }
#endif
                _Z31AppendNodeToCountedList0208df94P12List0208df94P13SafeAllocatorP12Copy0208e000((struct List0208df94*)data_02108fd4.field8,
                                                (SafeAllocator*)data_02108fd4.fieldC,
                                                (struct Copy0208e000*)&c);
                break;
            }
        }
    } else {
        c.field0 = (short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)p);
        s = (char*)_ZNK6Script9Parameter8ToStringEv((struct Variant02030b0c*)(p + 8));
        if (s != 0) {
            dst = ((SafeAllocator*)data_02108fd4.fieldC)->Allocate((unsigned int)(_Z12StringLengthPKc(s) + 1));
            c.field4 = (int)dst;
            if (dst != 0) {
                strcpy((char*)dst, s);
            }
        }
        c.field2.b0 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x10));
        c.field2.b9 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x18));
        c.field2.b2 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x20));
#if defined(jpn)
        extra = 0;
        if (parameterCount - 5) {
            extra = (char*)_ZNK6Script9Parameter8ToStringEv((struct Variant02030b0c*)(p + 0x28));
        }
#else
        c.field2.b15 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(p + 0x28));
#endif
#if defined(jpn)
        if (extra != 0) {
            dst = ((SafeAllocator*)data_02108fd4.fieldC)->Allocate((unsigned int)(_Z12StringLengthPKc(extra) + 1));
            c.field8 = (int)dst;
            if (dst != 0) {
                strcpy((char*)dst, extra);
            }
        }
#endif
        _Z31AppendNodeToCountedList0208df94P12List0208df94P13SafeAllocatorP12Copy0208e000((struct List0208df94*)data_02108fd4.field8,
                                        (SafeAllocator*)data_02108fd4.fieldC,
                                        (struct Copy0208e000*)&c);
    }
    return 1;
}
