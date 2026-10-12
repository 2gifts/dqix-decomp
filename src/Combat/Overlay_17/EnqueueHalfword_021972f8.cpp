#include <globaldefs.h>

#if defined(jpn)
enum { QUEUE_COUNTER_OFFSET = 0x4210, QUEUE_DATA_OFFSET = 0x4208 };
#else
enum { QUEUE_COUNTER_OFFSET = 0x44c0, QUEUE_DATA_OFFSET = 0x44b8 };
#endif


#if defined(jpn)
#define EnqueueHalfword_021972f8 func_ov017_02197ea8
#endif

// USA: func_ov017_021972f8
#if defined(jpn)
extern "C"
#endif
ARM void EnqueueHalfword_021972f8(void *obj, unsigned short val) {
	unsigned char *counter = (unsigned char *)obj + QUEUE_COUNTER_OFFSET;
	unsigned short *arr = (unsigned short *)((unsigned char *)obj + QUEUE_DATA_OFFSET);
	unsigned char idx = *counter;
	*counter = idx + 1;
	arr[idx] = val;
	*counter = *counter & 3;
}
