#include <globaldefs.h>
#include "System/Cache.h"

extern "C" void func_ov031_0220da1c(int a);
extern "C" void func_ov031_0220db6c(void);
extern "C" void func_ov031_0220d984(int a, void* b, int c, int d);
extern "C" void func_ov031_0220f394(int a);
void CallCallback28_0220ef9c(char* p);

extern void* data_ov031_0224e53c;

struct Msg0220e584 {
	unsigned short field0;
	unsigned short field2;
	unsigned short field4;
	unsigned short pad6;
	void* field8;
};

// USA: func_ov031_0220e584
extern "C" ARM void func_ov031_0220e584(Msg0220e584* self) {
	switch (self->field2) {
	case 0:
		switch (self->field4) {
		case 0xe: {
			unsigned char* base = (unsigned char*)data_ov031_0224e53c;
			int val = *(int*)(base + 0x2000 + 0x260);
			if (val == 0xc) {
				func_ov031_0220da1c(8);
				func_ov031_0220db6c();
			} else {
				func_ov031_0220da1c(9);
				unsigned char* base2 = (unsigned char*)data_ov031_0224e53c;
				func_ov031_0220d984(0, base2 + 0x2140, 0, 0x872);
			}
			break;
		}
		case 0xf: {
			unsigned short h = *(unsigned short*)((unsigned char*)self->field8 + 0xe);
			int x = h;
			func_ov031_0220f394((x >> 8) & 0xff);
			InvalidateDataCacheRange(self->field8, 0x620);
			CallCallback28_0220ef9c((char*)self->field8);
			break;
		}
		default: {
			func_ov031_0220da1c(0xb);
			unsigned char* base = (unsigned char*)data_ov031_0224e53c;
			int f4 = self->field4;
			func_ov031_0220d984(7, base + 0x2140, f4, 0x881);
			break;
		}
		}
		break;
	case 4:
	default: {
		func_ov031_0220da1c(0xb);
		unsigned char* base = (unsigned char*)data_ov031_0224e53c;
		func_ov031_0220d984(7, base + 0x2140, 0, 0x88c);
		break;
	}
	}
}
