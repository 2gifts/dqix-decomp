#include <globaldefs.h>

#if defined(jpn)
#define MergeIntoBuffers_0215fd60 func_ov006_021610c4
enum { kMergeBuffer = 0x140 };
#else
enum { kMergeBuffer = 0x14c };
#endif



extern "C" void __clear(void* buf, int len);
extern "C" void func_02071da4(void* obj, short* bufB, unsigned char* bufA, int val);

// USA: func_ov006_0215fd60
#if defined(jpn)
extern "C"
#endif
ARM void MergeIntoBuffers_0215fd60(void* obj, short* arr1, unsigned char* arr2, int val) {
	short bufB[3];
	unsigned char bufA[3];
	__clear(bufB, 6);
	__clear(bufA, 3);
	for (unsigned char i = 0; i < 3; i++) {
		short id = arr1[i];
		if (id > 0) {
			for (unsigned char j = 0; j < 3; j++) {
				short w = bufB[j];
				if (id == w) {
					bufB[j] = id;
					bufA[j] = (unsigned char)(bufA[j] + arr2[i]);
					break;
				}
				if (w <= 0) {
					bufB[j] = id;
					bufA[j] = arr2[i];
					break;
				}
			}
		}
	}
	func_02071da4((char*)obj + kMergeBuffer, bufB, bufA, val);
}
