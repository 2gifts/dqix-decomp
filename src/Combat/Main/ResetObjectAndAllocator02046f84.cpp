#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

int GetWord0x0(int* obj);
void SetField0x7cClearFields0x1ec0x1ee(unsigned char* obj, unsigned short val);
struct AngleTrig0202e9a4;
void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4* objParam, int angle);
extern "C" void func_0202eab8(void* obj);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int data_02114e20;

struct Struct02046f84 {
    int field0;
    int field4;
    char pad[0x24 - 8];
    SafeAllocator allocator;
    int field38;
};

// USA: func_02046f84
ARM void ResetObjectAndAllocator02046f84(struct Struct02046f84* s) {
    GameState* battleStruct = GameState::GetInstance();
    GetWord0x0((int*)battleStruct);
    void* obj = GetField0x3b0Value(battleStruct);
    SetField0x7cClearFields0x1ec0x1ee((unsigned char*)obj, 0);
    SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)obj, 0xf000);
    func_0202eab8(obj);

    if (s->field38 == 0) {
        void* p = s->allocator.GetSignedAllocator();
        if (p != NULL) {
            s->allocator.Reset();
            s->allocator.Destroy();
            TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
        }
    }
    s->field0 = 0;
    s->field4 = 0;
}
