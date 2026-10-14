#include <globaldefs.h>

int AccumulateFlaggedSlotBits02085fb4(unsigned char* actor);
int AccumulateFlaggedSlotBits02086020(unsigned char* actor);
int AccumulateFlaggedSlotBits0208608c(unsigned char* actor);
int AccumulateFlaggedSlotBits020860f8(unsigned char* actor);
int AccumulateFlaggedSlotBits02086164(unsigned char* actor);
int AccumulateFlaggedSlotBits020861d0(unsigned char* actor);
int AccumulateFlaggedSlotBits0208623c(unsigned char* actor);
int AccumulateSlotBitsFromTable020862a8(unsigned char* obj);
int AccumulateSlotBitsFromTable02086314(unsigned char* obj);
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
        int delta = AccumulateFlaggedSlotBits02085fb4(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x91c - SlotDataRegionOffset))->f0 + row->w0.f0;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w0.f0 += clamped;
        result = clamped;
        break;
    }
    case 423: {
        int delta = AccumulateFlaggedSlotBits02086020(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x91c - SlotDataRegionOffset))->f1 + row->w0.f1;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w0.f1 += clamped;
        result = clamped;
        break;
    }
    case 424: {
        int delta = AccumulateFlaggedSlotBits0208608c(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x91c - SlotDataRegionOffset))->f2 + row->w0.f2;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w0.f2 += clamped;
        result = clamped;
        break;
    }
    case 422: {
        int delta = AccumulateFlaggedSlotBits020860f8(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x920 - SlotDataRegionOffset))->f0 + row->w1.f0;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w1.f0 += clamped;
        result = clamped;
        break;
    }
    case 428: {
        int delta = AccumulateFlaggedSlotBits02086164(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x920 - SlotDataRegionOffset))->f1 + row->w1.f1;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w1.f1 += clamped;
        result = clamped;
        break;
    }
    case 426: {
        int delta = AccumulateFlaggedSlotBits020861d0(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x920 - SlotDataRegionOffset))->f2 + row->w1.f2;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w1.f2 += clamped;
        result = clamped;
        break;
    }
    case 425: {
        int delta = AccumulateFlaggedSlotBits0208623c(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x924 - SlotDataRegionOffset))->f0 + row->w2.f0;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 2, 999);
        row->w2.f0 += clamped;
        result = clamped;
        break;
    }
    case 262: {
        int delta = AccumulateSlotBitsFromTable020862a8(obj);
        int sum = delta + ((struct BitTriple10*)(obj + 0x924 - SlotDataRegionOffset))->f1 + row->w2.f1;
        unsigned int clamped = ClampLengthToMax((unsigned int)obj, sum, 3, 999);
        row->w2.f1 += clamped;
        result = clamped;
        break;
    }
    case 263: {
        int delta = AccumulateSlotBitsFromTable02086314(obj);
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
