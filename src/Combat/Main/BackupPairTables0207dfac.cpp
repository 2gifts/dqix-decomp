#include <globaldefs.h>

void BackupPairTableToBuffer_020bb700(int* out);
void ReadGlobalPair020bb910(int* dst);

// USA: func_0207dfac
ARM void BackupPairTables0207dfac(char* obj) {
    BackupPairTableToBuffer_020bb700((int*)(obj + 0x28));
    ReadGlobalPair020bb910((int*)(obj + 0x60));
}
