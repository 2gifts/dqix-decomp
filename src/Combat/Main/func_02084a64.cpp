#include <globaldefs.h>

extern "C" int _Z33AccumulateFlaggedSlotBits02085fb4Ph(unsigned char* actor);
extern "C" int _Z33AccumulateFlaggedSlotBits02086020Ph(unsigned char* actor);
extern "C" int _Z33AccumulateFlaggedSlotBits0208608cPh(unsigned char* actor);
extern "C" int _Z33AccumulateFlaggedSlotBits020860f8Ph(unsigned char* actor);
extern "C" int _Z33AccumulateFlaggedSlotBits02086164Ph(unsigned char* actor);
extern "C" int _Z33AccumulateFlaggedSlotBits020861d0Ph(unsigned char* actor);
extern "C" int _Z33AccumulateFlaggedSlotBits0208623cPh(unsigned char* actor);
extern "C" int _Z35AccumulateSlotBitsFromTable020862a8Ph(unsigned char* obj);
extern "C" int _Z35AccumulateSlotBitsFromTable02086314Ph(unsigned char* obj);
unsigned int ClampLengthToMax(unsigned int a, unsigned int start, unsigned int length, unsigned int max);

struct BitTriple10 {
    unsigned int f0 : 10;
    unsigned int f1 : 10;
    unsigned int f2 : 10;
    unsigned int : 2;
};

struct SlotPointRow {
    struct BitTriple10 w0;
    struct BitTriple10 w1;
    struct BitTriple10 w2;
};

#if defined(jpn)
enum { SlotDataRegionOffset = 0x98 };
#else
enum { SlotDataRegionOffset = 0 };
#endif

// USA: func_02084a64
extern "C" ARM int func_02084a64(unsigned char* obj, int id) {
    int index = *(int*)(obj + 0x950 - SlotDataRegionOffset);
    struct SlotPointRow* row = (struct SlotPointRow*)(obj + 0x850 - SlotDataRegionOffset) + index;
    unsigned int result = 0;
    int bad = 0;

    switch (id) {
    case 421: {
        int delta = _Z33AccumulateFlaggedSlotBits02085fb4Ph(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x91c - SlotDataRegionOffset))->f0 + row->w0.f0;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w0.f0 += clamped;
        result = clamped;
        break;
    }
    case 423: {
        int delta = _Z33AccumulateFlaggedSlotBits02086020Ph(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x91c - SlotDataRegionOffset))->f1 + row->w0.f1;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w0.f1 += clamped;
        result = clamped;
        break;
    }
    case 424: {
        int delta = _Z33AccumulateFlaggedSlotBits0208608cPh(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x91c - SlotDataRegionOffset))->f2 + row->w0.f2;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w0.f2 += clamped;
        result = clamped;
        break;
    }
    case 422: {
        int delta = _Z33AccumulateFlaggedSlotBits020860f8Ph(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x920 - SlotDataRegionOffset))->f0 + row->w1.f0;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w1.f0 += clamped;
        result = clamped;
        break;
    }
    case 428: {
        int delta = _Z33AccumulateFlaggedSlotBits02086164Ph(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x920 - SlotDataRegionOffset))->f1 + row->w1.f1;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w1.f1 += clamped;
        result = clamped;
        break;
    }
    case 426: {
        int delta = _Z33AccumulateFlaggedSlotBits020861d0Ph(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x920 - SlotDataRegionOffset))->f2 + row->w1.f2;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w1.f2 += clamped;
        result = clamped;
        break;
    }
    case 425: {
        int delta = _Z33AccumulateFlaggedSlotBits0208623cPh(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x924 - SlotDataRegionOffset))->f0 + row->w2.f0;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w2.f0 += clamped;
        result = clamped;
        break;
    }
    case 262: {
        int delta = _Z35AccumulateSlotBitsFromTable020862a8Ph(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x924 - SlotDataRegionOffset))->f1 + row->w2.f1;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 3, 999);
        row->w2.f1 += clamped;
        result = clamped;
        break;
    }
    case 263: {
        int delta = _Z35AccumulateSlotBitsFromTable02086314Ph(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x924 - SlotDataRegionOffset))->f2 + row->w2.f2;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 3, 999);
        row->w2.f2 += clamped;
        result = clamped;
        break;
    }
    case 427: {
        unsigned short cur = *(unsigned short*)(obj + 0x564);
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, cur, 2, 2600);
        unsigned short delta16 = (unsigned short)clamped;
        *(unsigned short*)(obj + 0x564) = *(unsigned short*)(obj + 0x564) + delta16;
        result = clamped;
        break;
    }
    default:
        bad = 1;
        break;
    }

    return bad ? -1 : (int)result;
}
