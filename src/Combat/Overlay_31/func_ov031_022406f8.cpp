#include <globaldefs.h>

struct BufferSegment {
    BufferSegment* next;
    unsigned char bytes[512];
};
struct TextBuffer {
    int length;
    unsigned char field_0x4[24];
    BufferSegment* next;
    unsigned char bytes[1024];
};
void CopyMemory_022415c8(void* destination, const void* source, unsigned int size);

// USA: func_ov031_022406f8
extern "C" ARM int func_ov031_022406f8(TextBuffer* buffer, unsigned char* destination, int offset, int size) {
    if (offset + size <= buffer->length) {
        if (size != 0) {
            if (offset < 1024) {
                int amount = 1024 - offset;
                if (size <= amount) amount = size;
                CopyMemory_022415c8(destination, buffer->bytes + offset, amount);
                offset += amount;
                size -= amount;
                destination += amount;
            }
            if (size != 0) {
                int rest = offset - 1024;
                int segments = rest >> 9;
                offset = rest & 511;
                int remaining = segments - 1;
                BufferSegment* segment = buffer->next;
                if (segments != 0) {
                    do {
                        segment = segment->next;
                    } while (remaining-- != 0);
                }
                if (size != 0) do {
                    int amount = 512 - offset;
                    if (size <= amount) amount = size;
                    CopyMemory_022415c8(destination, segment->bytes + offset, amount);
                    offset = (offset + amount) & 511;
                    size -= amount;
                    destination += amount;
                    segment = segment->next;
                } while (size != 0);
            }
        }
        return 1;
    }
    return 0;
}
