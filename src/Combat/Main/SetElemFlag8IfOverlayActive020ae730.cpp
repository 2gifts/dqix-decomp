#include <globaldefs.h>

#include "World/Zone3D.h"

extern "C" void* func_02012fe4(void);
void SetOrClearElemFlag0x4ByKeys_020ae694(int mode, int key1, unsigned short key2);
void SetFlagBitAndNotifyOverlay17_020ae4ec(int param0, int param1);

// USA: func_020ae730
ARM void SetElemFlag8IfOverlayActive020ae730(int a) {
    if (((Zone3D*)func_02012fe4())->currentZoneID_ != 0x1edd) {
        return;
    }
    Zone3D* zone = (Zone3D*)func_02012fe4();
    ZoneFeatures::Opcode6aEntry* p = GetElementStride0x74_0201e664(&zone->substruct_6c_, 3);
    ZoneFeatures::Opcode6aEntry* q = GetElementStride0x74_0201e664(&zone->substruct_6c_, 4);
    if (p == NULL || q == NULL) {
        return;
    }
    if (a != 0) {
        p->unk_28 &= ~8;
        q->unk_28 &= ~8;
    } else {
        p->unk_28 |= 8;
        q->unk_28 |= 8;
    }
    SetOrClearElemFlag0x4ByKeys_020ae694(a, 0, 0x10);
    SetFlagBitAndNotifyOverlay17_020ae4ec(6, a != 0);
}
