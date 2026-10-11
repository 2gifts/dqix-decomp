#include <globaldefs.h>

extern "C" void func_ov017_02195214(void* dst, void* src);

// JPN: func_ov017_02195f60
// USA: func_ov017_02195398  (semantic: RemoveEntryByKey_02195398)
extern "C" ARM void func_ov017_02195398(void* obj, unsigned char key) {
#if defined(jpn)
 enum {regionalOffset0=0x40d0, regionalOffset1=0x40d1, regionalOffset2=0xd0, regionalOffset3=0xd1};
#else
 enum {regionalOffset0=0x42f0, regionalOffset1=0x42f1, regionalOffset2=0x2f0, regionalOffset3=0x2f1};
#endif
	unsigned char* o = (unsigned char*)obj;
	int i = 0;
	while (i < o[regionalOffset0]) {
		unsigned char* p = o + i * 15;
		p = p + 0x4000;
		if (key == p[regionalOffset3]) {
			unsigned char* hdr = o + 0x4000;
			hdr[regionalOffset2] = hdr[regionalOffset2] - 1;
			while (i < hdr[regionalOffset2]) {
				func_ov017_02195214(o + regionalOffset1 + i * 15, o + regionalOffset1 + (i + 1) * 15);
				i++;
			}
			return;
		}
		i++;
	}
}
