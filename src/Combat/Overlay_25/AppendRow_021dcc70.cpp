#include <globaldefs.h>

struct FiveWordsAndByte_021dcd28;
extern void CopyFiveWordsAndByte_021dcd28(FiveWordsAndByte_021dcd28* dst, FiveWordsAndByte_021dcd28* src);

#if defined(jpn)
#define ROW_COUNT 0x703d
#define ROW_DATA 0x7040
#define ROW_BASE 0x7000
#define ROW_FIELD(n) ((n) - 0x10)
#else
#define ROW_COUNT 0x6e4d
#define ROW_DATA 0x6e50
#define ROW_BASE 0x6e00
#define ROW_FIELD(n) (n)
#endif

// JPN: 021dd564
// USA: func_ov025_021dcc70
ARM void AppendRow_021dcc70(char* obj, char* src) {
    unsigned char count = *(unsigned char*)(obj + ROW_COUNT);
    if (count >= 5) return;

    char* dst = obj + ROW_DATA + (count << 5);
    CopyFiveWordsAndByte_021dcd28((FiveWordsAndByte_021dcd28*)dst, (FiveWordsAndByte_021dcd28*)src);

    unsigned char idx = *(unsigned char*)(obj + ROW_COUNT);
    short v0 = *(short*)(src + 0x18);
    *(short*)(obj + ROW_BASE + (idx << 5) + ROW_FIELD(0x68)) = v0;

    idx = *(unsigned char*)(obj + ROW_COUNT);
    short v1 = *(short*)(src + 0x1a);
    *(short*)(obj + ROW_BASE + (idx << 5) + ROW_FIELD(0x6a)) = v1;

    idx = *(unsigned char*)(obj + ROW_COUNT);
    *(short*)(obj + ROW_BASE + (idx << 5) + ROW_FIELD(0x6c)) = 0;

    idx = *(unsigned char*)(obj + ROW_COUNT);
    *(short*)(obj + ROW_BASE + (idx << 5) + ROW_FIELD(0x6e)) = 0;

    idx = *(unsigned char*)(obj + ROW_COUNT);
    if (idx != 0) {
        unsigned short prev = *(unsigned short*)(obj + ROW_BASE + ((idx - 1) << 5) + ROW_FIELD(0x6c));
        *(unsigned short*)(obj + ROW_BASE + (idx << 5) + ROW_FIELD(0x6e)) = prev;
    }

    unsigned char c = *(unsigned char*)(obj + ROW_COUNT);
    *(unsigned char*)(obj + ROW_COUNT) = c + 1;
}
