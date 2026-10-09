#include <globaldefs.h>

#include "World/Zone3D.h"
struct ProximityNode0201b678 {
    int field0;
    int field4;
    Vector3fix position;
    char unknown14[0x28];
    int radius;
    char unknown40[0x30];
    ProximityNode0201b678* next;
};
void* GetPointerFromArray0x3c(unsigned char*, unsigned int);
int Vector3fix_Distance(const Vector3fix*, const Vector3fix*);

// USA: func_0201b678
extern "C" ARM ProximityNode0201b678* func_0201b678(Zone3D* zone, const Vector3fix* input) {
    ProximityNode0201b678* preferred = 0;
    ProximityNode0201b678* node = (ProximityNode0201b678*)GetPointerFromArray0x3c((unsigned char*)zone->substruct_6c_, 10);
    Vector3fix position;
    position.x = input->x * 6;
    position.y = input->y * 6;
    position.z = input->z * 6;
    int preferredDistance = 0x0ffff000;
    int fallbackDistance = preferredDistance;
    ProximityNode0201b678* fallback = 0;
    position.x -= zone->substruct_c_.unknown_38_;
    position.z -= zone->substruct_c_.unknown_3c_;
    while (node) {
        int distance = Vector3fix_Distance(&node->position, &position);
        if (distance < preferredDistance) {
            if (distance <= node->radius) {
                preferredDistance = distance;
                preferred = node;
            } else if (distance < fallbackDistance) {
                fallbackDistance = distance;
                fallback = node;
            }
        }
        node = node->next;
    }
    if (preferred) return preferred;
    if (!fallback) fallback = 0;
    return fallback;
}
