#include <globaldefs.h>

#if defined(jpn)
enum { kResourceTableOffset = 0x3500 };
#else
enum { kResourceTableOffset = 0x3710 };
#endif

extern "C" void func_ov017_021b996c(int a, int b, unsigned char c, unsigned char d, unsigned short e);
extern "C" void func_ov017_021b9a98(int a, int b, unsigned char c, unsigned char d, unsigned short e);

struct LocalEvt021d0808 {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
	unsigned char field6;
	unsigned char pad1;
	unsigned short field8;
};

// USA: func_ov017_021d0808
ARM void DispatchModeHelper_021d0808(int origParam0, LocalEvt021d0808* evt, int unused2, unsigned char* base) {
	int table2 = *(int*)(base + kResourceTableOffset);
	if (evt->field6 == 0) {
		func_ov017_021b996c(table2, origParam0, evt->field4, evt->field5, evt->field8);
	} else if (evt->field6 == 1) {
		func_ov017_021b9a98(table2, origParam0, evt->field4, evt->field5, evt->field8);
	}
}
