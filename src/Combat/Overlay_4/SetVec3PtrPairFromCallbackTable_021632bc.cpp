#include <globaldefs.h>

extern "C" void* func_ov004_0215e47c(void* a, int key);
void* GetCallbackTableAndCount_02184a30(void* obj, unsigned int* outCount);

struct Node021632bc {
    char pad[0x1868];
    void* vecA;
    void* vecB;
};

// USA: func_ov004_021632bc  (semantic: SetVec3PtrPairFromCallbackTable_021632bc)
extern "C" ARM int func_ov004_021632bc(void* self) {
    Node021632bc* node = (Node021632bc*)func_ov004_0215e47c(self, 0x82);
    if (node == NULL) return 0;
    unsigned int count = 0;
    char* table = (char*)GetCallbackTableAndCount_02184a30(self, &count);
    node->vecA = table + 0x2c;
    node->vecB = table + 0x30;
    return 0;
}
