#include <globaldefs.h>
#include "World/ZoneChest.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_02012fe4(void);
void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index);


// USA: func_ov001_0215fc48  (semantic: SetNodeFlagAndNotifyVariantC_0215fc48)
extern "C" ARM int func_ov001_0215fc48(char* args, int count) {
    int key0 = func_ov017_021d60f4(args);
    char* p = args + 0x8;
    args += 0x10;
    int key1 = func_ov017_021d60f4(p);
    int key2 = 1;
    int key3 = 1;
    if (count > 2) {
        key2 = func_ov017_021d60f4(args);
        args += 0x8;
    }
    if (count > 3) {
        key3 = func_ov017_021d60f4(args);
    }

    Zone3D* base = (Zone3D*)func_02012fe4();
    ZoneFeatures::Opcode6aEntry* node = (ZoneFeatures::Opcode6aEntry*)GetPointerFromArray0x3c((unsigned char*)&base->substruct_6c_, 2);
    while (node != NULL) {
        if (!(node->unk_2c.type2.unk_2_high & 1) && node->unk_2c.type2.unk_0 == key0 && node->unk_2c.type2.unk_1 == key1) {
            node->unk_2c.type2.unk_2_high = node->unk_2c.type2.unk_2_high | 0x300;
            func_02018300(base, node, key2, key3, 0);
            BmdjSceneElement* entry = FindEntryByNodeIdAndKey(base, node);
            entry->flags |= 0x40;
        }
        node = node->pNext;
    }
    return 1;
}
