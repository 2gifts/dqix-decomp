#include <globaldefs.h>

#if defined(jpn)
extern const char* data_020f2bcc;
extern "C" int func_020e2168(char* destination, const char* tablePath,
    int index, int variant, bool lock);
extern "C" void* func_020e0968(const char* filename, unsigned int* outLength);

// JPN: func_020e08f0
extern "C" ARM void* func_020e08f0(int index, unsigned int* outLength) {
    *outLength = 0;
    if (index < 0 || index > 12)
        return 0;
    char path[0x20] = {0};
    if (index == 9)
        index = 8;
    func_020e2168(path, data_020f2bcc, index, 0, true);
    return func_020e0968(path, outLength);
}
#endif
