#include <globaldefs.h>

#if defined(jpn)
#define data_020fdcce data_020fda36
#define LIST_VALUES 0x6ac
#define LIST_COUNT 0x6b0
#else
#define LIST_VALUES 0x758
#define LIST_COUNT 0x75c
#endif
extern unsigned char data_020fdcce;

// USA: func_02026348
ARM void StoreByteList02026348(char* obj, unsigned char* src, int count) {
    int i;
    if ((unsigned int)count > 4) {
        obj[LIST_COUNT] = 0;
        return;
    }
    for (i = 0; i < count; i++) {
        char* p = obj + i;
        unsigned char b = src[i];
        p[LIST_VALUES] = b;
        (&data_020fdcce)[b << 5] = 1;
    }
    obj[LIST_COUNT] = count;
}

// JPN: 0x02025d1c
