#include <globaldefs.h>

extern "C" void* func_0205ec34(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);

#if defined(jpn)
#define SetFlag0x8eIfBitTestFails func_02023464
extern "C" ARM int func_02023464(char* base, int index);
enum { kEntryBase = 0x600, kPresentOffset = 0xe0, kStateOffset = 0xde, kIndexOffset = 0xd8, kFlagOffset = 0xe2 };
#else
enum { kEntryBase = 0x700, kPresentOffset = 0x8c, kStateOffset = 0x8a, kIndexOffset = 0x84, kFlagOffset = 0x8e };
#endif

// USA: func_02023a9c
ARM int SetFlag0x8eIfBitTestFails(char* base, int index) {
    void* g = func_0205ec34();
    int offset = index * 0x1c;
    char* entry = base;
    entry += offset;
    entry += kEntryBase;

    unsigned short f8c = *(unsigned short*)(entry + kPresentOffset);
    if (f8c == 0) return 0;

    unsigned short f8a = *(unsigned short*)(entry + kStateOffset);
    if (f8a == 0) {
        unsigned short f84 = *(unsigned short*)(entry + kIndexOffset);
        if (TestBitInByteArray((int)g, (unsigned char*)g + 0x8c, f84 + 0x12 + 0x200)) {
            char* entry2 = base;
            entry2 += offset;
            entry2 += kEntryBase;
            *(unsigned short*)(entry2 + kFlagOffset) = 0;
            return 0;
        }
    }
    return 1;
}
