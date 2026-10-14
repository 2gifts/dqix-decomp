#include <globaldefs.h>

#pragma optimize_for_size off

void InvalidateDataCacheRange(const void* addr, unsigned int len);
extern "C" int func_02001aec(const void* a, const void* b, unsigned int len);

typedef void (*NotifyCallback_022378e4)(int);

struct NameSlot_022378e4 {
    char name[6];
    unsigned char inUse;
};

struct SystemState_022378e4 {
    unsigned char reserved0[0xf00];
    unsigned char cacheBlock[0x400];
    NameSlot_022378e4 slots[16];
    NotifyCallback_022378e4 callback;
    unsigned char reserved1[0x821];
    unsigned char pending;
};

struct Peer_022378e4 {
    unsigned char reserved0[4];
    char name[6];
    unsigned char reserved1[2];
    unsigned char signature[8];
    unsigned char reserved2[1];
    unsigned char flags;
};

struct PeerList_022378e4 {
    unsigned char reserved0[0xe];
    unsigned short count;
    Peer_022378e4* peers[1];
};

extern SystemState_022378e4* data_ov031_02290d0c;
extern char data_ov031_02249288[];

// USA: func_ov031_022378e4
extern "C" ARM void func_ov031_022378e4(PeerList_022378e4* list) {
    SystemState_022378e4* state = data_ov031_02290d0c;
    unsigned char pending = state->pending;
    int count;
    Peer_022378e4* peer;
    int i;
    int j;
    NameSlot_022378e4* slot;
    SystemState_022378e4* sys;

    if (pending != 0) {
        NotifyCallback_022378e4 notify = state->callback;
        if (notify != 0) {
            notify(pending);
        }
        return;
    }
    InvalidateDataCacheRange(state->cacheBlock, 0x400);

    count = list->count;
    i = 0;
    if (count <= 0) {
        return;
    }
    sys = data_ov031_02290d0c;
    do {
        peer = list->peers[i];
        if (func_02001aec(peer->signature, data_ov031_02249288, 8) == 0 && (peer->flags & 1) != 0) {
            slot = sys->slots;
            j = 0;
            do {
                if (func_02001aec(peer->name, slot->name, 6) == 0) {
                    NotifyCallback_022378e4 notify;
                    if (sys->slots[j].inUse != 0) {
                        break;
                    }
                    notify = sys->callback;
                    if (notify == 0) {
                        sys->pending = 1;
                        return;
                    }
                    notify(1);
                    return;
                }
                j++;
                slot++;
            } while (j < 16);
        }
        i++;
    } while (i < count);
}
