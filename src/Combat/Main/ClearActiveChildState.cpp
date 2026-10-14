#include <globaldefs.h>

void ClearField0x5cBit0_0203cea4(unsigned int* obj);
struct Struct02041538;
void RefreshSelectionState02041538(struct Struct02041538*);

// USA: func_02040bcc
ARM void ClearActiveChildState_02040bcc(char* self) {
    void* a = *(void**)(self + 0x14);
    if (a != NULL) {
        ClearField0x5cBit0_0203cea4((unsigned int*)a);
        return;
    }
    void* b = *(void**)(self + 0x18);
    if (b == NULL) return;
    RefreshSelectionState02041538((struct Struct02041538*)b);
}
