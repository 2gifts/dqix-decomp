#include <globaldefs.h>

#if defined(jpn)
static const int frameReadIndexOffset = 0xc0;
static const int frameBufferCountOffset = 0xa4;
#else
static const int frameReadIndexOffset = 0xc4;
static const int frameBufferCountOffset = 0xa8;
#endif

// The sibling producer func_ov016_0218f088 advances the produced count after
// recording a stream value. Consumption has a separate wrapping read index.
// Whether one entry always represents one displayed video frame is not established here.
// USA: func_ov016_0218f2f0
// JPN: func_ov016_0218f510
ARM int IncrementCounters_0218f2f0(void* streamState) {
	char* stateBytes = (char*)streamState;
	unsigned int consumedEntryCount = *(unsigned int*)(stateBytes + 0x9c);
	unsigned int producedEntryCount = *(unsigned int*)(stateBytes + 0xa0);
	if (consumedEntryCount >= producedEntryCount) return 0;
	*(unsigned int*)(stateBytes + 0x9c) = consumedEntryCount + 1;
	unsigned int nextReadIndex = *(unsigned int*)(stateBytes + frameReadIndexOffset) + 1;
	*(unsigned int*)(stateBytes + frameReadIndexOffset) = nextReadIndex;
	if (nextReadIndex == *(unsigned int*)(stateBytes + frameBufferCountOffset)) {
		*(unsigned int*)(stateBytes + frameReadIndexOffset) = 0;
	}
	return 1;
}
