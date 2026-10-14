#include <globaldefs.h>

void BackupPairTableToBuffer_020bb700(int* out);
void ReadGlobalPair020bb910(int* dst);
extern "C" int func_020bb588(unsigned int size, int a, int b);
extern "C" int func_020bb7cc(unsigned int size, int a, int b);

struct Buf0207de48 { unsigned int v[10]; };
struct Pair0207de48 { int v[2]; };
struct PairBackupCtx0207de48 {
    Buf0207de48 bufA;
    Buf0207de48 bufB;
    int checksumA;
    int adjA;
    Pair0207de48 globalPair;
    Pair0207de48 globalPairCopy;
    int checksumB;
    int adjB;
};

// USA: func_0207de48  (semantic: PairBackupAndChecksum0207de48)
extern "C" ARM void func_0207de48(void* pObj, int a, int b) {
    struct PairBackupCtx0207de48* obj = (struct PairBackupCtx0207de48*)pObj;
    BackupPairTableToBuffer_020bb700((int*)&obj->bufA);
    obj->bufB = obj->bufA;
    ReadGlobalPair020bb910(obj->globalPair.v);
    int remaining = a;
    obj->globalPairCopy = obj->globalPair;
    obj->checksumA = 0;

    while (remaining > 0) {
        if (remaining > 0x20000) {
            obj->checksumA = func_020bb588(0x20000, 0, 0);
            remaining -= 0x20000;
        } else {
            obj->checksumA = func_020bb588(remaining, 0, 0);
            remaining = 0;
        }
    }
    if (a != 0 && obj->checksumA == 0) a = 0;

    obj->checksumB = 0;
    if (b != 0) {
        obj->checksumB = func_020bb7cc(b, 0, 0);
    }
    if (b != 0 && obj->checksumB == 0) b = 0;

    obj->adjA = a;
    obj->adjB = b;
}
