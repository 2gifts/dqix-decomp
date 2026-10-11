#include <globaldefs.h>

extern void* GetOrInitField_0221188c(void);
extern "C" void func_ov031_02243c10(void*);
extern "C" void func_ov031_02243d20(void*);
extern "C" void func_ov031_02243e34(void*);
extern "C" void func_ov031_02244050(void*);
extern "C" void func_ov031_02244660(void*);
extern "C" void func_ov031_02244e44(void*);
extern "C" void func_ov031_02244ad0(void*);
extern "C" int func_ov031_022119d0(int*, int*);
extern "C" void func_ov031_02245548(void*);

struct Struct_02243b34 {
	unsigned char pad0[0x34];
	unsigned char f34;
	unsigned char pad1[0x394 - 0x35];
	int f394;
	unsigned char pad2[0x399 - 0x398];
	unsigned char f399;
	unsigned char pad3[0x3d0 - 0x39a];
	unsigned char f3d0;
};

// USA: func_ov031_02243b34  (semantic: DispatchByField34AndAdvanceTimer_02243b34)
extern "C" ARM void func_ov031_02243b34(Struct_02243b34* p) {
	if (p->f3d0 != 0) {
		GetOrInitField_0221188c();
	}
	switch (p->f34) {
		case 1: func_ov031_02243c10(p); break;
		case 2: func_ov031_02243d20(p); break;
		case 3: func_ov031_02243e34(p); break;
		case 4: func_ov031_02244050(p); break;
		case 5: func_ov031_02244660(p); break;
		case 6: func_ov031_02244e44(p); break;
		case 7: func_ov031_02244ad0(p); break;
		case 8: break;
		default: break;
	}
	if (p->f3d0 == 0 && p->f399 == 0) {
		int a, b;
		func_ov031_022119d0(&a, &b);
		p->f394 = -a;
	}
	func_ov031_02245548(p);
}
