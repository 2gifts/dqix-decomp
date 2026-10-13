#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "Graphics/NSBXX/RenderCommandCallbacks.h"
#include "Graphics/NSBXX/GeometryFifo.h"

#define REG_GXFIFO (*(volatile unsigned int*)0x04000400)
struct Bone020e2d54 { unsigned short flags; char pad_2[0xa]; int scaleZ; };
struct Output020e2d54 {
    union {
        Vector4fix rows[3];
        struct { int pad_0[6]; Vector3fix normal; Vector3fix side; };
    };
    Vector3fix position;
    char pad_3c[0xc];
};
extern char data_020ee9b8[];
extern int data_020ef0e8;
int SubmitBlock0x40IfNotBusy(int);
void SetFields0x0_0x4_0x8(int*, int, int, int);
extern "C" void* _Z32GetSubstructAt0x40OrNull020e2fb0Pv(void*);
extern "C" void func_020ca430(const void*, void*, int);
static inline int GetBoneScale020e2d54(Bone020e2d54* bone) { SDK_NULL_ASSERT(bone); return bone->scaleZ; }
static inline int GetVectorZ020e2d54(Vector3fix* vector) { SDK_NULL_ASSERT(vector); return vector->z; }
static inline int Divide020e2d54(int a, int b) { int value = fix32_Divide(a, b); return value; }

// USA: func_020e2d54
extern "C" ARM void func_020e2d54(int mode, RenderCommandHandler* entry, Output020e2d54* output) {
    Matrix4x4 matrix;
    Vector3fix scale;
    Vector3fix offset;
    if (!(entry->flags_ & 0x100)) {
        SendQueuedDataToGeometryFifo();
        REG_GXFIFO = 0x151110;
        REG_GXFIFO = 0;
        while (SubmitBlock0x40IfNotBusy((int)&matrix)) {}
        SetFields0x0_0x4_0x8(&scale.x, 0x1000, 0x1000, 0x1000);
        int correction = 0;
        if (mode == 1) {
            scale.x = Vector3fix_Length(&matrix.rows[0].xyz);
            scale.y = Vector3fix_Length(&matrix.rows[1].xyz);
            scale.z = Vector3fix_Length(&matrix.rows[2].xyz);
        }
        if (mode == 1) {
            SetFields0x0_0x4_0x8(&offset.x, 0, 0, 0);
            NSBXXInternalModel* model = entry->modelContext_->internalModel_;
            NSBXXNameList* list = (NSBXXNameList*)_Z32GetSubstructAt0x40OrNull020e2fb0Pv(model);
            int index = list ? NSBXXNameList_SearchIndex(list, data_020ee9b8) : -1;
            if (index >= 0) {
                list = (NSBXXNameList*)_Z32GetSubstructAt0x40OrNull020e2fb0Pv(model);
                Bone020e2d54* bone;
                if (!list) goto missingBone;
                {
                    unsigned int* resourceOffset;
                    if (list && (unsigned int)index < list->numEntries_) {
                        unsigned char* data = (unsigned char*)list + list->offsetToDataStart_;
                        unsigned short stride = *(unsigned short*)data;
                        resourceOffset = (unsigned int*)(data + 4 + stride * index);
                    } else resourceOffset = 0;
                    if (resourceOffset) {
                        bone = (Bone020e2d54*)((char*)list + *resourceOffset);
                        goto foundBone;
                    }
                }
            missingBone:
                bone = 0;
            foundBone:
                if (!(bone->flags & 1)) {
                    offset.z = FIX32_MULTIPLY(GetVectorZ020e2d54(&scale), GetBoneScale020e2d54(bone));
                }
                if (fix32abs(matrix.rows[3].z) >= 4) {
                    correction = FIX32_MULTIPLY(GetVectorZ020e2d54(&offset), Divide020e2d54(matrix.rows[3].x, matrix.rows[3].z));
                }
            }
        }
        output->position.x = matrix.rows[3].x + correction;
        output->position.y = matrix.rows[3].y;
        output->position.z = matrix.rows[3].z;
        if (mode == 1) {
            output->rows[0].w = scale.x;
            output->rows[1].w = scale.y;
            output->rows[2].w = scale.z;
        }
        if (mode == 0 && (matrix.rows[1].y || matrix.rows[1].z) && data_020ef0e8) {
            Vector3fix_Normalize(&matrix.rows[1].xyz, &output->normal);
            output->side.y = -output->normal.z;
            output->side.z = output->normal.y;
            data_020ef0e8 = 0;
        }
        func_020ca430(output, (void*)0x04000400, 0x48);
    }
    entry->flags_ |= 0x40;
}
