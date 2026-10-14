#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};

struct BoundedArray {
    unsigned short items[0xc];
    unsigned short count;
};
void AppendHalfwordCapped(struct BoundedArray* s, unsigned short value);

struct MessageState0209bed8 {
    struct BoundedArray* text;
    unsigned short current;
    unsigned short expectedId;
    void* script;
};

extern struct MessageState0209bed8* data_02109bc8;

// USA: func_0209bed8
extern "C" ARM bool func_0209bed8(struct Variant02030b0c* args, int argCount) {
    if (data_02109bc8->script == 0) {
        return true;
    }
    int id = ((Script::Parameter*)args)->ToInt();
    if (id != data_02109bc8->expectedId) {
        return true;
    }

    struct Variant02030b0c* range = args + 1;
    args += 2;
    int packed = ((Script::Parameter*)range)->ToInt();
    int firstHigh = (packed >> 24) & 0xf;
    int firstLow = (packed >> 16) & 0xf;
    int lastHigh = (packed >> 8) & 0xf;
    int lastLow = packed & 0xf;
    int first = firstHigh * 100 + firstLow;
    int last = lastHigh * 100 + lastLow;

    int matched = 0;
    if (first <= data_02109bc8->current && data_02109bc8->current <= last) {
        data_02109bc8->script = 0;
        matched = 1;
    } else if (firstHigh == 0 && firstLow == 0 && lastHigh == 0 && lastLow == 0) {
        matched = 1;
    }
    if (matched != 0) {
        for (int i = 0; i < argCount - 2; i++) {
            int value = ((Script::Parameter*)args)->ToInt();
            args++;
            unsigned short high = (unsigned short)(value >> 16);
            unsigned short low = (unsigned short)value;
            if (high != 0) {
                AppendHalfwordCapped(data_02109bc8->text, high);
            }
            if (low != 0) {
                AppendHalfwordCapped(data_02109bc8->text, low);
            }
        }
    }
    return true;
}
