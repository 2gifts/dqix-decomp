#include <globaldefs.h>

struct Struct0205d888 {
    char pad0[0x98];
    int field98;
    void* field9C;
    char pad1[0x14];
    unsigned char fieldB4;
};
void* GetLastEntry0205d888(struct Struct0205d888* p);
int IsField0x9cEqual3_0204c7cc(unsigned char* obj);
void SetFieldAt0x30_0205bc24(void* obj, int value);

// USA: func_ov000_02175440
ARM void UpdateLastEntryField02175440(void* obj) {
    void* entry = GetLastEntry0205d888((struct Struct0205d888*)((char*)obj + 0x188));
    if (entry == 0) return;
    if (!IsField0x9cEqual3_0204c7cc((unsigned char*)entry)) return;
    if (((unsigned char*)entry)[0xc5] & 0x2) return;
    SetFieldAt0x30_0205bc24((char*)obj + 0x18c, -1);
}
