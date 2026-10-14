#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"

extern "C" int func_02032fdc(void* obj, void* param1, int flag);
void* GetPtrField0x144(void* obj);
extern "C" void func_020ca528(void* ptr, void* addr);

struct Vec3Block020b3850 { unsigned int v[3]; };
extern "C" void _ZN12RenderConfig17SetObjectPositionEP8Vector3i(struct Vec3Block020b3850* src);

struct Vec3Block020b3880 { unsigned int v[3]; };
extern "C" void _ZN12RenderConfig14SetObjectScaleEP8Vector3i(struct Vec3Block020b3880* src);

extern "C" void _ZN12RenderConfig12SubmitToFifoEv(void);

extern "C" void func_02047448(int a, int b, int c);

extern int data_0210a0cc;
struct FlagRegs02076bec { unsigned char pad[0xfc]; unsigned int flags; };
extern struct FlagRegs02076bec data_0210a010;
extern int data_020e8920;

// USA: func_02076bec
ARM int TickActorFlagStateAndDispatch02076bec(unsigned char* obj, void* param1) {
    if (!((Object3D*)obj)->IsVisible()) {
        return 0;
    }

    int result = func_02032fdc(obj, param1, 0);
    if (*(unsigned char*)(obj + 0x17a) == 0) {
        return result;
    }

    GameState* battleStruct = GameState::GetInstance();
    void* f3b0 = GetField0x3b0Value(battleStruct);

    struct Vec3Block020b3850 localBuf = *(struct Vec3Block020b3850*)(obj + 0x44);
    localBuf.v[1] = *(unsigned int*)(obj + 0x170);
    _ZN12RenderConfig17SetObjectPositionEP8Vector3i(&localBuf);

    if (f3b0 != 0) {
        void* ptr = GetPtrField0x144(f3b0);
        func_020ca528(ptr, &data_0210a0cc);
        data_0210a010.flags &= ~0xa4;
    }

    struct Vec3Block020b3880 localBuf2 = *(struct Vec3Block020b3880*)&data_020e8920;
    _ZN12RenderConfig14SetObjectScaleEP8Vector3i(&localBuf2);
    _ZN12RenderConfig12SubmitToFifoEv();

    func_02047448(*(int*)(obj + 0x16c), 0, 1);
    return result;
}
