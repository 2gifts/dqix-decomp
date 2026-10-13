#include <globaldefs.h>
#include "World/ZoneChest.h"

// USA: func_02018b34
ARM BmdjSceneElement* FindEntryByNodeIdAndKey(Zone3D* zone, ZoneFeatures::Opcode6aEntry* parameter) {
    BmdjScriptNode* node;
    BmdjSceneElement* result;
    int count;
    int i;
    if (parameter->maybeType != 2) return NULL;
    if (zone->unknown_424_ != 0) return NULL;
    node = zone->firstBMDJStruct_41c_;
    while (node != NULL) {
        if (node->unknown0 == parameter->unk_2c.type2.unk_0) break;
        node = node->next;
    }
    result = NULL;
    if (node == NULL) return result;
    count = node->scriptState.elementCount;
    for (i = 0; i < count; i++) {
        if (parameter->unk_2c.type2.unk_1 == node->elements[i].id) {
            result = &node->elements[i];
            break;
        }
    }
    return result;
}
