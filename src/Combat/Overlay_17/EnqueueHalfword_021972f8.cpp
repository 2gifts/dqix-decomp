#include <globaldefs.h>

#if defined(jpn)
enum { kBufferOffset = 0x4208 };
#else
enum { kBufferOffset = 0x44b8 };
#endif

struct FourEntryBuffer {
    unsigned short entries[4];
    unsigned char nextSlot;
};

struct BufferOwner {
    unsigned char unknown0[kBufferOffset];
    FourEntryBuffer buffer;
};

// USA: func_ov017_021972f8
ARM void EnqueueHalfword_021972f8(void *obj, unsigned short val) {
	BufferOwner* owner = (BufferOwner*)obj;
	unsigned char slot = owner->buffer.nextSlot++;
	owner->buffer.entries[slot] = val;
	owner->buffer.nextSlot &= 3;
}
