#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void ResetFieldWithLog_0218d5c8(unsigned char* obj);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
int GetFieldIfFlag4_020100f8(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
extern AllocatorUnion data_02114e20;

// USA: func_ov017_021bf490  (semantic: ResetAllocatorsAndFlags_021bf490)
extern "C" ARM void func_ov017_021bf490(void* objRaw) {
    unsigned char* obj = (unsigned char*)objRaw;
    SafeAllocator* allocA = (SafeAllocator*)(obj + 0x34);
    SafeAllocator* allocB = (SafeAllocator*)(obj + 0x4c);

    void* ov = func_ov017_0218b5b0();
    unsigned char field48 = obj[0x48];
    if (field48 != 0 && ov != NULL) {
        ResetFieldWithLog_0218d5c8((unsigned char*)ov);
        obj[0x48] = 0;
    }

    SignedAllocatorHeader* h1 = allocA->GetSignedAllocator();
    if (h1 != NULL) {
        allocA->Destroy();
        TailForward02012da4(&data_02114e20, h1);
    }

    SignedAllocatorHeader* h2 = allocB->GetSignedAllocator();
    if (h2 != NULL) {
        allocB->Destroy();
        TailForward02012da4(&data_02114e20, h2);
    }

    int flagResult = GetFieldIfFlag4_020100f8((char*)GameState::GetInstance());
    if (flagResult != 0) {
        SetField0x23cTrue_020a27ac((void*)flagResult);
    }

    if (ov == NULL) return;
    ClearBitsInField4_0203b4e8((unsigned int*)ov, 0x80);
}
