#include <globaldefs.h>

extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(void*, int);
extern "C" void _Z26InitAllocatorArray02186e74P17Container02186e74P13SafeAllocator(void*, void*);
int GetField110ArrayValue021574d4(void*, int);
void SetPendingFlagAndSync_0215a878(char*);
void ResetAllocatorsAndClearFields0215b428(unsigned char*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void func_ov013_02186eec(void*, int);

// USA: func_ov002_021682c0  (semantic: Trans_021682c0)
extern "C" ARM void func_ov002_021682c0(char* self) {
    *(unsigned int*)(self + 0x247c) &= ~0x4;
    SetPendingFlagAndSync_0215a878(self);
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(self + 0xec8, 1);
    *(unsigned char*)(self + 0x2454) = 0;
    *(unsigned char*)(self + 0x2455) = 0;
    ResetAllocatorsAndClearFields0215b428((unsigned char*)self);
    _ZN13SafeAllocator5ResetEv(self + 0x850);
    func_ov013_02186eec(self + 0x1d04, 1);
    _Z26InitAllocatorArray02186e74P17Container02186e74P13SafeAllocator(self + 0x1d04, self + 0x850);
    *(unsigned char*)(self + 0x1d6b) = GetField110ArrayValue021574d4(self, *(short*)(self + 0x1c08));
    (*(int*)(self + 0x1bc0))++;
}
