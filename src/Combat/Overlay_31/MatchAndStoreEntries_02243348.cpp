#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02030b7c {
    int field0;
    void* field4;
};

extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);
int GetOffset10FromResult_0220ec04(int arg);

struct DataBlock02291e04 {
    unsigned char count;
#if defined(jpn)
    unsigned char pad0[3];
#else
    unsigned char pad0[4];
#endif
    unsigned char field5;
#if defined(jpn)
    unsigned char pad1[0x2b];
#else
    unsigned char pad1[0x26];
#endif
    void* entries;
};

extern DataBlock02291e04 data_ov031_02291e04;

// JPN: func_ov031_02243b28
// USA: func_ov031_02243348  (semantic: MatchAndStoreEntries_02243348)
extern "C" ARM int func_ov031_02243348(struct Struct02030b7c* s) {
    void* target = _ZNK6Script9Parameter8ToStringEv(s);
    int matched = 0;
    int i = 0;
    while (i < data_ov031_02291e04.count) {
        int entry = GetOffset10FromResult_0220ec04(i);
        if (strcmp((char*)entry + 0xc, (char*)target) == 0) {
            memcpy((char*)data_ov031_02291e04.entries + matched * 0xc0, (void*)entry, 0xc0);
            matched++;
            if (matched >= 8) break;
        }
        i++;
    }
    data_ov031_02291e04.field5 = matched;
    return 1;
}
