#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(void* obj);
struct Node02040668;
void ClearActiveChildFlag02040668(struct Node02040668* obj);
struct Node020406b0;
void SetActiveChildFlag020406b0(struct Node020406b0* obj);

struct Entry_02161408 { int type; int val; int pad2; void* child; };
struct DataTable_02161408 { char pad[4]; Entry_02161408* table; };
extern struct DataTable_02161408 data_ov001_02165880;

// USA: func_ov001_02161408  (semantic: DispatchToggleByTableType_02161408)
extern "C" ARM int func_ov001_02161408(void* self) {
    int idx = func_ov017_021d60f4(self);
    int flag = func_ov017_021d60f4((char*)self + 0x8);
    switch (data_ov001_02165880.table[idx].type) {
        case 0:
        case 1:
        case 4:
        case 5: {
            void* child = data_ov001_02165880.table[idx].child;
            if (child == 0) return 0;
            if (flag != 0) {
                ((Object3D*)((unsigned char*)child))->DisableFlag(1);
            } else {
                ((Object3D*)((unsigned char*)child))->EnableFlag(1);
            }
            break;
        }
        case 6: {
            void* c = data_ov001_02165880.table[idx].child;
            if (c == 0 || *(void**)((char*)c + 0x18) == 0) return 0;
            void* grandchild = *(void**)((char*)c + 0x18);
            if (flag != 0) {
                ((Object3D*)((unsigned char*)grandchild))->DisableFlag(1);
                ClearActiveChildFlag02040668((struct Node02040668*)data_ov001_02165880.table[idx].child);
            } else {
                ((Object3D*)((unsigned char*)grandchild))->EnableFlag(1);
                SetActiveChildFlag020406b0((struct Node020406b0*)data_ov001_02165880.table[idx].child);
            }
            break;
        }
        case 2: {
            void* child = data_ov001_02165880.table[idx].child;
            if (child == 0) return 0;
            if (flag != 0) {
                ClearActiveChildFlag02040668((struct Node02040668*)child);
            } else {
                SetActiveChildFlag020406b0((struct Node020406b0*)child);
            }
            break;
        }
        default:
            break;
    }
    return 1;
}
