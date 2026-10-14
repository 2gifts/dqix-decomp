#include <globaldefs.h>

void CopyStringBounded_020464a4(char* src, char* dst, int size);

// USA: func_020464e8
ARM void CopyStringToIndexedField0x2ec_020464e8(char* base, int index, char* src) {
    CopyStringBounded_020464a4(src, base + 0x2ec + index * 0x40, 0x40);
}
