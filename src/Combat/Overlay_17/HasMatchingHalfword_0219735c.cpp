#include <globaldefs.h>

#if defined(jpn)
enum { QUEUE_DATA_OFFSET = 0x4208 };
#else
enum { QUEUE_DATA_OFFSET = 0x44b8 };
#endif


#if defined(jpn)
#define HasMatchingHalfword_0219735c func_ov017_02197f0c
#endif

// USA: func_ov017_0219735c
#if defined(jpn)
extern "C"
#endif
ARM int HasMatchingHalfword_0219735c(unsigned char* obj, unsigned short key) {
	unsigned short* p = (unsigned short*)(obj + QUEUE_DATA_OFFSET);
	for (int i = 0; i < 4; i++, p++) {
		if (*p == key) {
			return 1;
		}
	}
	return 0;
}
