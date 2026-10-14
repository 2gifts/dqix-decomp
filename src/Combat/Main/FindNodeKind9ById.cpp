#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// USA: func_0201e6d4
ARM ZoneFeatures::Opcode6aEntry* FindNodeKind9ById_0201e6d4(ZoneFeatures* owner, int id) {
    ZoneFeatures::Opcode6aEntry* node;
    if (id < 0) {
        return 0;
    }
    node = owner->entries6aByType_[9];
    while (node != 0) {
        if (node->maybeType == 9 && node->unk_2c.type9.unk_0 == id) {
            return node;
        }
        node = node->pNext;
    }
    return 0;
}
