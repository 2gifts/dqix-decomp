#include <globaldefs.h>

extern char data_0210f844;

// USA: func_020bbf34
ARM void SetEntryByte_020bbf34(int index, int value) {
    (&data_0210f844)[index * 0x24] = (char)value;
}
