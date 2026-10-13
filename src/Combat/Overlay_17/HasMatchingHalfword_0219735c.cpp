#include <globaldefs.h>

#if defined(jpn)
enum { QUEUE_DATA_OFFSET = 0x4208 };
#else
enum { QUEUE_DATA_OFFSET = 0x44b8 };
#endif

struct FourEntryBuffer {
    unsigned short entries[4];
    unsigned char nextSlot;
};


#if defined(jpn)
#define HasMatchingHalfword_0219735c func_ov017_02197f0c
#endif

// USA: func_ov017_0219735c
#if defined(jpn)
extern "C"
#endif
ARM int HasMatchingHalfword_0219735c(unsigned char* obj, unsigned short key) {
	FourEntryBuffer* buffer = (FourEntryBuffer*)(obj + QUEUE_DATA_OFFSET);
	unsigned short* entry = buffer->entries;
	for (int i = 0; i < 4; i++, entry++) {
		if (*entry == key) {
			return 1;
		}
	}
	return 0;
}
