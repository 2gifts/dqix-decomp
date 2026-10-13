#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "std_library_functions.h"

struct BufferChunkEvent {
    unsigned char tag;
    unsigned char reserved[3];
    unsigned short kind : 2;
    unsigned short byteOffset : 14;
    unsigned char bytes[14];
};

struct SynchronizedBuffer {
    unsigned char bytes[0x2e0];
};

struct BufferReceiverView {
    unsigned char unknown00[2];
    unsigned char active;
#if defined(jpn)
    unsigned char unknown03[0x218 - 3];
#else
    unsigned char unknown03[0x288 - 3];
#endif
    SynchronizedBuffer* buffer;
};

ARM void CopyIntoSizedBuffer_021d2368(int unused0, unsigned char* source, int unused2, unsigned char* resourceBase) {
    BufferChunkEvent* event = (BufferChunkEvent*)source;
    GameResources* resources = (GameResources*)resourceBase;
    BufferReceiverView* receiver = (BufferReceiverView*)resources->unknown_ptr_array_3afc[13];
    if (!receiver->active) return;
    SynchronizedBuffer* buffer = receiver->buffer;
    if (buffer == NULL) return;
    unsigned int offset = event->byteOffset;
    int length = sizeof(event->bytes);
    if (offset + sizeof(event->bytes) > sizeof(buffer->bytes)) {
        length = sizeof(buffer->bytes) - offset;
    }
    if (length < 0) return;
    memcpy(buffer->bytes + offset, event->bytes, length);
}
