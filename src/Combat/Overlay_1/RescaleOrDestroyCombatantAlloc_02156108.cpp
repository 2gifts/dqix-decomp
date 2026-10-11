#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { globalOffset = 0x4c };
#else
enum { globalOffset = 0x8c };
#endif

char* GetGlobalField0x1c020421a0(void);
void SetFlag0x2IfByte0xd4Not3(unsigned char* obj);
extern "C" void func_0208bb78(void* obj, int count);
struct StructAllocGroup0208ba54;
void DestroyStructAllocGroup0208ba54(struct StructAllocGroup0208ba54*);
unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);
int GetGlobal02109400(void);
extern "C" void _Z21BlankFunction02094b40v(int val);
extern "C" void func_02094ab0(int val);
extern "C" void _Z21BlankFunction02094b34v(int val, int f20, int f24, unsigned char f28, unsigned char f29);
int StoreArgIfMatched_02153948(unsigned short arg);

struct Obj02156108 {
    char pad0[0xa];
    unsigned short field0xa;
    char pad1[0x42];
    unsigned short field0x4e;
    unsigned short flags0x50;
#if defined(jpn)
    char pad2[0xa8];
#else
    char pad2[0xac];
#endif
    unsigned char field0xfe;
    char pad3[0x21];
    void* field0x120;
};

// USA: func_ov001_02156108  (semantic: RescaleOrDestroyCombatantAlloc_02156108)
extern "C" ARM int func_ov001_02156108(struct Obj02156108* self) {
    GameState* battle = GameState::GetInstance();
    char* g6 = GetGlobalField0x1c020421a0();
    unsigned int* obj17 = (unsigned int*)((int)func_ov017_0218b5b0());

    if ((self->flags0x50 & 0x2) || (self->flags0x50 & 0x8)) {
        void* ptr = self->field0x120;
        if (ptr) {
            if (*(short*)((char*)ptr + 0xd2) >= 0) {
                SetFlag0x2IfByte0xd4Not3((unsigned char*)ptr);
                unsigned int scaleCount = battle->GetTickCount();
                func_0208bb78(self->field0x120, scaleCount);
                return self->field0xa;
            }
            DestroyStructAllocGroup0208ba54((struct StructAllocGroup0208ba54*)ptr);
        }
        *(int*)(g6 + globalOffset) = 0;
        self->field0x120 = 0;
    }

    if (GetBitsInField0(obj17, 0x1000) == 0) {
        int val = GetGlobal02109400();
        _Z21BlankFunction02094b40v(val);
        func_02094ab0(val);
        _Z21BlankFunction02094b34v(val, 0x6f, 0x1388, 1, 1);
    }
    self->field0xfe = 0;
    StoreArgIfMatched_02153948(self->field0x4e);
    return 0xb;
}
