#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct Queue6584 {
    char pad_0x0[0x102];
    unsigned short count;
    BlockedContextList blocked;
};
struct Channel6584 {
    char pad_0x0[0x48];
    int length;
    char* buffer;
    char pad_0x50[0x18];
    Queue6584* queue;
    char pad_0x6c[4];
    short flags;
    char field_0x72;
    signed char mode;
};
struct Transfer6584 {
    int field_0x0;
    Channel6584* channel;
    char pad_0x8[8];
    char* destinationA;
    int capacityA;
    char* destinationB;
    int capacityB;
    unsigned short count;
    unsigned short field_0x22;
    unsigned short first;
    unsigned short second;
    unsigned int update;
};
void UpdateObjFromContext_022031bc(int, unsigned short, unsigned int);
void UpdateAndWaitOnContext_02203424();
extern "C" int func_ov031_022066b4(int);
extern "C" int func_ov031_02206758(char*, int, Transfer6584*);
extern "C" int func_ov031_02203a84(char*, int);

static inline bool IsSpecialMode6584(Channel6584* channel) {
    return channel->mode == 0 || channel->mode == 4;
}

// USA: func_ov031_02206584
extern "C" ARM int func_ov031_02206584(Transfer6584* transfer) {
    char* buffer;
    Channel6584* channel;
    Queue6584* queue;
    int result;
    channel = transfer->channel;
    result = 0;
    queue = channel->queue;
    if (IsSpecialMode6584(channel)) {
        if (!(channel->flags & 4)) goto failed;
    }
    if (transfer->update != 0) {
        UpdateObjFromContext_022031bc(transfer->first, transfer->second, transfer->update);
    }
    {
        buffer = channel->buffer;
        int headerSize = (channel->mode == 0 || channel->mode == 4) ? 0x36 : 0x2a;
        int length;
        if (channel->mode == 0 || channel->mode == 4) length = func_ov031_022066b4(channel->length - headerSize);
        else length = channel->length - headerSize;
        for (;;) {
            int copied = func_ov031_02206758(buffer + headerSize, length, transfer);
            if (copied <= 0) break;
            int received = func_ov031_02203a84(buffer + headerSize, copied);
            if (received <= 0) {
                if (IsSpecialMode6584(channel)) {
                    channel->flags &= ~0xe;
                    channel->flags |= 0x80;
                    UpdateAndWaitOnContext_02203424();
                }
                result = -76;
                break;
            }
            result += received;
        }
        goto completed;
    }
failed:
    result = -76;
completed:
    queue->count = transfer->count;
    UnblockContexts(&queue->blocked);
    return result;
}
