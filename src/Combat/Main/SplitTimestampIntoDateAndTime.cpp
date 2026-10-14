#include <globaldefs.h>

struct TimeOfDay020cfaf4;
void SplitSecondsIntoTimeOfDay(struct TimeOfDay020cfaf4* out, int time);

extern "C" void func_020cf9f4(void* out, int days);
extern "C" int _ll_mod(unsigned int lo, unsigned int hi, unsigned int divLo, unsigned int divHi);
extern "C" int _ll_sdiv(unsigned int lo, unsigned int hi, unsigned int divLo, unsigned int divHi);

// USA: func_020cfb74
ARM void SplitTimestampIntoDateAndTime_020cfb74(void* datePtr, struct TimeOfDay020cfaf4* timePtr, long long timestamp) {
    if (timestamp < 0) {
        timestamp = 0;
    } else if (timestamp > 0xbc19137fLL) {
        timestamp = 0xbc19137fLL;
    }
    unsigned int lo = (unsigned int)timestamp;
    unsigned int hi = (unsigned int)(timestamp >> 32);
    int secOfDay = _ll_mod(lo, hi, 0x15180, 0);
    SplitSecondsIntoTimeOfDay(timePtr, secOfDay);
    int days = _ll_sdiv(lo, hi, 0x15180, 0);
    func_020cf9f4(datePtr, days);
}
