#include <globaldefs.h>
#include "World/ZoneChest.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_02012fe4(void);

void* GetPointerFromArray0x3c_0201e838(unsigned char* obj, unsigned int index);

// USA: func_ov001_02160b08
extern "C" ARM int func_ov001_02160b08(void* self, int mode) {
    int a = func_ov017_021d60f4(self);
    int b = func_ov017_021d60f4((char*)self + 0x8);
    if (mode > 2) {
        func_ov017_021d60f4((char*)self + 0x10);
    }
    Zone3D* list = (Zone3D*)func_02012fe4();
    ZoneFeatures::Opcode6aEntry* node = (ZoneFeatures::Opcode6aEntry*)GetPointerFromArray0x3c_0201e838((unsigned char*)&list->substruct_6c_, 2);
    while (node != NULL) {
        if ((node->unk_2c.type2.unk_2_high & 1) && node->unk_2c.type2.unk_0 == a && node->unk_2c.type2.unk_1 == b) {
            node->unk_2c.type2.unk_2_high &= ~0x200;
            func_0201874c(list, node);
        }
        node = node->pNext;
    }
    return 1;
}
