// JPN: func_ov017_02199f10
#if defined(jpn)
enum { RegionOffset36b8 = 0x34a8, RegionOffset36bc = 0x34ac, RegionOffset2774 = 0x27b4, RegionOffset2780 = 0x27c0, RegionOffset2788 = 0x27c8 };
#else
enum { RegionOffset36b8 = 0x36b8, RegionOffset36bc = 0x36bc, RegionOffset2774 = 0x2774, RegionOffset2780 = 0x2780, RegionOffset2788 = 0x2788 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_0202c508(void* state);
void* GetField0x3f8Address(GameState* battleStruct);
struct PointerField32c_ffc0;
void* GetPointerAt0x32c(struct PointerField32c_ffc0* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
void InitStruct02070378(char* obj);
extern "C" void func_ov017_021d1a18(int a, int b, int c, int d);

// USA: func_ov017_02199360  (semantic: ConfigureFieldByFlag36b8_02199360)
extern "C" ARM void func_ov017_02199360(void* obj) {
    if (!*(unsigned char*)((char*)obj + RegionOffset36b8)) return;

    GameState* battleStruct = GameState::GetInstance();
    void* state = func_0202ae18();
    void* base = func_02012fe4();
    void* src = *(void**)((char*)obj + RegionOffset36bc);
    void* fieldPtr = GetField0x3f8Address(battleStruct);
    void* ptr32c = GetPointerAt0x32c((struct PointerField32c_ffc0*)battleStruct);

    if (func_0202c508(state)) {
        _ZN8Vector3iaSERKS_((int*)((char*)base + RegionOffset2774), (int*)((char*)src + 0x40));
        *(int*)((char*)base + RegionOffset2780) = *(short*)((char*)src + 0x4c);
        InitStruct02070378((char*)fieldPtr);
        *(short*)((char*)fieldPtr + 0x0) = 0x2710;
        ((char*)fieldPtr)[0x2] = 1;
        ((char*)fieldPtr)[0x7] = 1;
        _ZN8Vector3iaSERKS_((int*)((char*)fieldPtr + 0x10), (int*)((char*)ptr32c + 0x44));
        *(short*)((char*)fieldPtr + 0x1c) = *(int*)((char*)ptr32c + 0x54);
        ((char*)base)[RegionOffset2788] = 1;
        func_ov017_021d1a18(1, -1, 1, 0);
    } else {
        InitStruct02070378((char*)fieldPtr);
        *(short*)((char*)fieldPtr + 0x0) = 0x170c;
        ((char*)fieldPtr)[0x2] = 1;
        ((char*)fieldPtr)[0x7] = 1;
        *(int*)((char*)fieldPtr + 0x10) = -0x7000;
        *(int*)((char*)fieldPtr + 0x14) = 0x2e1;
        *(int*)((char*)fieldPtr + 0x18) = 0x5e66;
        *(short*)((char*)fieldPtr + 0x1c) = 0x3244;
    }
}
