#include <globaldefs.h>
#include "System/Memory.h"

struct DispatchEntry0202cefc {
    unsigned char pad0[0x3c];
    unsigned short unknown_0x3c;
    unsigned char pad3e[2];
    unsigned short mode;
    unsigned char pad42[2];
    unsigned int identifier;
    unsigned char pad48[3];
    unsigned char flags;
    unsigned char pad4c[0x74];
};
struct DispatchReply0202cefc {
    unsigned char pad0[2];
    unsigned short error;
    unsigned char pad4[4];
    unsigned short type;
    unsigned char pada[4];
    unsigned short count;
    DispatchEntry0202cefc* entries[1];
};
struct DispatchState0202cefc {
    unsigned char pad0[4];
    unsigned short active;
    unsigned char pad6[0xa];
    int state;
    unsigned char pad14[8];
    int check;
    unsigned char pad20[0x24];
    void (*callback)(DispatchEntry0202cefc*);
};
struct DispatchInfo0202cefc {
    unsigned char pad0[8];
    unsigned int identifier;
};
extern DispatchState0202cefc data_021015a0;
extern unsigned char data_02101b80[0x400];
extern DispatchInfo0202cefc data_02101640;
extern DispatchEntry0202cefc data_021016e0;
void SetField0x48UnlessState9Or10_0202c848(int);
int IsDispatchComplete0202d0e0();
void InvalidateDataCacheRange(const void*, unsigned int);
extern "C" int func_020c0290(DispatchEntry0202cefc*);
extern "C" int func_0202cddc();
static inline int IsDispatchEntryMode0202cefc(DispatchEntry0202cefc* entry) { return entry->mode == 1; }

// USA: func_0202cefc
extern "C" ARM void func_0202cefc(DispatchReply0202cefc* reply) {
    if (reply->error != 0) {
        SetField0x48UnlessState9Or10_0202c848(reply->error);
        data_021015a0.state = 9;
        return;
    }
    if (data_021015a0.state != 2) {
        data_021015a0.active = 0;
        if (!IsDispatchComplete0202d0e0()) data_021015a0.state = 9;
        return;
    }
    if (reply->type != 4 && reply->type == 5) {
        if (reply->count != 0) InvalidateDataCacheRange(data_02101b80, 0x400);
        int index;
        int found = 0;
        index = 0;
        for (; index < reply->count; index++) {
            DispatchEntry0202cefc* entry = reply->entries[index];
            if (data_021015a0.check != 0 && func_020c0290(entry)) {
                if (data_021015a0.callback) data_021015a0.callback(entry);
            } else {
                int valid = 0;
                if (entry->unknown_0x3c >= 0x10) valid = IsDispatchEntryMode0202cefc(entry);
                if (valid == 0) continue;
                if (entry->identifier != data_02101640.identifier) continue;
                switch (entry->flags & 3) {
                case 1:
                    VectorizedInvertedMemcpy(entry, &data_021016e0, 0xc0);
                    found = 1;
                    goto finished;
                }
            }
        }
finished:
        if (found) {
            if (data_021015a0.callback) data_021015a0.callback(&data_021016e0);
            if (data_021015a0.active != 0) {
                if (!IsDispatchComplete0202d0e0()) data_021015a0.state = 9;
                return;
            }
        }
    }
    if (!func_0202cddc()) data_021015a0.state = 9;
}
