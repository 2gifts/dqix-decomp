#include <globaldefs.h>

struct Sub0218f3c4 {
	char pad1c[0x1c];
	int val;
};

struct Obj0218f3c4 {
	char pad1c[0x1c];
	unsigned char state;
	char pad24[0x24 - 0x1d];
	struct Sub0218f3c4* sub;
};

// USA: func_ov015_0218f3c4
ARM float GetRatio0218f3c4(struct Obj0218f3c4* obj) {
	switch (obj->state) {
	case 0:
	case 1:
		return (float)obj->sub->val / 4096.0f;
	default:
		return (float)obj->sub->val / 4096.0f;
	}
}
