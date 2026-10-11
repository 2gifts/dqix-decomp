#include <globaldefs.h>

#if defined(jpn)
static const int frameReadIndexOffset = 0xc0;
static const int frameBufferCountOffset = 0xa4;
#else
static const int frameReadIndexOffset = 0xc4;
static const int frameBufferCountOffset = 0xa8;
#endif

// USA: func_ov016_0218f2f0
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
