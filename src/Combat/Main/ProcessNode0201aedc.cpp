#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "World/Zone3D.h"

int IsValueInRange0201b5d8(int x);

struct Obj02052338;

void ClearGlobalFlagBits02016d8c(void* arg0);

struct Vec3Block020b3850;
extern "C" void _ZN12RenderConfig17SetObjectPositionEP8Vector3i(Vec3Block020b3850* src);

#if defined(jpn)
enum { NodeBufferOffset = 0x25f4 };
#else
enum { NodeBufferOffset = 0x25b4 };
#endif

// USA: func_0201aedc
ARM void ProcessNode0201aedc(Zone3D* p) {
    if (IsValueInRange0201b5d8(p->currentZoneID_)) return;

    char* buf = (char*)p + NodeBufferOffset;

    BmdjScriptNode* node = GetNodeAtDepth020196fc(p, 5);
    if (node != 0) {
        BmdjSceneElement* ptr1 = node->elements;
        unsigned short flags = ptr1->flags;
        if (!(flags & 4)) {
            BmdjElementResource* ptr2 = ptr1->resource;
            Model3D* r6 = ptr2->model;
            if (r6 != 0 && r6->rawInternalModel_ != 0) {
                void* obj = LightingManager::GetInstance();
                NSBXXInternalModel* arg1 = r6->rawInternalModel_;
                ((LightingManager*)((Obj02052338*)obj))->ApplyAmbientColorToModel((NSBXXInternalModel*)(arg1));
                ClearGlobalFlagBits02016d8c(buf + 0x48);
                _ZN12RenderConfig17SetObjectPositionEP8Vector3i((Vec3Block020b3850*)(buf + 0x6c));
                RenderConfig::SubmitToFifo();
                r6->Draw(1);
            }
        }
    }

    BmdjScriptNode* node2 = GetNodeAtDepth020196fc(p, 4);
    if (node2 == 0) return;
    BmdjSceneElement* ptr1b = node2->elements;
    unsigned short flagsb = ptr1b->flags;
    if (flagsb & 4) return;
    BmdjElementResource* ptr2b = ptr1b->resource;
    Model3D* r5v = ptr2b->model;
    if (r5v != 0 && r5v->rawInternalModel_ != 0) {
        void* obj2 = LightingManager::GetInstance();
        NSBXXInternalModel* arg1b = r5v->rawInternalModel_;
        ((LightingManager*)((Obj02052338*)obj2))->ApplyAmbientColorToModel((NSBXXInternalModel*)(arg1b));
        ClearGlobalFlagBits02016d8c(buf + 0x14);
        _ZN12RenderConfig17SetObjectPositionEP8Vector3i((Vec3Block020b3850*)(buf + 0x38));
        RenderConfig::SubmitToFifo();
        r5v->Draw(1);
    }
}
