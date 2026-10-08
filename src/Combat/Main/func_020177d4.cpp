#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/ZoneResourceTree.h"
#include <globaldefs.h>

// USA: func_020177d4
extern "C" ARM void func_020177d4(Zone3D *zone, void *resourceNode, SafeAllocator *allocator) {
    ZoneResourceTree *tree = static_cast<ZoneResourceTree *>(resourceNode);
    GameState::GetInstance();
    LightingManager *lighting = LightingManager::GetInstance();
    Manager_1f2a4 *manager    = reinterpret_cast<Manager_1f2a4 *>(&tree->resources.records);
    int count                 = manager->count;
    tree->nodes = static_cast<ZoneResourceRuntimeNode *>(allocator->Allocate(count * sizeof(ZoneResourceRuntimeNode)));
    if (tree->nodes == NULL) return;

    for (int i = 0; i < count; i++) {
        ZoneResourceTreeRecord *source = reinterpret_cast<ZoneResourceTreeRecord *>(GetElementByIndexStride0x20(manager, i));
        ZoneResourceRuntimeNode *node  = &tree->nodes[i];
        Init02013018(reinterpret_cast<InitTarget02013018 *>(node));
        node->key = source->key;
    }

    for (int i = 0; i < count; i++) {
        ZoneResourceTreeRecord *source = reinterpret_cast<ZoneResourceTreeRecord *>(GetElementByIndexStride0x20(manager, i));
        ZoneResourceRuntimeNode *node  = &tree->nodes[i];
        int parentKey                  = source->parentKey;
        if (parentKey > -1) {
            for (int j = 0; j < count; j++) {
                ZoneResourceRuntimeNode *parent = &tree->nodes[j];
                if (source->parentKey == parent->key) {
                    node->parent = parent;
                    AppendToNodeList(reinterpret_cast<ListNode *>(parent), reinterpret_cast<ListNode *>(node));
                    break;
                }
            }
        } else if (i != 0) {
            AppendNodeToList020130e0(reinterpret_cast<Node020130e0 *>(tree->nodes), reinterpret_cast<Node020130e0 *>(node));
        }
    }

    int timeOfDay        = lighting->timeOfDayIndex_;
    void *overrideObject = func_ov017_0218b5b0()->unknown_ptr_3718;
    if (overrideObject != NULL && IsField600B4Zero_021b8b54(overrideObject)) {
        unsigned char *overrideData = static_cast<unsigned char *>(func_ov017_021b8478(overrideObject));
        timeOfDay                   = overrideData[5];
    }

    for (int i = 0; i < count; i++) {
        ZoneResourceTreeRecord *source = reinterpret_cast<ZoneResourceTreeRecord *>(GetElementByIndexStride0x20(manager, i));
        ZoneResourceRuntimeNode *node  = &tree->nodes[i];
        node->source                   = source;
        node->unknown3a                = 0;
        Vector3i position              = source->position;
        if (node->parent == NULL) Vector3fix_Add(&position, &tree->position, &position);

        if (source->flags & 0x10)
            node->flags |= 4;
        else if (source->flags & (1 << timeOfDay))
            node->flags &= ~4;
        else
            node->flags |= 4;

        if (source->trackerKey < 0) {
            node->tracker = &tree->resources.trackers[source->key];
        } else {
            int index =
                FindRecordIndexByHalfwordKey(reinterpret_cast<Table_1f1b0 *>(&tree->resources.records), source->trackerKey);
            if (index >= 0) node->tracker = &tree->resources.trackers[index];
        }

        Struct02012ff0 *tracker = node->tracker;
        if (tracker != NULL) {
            if (tracker->field0 == 0 && tracker->field4 == 0) node->tracker = NULL;
            if (tracker->field0 == 1 && tracker->field4 == 0) node->tracker = NULL;
            if (tracker->field0 == 2 && tracker->field4 == 0) node->tracker = NULL;
            if (tracker->field0 == 2 && node->tracker != NULL) {
                node->object = static_cast<Object3D *>(allocator->Allocate(sizeof(Object3D)));
                if (node->object == NULL) {
                    node->tracker = NULL;
                } else {
                    node->object->Initialize();
                    reinterpret_cast<Object3D *>(tracker->field4)->ShallowCloneTo(node->object);
                }
            }
        }
    }
    InitWithUnitScaleVec0201310c(tree->nodes);
}
