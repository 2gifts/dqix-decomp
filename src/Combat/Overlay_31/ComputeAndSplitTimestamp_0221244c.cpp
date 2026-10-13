#include <globaldefs.h>

extern void* data_ov031_0224e688;
extern long long data_ov031_0224e68c;
extern long long data_ov031_0224e694;

int GetOrInitStoredValueAt0x2c(void* a, void* b);
long long ComputeEntryByteOffset(int arg0, unsigned char* arg1);
struct TimeOfDay020cfaf4;
void SplitTimestampIntoDateAndTime(void* datePtr, struct TimeOfDay020cfaf4* timePtr, long long timestamp);

// USA: func_ov031_0221244c  (semantic: ComputeAndSplitTimestamp_0221244c)
extern "C" ARM int func_ov031_0221244c(void* date, void* time) {
    if (data_ov031_0224e688 == NULL) return 0;
    if (GetOrInitStoredValueAt0x2c(date, time) != 0) return 0;
    long long offset = ComputeEntryByteOffset((int)date, (unsigned char*)time);
    if (offset == -1LL) return 0;
    if (offset < data_ov031_0224e68c) {
        offset += 0xbc191380LL;
    }
    long long adjusted = offset - data_ov031_0224e694;
    if (adjusted < 0LL || adjusted > 0xbc19137fLL) return 0;
    SplitTimestampIntoDateAndTime(date, (struct TimeOfDay020cfaf4*)time, adjusted);
    return 1;
}
