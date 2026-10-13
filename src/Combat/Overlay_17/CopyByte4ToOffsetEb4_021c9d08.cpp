#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { kWorkByteOffset = 0xe30 };
#else
enum { kWorkByteOffset = 0xeb4 };
#endif


#if defined(jpn)
#define CopyByte4ToOffsetEb4_021c9d08 func_ov017_021ca1b8
#endif

extern "C" void* func_ov017_021b8468(void*);

struct ByteEvent {
    unsigned char unknown0[4];
    unsigned char value;
};

struct EventByteWork {
    unsigned char unknown0[kWorkByteOffset];
    unsigned char unknownEventByte;
};

// USA: func_ov017_021c9d08
#if defined(jpn)
extern "C"
#endif
ARM void CopyByte4ToOffsetEb4_021c9d08(void* unused0, void* src, void* unused2, void* obj) {
	EventByteWork* dst = (EventByteWork*)func_ov017_021b8468(((GameResources*)obj)->unknown_ptr_3718);
	if (dst) {
		dst->unknownEventByte = ((ByteEvent*)src)->value;
	}
}
