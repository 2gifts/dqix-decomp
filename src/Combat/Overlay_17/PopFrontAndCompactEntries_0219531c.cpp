#include <globaldefs.h>

extern "C" void func_ov017_02195214(void* dst, void* src);

#if defined(jpn)
static const int kCountOffset=0x40d0, kEntriesOffset=0x40d1;
#else
static const int kCountOffset=0x42f0, kEntriesOffset=0x42f1;
#endif

// USA: func_ov017_0219531c
ARM int PopFrontAndCompactEntries_0219531c(void* obj, void* outEntry) {
	unsigned char* o = (unsigned char*)obj;
	if (o[kCountOffset] == 0) return 0;
	func_ov017_02195214(outEntry, o + kEntriesOffset);
	o[kCountOffset] = o[kCountOffset] - 1;
	int i = 0;
	while (i < o[kCountOffset]) {
		func_ov017_02195214(o + kEntriesOffset + i * 15, o + kEntriesOffset + (i + 1) * 15);
		i++;
	}
	return 1;
}
