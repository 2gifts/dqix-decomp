#include <globaldefs.h>

struct TimingPair {
    int first;
    int second;
};

extern "C" int func_ov031_0220783c(TimingPair*, int, unsigned long long);
extern "C" unsigned long long func_0200cf24(long long, long long);

// USA: func_ov031_0221e54c
extern "C" THUMB int func_ov031_0221e54c(void* unused, const TimingPair* request, int unused2, int unused3, const TimingPair* duration) {
    TimingPair parameters = *request;
    unsigned long long ticks = 0;
    ticks += func_0200cf24(duration->first, 0x1ff6210) >> 6;
    ticks += func_0200cf24(duration->second, 0x1ff6210) >> 6;
    return func_ov031_0220783c(&parameters, 1, ticks);
}
