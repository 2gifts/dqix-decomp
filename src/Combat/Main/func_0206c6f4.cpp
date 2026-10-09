#include <globaldefs.h>
#include "Combat/NodeLookup.h"
#include "Graphics/Vector.h"
#include "Resource/Script.h"
struct Node0206c6f4 {
    unsigned char pad0[0x10];
    int x;
    int field_0x14;
    int z;
    unsigned char pad1[3];
    unsigned char mode;
    unsigned short field_0x20;
    short angle;
    int maxX;
    int maxZ;
    int minX;
    int minZ;
    unsigned char pad2[0x44 - 0x34];
    unsigned short id;
    unsigned char pad3[0x70 - 0x46];
    Node0206c6f4* next;
};
struct Data0206c6f4 {
    unsigned char pad0[0xa];
    unsigned short id;
    unsigned int field_0xc;
    void* head;
};
extern Data0206c6f4 data_02108cec;
// USA: func_0206c6f4
extern "C" ARM int func_0206c6f4(Script::Parameter* p) {
    Node0206c6f4* node = (Node0206c6f4*)FindNodeByByteId(data_02108cec.head, p->ToInt());
    if (!node) return 0;
    while (node) {
        if (node->id == data_02108cec.id) break;
        node = node->next;
    }
    if (!node) return 0;
    node->mode = 8;
    node->angle = (int)(4096.0f * p[1].ToFloat());
    int radius = (int)(4096.0f * p[2].ToFloat());
    int x = (int)(((long long)radius * fix32sin(node->angle) + 0x800) >> 12);
    int z = (int)(((long long)radius * fix32cos(node->angle) + 0x800) >> 12);
    node->maxX = node->x + x;
    node->maxZ = node->z + z;
    node->minX = node->x - x;
    node->minZ = node->z - z;
    int minimum = node->minX, maximum = node->maxX;
    if (maximum < minimum) {
        node->maxX = minimum;
        node->minX = maximum;
    }
    minimum = node->minZ;
    maximum = node->maxZ;
    if (maximum < minimum) {
        node->maxZ = minimum;
        node->minZ = maximum;
    }
    return 1;
}
