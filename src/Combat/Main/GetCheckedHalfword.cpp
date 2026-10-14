#include <globaldefs.h>

// USA: func_0209c0a8
ARM int GetCheckedHalfword_0209c0a8(void* obj, int index) {
    if (*(unsigned short*)((char*)obj + 0x18) <= index) {
        return -1;
    }
    return ((unsigned short*)obj)[index];
}
