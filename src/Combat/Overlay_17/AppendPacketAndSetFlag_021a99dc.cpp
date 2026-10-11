#if defined(jpn)
enum {regionalOffset0=0xe94, regionalOffset1=0x200, regionalOffset2=0xdec, regionalOffset3=0x218};
#else
enum {regionalOffset0=0xe98, regionalOffset1=0x204, regionalOffset2=0xdf0, regionalOffset3=0x21c};
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

struct PacketTargetStruct021a99dc {
    unsigned char pad0[regionalOffset0];
    unsigned char flags;
};

struct PacketOwnerStruct021a99dc {
    unsigned char pad0[0x20];
    PacketTargetStruct021a99dc* target;
    unsigned char pad1[0x1];
    unsigned char sendCount;
    unsigned char recvCount;
};

// JPN: func_ov017_021aa1b0
// USA: func_ov017_021a99dc  (semantic: AppendPacketAndSetFlag_021a99dc)
extern "C" ARM void func_ov017_021a99dc(PacketOwnerStruct021a99dc* self, void* src, int mode, int amount, unsigned char flag) {
    PacketTargetStruct021a99dc* target = self->target;
    if (target == NULL) {
        return;
    }
    if (mode == 0) {
        unsigned char b = self->sendCount;
        memcpy((char*)target + regionalOffset1 + 0xc00 + b, src, amount);
        self->sendCount = self->sendCount + amount;
    } else if (mode == 2) {
        memcpy((char*)target + regionalOffset2, src, amount);
        target = self->target;
        target->flags = target->flags | 0x4;
    } else {
        target->flags = target->flags | 0x1;
        unsigned char b = self->recvCount;
        memcpy((char*)self->target + regionalOffset3 + 0xc00 + b, src, amount);
        self->recvCount = self->recvCount + amount;
    }
    if (flag != 0) {
        target = self->target;
        target->flags = target->flags | 0x2;
    }
}
