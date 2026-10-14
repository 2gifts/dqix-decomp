#include <globaldefs.h>

// USA: func_0205c710
ARM unsigned int SelectField0x18Or0x68ByFlags_0205c710(unsigned char* obj) {
    unsigned int result = 0;
    if (obj[0x94] && obj[0x50]) result = *(unsigned int*)(obj + 0x18);
    if (obj[0x95]) result = *(unsigned int*)(obj + 0x68);
    return result;
}
