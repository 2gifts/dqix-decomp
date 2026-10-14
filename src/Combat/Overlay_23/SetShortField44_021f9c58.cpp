#include <globaldefs.h>

struct S_9c58 {
	char pad[0x44];
	short val;
};

// USA: func_ov023_021f9c58
ARM void SetShortField44_021f9c58(S_9c58* obj, unsigned short v) {
	obj->val = v;
}
