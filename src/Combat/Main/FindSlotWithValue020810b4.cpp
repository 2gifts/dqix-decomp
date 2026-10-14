#include <globaldefs.h>

void* GetElementStride0x18_0207f100(unsigned char* obj, short index);

// USA: func_020810b4
ARM void* FindSlotWithValue020810b4(unsigned char* self, short val) {
    short count = *(short*)(self + 0x10);
    short i;
    for (i = 0; i < count; i++) {
        unsigned char* rec = (unsigned char*)GetElementStride0x18_0207f100(self + 0xc, i);
        if (rec == NULL) {
            continue;
        }
        {
            unsigned char j = 0;
            while (j < rec[0x13]) {
                short* arr = *(short**)(rec + 0);
                if (val == arr[j]) {
                    return rec;
                }
                j = j + 1;
            }
        }
    }
    return NULL;
}
