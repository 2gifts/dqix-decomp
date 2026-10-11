#include <globaldefs.h>
#if defined(jpn)
enum { kAllocatorOffset = 0x24 };
#else
enum { kAllocatorOffset = 0x58 };
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

void SetByteField0x253(void* obj);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern int data_02114e20;

struct Obj020d9d60 {
    char pad[kAllocatorOffset];
    SafeAllocator allocator;   // kAllocatorOffset
};

// USA: func_020d9d60
ARM void ShutdownObject020d9d60(struct Obj020d9d60* self) {
    SetByteField0x253((void*)GameState::GetInstance()->GetUnknownGameObject());
    ClearBitsInWord((unsigned int*)((int)func_ov017_0218b5b0()), 0x10);
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0xe);
    void* p = self->allocator.GetSignedAllocator();
    if (p == NULL) return;
    self->allocator.Destroy();
    TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
}
