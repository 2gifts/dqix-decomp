#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Graphics/NSBXX/RenderConfig.h"

extern "C" int func_02032fdc(void* obj, void* param1, int flag);
void* GetPtrField0x144_0202ed74(void* obj);
extern "C" void func_020ca528(void* ptr, void* addr);

extern "C" void func_02047448(int a, int b, int c);

extern int data_0210a0cc;
extern Vector3i data_020e8920;

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
    void* f3b0 = GetField0x3b0Value_020100bc(battleStruct);

    Vector3i localBuf = *(Vector3i*)(obj + 0x44);
    localBuf.y = *(int*)(obj + 0x170);
    RenderConfig::SetObjectPosition(&localBuf);

    if (f3b0 != 0) {
        void* ptr = GetPtrField0x144_0202ed74(f3b0);
        func_020ca528(ptr, &data_0210a0cc);
        data_0210a010.flags &= ~0xa4;
    }

    Vector3i localBuf2 = data_020e8920;
    RenderConfig::SetObjectScale(&localBuf2);
    RenderConfig::SubmitToFifo();

    func_02047448(*(int*)(obj + 0x16c), 0, 1);
    return result;
}
