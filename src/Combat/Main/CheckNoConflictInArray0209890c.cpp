#include <globaldefs.h>

extern "C" int func_02001aec(void* a, void* b, int n);

struct IdentityRecord {
    unsigned char unknown0[0x14];
    unsigned char identity[6];
    unsigned char unknown1a[0x6c - 0x1a];
    unsigned int unknown6c : 26;
    unsigned int eligible : 1;
    unsigned int unknown6cHigh : 5;
    unsigned char unknown70[0xe8 - 0x70];
};

#if defined(jpn)
#define CheckNoConflictInArray0209890c func_0209a55c
extern "C" ARM int CheckNoConflictInArray0209890c(void* arr, void* obj);
#endif

// USA: func_0209890c
ARM int CheckNoConflictInArray0209890c(void* arr, void* obj) {
    IdentityRecord* records = static_cast<IdentityRecord*>(arr);
    IdentityRecord* candidate = static_cast<IdentityRecord*>(obj);
    int i;
    if (!candidate->eligible) {
        return 0;
    }
    for (i = 0; i < 30; i++) {
        if (func_02001aec(records[i].identity, candidate->identity, sizeof(candidate->identity)) == 0) {
            return 0;
        }
    }
    return 1;
}
