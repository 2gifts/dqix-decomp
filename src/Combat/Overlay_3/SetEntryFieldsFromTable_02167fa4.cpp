#include <globaldefs.h>

int SetEntryFlagById02080b40(void* obj, int id);
int SetEntryFlagById02080b2c(void* obj, int id);
void SetEntryHalfword0xe(void* obj, int id, int value);
void SetSublistEntryField14LowBits_02080798(void* obj, int id, int value);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);
ARM int GetTableByte020dd11c(unsigned int a, unsigned int b);

// JPN: func_ov003_02167e38
// USA: func_ov003_02167fa4  (semantic: SetEntryFieldsFromTable_02167fa4)
extern "C" ARM void func_ov003_02167fa4(void* arg0, int flag, unsigned char* table) {
    void* obj = *(void**)((char*)arg0 + 0x10);
    int idA = 0x1f;
    int idB = 0x24;
    for (unsigned char k = 0; k < 5; k++) {
        if (flag == 0) {
            SetEntryFlagById02080b2c(obj, idA);
            SetEntryFlagById02080b2c(obj, idB);
        } else {
            SetEntryFlagById02080b40(obj, idA);
            SetEntryFlagById02080b40(obj, idB);
            int t = GetTableByte020dd11c(flag, k);
            short adj = (short)(t + 0x26);
            unsigned char byteVal = table[t];
            int nibble = 0xf;
            if (byteVal == 0x64) nibble = 0xd;
            SetEntryHighNibble0x13((struct Container02080cc0*)obj, idB, nibble);
            SetEntryHalfword0xe(obj, idA, adj);
#if !defined(jpn)
            SetSublistEntryField14LowBits_02080798(obj, idA, 1);
#endif
            SetEntryFirstField02080fa8((struct Container02080fa8*)obj, idB, byteVal);
        }
        idA = (short)(idA + 1);
        idB = (short)(idB + 1);
    }
}
