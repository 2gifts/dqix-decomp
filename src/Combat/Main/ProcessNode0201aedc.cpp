#include <globaldefs.h>
#include "Graphics/LightingManager.h"

int IsValueInRange0201b5d8(int x);

struct Obj020196fc;
struct Node020196fc;
Node020196fc* GetNodeAtDepth020196fc(Obj020196fc* obj, int count);


struct Obj02052338;

void ClearGlobalFlagBits02016d8c(void* arg0);

struct Vec3Block020b3850;
extern "C" void _ZN12RenderConfig17SetObjectPositionEP8Vector3i(Vec3Block020b3850* src);

extern "C" void _ZN12RenderConfig12SubmitToFifoEv(void);

extern "C" void _ZN7Model3D4DrawEb(void* a, int b);

struct Ctx0201aedc { unsigned short field0; };


#if defined(jpn)
enum { NodeBufferOffset = 0x25f4 };
#else
enum { NodeBufferOffset = 0x25b4 };
#endif

// JPN: func_0201ac7c
// USA: func_0201aedc
ARM void ProcessNode0201aedc(Ctx0201aedc* p) {
    if (IsValueInRange0201b5d8(p->field0)) return;

    char* buf = (char*)p + NodeBufferOffset;

    Node020196fc* node = GetNodeAtDepth020196fc((Obj020196fc*)p, 5);
    if (node != 0) {
        void* ptr1 = *(void**)((char*)node + 0x44);
        unsigned short flags = *(unsigned short*)((char*)ptr1 + 2);
        if (!(flags & 4)) {
            void* ptr2 = *(void**)((char*)ptr1 + 0x24);
            void* r6 = *(void**)((char*)ptr2 + 4);
            if (r6 != 0 && *(int*)((char*)r6 + 0x54) != 0) {
                void* obj = LightingManager::GetInstance();
                int arg1 = *(int*)((char*)r6 + 0x54);
                ((LightingManager*)((Obj02052338*)obj))->ApplyAmbientColorToModel((NSBXXInternalModel*)(arg1));
                ClearGlobalFlagBits02016d8c(buf + 0x48);
                _ZN12RenderConfig17SetObjectPositionEP8Vector3i((Vec3Block020b3850*)(buf + 0x6c));
                _ZN12RenderConfig12SubmitToFifoEv();
                _ZN7Model3D4DrawEb(r6, 1);
            }
        }
    }

    Node020196fc* node2 = GetNodeAtDepth020196fc((Obj020196fc*)p, 4);
    if (node2 == 0) return;
    void* ptr1b = *(void**)((char*)node2 + 0x44);
    unsigned short flagsb = *(unsigned short*)((char*)ptr1b + 2);
    if (flagsb & 4) return;
    void* ptr2b = *(void**)((char*)ptr1b + 0x24);
    void* r5v = *(void**)((char*)ptr2b + 4);
    if (r5v != 0 && *(int*)((char*)r5v + 0x54) != 0) {
        void* obj2 = LightingManager::GetInstance();
        int arg1b = *(int*)((char*)r5v + 0x54);
        ((LightingManager*)((Obj02052338*)obj2))->ApplyAmbientColorToModel((NSBXXInternalModel*)(arg1b));
        ClearGlobalFlagBits02016d8c(buf + 0x14);
        _ZN12RenderConfig17SetObjectPositionEP8Vector3i((Vec3Block020b3850*)(buf + 0x38));
        _ZN12RenderConfig12SubmitToFifoEv();
        _ZN7Model3D4DrawEb(r5v, 1);
    }
}
