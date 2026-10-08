#include "World/ZoneResourceInitialization.h"
#include <globaldefs.h>

// USA: func_02014a24
extern "C" ARM int func_02014a24(Zone3D *zone, void *data) {
    ZoneResourceNode *node   = static_cast<ZoneResourceNode *>(data);
    int count                = node->elementCount;
    SafeAllocator *allocator = zone->pAllocator_68_;
    node->trackers           = static_cast<Struct02012ff0 *>(allocator->Allocate(count * sizeof(Struct02012ff0)));
    if (node->trackers == NULL) return 0;

    for (int index = 0; index < count; index++) {
        Src02015134 *source =
            static_cast<Src02015134 *>(GetElementStride0xc(reinterpret_cast<unsigned char *>(&node->records), index));
        Struct02012ff0 *trackers = node->trackers;
        InitTrackerFields02012ff0(trackers + index);
        if (source != NULL) {
            if (reinterpret_cast<char *>(source->id)[3] == 'A') {
                func_02015134(reinterpret_cast<Ctx02015134 *>(zone), reinterpret_cast<Out02015134 *>(trackers + index),
                              source);
            } else if (static_cast<unsigned char>(source->pad[2]) & 0x10) {
                func_020151cc(zone, trackers + index, source);
            } else {
                func_02014d80(zone, node, trackers + index, source);
            }
        }
    }
    func_020177d4(zone, node, allocator);
    return 1;
}
