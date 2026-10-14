#include <globaldefs.h>

void RestorePairTableFromBuffer_020bb740(int* out);
void WriteGlobalPair020bb92c(int* src);

// USA: func_0207df90
ARM void RestorePairTables0207df90(char* obj) {
    RestorePairTableFromBuffer_020bb740((int*)(obj + 0x28));
    WriteGlobalPair020bb92c((int*)(obj + 0x60));
}
