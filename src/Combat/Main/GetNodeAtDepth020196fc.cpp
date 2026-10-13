#include <globaldefs.h>

#include "World/Zone3D.h"

// USA: func_020196fc
ARM BmdjScriptNode* GetNodeAtDepth020196fc(Zone3D* obj, int count) {
    BmdjScriptNode* cur = obj->firstBMDJStruct_41c_;
    int i;
    for (i = 0; i < count; i++) {
        if (cur == 0) {
            return 0;
        }
        cur = cur->next;
    }
    return cur;
}
