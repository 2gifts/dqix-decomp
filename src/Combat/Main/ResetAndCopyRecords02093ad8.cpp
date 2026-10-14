#include <globaldefs.h>

struct CopyPayload {
#if defined(jpn)
    char data[11];
#else
    char data[48];
#endif
};

struct CopyableRecord {
    CopyPayload payload;
#if defined(jpn)
    unsigned char unknownB;
#endif
    short requestId;
    signed char partySlot;
    unsigned char flags;
};

void ClearRegion02093980(char* storage);
void CopyRecord_02093b54(CopyableRecord* destination, CopyableRecord* source);

// USA: func_02093ad8  (semantic: ResetAndCopyRecords02093ad8)
extern "C" ARM void func_02093ad8(void* unused, CopyableRecord* source, CopyableRecord* destination, int count) {
    int i;
    for (i = 0; i < 8; i++) {
        ClearRegion02093980((char*)(destination + i));
    }
    int j;
    for (j = 0; j < count; j++) {
        CopyRecord_02093b54(destination + j, source + j);
    }
    int k;
    for (k = 0; k < 8; k++) {
        ClearRegion02093980((char*)(source + k));
    }
}
