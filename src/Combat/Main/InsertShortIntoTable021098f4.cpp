#include <globaldefs.h>

#if defined(jpn)
#define data_021098f4 data_021095ac
#endif
extern unsigned short data_021098f4[];
extern void InsertOrShiftShort02099554(unsigned short* arr, unsigned short value);

// USA: func_0209953c
ARM void InsertShortIntoTable021098f4(unsigned short value) {
    InsertOrShiftShort02099554(data_021098f4, value);
}
